#include "stable.h"
#include "Core.h"
#include "AppManager.h"
#include "WindowInterface.h"

app_creator Core::s_actor;
core_creator Core::s_cctor;

void Core::parse_header(msg_header_t const&& head)
{
	auto&&[stateCode, strErr, datetime] = head;
	if (stateCode)
	{
		debug_out << Core::gbk_from_utf8(strErr) << std::endl;
		debug_out << Core::gbk_from_utf8(datetime) << std::endl;
		debug_out << "StateCode ：" << stateCode << std::endl;
	}
}

Core::sep_type const Core::sep = { 0x1f,0x2d,0x2d,0x2d,0x2d,0x1f };

void Core::registerAppFactory(app_creator fun)
{
	if (!fun)
	{
		debug_out << "工厂函数指针为nullptr" << std::endl;
		return;
	}
	if (s_actor)
	{
		debug_out << "工厂已经存在，现在开始覆盖" << std::endl;
	}
	s_actor = fun;
}

void Core::registerFactory(core_creator fun)
{
	if (!fun)
	{
		debug_out << "core 注册工厂实参为nullptr" << std::endl;
		return;
	}
	if (s_cctor)
	{
		debug_out << "core 工厂函数已经存在,现在开始覆盖" << std::endl;
	}
	s_cctor = fun;
}

core_ptr Core::make_core()
{
	if (s_cctor)
	{
		BOOST_ASSERT_MSG(s_cctor, "还没有注册Core工厂函数");
		core_ptr ptr = boost::bind(s_cctor)();
		return ptr;
	}
	return core_ptr();
}

std::string Core::gbk_to_utf8(std::string const& gbk) 
{
	return boost::locale::conv::to_utf<char>(gbk, "GBK");
}

std::string Core::gbk_from_utf8(std::string const& utf) 
{
	return boost::locale::conv::from_utf(utf, "GBK");
}

std::wstring Core::gbk_to_unicode(std::string const& gbk)
{
	return boost::locale::conv::to_utf<wchar_t>(gbk, "GBK");
}

std::string Core::gbk_from_unicode(std::wstring const& wstr)
{
	return boost::locale::conv::from_utf(wstr, "GBK");
}

std::string Core::stage_encrypt(const std::string &clearText, int len, RSA * rsa,int mode)
{
	const static int32_t everySize = 200;	
 	std::stringstream io;
	rsa_buffer_t subarray;					///每次加密的缓冲区
	rsa_buffer_t encryptedText;				///每次拼接的缓冲区
	rsa_buffer_t stageEncry(len);
	int32_t remSize = clearText.size();
	io << clearText;
	while (!io.eof())
	{
		subarray.resize(everySize < remSize ? everySize : remSize);
		std::fill(stageEncry.begin(), stageEncry.end(), 0);
		std::fill(subarray.begin(), subarray.end(), 0);
		io.read(subarray.data(), everySize < remSize ? everySize : remSize + 1);
		if ((mode == 0 ? RSA_public_encrypt(subarray.size(), (uint8_t*)subarray.data(), (uint8_t*)stageEncry.data(), rsa, RSA_PKCS1_PADDING) :
				RSA_private_encrypt(subarray.size(), (uint8_t*)subarray.data(), (uint8_t*)stageEncry.data(), rsa, RSA_PKCS1_PADDING)) < 0)
		{
			debug_out << "分段加密出错" << std::endl;
		}
		encryptedText.insert(encryptedText.end(), stageEncry.begin(), stageEncry.end());
		remSize -= subarray.size();
		remSize > 0 ? encryptedText.insert(encryptedText.end(), sep.begin(), sep.end()) : void(0);
	}

	return std::string(encryptedText.data(), encryptedText.size());
}

std::string Core::stage_decrypt(const std::string &encryStr, int len, RSA * rsa,int mode)
{
	rsa_buffer_t decryBuf;
	rsa_buffer_t subarray(len);
	typedef boost::split_iterator<std::string::const_iterator> string_split_iterator;
	string_split_iterator p, endp;
	std::string str(encryStr.data(), encryStr.size());
	auto decry = [&mode,&len](std::string const& substr, rsa_buffer_t& subarray, RSA*& rsa)
		///返回真实的加密字节数
	{
		if (substr.empty())
		{
			return;
		}
		subarray.reserve(len);
		std::fill(subarray.begin(), subarray.end(), 0);
		int32_t&& actual = mode == 0 ? RSA_private_decrypt(substr.size(), (uint8_t*)substr.data(), (uint8_t*)subarray.data(), rsa, RSA_PKCS1_PADDING) :
			RSA_public_decrypt(substr.length(), (uint8_t*)substr.data(), (uint8_t*)subarray.data(), rsa, RSA_PKCS1_PADDING);
		if(actual < 0)
		{
			debug_out << "分段解密中出错" << std::endl;
			return;
		}
		subarray.resize(actual);
		return;
	};
	for (p = boost::make_split_iterator(encryStr, boost::first_finder(sep, boost::is_iequal())); p != endp; ++p)
	{
		std::stringstream in;
		in << *p;
		decry(in.str(), subarray, rsa);
		decryBuf.insert(decryBuf.end(), subarray.begin(), subarray.end());
	}
	return std::string(decryBuf.data(), decryBuf.size());
}

std::string Core::rsa_pub_encrypt(const std::string &clearText, const std::string &pubKey)
{
	RSA* rsa = extractRsa(pubKey, 0);
	if (!rsa)
	{
		debug_out << "没有正确使用加密RSA创建失败" << std::endl;
		return std::string();
	}
	int len = RSA_size(rsa);
	std::string&& strRet = stage_encrypt(clearText, len, rsa);
	// 释放内存  
	RSA_free(rsa);
	return strRet;
}

std::string Core::rsa_pub_decrypt(const std::string &cipherText, const std::string &pubKey)
{
	RSA* rsa = extractRsa(pubKey, 0);
	if (!rsa)
	{
		debug_out << "没有正确使用加密RSA创建失败" << std::endl;
		return std::string();
	}
	int len = RSA_size(rsa);
	std::string&& strRet = stage_decrypt(cipherText, len, rsa, 1);
	RSA_free(rsa);
	return strRet;
}

std::string Core::rsa_pri_encrypt(const std::string &clearText, const std::string &priKey)
{
	RSA* rsa = extractRsa(priKey, 1);

	if (!rsa)
	{
		debug_out << "没有正确使用加密RSA创建失败" << std::endl;
		return std::string();
	}
	int len = RSA_size(rsa);
	std::string&& strRet = stage_encrypt(clearText, len, rsa,1);

	RSA_free(rsa);
	return strRet;
}

//type = 0公钥 1=私钥
RSA* Core::extractRsa(const std::string &key, int type)
{
	RSA *rsa = NULL;
	BIO *keybio = BIO_new_mem_buf((unsigned char *)key.c_str(), -1);
	RSA* pRSAPublicKey = RSA_new();
	if (type == 0)
	{
		rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa, NULL, NULL);
	}
	else if (type == 1)
	{
		rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);
	}
	BIO_free_all(keybio);
	return rsa;
}

std::string Core::rsa_pri_decrypt(const std::string &cipherText, const std::string &priKey)
{
	RSA* rsa = extractRsa(priKey, 1);
	if (!rsa)
	{
		debug_out << "没有正确使用加密RSA创建失败" << std::endl;
		return std::string();
	}
	int len = RSA_size(rsa);
	std::string&& strRet = stage_decrypt(cipherText, len, rsa);
	// 释放内存  
	RSA_free(rsa);
	return strRet;
}

void Core::registerEncode(int32_t pktNum, encode_funciton fun)
{
	auto&& it = m_coderMap.find(pktNum);
	if (it == m_coderMap.cend())
	{
		m_coderMap.insert(std::make_pair(pktNum, fun));
	}
	else
	{
		debug_out << "该打包码已经注册" << std::endl;
	}
}

std::string Core::encode(int32_t pktNum, std::string const&& e) const
{
	auto&& it = m_coderMap.find(pktNum);
	if (it != m_coderMap.cend())
	{
		std::string const&& strBody = boost::bind(it->second, _1)(boost::cref(e));
		std::string const&& cipherBody = Core::rsa_pub_encrypt(strBody, m_serverPubkey);
		if (cipherBody.empty())
		{
			debug_out << "加密失败，请检查服务端公钥" << std::endl;
		}
		return cipherBody;
	}
	else
	{
		debug_out << "没有注册打包器 ：" << pktNum << std::endl;
	}
	return std::string();
}

std::string Core::encode(int32_t pktNum, std::string const& e) const
{
	return encode(pktNum, std::move(e));
}

Core::Core()
	: m_isRun(false)
	, m_isEncodeExit(false)
{

}

Core::~Core()
{
	m_isRun = false;
	m_isEncodeExit = true;
	if (m_encodeWork &&  m_encodeWork->joinable())
	{
		m_encodeWork->join();
		m_encodeWork->detach();
	}
}

AppManager* Core::appManager()
{
	if (!def_instance)
	{
		BOOST_ASSERT_MSG(s_actor, "还没有注册App工厂函数");
		def_instance = boost::bind(s_actor)();
	}
	return def_instance.get();
}

void Core::run()
{
	if (m_isRun)
	{
		appManager()->stop();
		def_instance.reset();
		if (m_encodeWork && m_encodeWork->joinable())
		{
#if 1	//主线程中等待报错使用下方转移线程
			if (boost::this_thread::get_id() != m_encodeWork->get_id())
			{
				m_isEncodeExit = true;
				m_encodeWork->join();
				m_encodeWork.reset();
#else
				m_encodeWork->interruption_requested() ? m_encodeWork->interrupt() : void(0);
				thread_ptr thread = boost::make_shared<thread_type>(boost::bind(&this_type::dispatchEncode, this));
				m_encodeWork->swap(*thread);
				m_encodeWork = thread;
#endif
			}
		}
		debug_out << "Core::run() is called" << std::endl;
	}
	appManager()->start();
	m_isRun = true;
	m_isEncodeExit = false;
	if (!m_encodeWork)
	{
		m_encodeWork = boost::make_shared<thread_type>(boost::bind(&this_type::dispatchEncode, this));
	}
	initOthers();
}

void Core::setServerPubkey(std::string const& pubkey)
{
	m_serverPubkey = pubkey;
}

void Core::setLocalPubKey(std::string const& pubKey)
{
	m_localPubKey = pubKey;
}

void Core::setMainWindow(WindowInterface* pWindow)
{
	m_pLoginWindow = pWindow;
}

WindowInterface* Core::mainWindow() const
{
	return m_pLoginWindow;
}

void Core::registerEvent(int32_t iCommand, event_fuction fun)
{
	def_instance->eventManager()->registerEvent(iCommand, fun);
}

void Core::initOthers()
{
	///查看编码器是否在子类被创建，没有则创建默认
	if (!m_encoder)
	{
		m_encoder = boost::make_shared<Encoder>();
	}
	net_ptr iNet = appManager()->loginNetptr();
	iNet ? iNet->registerNetError(boost::bind(&this_type::netLoginError, this, _1)),
		iNet->registerConnected(boost::bind(&this_type::netLoginConnect, this, _1)) : void();

	iNet = appManager()->areaNetptr();
	iNet ? iNet->registerConnected(boost::bind(&this_type::netAreaConnect, this, _1)),
		iNet->registerNetError(boost::bind(&this_type::netAreaError, this, _1)) : void();

	REG_EVENT(message::LC_COMMAND_NONE, receipt_none);
	REG_EVENT(message::LC_COMMAND_LOGIN_RESPONSE, receipt_login_result);

	//REG_ENC(message::CA_COMMAND_NONE, last_reques);
	REG_ENC(message::CL_COMMAND_LOGIN_REQUEST, encode_userLogin);
}

void Core::dispatchEncode()
{
	while (!m_isEncodeExit)
	{
		if (!appManager())
		{
			boost::this_thread::yield();
			continue;
		}
		if (!appManager()->localQueueInterface())
		{
			boost::this_thread::yield();
			continue;
		}
		if (appManager()->localQueueInterface()->isEmpty())
		{
			boost::this_thread::yield();
			continue;
		}
		auto&& msg = appManager()->localQueueInterface()->popMsg();
		auto&&[header, strBody] = msg;
		int32_t nCommand = 0;
		std::tie(nCommand, std::ignore, std::ignore) = header;
		std::string&& serializeStr = encode(nCommand, strBody);
		AppManager::connect_type connection = appManager()->currentNetWork();
		net_ptr iNet;
		if (connection == AppManager::loginNet)
		{
			iNet = appManager()->loginNetptr();
		}
		else if (connection == AppManager::areaNet)
		{
			iNet = appManager()->areaNetptr();
		}
		if (iNet)
		{
			iNet->launchMsg(header, serializeStr);
		}
	}
}

void Core::netLoginConnect(std::string const& strMsg)
{
	debug_out << strMsg << std::endl;
}

void Core::netLoginError(std::string const& strErr)
{
	std::string const&& s = std::move(strErr);
	///抛出的丢包请求
	if (strErr == "error_lose")
	{
		auto&& msg = encode(-1/*缺省值*/, s);
		auto&& net = appManager()->loginNetptr();
		net ? net->launchMsg(m_encoder->last_header(""), msg) : void();
	}
	else
	{
		debug_out << strErr << std::endl;
	}
}

//区域服登录成功后，释放掉登录服的连接
void Core::netAreaConnect(std::string const& strMsg)
{
	appManager()->releaseLogin();
}

void Core::netAreaError(std::string const& strErr)
{
	std::string const&& s = std::move(strErr);
	///抛出的丢包请求
	if (strErr == "error_lose")
	{
		auto&& msg = encode(-1/*缺省值*/, s);
		auto&& net = appManager()->loginNetptr();
		net ? net->launchMsg(m_encoder->last_header(""), msg) : void();
	}
	else
	{
		debug_out << strErr << std::endl;
	}
}

void Core::receipt_login_result(std::string const& strMsg, msg_header_t const& head)
{
	parse_header(std::move(head));
	UserLoginResponse const&& req = unpack_binary<UserLoginResponse>(strMsg);
	if (req.access_token.empty())
	{
		m_pLoginWindow->receiptLogin("密码或账号输入错误");
	}
	m_access_token = req.access_token;
	net_ptr iNet = appManager()->areaNetptr();
	if(!req.server_address.empty() && !req.server_port.empty())
	{
		iNet->start(req.server_address, boost::lexical_cast<uint16_t>(req.server_port));
		m_pLoginWindow->receiptLogin("pass accpet");
	}
	debug_out << "登录凭据随机串：" << req.access_token << std::endl;
	debug_out << "区域服务器ID：" << req.server_uuid << std::endl;
	debug_out << "区域服务器地址：" << req.server_address << std::endl;
	debug_out << "区域服端口：" << req.server_port << std::endl;
}


//*********************************************************
// 函数：   receipt_none
// 全称：  	Core::receipt_none
// 说明：	空消息，报文为空,说明为服务端接收到个错误值，需要客户端进行重发
// *****	从编码队列中取出最后一次发送的数据包，进行发送，编码器中已经序列化好的数据
// *****	不用重新进入到编码队列，所以直接进入到本地的队列等待发送
// 权限：   public 
// 返回值： void
// 限定词：
// 参数： 	std::string const & strMsg				解释：
// 参数： 	msg_header_t const & head				解释：
//*********************************************************
void Core::receipt_none(std::string const& strMsg, msg_header_t const& head)
{
	parse_header(std::move(head));
	auto&&[nCommand, nonce, strDatetime] = m_encoder->last_header("");
	auto&& strBody = m_encoder->last_msg("error_lose");
	std::string&& date = boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());
	client_header_t&& header = std::make_tuple(nCommand, m_access_token, date);
	appManager()->localQueueInterface()->pushMsg(std::make_tuple(header, strBody));		
}

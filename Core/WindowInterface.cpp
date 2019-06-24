#include "stable.h"
#include "WindowInterface.h"
#include "AppManager.h"
#include "Core.h"

void WindowInterface::requestLogin(int32_t user_type, std::string const username, std::string const pass, std::string const pubFile)
{
	UserLoginRequest req;
	req.user_type = user_type;
	req.accoct = username;
	req.passwd = pass;
	std::fstream file(pubFile, std::ios::in);
	if (!file.is_open())
	{
		debug_out << "公钥读取失败" << std::endl;
		return;
	}
	file.seekp(0, std::ios::end);
	int32_t len = file.tellp();
	std::vector<char> pubKey;
	pubKey.resize(len);
	file.seekp(0, std::ios::beg);
	file.read(pubKey.data(), len);
	file.close();
	req.public_key = pubKey.data();
	m_pCore->setLocalPubKey(pubKey.data());
	std::string const&& localSer = Core::pack_binary(req);
	m_pCore->pack_message<message::CL_COMMAND_LOGIN_REQUEST>(std::move(localSer));
}

#include "TestNetwork.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QPushButton>
#include <QMessageBox>
#include <array> 
#include <qt_windows.h>
#include <UserLogin.pb.h>
#include <QStringLiteral>

#pragma comment(lib,"libprotobufd.lib")

TestNetwork::TestNetwork(QWidget *parent)
	: QMainWindow(parent)
	, m_pServer(new QTcpServer(this))
	, m_nsize(0)
{
	ui.setupUi(this);
	connect(m_pServer, &QTcpServer::newConnection, [this]() {
		if (m_pServer->hasPendingConnections())
		{
			auto sock = std::move(m_pServer->nextPendingConnection());
			connect(sock, &QTcpSocket::disconnected, [this, &sock]() {
				m_pSockList.removeOne(sock);
			});
			m_pSockList.push_back(std::move(sock));
		
		}
	});
	connect(ui.btnSend, &QPushButton::clicked, this, &TestNetwork::on_send);
	connect(ui.btnbuild, &QPushButton::clicked, this, &TestNetwork::on_build);
	m_pServer->listen(QHostAddress::Any, 6000);
	message::UserLoginResponse* repone = message::UserLoginResponse::default_instance().New();
	repone->add_user_name("张三");
	repone->add_user_name("李四");
	auto vec = repone->user_name();
	for (auto&& r : vec)
	{
		std::cout << r;
	}
}

void TestNetwork::on_send()
{
	static int32_t ra = 0;
	const int m = 4;
	if (m_vecdata.isEmpty())
	{
		QMessageBox::warning(this, QStringLiteral("数据已经没了"), QStringLiteral("没有数据可发送"));
	}
	if (!(ra % m))
	{
		for (auto&& sock : m_pSockList)
		{
			sock->write(m_vecdata.data(),m_vecdata.size() / m);
		}
	}
	else
	{
		for (auto&& sock : m_pSockList)
		{
			sock->write(m_vecdata.data() + m_vecdata.size() / m, m_vecdata.size() - m_vecdata.size() / m);
		}
		m_vecdata.clear();
	}
	++ra;
}

void TestNetwork::on_build()
{
	std::array<unsigned char, 4> g_head = { 0xaa,0xaa,0xaa,0xaa };
	std::array<unsigned char, 4> g_end = { 0xff,0xff,0xff,0xff };
	std::string begin(reinterpret_cast<char const *>(g_head.data()), g_head.size());
	std::string end(reinterpret_cast<char const*>(g_end.data()), g_end.size());

	int32_t nsize = 0;
	QString data = std::move(ui.editData->text());
	int32_t nCount = ui.dataSize->value();

#if 0
	int32_t nSize = std::move(ui.dataSize->value()) * 1024 * 1024;
	if (nSize <= 0)
	{
		return;
	}
#endif

	std::string str = std::move(data.toStdString());
	nsize = str.size() + begin.size() + end.size() + sizeof(int32_t);
	m_vecdata.resize(nsize * nCount);
	int32_t lenght = (int32_t)str.size();
	for (int i = 0; i < nCount; ++i)
	{
		memcpy_s(m_vecdata.data() + nsize * i, m_vecdata.size(), begin.data(), begin.size());							 //拷贝begin
		memcpy_s(m_vecdata.data() + nsize * i + begin.size(), m_vecdata.size() - begin.size(), &lenght, sizeof(int32_t));//拷贝大小
		memcpy_s(m_vecdata.data() + nsize * i + begin.size() + sizeof(int32_t),
			m_vecdata.size() - begin.size() - sizeof(int32_t), std::move(str.data()), str.size());					//拷贝报文
		memcpy_s(m_vecdata.data() + nsize * i + begin.size() + sizeof(int32_t) + str.size(),
			m_vecdata.size() - begin.size() - sizeof(int32_t) - str.size(), end.data(), end.size());					//拷贝end
	}
#if 0
	int32_t nCount = nSize / str.size();
	for (int i = 0; i < nCount; i++)
	{
		memcpy_s(vecdata.data() + i * str.size(), vecdata.size() - i * str.size(), str.c_str(), str.size());
	}
#endif
}

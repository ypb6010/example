#include "stable.h"
#include "TcpClient.h"  
#include <QProcess>
#include <QFile>
#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>
#include <QItemDelegate>
#include <QHeaderView>
#include <QPainter>
#include <QPushButton>

#include <../MedicalWidget/TableHeaderView.h>
#include <../MedicalWidget/ButtonDelegate.h>
class WaitMode :public QStandardItemModel
{
public:
	using QStandardItemModel::QStandardItemModel;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
	{
		if (Qt::TextAlignmentRole == role)
			return Qt::AlignCenter;
		return QStandardItemModel::data(index, role);
	}
};


#if 0

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTableView view;
	view.resize(800, 600);
	WaitMode mode;
	QStringList header;
	auto headerview = new TableHeaderView(Qt::Horizontal, &view);
	headerview->setMinimumHeight(50);
	headerview->setSectionResizeMode(QHeaderView::Stretch);
	view.setHorizontalHeader(headerview);
	
	view.verticalHeader()->setVisible(false);
	header << QStringLiteral("就诊号") << QStringLiteral("患者姓名") << QStringLiteral("状态") << QStringLiteral("前方等待人数") << QStringLiteral("操作");
	mode.setHorizontalHeaderLabels(header);
	view.setStyleSheet(QLatin1String("QTableView\n" \
		"{\n" \
		"	font-family: MicrosoftYaHei;\n"\
		"	font-size: 16px;\n"\
		"	line-height: 20px;\n"\
		"	color: #333333;\n"\
		"	show-decoration-selected: 1;\n"\
		"\n"\
		"}\n"\
		"\n"\
		"QTreeView::item \n"\
		"{\n"\
		"   min-height:50px;\n"\
		"	font-family: MicrosoftYaHei;\n"\
		"	font-size: 16px;\n"\
		"	line-height: 20px;\n"\
		"	color: #333333;\n"\
		"	show-decoration-selected: 1;\n"\
		"}"));
	QList<QStandardItem*> row;
	QStandardItem* num = new QStandardItem("4");
	QStandardItem* name = new QStandardItem(QStringLiteral("刘桂香"));
	QStandardItem* state = new QStandardItem(QStringLiteral("完成"));
	QStandardItem* queueNum = new QStandardItem("10");
	QStandardItem* handler = new QStandardItem(QStringLiteral("就诊恢复"));
	row << num << name << state << queueNum << handler;

	for (auto& it : row)
	{
		it->setEditable(false);
		qDebug() << it;
	}
	view.setSelectionMode(QAbstractItemView::NoSelection);
	view.setItemDelegateForColumn(4, new ButtonDelegate(&view));

	mode.appendRow(row);

	view.setModel(&mode);
	view.show();
	return app.exec();
}
#endif


#if 0
void genRSAkey(QString priKeyFile,QString pubKeyFile)
{
	QStringList arguments;
	arguments << "genrsa" << "-out" << priKeyFile << "-f4" << "2048";
	QProcess::execute("openssl", arguments);
	arguments.clear();
	arguments << "rsa" << "-in" << priKeyFile << "-pubout" << "-out" << pubKeyFile;
	QProcess::execute("openssl", arguments);
}
void readRSA(QString const& pubFile, QString const& priFile, QString const& serverPubFile, std::string& pubKey, std::string& priKey, std::string& serverKey)
{
	QFile file(pubFile);
	if (!file.open(QIODevice::ReadOnly))
	{
		debug_out << "打开本地公钥失败" << std::endl;
	}
	auto data = file.readAll();
	pubKey = data.toStdString();
	file.close();
	file.setFileName(priFile);
	if (!file.open(QIODevice::ReadOnly))
	{
		debug_out << "打开本地私钥失败" << std::endl;
	}
	data.clear();
	data = file.readAll();
	priKey = data.toStdString();
	file.close();

	file.setFileName(serverPubFile);
	if (!file.open(QIODevice::ReadOnly))
	{
		debug_out << "打开服务端公钥失败" << std::endl;
	}
	data.clear();
	serverKey = data.toStdString();
	file.close();
}
#endif
bool isExit = false;
void threadFun()
{
	while (!isExit)
	{
		boost::this_thread::yield();
	}
}
#if 1
int main(int argc, char *argv[])
{
	try
	{

		std::string str = "中文字符串";
		QString qstr = QString::fromStdString(str);
		if (str == qstr.toStdString())
		{
			debug_out << "1111" << std::endl;
		}
		qstr = QStringLiteral("中文字符串");
		std::string str2 = qstr.toStdString();
		if (str == str2)
		{
			debug_out << "2222222222" << std::endl;
		}
		debug_out << str << std::endl;
		for (auto& ch : str2)
		{
			debug_out << " 0x" << std::hex << (unsigned int)(unsigned char)ch;
		}
		debug_out << std::endl;

		for (auto& ch : str)
		{
			debug_out << " 0x" << std::hex << (unsigned int)(unsigned char)ch;
		}
		debug_out << std::endl;
		debug_out << str2 << std::endl;
		
		system("pause");

#if 0
		QString const priFile = "system.dll";
		QString const pubFile = "localUser.dll";
		QString const serverFile = "server_public_key.pem";
		genRSAkey(priFile, pubFile);

		
		Core::registerAppFactory(&AssistManager::creatAppManager);
		Core::registerFactory(&AssistCore::creator);
		core_ptr core = Core::make_core();
		core->run();
		core->appManager()->netInterface()->start("192.168.1.135", 9000);
		std::string clientPri;
		std::string clientPub;
		std::string srvPub;

		QFile file(pubFile);
		if (!file.open(QIODevice::ReadOnly))
		{
			debug_out << "打开本地公钥失败" << std::endl;
		}
		auto data = file.readAll();
		clientPub = data.toStdString();
		file.close();
		file.setFileName(priFile);
		if (!file.open(QIODevice::ReadOnly))
		{
			debug_out << "打开本地私钥失败" << std::endl;
		}
		data.clear();
		data = file.readAll();
		clientPri = data.toStdString();
		file.close();

		file.setFileName(serverFile);
		if (!file.open(QIODevice::ReadOnly))
		{
			debug_out << "打开服务端公钥失败" << std::endl;
		}
		data.clear();
		data = file.readAll();
		srvPub = data.toStdString();
		file.close();
		core->setServerPubkey(srvPub);
		core->appManager()->setClientprikey(clientPri);
		char ch = 0;
		do 
		{					
			std::cin >> ch;
			switch (ch)
			{
			case 'r':
			{
				break;
			}
			case '1':
			{
				UserLoginRequest request;
				request.user_type = 1;
				request.user_type = 0;
				request.accoct = Core::gbk_to_utf8("助诊账号");
				request.passwd = Core::gbk_to_utf8("Aa111111");
				request.public_key = clientPub;	
				std::string const&&  s = Core::pack_binary(request);
				auto&& body = core->encode(1024, s);

				auto&& pCall = core->appManager()->netInterface();
				pCall ? pCall->launchMsg(std::make_tuple(1024,"aaaa","2019-3-30"), body) : void();
			}
				break;
			case '2':
				break;
			case '3':
				break;
			default:
				break;
			}
		} while (ch != 'q');
		core.reset();
#endif
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	system("pause");

	return 0;
}
#endif


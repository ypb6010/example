#include "stable.h"
#include "ExpertsGui.h"
#include <QtWidgets/QApplication>
#include "LoginDialog.h"


std::string const priFile = "system.pem";
std::string const pubFile = "localUser.pem";
std::string const serverFile = "server_pub.info";

void genRSAkey(std::string priKeyFile, std::string pubKeyFile)
{
	QStringList arguments;
	arguments << "genrsa" << "-out" << QString::fromStdString(priKeyFile) << "-f4" << "2048";
	QProcess::execute("openssl", arguments);
	arguments.clear();
	arguments << "rsa" << "-in" << QString::fromStdString(priKeyFile) << "-pubout" << "-out" << QString::fromStdString(pubKeyFile);
	QProcess::execute("openssl", arguments);
}

void readRSA(std::string const& priFile, std::string const& serverPubFile, std::string& priKey, std::string& serverKey)
{
	QFile file(QString::fromStdString(priFile));
	if (!file.open(QIODevice::ReadOnly))
	{
		debug_out << "打开本地私钥失败" << std::endl;
	}
	auto data = file.readAll();
	priKey = data.toStdString();
	file.close();

	file.setFileName(QString::fromStdString(serverPubFile));
	if (!file.open(QIODevice::ReadOnly))
	{
		debug_out << "打开服务端公钥失败" << std::endl;
	}
	data.clear();
	data = file.readAll();
	serverKey = data.toStdString();
	file.close();
}

void regExterntype()
{
	qRegisterMetaType<DiagnosisInfoResponse>("DiagnosisInfoResponse");
	qRegisterMetaType<DoctorInfoResponse>("DoctorInfoResponse");
	qRegisterMetaType<DiagnosisListPush>("DiagnosisListPush");
	qRegisterMetaType<DoctorBeginResponse>("DoctorBeginResponse");
	qRegisterMetaType<DoctorCallResponse>("DoctorCallResponse");
	qRegisterMetaType<DoctorAcceptCallResultPush>("DoctorAcceptCallResultPush");
	qRegisterMetaType<DoctorPauseResponse>("DoctorPauseResponse");
	qRegisterMetaType<DoctorRoomIDPush>("DoctorRoomIDPush");
	qRegisterMetaType<DoctorStopResponse>("DoctorStopResponse");
	qRegisterMetaType<DoctorLeaveResponse>("DoctorLeaveResponse");
	qRegisterMetaType<DoctorLeaveRecoverResponse>("DoctorLeaveRecoverResponse");
	qRegisterMetaType<DoctorSurePassResponse>("DoctorSurePassResponse");
	qRegisterMetaType<IllHistoryResponse>("IllHistoryResponse");
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	regExterntype();
	genRSAkey(priFile, pubFile);
	std::string pubKey;
	std::string priKey;
	std::string serverKey;
	readRSA(priFile, serverFile, priKey, serverKey);
	Core::registerAppFactory(&ExpertsManager::creatAppManager);
	Core::registerFactory(&ExpertsCore::creator);
	core_ptr core = Core::make_core();
	core->run();
	core->setServerPubkey(serverKey);
	core->appManager()->setClientprikey(priKey);
	core->appManager()->loginNetptr()->start("192.168.1.135", 9000);

	LoginDialog login(core.get());
	core->Core::setMainWindow(&login);

	ExpertsGui w(core.get());
	core->setMainWindow(&w);
	int ret = -1;
	if (login.exec() == QDialog::Accepted)		//后期打开，此处为等待登录验证
	{
		QDesktopWidget *deskdop = QApplication::desktop();
		w.show();
		w.move((deskdop->width() - w.width()) / 2, (deskdop->height() - w.height()) / 2);
		ret = a.exec();
	}
	return ret;
}

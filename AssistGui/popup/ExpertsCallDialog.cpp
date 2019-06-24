#include "stable.h"
#include "ExpertsCallDialog.h"

ExpertsCallDialog::ExpertsCallDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
}

ExpertsCallDialog::~ExpertsCallDialog()
{
}

void ExpertsCallDialog::init()
{
	ui.patientheadImage->setPixmap(QPixmap(":/res/MainWindow/Patdef.png"));
	ui.patName->setText("------");
	ui.patSex->setText(string2Sex(std::string()));
	ui.patAgelab->setText("δ֪");
	ui.patBirthlab->setText("----------");
	ui.doctorheadImage->setPixmap(QPixmap(":/res/MainWindow/doctor.png"));
	ui.doctorNamelab->setText("------");
	ui.doctorSexlab->setText(string2Sex(std::string()));
	ui.depAndlev->setText(QStringLiteral("δ֪"));
	ui.hospitallab->setText(QStringLiteral("------------"));
}

void ExpertsCallDialog::setPatient(PatientBaseInfo const& patient)
{
	QPixmap headImage;
	headImage.loadFromData((uchar*)patient.avatar.data(), patient.avatar.size());
	headImage.isNull() ? void(0) : ui.patientheadImage->setPixmap(headImage);
	ui.patName->setText(String2QString(patient.name));
	ui.patSex->setText(string2Sex(patient.sex));
	QDate date = QDate::currentDate();
	int years = date.year();
	QDate birth = QDate::fromString(String2QString(patient.birthday), "yyyy-MM-dd");
	int age = birth.year() - years;
	ui.patAgelab->setText(QString::number(qAbs(age)) + QStringLiteral("��"));
	ui.patBirthlab->setText(String2QString(patient.birthday));
}

void ExpertsCallDialog::setDoctor(DoctorInfoResponse const& doctor)
{
	QPixmap headImage;
	headImage.loadFromData((uchar*)doctor.head_image.data(), doctor.head_image.size());
	headImage.isNull() ? void(0) : ui.doctorheadImage->setPixmap(headImage);
	ui.doctorNamelab->setText(String2QString(doctor.doctor_name));
	ui.doctorSexlab->setText(string2Sex(doctor.sex));
	ui.depAndlev->setText(String2QString(std::string(doctor.office_name + "-" + doctor.duty_name)));
	ui.hospitallab->setText(String2QString(doctor.hospital_name));
}
QString ExpertsCallDialog::string2Sex(std::string const& sex)
{
	if (sex == "1")
		return QStringLiteral("(��)");
	else if (sex == "2")
		return QStringLiteral("(Ů)");
	else
		return QStringLiteral("(δ֪)");
}
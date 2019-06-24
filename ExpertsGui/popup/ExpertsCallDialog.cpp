#include "stable.h"
#include "ExpertsCallDialog.h"

CallAssistDialog::CallAssistDialog(QWidget *parent)
	: QDialog(parent)
	, m_ptimer(new QTimer(this))
	, m_timeMes(60)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	connect(m_ptimer, &QTimer::timeout, this, &CallAssistDialog::timeout_slot);
	connect(ui.doneBtn, &QAbstractButton::clicked, [this]() {
		done(-1);
	});
}

CallAssistDialog::~CallAssistDialog()
{
}

void CallAssistDialog::init()
{
	QPixmap pixmap(":/res/MainWindow/Patdef.png");
	ui.patientheadImage->setPixmap(pixmap);
	ui.patName->setText(QStringLiteral("------"));
	ui.patSex->setText(QStringLiteral("(未知)"));
	ui.patAgelab->setText(QStringLiteral("(未知)"));
	ui.patBirthlab->setText("0000-00-00");
	ui.doctorheadImage->setPixmap(QPixmap(":/res/MainWindow/doctor.png"));
	ui.doctorNamelab->setText(QStringLiteral("------"));
	ui.phonelab->setText(QStringLiteral("未知号码"));
	ui.hospitallab->setText(QStringLiteral("未知医院"));
	ui.waitlab->setVisible(true);
	ui.waitlab_2->setVisible(true);
	ui.textlab->setText(QStringLiteral("60秒"));
	ui.cancelBtn->setVisible(true);
	ui.cancelBtn->setEnabled(false);
	ui.okBtn->setVisible(false);
	ui.doneBtn->setEnabled(false);
	ui.doneBtn->setVisible(false);	
}

void CallAssistDialog::setTitle(QString const& strTitle)
{
	ui.titlelab->setText(strTitle);
}

void CallAssistDialog::setPatient(PatientBaseInfo const& patient)
{
	QPixmap headImage;
	headImage.loadFromData((uchar*)patient.avatar.data(), patient.avatar.size());
	headImage.isNull() ? void (0) : ui.patientheadImage->setPixmap(headImage);
	ui.patName->setText(String2QString(patient.name));
	ui.patSex->setText(string2Sex(patient.sex));
	QDate date = QDate::currentDate();
	int years = date.year(); 
	QDate birth = QDate::fromString(String2QString(patient.birthday), "yyyy-MM-dd");
	int age = birth.year() - years;
	ui.patAgelab->setText(QString::number(qAbs(age)) + QStringLiteral("岁"));
	ui.patBirthlab->setText(String2QString(patient.birthday));
}

void CallAssistDialog::setDoctor(DiagnosisInfoResponse const& assist)
{
	QPixmap headImage;
	headImage.loadFromData((uchar*)assist.head_image.data(), assist.head_image.size());
	headImage.isNull() ? void(0) : ui.doctorheadImage->setPixmap(headImage);
	ui.doctorNamelab->setText(String2QString(assist.owner));
	ui.doctorSexlab->setText(string2Sex("3"));
	ui.phonelab->setText(String2QString(assist.phone));
	ui.hospitallab->setText(String2QString(assist.address));
}

void CallAssistDialog::assistAgree()
{
	m_ptimer->stop();
	ui.waitlab->setVisible(false);
	ui.waitlab_2->setVisible(false);
	ui.textlab->setText(QStringLiteral("助诊医生已经应答，即将开始远程门诊"));
	ui.cancelBtn->setVisible(false);
	ui.okBtn->setVisible(true);
}

void CallAssistDialog::assistDisagree()
{
	m_ptimer->stop();
	ui.titlelab->setText(QStringLiteral("无应答提示"));
	ui.waitlab->setVisible(false);
	ui.waitlab_2->setVisible(false);
	ui.textlab->setText(QStringLiteral("助诊医生无应答，系统已为该患者过号！"));
	ui.okBtn->setVisible(false);
	ui.cancelBtn->setVisible(false);
	ui.doneBtn->setVisible(true);
	ui.doneBtn->setEnabled(true);
}

int CallAssistDialog::waitTimeSec()
{
	return qAbs(m_timeMes) + 60;
}

void CallAssistDialog::timeout_slot()
{
	m_timeMes--;
	if (m_timeMes >= 0)
	{
		QString text = QString::number(m_timeMes) + QStringLiteral("秒");
		ui.textlab->setText(text);
	}

	if (m_timeMes == 0)
	{
		ui.cancelBtn->setVisible(true);
		ui.cancelBtn->setEnabled(true);
		ui.okBtn->setVisible(false);
	}
}

QString CallAssistDialog::string2Sex(std::string const& sex)
{
	if (sex == "1")
		return QStringLiteral("(男)");
	else if (sex == "2")
		return QStringLiteral("(女)");
	else
		return QStringLiteral("(未知)");
}

void CallAssistDialog::showEvent(QShowEvent *e)
{
	if (e->type() == QEvent::Show)
	{
		m_timeMes = 60;
		m_ptimer->start(1000);
	}
	if (e->type() == QEvent::Hide)
	{
		m_ptimer->stop();
	}
	__super::showEvent(e);
}

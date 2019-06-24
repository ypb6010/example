#include "stable.h"
#include "AssistGui.h"
#include "LeftInfo/LeftExpandWidget.h"
#include "LeftInfo/LeftShutupWidget.h"
#include <QHBoxLayout>
#include "MainWindow.h"
#include "popup/HistoryStatisDialog.h"
#include "popup/ExpertsCallDialog.h"


AssistGui::AssistGui(Core* pCore, QWidget *parent)
	: QWidget(parent)
	, AssistWindowInterface(dynamic_cast<AssistCore*>(pCore))
	, m_pTimer(new QTimer(this))
	, m_process(new QProcess)
	, m_pWaitModel(new TableModel(this))
	, m_pPassModel(new TableModel(this))
	, m_pPauseModel(new TableModel(this))
	, m_pCompleteModel(new TableModel(this))
	, m_pOfflineModel(new TableModel(this))
	, m_platelyModel(new TableModel(this))
	, m_pHistoryModel(new TableModel(this))
	, m_pRemoteModel(new TableModel(this))
	, m_pCallDialog(new ExpertsCallDialog(this))
	, m_pHisDialog(nullptr)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setWindowTitle(QStringLiteral("助诊医生工作站"));
	ui.shutupWidget->setVisible(false);
	connect(ui.mainWindow->ui.closeBtn, &QAbstractButton::clicked,this, &QWidget::close);
	connect(ui.mainWindow->ui.expandBtn, &QToolButton::clicked, [this](bool checked) {
			ui.expandWidget->setVisible(!checked);
			ui.shutupWidget->setVisible(checked);
	});
	connect(ui.mainWindow->ui.minBtn, &QAbstractButton::clicked, this, &QWidget::showMinimized);
	connect(ui.mainWindow->ui.maxBtn, &QAbstractButton::clicked, [this](bool checked) {
		checked ? showMaximized() : showNormal();	
	});
	connect(m_pTimer, &QTimer::timeout, this, &this_type::on_timeout);
	initExpandTableView();
	initMainWindow();
	initPopup();
}

AssistGui::~AssistGui()
{
	m_process->kill();
}

void AssistGui::initExpandTableView()
{
	auto headerview = new TableHeaderView(Qt::Horizontal, ui.expandWidget->ui.tableView);
	headerview->setMinimumHeight(50);
	ui.expandWidget->ui.tableView->setHorizontalHeader(headerview);
	ui.expandWidget->ui.tableView->verticalHeader()->setVisible(false);
	QStringList header;
	header << QStringLiteral("专家号") << QStringLiteral("患者姓名") << QStringLiteral("专家") << QStringLiteral("状态") << QStringLiteral("前方等待人数") << QStringLiteral("操作");
	ui.expandWidget->ui.tableView->setModel(m_pWaitModel);
	m_pWaitModel->setHorizontalHeaderLabels(header);
	m_pPassModel->setHorizontalHeaderLabels(header);
	m_pPauseModel->setHorizontalHeaderLabels(header);
	m_pCompleteModel->setHorizontalHeaderLabels(header);
	headerview->setSectionResizeMode(0, QHeaderView::Stretch);
	headerview->setSectionResizeMode(1, QHeaderView::Stretch);
	headerview->setSectionResizeMode(2, QHeaderView::Stretch);
	headerview->setSectionResizeMode(3, QHeaderView::Stretch);
	headerview->setSectionResizeMode(4, QHeaderView::ResizeToContents);
	headerview->setSectionResizeMode(5, QHeaderView::Stretch);
	ui.expandWidget->ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	ButtonDelegate* delegate = new ButtonDelegate(ui.expandWidget->ui.tableView);
	ui.expandWidget->ui.tableView->setItemDelegateForColumn(5, delegate);
	connect(delegate, &ButtonDelegate::clicked, this, &this_type::on_row_clicked);
	connect(ui.expandWidget->ui.waitPageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pWaitModel); });
	connect(ui.expandWidget->ui.passPageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pPassModel); });
	connect(ui.expandWidget->ui.pausePageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pPauseModel); });
	connect(ui.expandWidget->ui.completePageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pCompleteModel); });

	connect(ui.expandWidget->ui.startService, &QAbstractButton::clicked, this, &this_type::on_start);
	connect(ui.expandWidget->ui.leaveService, &QAbstractButton::clicked, this, &this_type::on_leave);
	connect(ui.expandWidget->ui.stopService, &QAbstractButton::clicked, this, &this_type::on_stop);

	connect(ui.shutupWidget->ui.startShutStateBtn, &QAbstractButton::clicked, ui.expandWidget->ui.startService, &QAbstractButton::clicked);
	connect(ui.shutupWidget->ui.leaveShutStateBtn, &QAbstractButton::clicked, ui.expandWidget->ui.leaveService, &QAbstractButton::clicked);
	connect(ui.shutupWidget->ui.stopShutStateBtn, &QAbstractButton::clicked, ui.expandWidget->ui.stopService, &QAbstractButton::clicked);

}

void AssistGui::initMainWindow()
{
	ui.mainWindow->ui.patNamelab->setText("-----");
	ui.mainWindow->ui.patSex->setText(QStringLiteral("(--)"));
	ui.mainWindow->ui.patAgelab->setText(QStringLiteral("--"));
	ui.mainWindow->ui.dateOfBirthlab->setText(QStringLiteral("--------"));

	auto headerview = new TableHeaderView(Qt::Horizontal, ui.expandWidget->ui.tableView);
	headerview->setMinimumHeight(50);
	headerview->setSectionResizeMode(QHeaderView::Stretch);
	ui.mainWindow->ui.offline_tableview->setHorizontalHeader(headerview);
	ui.mainWindow->ui.lately_tableview->setHorizontalHeader(headerview->clone());
	ui.mainWindow->ui.history_tableview->setHorizontalHeader(headerview->clone());
	ui.mainWindow->ui.remote_tableview->setHorizontalHeader(headerview->clone());
	ui.mainWindow->ui.typeCombox->setView(new QListView());
	ui.mainWindow->ui.departCombox->setView(new QListView());
	ui.mainWindow->ui.docName->setText("-----");
	ui.mainWindow->ui.docSex->setText("(--)");
	ui.mainWindow->ui.docLevlab->setText("-------");
	ui.mainWindow->ui.typeDeplab->setText("------");
	ui.mainWindow->ui.phoneLab->setText("-----------");
	ui.mainWindow->ui.hospitallab->setText("-----------");

	QStringList header;
	header << QStringLiteral("类型") << QStringLiteral("项目") << QStringLiteral("时间") << QStringLiteral("查看") << QStringLiteral("删除");
	m_pOfflineModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.offline_tableview->setModel(m_pOfflineModel);
	header.clear();		

	header << QStringLiteral("类型") << QStringLiteral("项目") << QStringLiteral("时间") << QStringLiteral("诊断结论") << QStringLiteral("查看");
	m_platelyModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.lately_tableview->setModel(m_platelyModel);

	m_pHistoryModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.history_tableview->setModel(m_pHistoryModel);
	header.clear();	
	
	header << QStringLiteral("时间") << QStringLiteral("科室") << QStringLiteral("医院") << QStringLiteral("医生") << QStringLiteral("查看");
	m_pRemoteModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.remote_tableview->setModel(m_pRemoteModel);
	header.clear();

	connect(ui.mainWindow->ui.allergyBtn, &QAbstractButton::clicked, this, &this_type::on_allergy);
	connect(ui.mainWindow->ui.pastHistorylab, &QAbstractButton::clicked, this, &this_type::on_past);
	connect(ui.mainWindow->ui.familuyHistorylab, &QAbstractButton::clicked, this, &this_type::on_family);
	connect(ui.mainWindow->ui.heredityHistorylab, &QAbstractButton::clicked, this, &this_type::on_heredity);
}

void AssistGui::initPopup()
{
	if (!m_pHisDialog)
	{
		m_pHisDialog = new HistoryDialog(this);
		m_pHisDialog->setVisiableAppend(false);
		m_pHisDialog->hide();
	}
}

void AssistGui::receiptDiagnosisInfo(DiagnosisInfoResponse const& request)
{
	data_ptr pDataManager = m_pManager->dataManager();
	pDataManager->setDiagnosisInfo(request);
	QMetaObject::invokeMethod(this, "private_diagno_info", Qt::QueuedConnection, Q_ARG(DiagnosisInfoResponse, request));
}

void AssistGui::receiptDiagnosisList(DiagnosisListPush const& request)
{
	data_ptr pDataManager = m_pManager->dataManager();
	pDataManager->addWaitElems(request.wait_force);
	pDataManager->addWaitElems(request.wait);
	pDataManager->addPauseElems(request.pause);
	pDataManager->addPassElems(request.pass);
	pDataManager->addCompleteElems(request.complete);
	QMetaObject::invokeMethod(this, "private_diagnosis_list", Qt::QueuedConnection, Q_ARG(DiagnosisListPush, request));
}

void AssistGui::receiptStartSerive(DiagnosisBeginResponse const& result)
{
	QMetaObject::invokeMethod(this, "private_start", Qt::QueuedConnection, Q_ARG(DiagnosisBeginResponse, result));
}

void AssistGui::receiptCallNext(DiagnosisAcceptCallPush const& result)
{	
	data_ptr data = m_pManager->dataManager();
	result.now_id, result.now;
	result.next_id, result.next;
	data->setCurrentRegID(result.register_id);
	data->setCurrentDoctorID(result.doctor_id);
	data->setCurrentPatID(result.now_id);
	data->setCurrentPatName(result.now);
	data->setNextPatID(result.next_id);
	data->setNextName(result.next);

	data->setNextPatID(result.next_id);
	data->setCurrentDoctorID(result.doctor_id);
	data->setCurrentRegID(result.register_id);
	data->setCurrentPatInfo(result.patient_info);
	data->setCurrentDoctor(result.doctor_info);
	QMetaObject::invokeMethod(this, "private_call_next", Qt::QueuedConnection, Q_ARG(DiagnosisAcceptCallPush, result));
}

void AssistGui::receiptCallResult(DiagnosisResponseCallResponse const& result)
{
	if (result.result == "0")
	{
		debug_out << "助诊回复专家叫号请求回应失败" << std::endl;
		debug_out << "附加消息" << result.reason << std::endl;
		return;
	}
	if (result.response == "0")
	{
		debug_out << "助诊申请了过号" << std::endl;
	}
	else
	{
		data_ptr data = m_pManager->dataManager();
		data->setRoom(result.room);
		QMetaObject::invokeMethod(this, "private_call_result", Qt::QueuedConnection, Q_ARG(DiagnosisResponseCallResponse, result));
	}
}

void AssistGui::receiptSurePassPush(DoctorSurePassPush const& result)
{
	data_ptr data = m_pManager->dataManager();
	std::string const&& regId = data->currentRegID();
	std::string const&& doctorID = data->currentDoctorID();
	std::string patientID = data->currentPatID();
	if (result.register_id == regId && result.patient_id == patientID && result.doctor_id == doctorID)
	{
		debug_out << patientID << "已经被专家过号处理" << std::endl;
		QMetaObject::invokeMethod(this, "private_sure_pass_push", Qt::QueuedConnection, Q_ARG(DoctorSurePassPush, result));
	}
}

void AssistGui::receiptPausePush(DiagnosisPausePush const& result)
{
	QMetaObject::invokeMethod(this, "private_pause_push", Qt::QueuedConnection, Q_ARG(DiagnosisPausePush, result));
}

void AssistGui::receiptLeave(DiagnosisLeaveResponse const& result)
{
	QMetaObject::invokeMethod(this, "private_leave", Qt::QueuedConnection, Q_ARG(DiagnosisLeaveResponse, result));
}

void AssistGui::receiptLeaveRecover(DiagnosisLeaveRecoverResponse const& result)
{
	QMetaObject::invokeMethod(this, "private_leave_recover", Qt::QueuedConnection, Q_ARG(DiagnosisLeaveRecoverResponse, result));
}

void AssistGui::receiptCompletePush(DoctorCompletePush const& result)
{
	data_ptr data = m_pManager->dataManager();
	data->resetCurrent();
	QMetaObject::invokeMethod(this, "private_complete_push", Qt::QueuedConnection, Q_ARG(DoctorCompletePush, result));
}

void AssistGui::receiptShare(DiagnosisSpareResponse const& result)
{
	if (result.diagnosis_id != m_pManager->dataManager()->diagnosisInfo().organize_id)
	{
		debug_out << "发现备注ID可能出错" << std::endl;
	}
}

void AssistGui::receiptComplete(DiagnosisCompleteResponse const& result)
{
	if (result.diagnosis != m_pManager->dataManager()->diagnosisInfo().organize_id)
	{
		debug_out << "发现结束门诊ID可能出错" << std::endl;
		return;
	}
	QMetaObject::invokeMethod(this, "private_complete", Qt::QueuedConnection, Q_ARG(DiagnosisCompleteResponse, result));
}

void AssistGui::receiptHistory(IllHistoryResponse const& result)
{
	data_ptr data = m_pManager->dataManager();
	data->setCurrentHistory(result);
	QMetaObject::invokeMethod(this, "private_history", Qt::QueuedConnection, Q_ARG(IllHistoryResponse, result));
}

void AssistGui::private_diagno_info(DiagnosisInfoResponse const& request) const
{
	ui.mainWindow->ui.assisSitelab->setText(String2QString(request.organize_name));
	ui.mainWindow->ui.assisLev->setText(String2QString(request.username));
}

void AssistGui::private_diagnosis_list(DiagnosisListPush const& result) const
{
	debug_out << "更新队列" << std::endl;
	auto everyListHandler = [this](stateList const& list, TableModel* model,bool isClean= true)
	{
		isClean ? model->removeRows(0, model->rowCount()) : void(0);
		for (auto&& value : list)
		{
			auto row = value.state == "候诊中" || value.state == "候诊" || value.state == "完成" ? TableModel::make_assist_registrarow(
				std::make_tuple(value.rank,value.patient_id,value.register_id,value.doctor_id,value.doctor_name,value.patient_name,value.code,value.state,value.wait_num))
				: TableModel::make_assist_registrarow(
					std::make_tuple(value.rank, value.patient_id, value.register_id, value.doctor_id, value.doctor_name, value.patient_name, value.code, value.state, value.wait_num),
					true, true);
			model->appendRow(row);
		}
	};
	everyListHandler(result.wait_force, m_pWaitModel);
	everyListHandler(result.wait, m_pWaitModel,false);
	everyListHandler(result.pass, m_pPassModel);
	everyListHandler(result.pause, m_pPauseModel);
	everyListHandler(result.complete, m_pCompleteModel);
	updatePages();

}

void AssistGui::private_start(DiagnosisBeginResponse const& result) const
{
	(void)result;
	ui.expandWidget->ui.startService->setEnabled(false);
	ui.expandWidget->ui.stopService->setEnabled(false);
	ui.expandWidget->ui.leaveService->setEnabled(true);
	ui.shutupWidget->ui.startShutStateBtn->setEnabled(false);
	ui.shutupWidget->ui.leaveShutStateBtn->setEnabled(true);
	ui.shutupWidget->ui.stopShutStateBtn->setEnabled(false);
	m_pTimer->start(1000);
}


void AssistGui::private_call_next(DiagnosisAcceptCallPush const& result)
{
	m_pCallDialog->init();
	m_pCallDialog->setPatient(result.patient_info);
	m_pCallDialog->setDoctor(result.doctor_info);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pCallDialog->objectName());
	pMaskWidget.setMainWidget(this);

	ui.expandWidget->ui.curName->setText(String2QString(result.now));
	ui.expandWidget->ui.nextNameLab->setText(String2QString(result.next));
	
	int res = m_pCallDialog->exec();
	if (res == QDialog::Accepted)
	{
		requestCallResult(true);
	}
	else if (res == QDialog::Rejected)
	{
		requestCallResult(false);
	}
	else
	{
		debug_out << "专家使用了过号" << std::endl;
	}
}

void AssistGui::private_call_result(DiagnosisResponseCallResponse const& result)
{
	updateDoctor();
	updatePatient();
	int ms = QTime::currentTime().msecsSinceStartOfDay();
	QString strCommand = QStringLiteral("ClassName=%0&SrvIP=%1&UserName=%2&Password=%3&RoomID=%4&AnonymousUser=0")
		.arg(ms).arg("118.122.92.92").arg("zdwl02").arg("123456").arg(String2QString(result.room));
	QStringList commandList;
	commandList << strCommand;
	m_process->start(QString("IMActive/ActiveMeeting.exe"), commandList);
}

void AssistGui::private_sure_pass_push(DoctorSurePassPush const& result)
{
	(void)result;
	m_pCallDialog->done(-1); 
}

void AssistGui::private_pause_push(DiagnosisPausePush const& result)
{
	ButtonDialog dialog(this);
	m_process->kill();
	dialog.setCancelButtonVisiable(false);
	dialog.setTitle(QStringLiteral("提示暂停"));
	dialog.setDisplayText(QStringLiteral("专家已经将该患者暂停，如需再次就诊需给病人恢复队列"));
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	dialog.exec();
	m_pManager->dataManager()->resetCurrent();
	resetDoctor();
	resetPatient();
}

void AssistGui::private_leave(DiagnosisLeaveResponse const& result)
{
 	ui.expandWidget->ui.leaveService->setChecked(true);
	ui.expandWidget->ui.leaveService->setText(QStringLiteral("继续"));
	ui.shutupWidget->ui.leaveShutStateBtn->setChecked(true);
	ui.shutupWidget->ui.leaveShutStateBtn->setText(QStringLiteral("继续"));
}

void AssistGui::private_leave_recover(DiagnosisLeaveRecoverResponse const& result)
{
	ui.expandWidget->ui.leaveService->setChecked(false);
	ui.expandWidget->ui.leaveService->setText(QStringLiteral("离开"));
	ui.shutupWidget->ui.leaveShutStateBtn->setChecked(false);
	ui.shutupWidget->ui.leaveShutStateBtn->setText(QStringLiteral("离开"));
}

void AssistGui::private_complete_push(DoctorCompletePush const& result)
{
	ui.mainWindow->ui.related->setText(String2QString(result.treat_main));
	ui.mainWindow->ui.suggested->setText(String2QString(result.treat_propose));
	ui.mainWindow->ui.dispose->setText(String2QString(result.deal_propose));
	ui.mainWindow->ui.medical->setText(String2QString(result.prescript_propose));
	resetDoctor();
	resetPatient();
	QString strRemark = ui.mainWindow->ui.remark->toPlainText();
	if (!strRemark.isEmpty())
	{
		requestSpare(QString2String(strRemark));
	}
	m_process->kill();
}

void AssistGui::private_complete(DiagnosisCompleteResponse const& result)
{
	ui.expandWidget->ui.startService->setEnabled(true);
	ui.expandWidget->ui.leaveService->setEnabled(false);
	ui.expandWidget->ui.stopService->setEnabled(false);
	
	ui.shutupWidget->ui.startShutStateBtn->setEnabled(true);
	ui.shutupWidget->ui.leaveShutStateBtn->setEnabled(false);
	ui.shutupWidget->ui.stopShutStateBtn->setEnabled(false);
}

void AssistGui::private_history(IllHistoryResponse const& result)
{
	if (m_pHisDialog)
		m_pHisDialog->setData(result);
}

void AssistGui::on_start()
{
	ButtonDialog dialog(this);
	dialog.setTitle(QStringLiteral("开始门诊确认"));
	dialog.setDisplayText(QStringLiteral("您确定开始门诊吗？"));
	dialog.resize(600, 220);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	if (QDialog::Accepted == dialog.exec())
	{
		requestStart();
	}
}

void AssistGui::on_timeout()
{
	QDateTime currentTime = QDateTime::currentDateTime();
	ui.mainWindow->ui.dateTimelab->setText(currentTime.toString("yyyy-MM-dd HH:mm:ss"));
	requestHeartbeat();
}

void AssistGui::on_row_clicked(QModelIndex index)
{
	debug_out << "行：" << index.row() << "列" << index.column() << "被点击" << std::endl;
	QVariantList dataInfo = index.data(Qt::UserRole + 3).toList();
	QString&& state = dataInfo.at(7).toString();
	ButtonDialog dialog(this);
	dialog.setTitle(QStringLiteral("恢复队列确认"));

	dialog.resize(600, 220);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	QString text = QStringLiteral("您确定要给%0恢复队列吗?").arg(dataInfo.at(5).toString());
	dialog.setDisplayText(text);
	if (state == QStringLiteral("暂停"))
	{
		if (dialog.exec() == QDialog::Accepted)
		{
			requestPauseRecover(QString2String(dataInfo.at(1).toString()));
		}
	}
	else if (state == QStringLiteral("过号"))
	{
		if (dialog.exec() == QDialog::Accepted)
		{
			requestPassRecover(QString2String(dataInfo.at(1).toString()));
		}
	}
	else
	{
		debug_out << "默认不做处理状态" << std::endl;
	}

	debug_out << "patient_id:" << QString2String(dataInfo.at(1).toString()) << std::endl;
	debug_out << "register_id:" << QString2String(dataInfo.at(2).toString()) << std::endl;
	debug_out << "doctor_id" << QString2String(dataInfo.at(3).toString()) << std::endl;
}

void AssistGui::on_leave(bool checked)
{
	ButtonDialog dialog(this);
	dialog.setTitle(checked ? QStringLiteral("离开确认") : QStringLiteral("继续确认"));
	dialog.setDisplayText(checked ? QStringLiteral("您确定要进行离开操作吗？") : QStringLiteral("您确定要进行继续操作吗?"));
	dialog.resize(600, 200);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		checked ? requestLeave() : requestLeaveRecover();
	}
	else
	{
		ui.expandWidget->ui.leaveService->setChecked(!checked);
		ui.shutupWidget->ui.leaveShutStateBtn->setChecked(!checked);
	}
}

void AssistGui::on_stop()
{
	requestComplete();
}

void AssistGui::on_allergy()
{
	initHisDialog(HistoryDialog::Drug);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void AssistGui::on_past()
{
	initHisDialog(HistoryDialog::Past);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void AssistGui::on_family()
{
	initHisDialog(HistoryDialog::Family);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void AssistGui::on_heredity()
{
	initHisDialog(HistoryDialog::Genetic);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void AssistGui::updatePatient()
{
	data_ptr data = m_pManager->dataManager();
	auto&& currentPat = data->currentPatInfo();
	QPixmap pixmap;
	pixmap.loadFromData((uchar*)currentPat.avatar.data(), currentPat.avatar.size());
	ui.mainWindow->ui.headImagelab->setPixmap(pixmap.isNull() ? QPixmap(":/res/MainWindow/Patdef.png"):pixmap);
	ui.mainWindow->ui.patNamelab->setText(String2QString(currentPat.name));
	ui.mainWindow->ui.patSex->setText(string2Sex(currentPat.sex));
	QDate date = QDate::currentDate();
	int years = date.year();
	QDate birth = QDate::fromString(String2QString(currentPat.birthday), "yyyy-MM-dd");
	int age = birth.year() - years;
	ui.mainWindow->ui.patAgelab->setText(QString::number(qAbs(age)) + QStringLiteral("岁"));
	ui.mainWindow->ui.dateOfBirthlab->setText(String2QString(currentPat.birthday));
}

void AssistGui::updateDoctor()
{
	data_ptr data = m_pManager->dataManager();
	auto&& currentDoctor = data->currentDoctor();
	QPixmap pixmap;
	pixmap.loadFromData((uchar*)currentDoctor.head_image.data(), currentDoctor.head_image.size());
	ui.mainWindow->ui.docImagelab->setPixmap(pixmap.isNull() ? QPixmap(":/res/MainWindow/Patdef.png") : pixmap);
	ui.mainWindow->ui.docName->setText(String2QString(currentDoctor.doctor_name));
	ui.mainWindow->ui.docSex->setText(string2Sex(currentDoctor.sex));
	ui.mainWindow->ui.docLevlab->setText(String2QString(currentDoctor.duty_name));
	ui.mainWindow->ui.typeDeplab->setText(String2QString(currentDoctor.office_name));
	ui.mainWindow->ui.phoneLab->setText(String2QString(currentDoctor.phone));
	ui.mainWindow->ui.hospitallab->setText(String2QString(currentDoctor.hospital_name));
}

void AssistGui::resetPatient()
{
	ui.mainWindow->ui.headImagelab->setPixmap(QPixmap(":/res/MainWindow/Patdef.png"));
	ui.mainWindow->ui.patNamelab->setText("------");
	ui.mainWindow->ui.patSex->setText(QStringLiteral("(--)"));
	QDate date = QDate::currentDate();
	ui.mainWindow->ui.patAgelab->setText(QStringLiteral("--"));
	ui.mainWindow->ui.dateOfBirthlab->setText(QStringLiteral("----------"));
}

void AssistGui::resetDoctor()
{
	ui.mainWindow->ui.docImagelab->setPixmap(QPixmap(":/res/MainWindow/Patdef.png"));
	ui.mainWindow->ui.docName->setText("------");
	ui.mainWindow->ui.docSex->setText(QStringLiteral("--"));
	ui.mainWindow->ui.docLevlab->setText(QStringLiteral("--------")); 
	ui.mainWindow->ui.typeDeplab->setText(QStringLiteral("--------"));
	ui.mainWindow->ui.phoneLab->setText("-----------");
	ui.mainWindow->ui.hospitallab->setText("------------");
}

void AssistGui::updatePages() const
{
	ui.expandWidget->ui.waitPageBtn->setText(QString::number(m_pWaitModel->rowCount()));
	ui.expandWidget->ui.pausePageBtn->setText(QString::number(m_pPauseModel->rowCount()));
	ui.expandWidget->ui.passPageBtn->setText(QString::number(m_pPassModel->rowCount()));
	ui.expandWidget->ui.completePageBtn->setText(QString::number(m_pCompleteModel->rowCount()));
}

QString AssistGui::string2Sex(std::string const& sex)
{
	if (sex == "1")
		return QStringLiteral("(男)");
	else if (sex == "2")
		return QStringLiteral("(女)");
	else
		return QStringLiteral("(未知)");
}

void AssistGui::initHisDialog(HistoryDialog::WindowIndex index)
{
	m_pHisDialog->setIndex(index);

	data_ptr data = m_pManager->dataManager();
	auto&& value = data->currentPatHistory();

	if (!value)
	{
		if (data->currentPatID().empty())
		{
			return;
		}
		requestHistory(data->currentPatID());
	}
	else
	{
		m_pHisDialog->setData(*value);
	}
}


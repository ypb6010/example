#include "stable.h"
#include "ExpertsGui.h"
#include "popup/ExpertsCallDialog.h"

ExpertsGui::ExpertsGui(Core* pCore, QWidget *parent)
	: QWidget(parent)
	, ExpertsWindowInterface(dynamic_cast<ExpertsCore*>(pCore))
	, m_pWaitModel(new TableModel(this))
	, m_pPassModel(new TableModel(this))
	, m_pPauseModel(new TableModel(this))
	, m_pCompleteModel(new TableModel(this))
	, m_platelyModel(new TableModel(this))
	, m_pHistoryModel(new TableModel(this))
	, m_pRemoteModel(new TableModel(this))
	, m_pCallAssist(nullptr)
	, m_pTimer(new QTimer(this))
	, m_process(new QProcess())
	, m_pHisDialog(nullptr)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	setWindowTitle(QStringLiteral("远程专家工作站"));
	ui.shutupWidget->setVisible(false);
	connect(ui.mainWindow->ui.closeBtn, &QAbstractButton::clicked, this, &QWidget::close);
	connect(ui.mainWindow->ui.expandBtn, &QToolButton::clicked, [this](bool checked) {
		ui.expandWidget->setVisible(!checked);
		ui.shutupWidget->setVisible(checked);
	});
	connect(ui.mainWindow->ui.minBtn, &QAbstractButton::clicked, this, &QWidget::showMinimized);
	connect(ui.mainWindow->ui.maxBtn, &QAbstractButton::clicked, [this](bool checked) {
		checked ? showMaximized() : showNormal();
	});
	connect(m_pTimer, &QTimer::timeout, this, &this_type::on_timeout);
	initLeftTableView();
	initMainWindow();
	initPopup();
}

ExpertsGui::~ExpertsGui()
{
	m_process->kill();
}

void ExpertsGui::initLeftTableView()
{
	auto headerview = new TableHeaderView(Qt::Horizontal, ui.expandWidget->ui.tableView);
	headerview->setMinimumHeight(50);
	ui.expandWidget->ui.tableView->setHorizontalHeader(headerview);

	ui.expandWidget->ui.tableView->verticalHeader()->setVisible(false);
	QStringList header;
	header << QStringLiteral("就诊号") << QStringLiteral("患者姓名") << QStringLiteral("性别") << QStringLiteral("操作");
	ui.expandWidget->ui.tableView->setModel(m_pWaitModel);
	m_pWaitModel->setHorizontalHeaderLabels(header);
	m_pPassModel->setHorizontalHeaderLabels(header);
	m_pPauseModel->setHorizontalHeaderLabels(header);
	m_pCompleteModel->setHorizontalHeaderLabels(header);
	headerview->setSectionResizeMode(0, QHeaderView::Stretch);
	headerview->setSectionResizeMode(1, QHeaderView::Stretch);
	headerview->setSectionResizeMode(2, QHeaderView::Stretch);
	headerview->setSectionResizeMode(3, QHeaderView::Stretch);

	ui.expandWidget->ui.tableView->setItemDelegateForColumn(3, new ButtonDelegate(ui.expandWidget->ui.tableView));
	ui.expandWidget->ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	connect(ui.expandWidget->ui.waitPageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pWaitModel); });
	connect(ui.expandWidget->ui.passPageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pPassModel); });
	connect(ui.expandWidget->ui.pausePageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pPauseModel); });
	connect(ui.expandWidget->ui.completePageBtn, &QAbstractButton::clicked, [this]() { ui.expandWidget->ui.tableView->setModel(m_pCompleteModel); });
	connect(ui.expandWidget->ui.startService, &QAbstractButton::clicked, this, &this_type::on_start);
	connect(ui.expandWidget->ui.leaveService, &QAbstractButton::clicked, this, &this_type::on_leave);
	connect(ui.shutupWidget->ui.startShutStateBtn, &QAbstractButton::clicked, ui.expandWidget->ui.startService, &QAbstractButton::clicked);
	connect(ui.shutupWidget->ui.leaveShutStateBtn, &QAbstractButton::clicked, ui.expandWidget->ui.leaveService, &QAbstractButton::clicked);
	connect(ui.shutupWidget->ui.stopShutStateBtn, &QAbstractButton::clicked, ui.expandWidget->ui.stopService, &QAbstractButton::clicked);
}

void ExpertsGui::initMainWindow()
{
	connect(ui.mainWindow->ui.pauseBtn, &QAbstractButton::clicked, this, &this_type::on_pause);
	connect(ui.mainWindow->ui.completeBtn, &QAbstractButton::clicked, this, &this_type::on_complete);
	connect(ui.mainWindow->ui.callNextBtn, &QAbstractButton::clicked, this, &this_type::on_call_next);
	connect(ui.mainWindow->ui.videoBtn, &QAbstractButton::clicked, this, &this_type::on_video);
	connect(ui.mainWindow->ui.allergyBtn, &QAbstractButton::clicked, this, &this_type::on_allergy);
	connect(ui.mainWindow->ui.pastHistorylab, &QAbstractButton::clicked, this, &this_type::on_past);
	connect(ui.mainWindow->ui.familuyHistorylab, &QAbstractButton::clicked, this, &this_type::on_family);
	connect(ui.mainWindow->ui.heredityHistorylab, &QAbstractButton::clicked, this, &this_type::on_heredity);

	auto headerview = new TableHeaderView(Qt::Horizontal, ui.expandWidget->ui.tableView);
	headerview->setMinimumHeight(50);
	headerview->setSectionResizeMode(QHeaderView::Stretch);
	ui.mainWindow->ui.lately_tableview->setHorizontalHeader(headerview);
	ui.mainWindow->ui.history_tableview->setHorizontalHeader(headerview->clone());
	ui.mainWindow->ui.remote_tableview->setHorizontalHeader(headerview->clone());
	QStringList header;
	header << QStringLiteral("类型") << QStringLiteral("项目") << QStringLiteral("时间") << QStringLiteral("诊断结论") << QStringLiteral("查看");
	m_platelyModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.lately_tableview->setModel(m_platelyModel);
	header.clear();
	header << QStringLiteral("项目") << QStringLiteral("时间") << QStringLiteral("诊断结论") << QStringLiteral("查看");
	m_pHistoryModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.history_tableview->setModel(m_pHistoryModel);

	header.clear();
	header << QStringLiteral("时间") << QStringLiteral("科室") << QStringLiteral("医院") << QStringLiteral("医生") << QStringLiteral("查看");
	m_pRemoteModel->setHorizontalHeaderLabels(header);
	ui.mainWindow->ui.remote_tableview->setModel(m_pRemoteModel);

	ui.mainWindow->ui.typeCombox->setView(new QListView());
}

void ExpertsGui::initPopup()
{
	if (!m_pHisDialog)
	{
		m_pHisDialog = new HistoryDialog(this);
		m_pHisDialog->hide();
	}
	
	connect(m_pHisDialog, &HistoryDialog::addDrugClicked, this, &this_type::on_add_drug);
	connect(m_pHisDialog, &HistoryDialog::addPastClecked, this, &this_type::on_add_past);
	connect(m_pHisDialog, &HistoryDialog::addFamilyClicked, this, &this_type::on_add_family);
	connect(m_pHisDialog, &HistoryDialog::addGeneticClicked, this, &this_type::on_add_genetic);
	
}

void ExpertsGui::receiptDoctorInfo(DoctorInfoResponse const& result)
{
	data_ptr data = m_pManager->dataManager();
	data->setDoctorInfo(result);
	QMetaObject::invokeMethod(this, "private_doctor_info", Qt::QueuedConnection, Q_ARG(DoctorInfoResponse, result));
}

void ExpertsGui::receiptExpertsList(DiagnosisListPush const& result)
{
	data_ptr pDataManager = m_pManager->dataManager();
	pDataManager->addWaitElems(result.wait_force);
	pDataManager->addWaitElems(result.wait);
	pDataManager->addPauseElems(result.pause);
	pDataManager->addPassElems(result.pass);
	pDataManager->addCompleteElems(result.complete);
	QMetaObject::invokeMethod(this, "private_doctor_list", Qt::QueuedConnection, Q_ARG(DiagnosisListPush, result));
}

void ExpertsGui::receiptBegin(DoctorBeginResponse const& result)
{
	QMetaObject::invokeMethod(this, "private_begin", Qt::QueuedConnection, Q_ARG(DoctorBeginResponse, result));
}

void ExpertsGui::receiptCallNext(DoctorCallResponse const& result)
{
	if (result.res == "0")
	{
		return;
	}
	data_ptr pDataManager = m_pManager->dataManager();	
	pDataManager->setCurrentPatID(result.now_id);
	pDataManager->setCurrentPatName(result.now);
	pDataManager->setNextID(result.next_id);
	pDataManager->setNextPatName(result.next);
	pDataManager->setCurrentAssistID(result.diagnosis_id);
	pDataManager->setCurrentRegID(result.register_id);
	pDataManager->setCurrentAssist(result.diagnosis_info);
	pDataManager->setCurrentPatInfo(result.patient_info);
	QMetaObject::invokeMethod(this, "private_call_next", Qt::QueuedConnection, Q_ARG(DoctorCallResponse, result));
	debug_out << "叫号请求中，当前的病人ID：" << result.now_id << std::endl;
}

void ExpertsGui::receiptCallResult(DoctorAcceptCallResultPush const& result)
{
	if (result.response == "1")
	{
		data_ptr data = m_pManager->dataManager();
		if (data->currentRegID() != result.register_id)
		{
			debug_out << "发现挂号和助诊返回挂号不一致" << result.register_id << std::endl;
			return;
		}
	}
	QMetaObject::invokeMethod(this, "private_call_result", Qt::QueuedConnection, Q_ARG(DoctorAcceptCallResultPush, result));
}

void ExpertsGui::receiptPause(DoctorPauseResponse const& result)
{
	data_ptr data = m_pManager->dataManager();
	std::string const&& assistID = data->currentAssistID();
	std::string const&& regID = data->currentRegID();
	std::string const&& patientID = data->currentPatID();
	if (assistID == result.diagnosis_id && regID == result.register_id && patientID == result.patient_id)
	{
		//认定和当前值一样
		data->setCurrentAssistID("");
		data->setCurrentPatID("");
		data->setCurrentPatName("");
		data->setCurrentRegID("");
		data->removeWaitFromID(result.patient_id);
		QMetaObject::invokeMethod(this, "private_pause", Qt::QueuedConnection, Q_ARG(DoctorPauseResponse, result));
	}
}

void ExpertsGui::receiptRoomPush(DoctorRoomIDPush const& result)
{
	data_ptr data = m_pManager->dataManager();	
	data->setRoom(result.room_id);
}

void ExpertsGui::receiptSurePass(DoctorSurePassResponse const& result)
{
	debug_out << result.datetime << std::endl;
	debug_out << result.register_id << std::endl;
	debug_out << result.doctor_id << std::endl;
	debug_out << result.result << std::endl;
	debug_out << result.reason << std::endl;
	if (result.result == "0")
	{
		QMetaObject::invokeMethod(this, "private_sure_pass", Qt::QueuedConnection, Q_ARG(DoctorSurePassResponse, result));
	}
}

void ExpertsGui::receiptStop(DoctorStopResponse const& result)
{
	data_ptr data = m_pManager->dataManager();
	if (result.result == "1")
	{
		data->resetCurrent();
		data->resetAssist();
		QMetaObject::invokeMethod(this, "private_stop", Qt::QueuedConnection, Q_ARG(DoctorStopResponse, result));
	}
}

void ExpertsGui::receiptLeave(DoctorLeaveResponse const& result)
{
	if (result.doctor_id == m_pManager->dataManager()->doctorInfo().doctor_id)
	{
		QMetaObject::invokeMethod(this, "private_leave", Qt::QueuedConnection, Q_ARG(DoctorLeaveResponse, result));
	}
	else
	{
		debug_out << "离开响应中医生ID和本地医生不一致" << std::endl;
	}
}

void ExpertsGui::receiptLeaveRecover(DoctorLeaveRecoverResponse const& result)
{
	if (result.doctor_id == m_pManager->dataManager()->doctorInfo().doctor_id)
	{
		QMetaObject::invokeMethod(this, "private_leave_recover", Qt::QueuedConnection, Q_ARG(DoctorLeaveRecoverResponse, result));
	}
	else
	{
		debug_out << "离开响应中医生ID和本地医生不一致" << std::endl;
	}
}

void ExpertsGui::receiptComplete(DoctorCompleteResponse const& result)
{
	if (result.doctor_id == m_pManager->dataManager()->doctorInfo().doctor_id)
	{
		QMetaObject::invokeMethod(this, "private_doctor_complete", Qt::QueuedConnection, Q_ARG(DoctorCompleteResponse, result));
	}
}

void ExpertsGui::receiptHistory(IllHistoryResponse const& result)
{
	auto print = [](std::list<ListContent> const& list)
	{
		for (auto&& value : list)
		{
			debug_out << "content" << value.content << std::endl;
			debug_out << "doctor_id" << value.doctor_id << std::endl;
			debug_out << "patient_id" << value.patient_id << std::endl;
			debug_out << "datetime" << value.datetime << std::endl;
			debug_out << std::endl;
		}
	};
	data_ptr data = m_pManager->dataManager();
	data->setCurrentHistory(result);
	print(result.drug);
	print(result.past);
	print(result.family);
	print(result.genetic);
	QMetaObject::invokeMethod(this, "private_history", Qt::QueuedConnection, Q_ARG(IllHistoryResponse, result));
}

void ExpertsGui::receiptAddHistory(IllHistoryAddResponse const& result)
{
	if (result.patient_id != m_pManager->dataManager()->currentPatID())
	{
		debug_out << "发现添加病史中和当前的病患ID不一致" << std::endl;
	}
}

void ExpertsGui::private_doctor_info(DoctorInfoResponse const& result)
{
	ui.mainWindow->ui.expertshospital->setText(String2QString(result.hospital_name));
	ui.mainWindow->ui.doctorNamelab->setText(String2QString(result.doctor_name));
}

void ExpertsGui::private_doctor_list(DiagnosisListPush const& result)
{
	debug_out << "更新队列" << std::endl;
	auto everyListHandler = [this](stateList const& list, TableModel* model)
	{
		model->removeRows(0, model->rowCount());
		for (auto&& value : list)
		{
			auto row = TableModel::make_experts_registrarow(QString::number(value.rank), String2QString(value.patient_name), string2Sex(value.sex));
			model->appendRow(row);
		}
	};
	everyListHandler(result.wait_force, m_pWaitModel);
	everyListHandler(result.wait, m_pWaitModel);
	everyListHandler(result.pass, m_pPassModel);
	everyListHandler(result.pause, m_pPauseModel);
	everyListHandler(result.complete, m_pCompleteModel);
	updatePages();
}

void ExpertsGui::private_begin(DoctorBeginResponse const& result)
{
	if (result.result == "0")
	{
		ButtonDialog dialog(this);
		dialog.setCancelButtonVisiable(false);
		dialog.setTitle(QStringLiteral("提示"));
		dialog.setDisplayText(String2QString(result.reason));
		dialog.resize(600, 220);
		SnMaskWidget pMaskWidget(this);
		pMaskWidget.addDialogName(dialog.objectName());
		pMaskWidget.setMainWidget(this);
		dialog.exec();
	}
	else
	{
		ui.expandWidget->ui.startService->setEnabled(false);
		ui.expandWidget->ui.stopService->setEnabled(false);
		ui.expandWidget->ui.leaveService->setEnabled(true);
		ui.mainWindow->ui.callNextBtn->setVisible(true);
		ui.shutupWidget->ui.startShutStateBtn->setEnabled(false);
		ui.shutupWidget->ui.leaveShutStateBtn->setEnabled(true);
		ui.shutupWidget->ui.stopShutStateBtn->setEnabled(false);
		m_pTimer->start(1000);
	}
}

void ExpertsGui::private_call_next(DoctorCallResponse const& result)
{
	if (!m_pCallAssist)
	{
		m_pCallAssist = new CallAssistDialog(this);
	}
	if (!m_pCallAssist->isHidden())
	{
		m_pCallAssist->hide();
	}
	//设置当前标牌
	ui.expandWidget->ui.currentPatlab->setText(String2QString(result.now));
	ui.expandWidget->ui.nextNameLab->setText(String2QString(result.next));
	//遮挡，等待应答窗体，从外部接收消息，响应弹出窗体
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pCallAssist->objectName());
	pMaskWidget.setMainWidget(this);
	m_pCallAssist->init();
	m_pCallAssist->setPatient(result.patient_info);
	m_pCallAssist->setDoctor(result.diagnosis_info);
	m_pCallAssist->setTitle(QStringLiteral("正在等待助诊医生应答"));
	auto res = m_pCallAssist->exec();
	if (res == QDialog::Accepted)
	{
		//触发的应答信号,将进入到就诊状态
		debug_out << "助诊应答了信号" << std::endl;
		enterRoom();
		workState();
	}
	else if(res == QDialog::Rejected)
	{
		//专家拒绝，使用了过号请求
		int waitSec = m_pCallAssist->waitTimeSec();
		requestPassPat(waitSec);
		debug_out << "专家使用了过号，专家等待了" << waitSec << "秒" << std::endl;
	}
	else
	{
		debug_out << "助诊端无应答，系统自动过号" << std::endl;
	}
}

void ExpertsGui::private_call_result(DoctorAcceptCallResultPush const& result)
{
	//助诊申请了过号
	if (result.response == "0")
	{
		if (m_pCallAssist->isVisible())
		{
			m_pCallAssist->assistDisagree();
		}
	}
	else if (result.response == "1")
	{
		if (m_pCallAssist->isVisible())
		{
			m_pCallAssist->assistAgree();
			updatePatient();
			updateAssist();
		}
	}
}

void ExpertsGui::private_pause(DoctorPauseResponse const& result)
{
	ui.expandWidget->ui.currentPatlab->setText("------");
	waitState();
	resetDoctor();
	resetPatient();
	m_process->kill();
}

void ExpertsGui::private_stop(DoctorStopResponse const& result)
{
	if (result.result == "1")
	{
		waitState();
		resetPatient();
		resetDoctor();
		m_process->kill();
	}
}

void ExpertsGui::private_leave(DoctorLeaveResponse const& result)
{
	ui.expandWidget->ui.leaveService->setChecked(true);
	ui.expandWidget->ui.leaveService->setText(QStringLiteral("继续"));
	ui.shutupWidget->ui.leaveShutStateBtn->setChecked(true);
	ui.shutupWidget->ui.leaveShutStateBtn->setText(QStringLiteral("继续"));
}

void ExpertsGui::private_leave_recover(DoctorLeaveRecoverResponse const& result)
{
	ui.expandWidget->ui.leaveService->setChecked(false);
	ui.expandWidget->ui.leaveService->setText(QStringLiteral("离开"));
	ui.shutupWidget->ui.leaveShutStateBtn->setChecked(false);
	ui.shutupWidget->ui.leaveShutStateBtn->setText(QStringLiteral("离开"));
}

void ExpertsGui::private_doctor_complete(DoctorCompleteResponse const& result)
{
	ui.expandWidget->ui.startService->setEnabled(true);
	ui.expandWidget->ui.leaveService->setEnabled(false);
	ui.expandWidget->ui.stopService->setEnabled(false);

	ui.shutupWidget->ui.startShutStateBtn->setEnabled(true);
	ui.shutupWidget->ui.leaveShutStateBtn->setEnabled(false);
	ui.shutupWidget->ui.stopShutStateBtn->setEnabled(false);
}

void ExpertsGui::private_sure_pass(DoctorSurePassResponse const& result)
{
	(void)result;
	enterRoom();
	workState();
}

void ExpertsGui::private_history(IllHistoryResponse const& result)
{
	if(m_pHisDialog)
		m_pHisDialog->setData(result);
}

void ExpertsGui::on_start()
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

void ExpertsGui::on_leave(bool checked)
{
	ButtonDialog dialog(this);
	dialog.setTitle(checked ? QStringLiteral("离开确认"):QStringLiteral("继续确认"));
	dialog.setDisplayText(checked? QStringLiteral("您确定要进行离开操作吗？"):QStringLiteral("您确定要进行继续操作吗?"));
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

void ExpertsGui::on_stop()
{
	ButtonDialog dialog(this);
	dialog.setTitle(QStringLiteral("结束确认"));
	dialog.setDisplayText(QStringLiteral("您确定要结束门诊操作吗?"));
	dialog.resize(600, 200);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		requestDoctorComplete();
	}
}

void ExpertsGui::on_call_next()
{
	ButtonDialog dialog(this);
	dialog.setTitle(QStringLiteral("就诊叫号确认"));
	dialog.setDisplayText(QStringLiteral("您确定要进行就诊叫号吗？"));
	dialog.resize(600, 200);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	if (QDialog::Accepted == dialog.exec())
	{
		requestCallNext();
	}
}

void ExpertsGui::on_timeout()
{
	QDateTime currentTime = QDateTime::currentDateTime();
	ui.mainWindow->ui.dateTimelab->setText(currentTime.toString("yyyy-MM-dd HH:mm:ss"));
	requestHeartbeat();
}

void ExpertsGui::on_pause()
{
	requestPausePat();
}

void ExpertsGui::on_complete()
{
	ButtonDialog dialog(this);
	dialog.setTitle(QStringLiteral("就诊完成确认"));
	dialog.setDisplayText(QStringLiteral("您确定要执行就诊完成操作吗？"));
	dialog.resize(600, 200);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(dialog.objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() != QDialog::Accepted)
	{
		return;
	}
	QString strTelltion = ui.mainWindow->ui.telltionEdit->toPlainText();
	QString strRemark = ui.mainWindow->ui.remark->toPlainText();
	QString strDispose = ui.mainWindow->ui.disposeEdit->toPlainText();
	QString strPrescription = ui.mainWindow->ui.prescription->toPlainText();
	if (strTelltion.isEmpty())
	{
		dialog.setCancelButtonVisiable(false);
		dialog.setDisplayText(QStringLiteral("请输入患者主诉"));
		dialog.resize(600, 200);
		SnMaskWidget pMaskWidget(this);
		pMaskWidget.addDialogName(dialog.objectName());
		pMaskWidget.setMainWidget(this);
		dialog.exec();
		return;
	}
	if (strRemark.isEmpty())
	{
		dialog.setCancelButtonVisiable(false);
		dialog.setDisplayText(QStringLiteral("请输入诊断建议"));
		dialog.resize(600, 200);
		SnMaskWidget pMaskWidget(this);
		pMaskWidget.addDialogName(dialog.objectName());
		pMaskWidget.setMainWidget(this);
		dialog.exec();
		return;
	}
	if (strDispose.isEmpty())
	{
		dialog.setCancelButtonVisiable(false);
		dialog.setDisplayText(QStringLiteral("请输入处理建议"));
		dialog.resize(600, 200);
		SnMaskWidget pMaskWidget(this);
		pMaskWidget.addDialogName(dialog.objectName());
		pMaskWidget.setMainWidget(this);
		dialog.exec();
		return;
	}
	if (strPrescription.isEmpty())
	{
		dialog.setCancelButtonVisiable(false);
		dialog.setDisplayText(QStringLiteral("请输入处方建议"));
		dialog.resize(600, 200);
		SnMaskWidget pMaskWidget(this);
		pMaskWidget.addDialogName(dialog.objectName());
		pMaskWidget.setMainWidget(this);
		dialog.exec();
		return;
	}
	requestComplete(QString2String(strTelltion), QString2String(strRemark), QString2String(strDispose), QString2String(strPrescription));
}

void ExpertsGui::on_video()
{
	if (m_process->state() == QProcess::Running || m_process->state() == QProcess::Starting)
	{
		debug_out << "视频窗口已经打开" << std::endl;
		return;
 	}
	enterRoom();
}

void ExpertsGui::on_allergy()
{
	initHisDialog(HistoryDialog::Drug);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();	
}

void ExpertsGui::on_past()
{
	initHisDialog(HistoryDialog::Past);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void ExpertsGui::on_family()
{
	initHisDialog(HistoryDialog::Family);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void ExpertsGui::on_heredity()
{
	initHisDialog(HistoryDialog::Genetic);
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	m_pHisDialog->exec();
}

void ExpertsGui::on_add_drug()
{
	if (m_pHisDialog->isActiveWindow())
	{
		m_pHisDialog->hide();
	}
	AppendHistoryDialog dialog;
	dialog.setWindowTitle(QStringLiteral("新增药物过敏史"));
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		requestAddHistory(0, QString2String(dialog.plianText()));
	}
}

void ExpertsGui::on_add_past()
{
	if (m_pHisDialog->isActiveWindow())
	{
		m_pHisDialog->hide();
	}
	AppendHistoryDialog dialog;
	dialog.setWindowTitle(QStringLiteral("新增既往史"));
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		requestAddHistory(1, QString2String(dialog.plianText()));
	}
}

void ExpertsGui::on_add_family()
{
	if (m_pHisDialog->isActiveWindow())
	{
		m_pHisDialog->hide();
	}
	AppendHistoryDialog dialog;
	dialog.setWindowTitle(QStringLiteral("新增家族史"));
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		requestAddHistory(2, QString2String(dialog.plianText()));
	}
}

void ExpertsGui::on_add_genetic()
{
	if (m_pHisDialog->isActiveWindow())
	{
		m_pHisDialog->hide();
	}
	AppendHistoryDialog dialog;
	dialog.setWindowTitle(QStringLiteral("新增遗传病史"));
	SnMaskWidget pMaskWidget(this);
	pMaskWidget.addDialogName(m_pHisDialog->objectName());
	pMaskWidget.setMainWidget(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		requestAddHistory(3, QString2String(dialog.plianText()));
	}
}

void ExpertsGui::waitState()
{
	ui.mainWindow->ui.callNextBtn->setVisible(true);
	ui.mainWindow->ui.videoBtn->setVisible(false);
	ui.mainWindow->ui.completeBtn->setVisible(false);
	ui.mainWindow->ui.pauseBtn->setVisible(false);
}

void ExpertsGui::workState()
{
	ui.mainWindow->ui.callNextBtn->setVisible(false);
	ui.mainWindow->ui.videoBtn->setVisible(true);
	ui.mainWindow->ui.completeBtn->setVisible(true);
	ui.mainWindow->ui.pauseBtn->setVisible(true);
}

void ExpertsGui::updatePages()
{
	ui.expandWidget->ui.waitPageBtn->setText(QString::number(m_pWaitModel->rowCount()));
	ui.expandWidget->ui.pausePageBtn->setText(QString::number(m_pPauseModel->rowCount()));
	ui.expandWidget->ui.passPageBtn->setText(QString::number(m_pPassModel->rowCount()));
	ui.expandWidget->ui.completePageBtn->setText(QString::number(m_pCompleteModel->rowCount()));
}

void ExpertsGui::updatePatient()
{
	data_ptr data = m_pManager->dataManager();
	auto&& patInfo = data->currentPatInfo();
	QPixmap pixmap;
	pixmap.loadFromData((uchar*)patInfo.avatar.data(), patInfo.avatar.size());
	ui.mainWindow->ui.headImagelab->setPixmap(pixmap.isNull() ? QPixmap(":/res/MainWindow/Patdef.png") : pixmap);
	ui.mainWindow->ui.patNamelab->setText(String2QString(patInfo.name));
	ui.mainWindow->ui.patSex->setText( '(' +string2Sex(patInfo.sex) + ')');
	QDate date = QDate::currentDate();
	int years = date.year();
	QDate birth = QDate::fromString(String2QString(patInfo.birthday), "yyyy-MM-dd");
	int age = birth.year() - years;
	ui.mainWindow->ui.patAgelab->setText(QString::number(qAbs(age)) + QStringLiteral("岁"));
	ui.mainWindow->ui.dateOfBirthlab->setText(String2QString(patInfo.birthday));
}

void ExpertsGui::updateAssist()
{
	data_ptr data = m_pManager->dataManager();
	auto&& assistInfo = data->currentAssist();
	QPixmap pixmap;
	pixmap.loadFromData((uchar*)assistInfo.head_image.data(), assistInfo.head_image.size());
	ui.mainWindow->ui.docImagelab->setPixmap(pixmap.isNull() ? QPixmap(":/res/MainWindow/doctor.png") : pixmap);
	ui.mainWindow->ui.phoneLab->setText(String2QString(assistInfo.organize_name));
	ui.mainWindow->ui.hospitallab->setText(String2QString(assistInfo.address));
}

void ExpertsGui::resetPatient()
{
	ui.mainWindow->ui.headImagelab->setPixmap(QPixmap(":/res/MainWindow/Patdef.png"));
	ui.mainWindow->ui.patNamelab->setText("------");
	ui.mainWindow->ui.patSex->setText(QStringLiteral("(未知)"));
	QDate date = QDate::currentDate();
	ui.mainWindow->ui.patAgelab->setText(QStringLiteral("未知"));
	ui.mainWindow->ui.dateOfBirthlab->setText(QStringLiteral("未知"));
}

void ExpertsGui::resetDoctor()
{
	ui.mainWindow->ui.docImagelab->setPixmap(QPixmap(":/res/MainWindow/Patdef.png"));
	ui.mainWindow->ui.phoneLab->setText("-----------");
	ui.mainWindow->ui.hospitallab->setText("------------");
}

void ExpertsGui::enterRoom()
{
	if (m_process->state() == QProcess::Starting || m_process->state() == QProcess::Running)
	{
		return;
	}
	data_ptr data = m_pManager->dataManager();
	std::string room = data->room();
	if (room.empty())
	{
		debug_out << "没有找到房间号，请检查逻辑顺序" << std::endl;
	}
	int ms = QTime::currentTime().msecsSinceStartOfDay();
	QString strCommand = QStringLiteral("ClassName=%0&SrvIP=%1&UserName=%2&Password=%3&RoomID=%4&AnonymousUser=0")
		.arg(ms).arg("118.122.92.92").arg("zdwl").arg("123456").arg(String2QString(room));
	QStringList commandList;
	commandList << strCommand;
	m_process->start(QString("IMActive/ActiveMeeting.exe"), commandList);
}

QString ExpertsGui::string2Sex(std::string const& sex)
{
	if (sex == "1")
		return QStringLiteral("男");
	else if (sex == "2")
		return QStringLiteral("女");
	else
		return QStringLiteral("未知");
}


void ExpertsGui::initHisDialog(HistoryDialog::WindowIndex index)
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

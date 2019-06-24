#include "stable.h"
#include "HistoryStatisDialog.h"

HistoryStatisDialog::HistoryStatisDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	connect(ui.closeBtn, &QAbstractButton::clicked, this, &QDialog::accept);
	m_pModel = new TableModel(ui.tableView);
	TableHeaderView* headerView = new TableHeaderView(Qt::Horizontal,ui.tableView);
	ui.tableView->setHorizontalHeader(headerView);
	ui.tableView->verticalHeader()->setVisible(false);
	QStringList headerlabs;
	headerlabs << QStringLiteral("日期") << QStringLiteral("患者") << QStringLiteral("远程") << QStringLiteral("操作");
	m_pModel->setHorizontalHeaderLabels(headerlabs);
	ui.tableView->setModel(m_pModel);
	headerView->setMinimumHeight(50);
	headerView->setSectionResizeMode(0, QHeaderView::Fixed);
	headerView->setSectionResizeMode(1, QHeaderView::Fixed);
	headerView->setSectionResizeMode(2, QHeaderView::Fixed);
	headerView->setSectionResizeMode(3, QHeaderView::Stretch);
	headerView->resizeSection(0, 150);
	headerView->resizeSection(1, 260);
	headerView->resizeSection(2, 320);
	headerView->resizeSection(3, 232);
	ui.tableView->setItemDelegateForColumn(3, new ButtonBoxDelegate(ui.tableView));

	auto row1 = TableModel::make_historyStatis("2019-3-3", QStringLiteral("刘桂香（女）- 36岁"), QStringLiteral("尤斌（男）- 心外科-安贞医院"), QStringLiteral("患者详情;诊断详情"));
	auto row2 = TableModel::make_historyStatis("2019-3-3", QStringLiteral("刘桂香（女）- 36岁"), QStringLiteral("尤斌（男）- 心外科-安贞医院"), QStringLiteral("患者详情;诊断详情"));
	auto row3 = TableModel::make_historyStatis("2019-3-3", QStringLiteral("刘桂香（女）- 36岁"), QStringLiteral("尤斌（男）- 心外科-安贞医院"), QStringLiteral("患者详情;诊断详情"));
	auto row4 = TableModel::make_historyStatis("2019-3-3", QStringLiteral("刘桂香（女）- 36岁"), QStringLiteral("尤斌（男）- 心外科-安贞医院"), QStringLiteral("患者详情;诊断详情"));
	auto row5 = TableModel::make_historyStatis("2019-3-3", QStringLiteral("刘桂香（女）- 36岁"), QStringLiteral("尤斌（男）- 心外科-安贞医院"), QStringLiteral("患者详情;诊断详情"));
	m_pModel->appendRow(row1);
	m_pModel->appendRow(row2);
	m_pModel->appendRow(row3);
	m_pModel->appendRow(row4);
	m_pModel->appendRow(row5);
}

HistoryStatisDialog::~HistoryStatisDialog()
{
}

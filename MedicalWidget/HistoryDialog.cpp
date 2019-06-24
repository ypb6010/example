#include "stable.h"
#include "HistoryDialog.h"
#include "ui_HistoryDialog.h"

HistoryDialog::HistoryDialog(QWidget *parent)
	: QDialog(parent)
	, drupModel(new QStandardItemModel(this))
	, pastModel(new QStandardItemModel(this))
	, familyModel(new QStandardItemModel(this))
	, geneticModel(new QStandardItemModel(this))
	, ui(new Ui::HistoryDialog)
{
	ui->setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	setWindowTitle(QStringLiteral("»¼Õß²¡Ê·ÏêÇé"));
	QHeaderView* drupHeader = new QHeaderView(Qt::Horizontal, ui->drugView);
	QHeaderView* pastHeader = new QHeaderView(Qt::Horizontal, ui->pastView);
	QHeaderView* familyHeader = new QHeaderView(Qt::Horizontal, ui->familyView);
	QHeaderView* geneticHeader = new QHeaderView(Qt::Horizontal, ui->geneticView);

	ui->drugView->setModel(drupModel);
	ui->pastView->setModel(pastModel);
	ui->familyView->setModel(familyModel);
	ui->geneticView->setModel(geneticModel);

	drupModel->setHorizontalHeaderLabels(QStringList({ "","" }));
	pastModel->setHorizontalHeaderLabels(QStringList({ "","" }));
	familyModel->setHorizontalHeaderLabels(QStringList({ "","" }));
	geneticModel->setHorizontalHeaderLabels(QStringList({ "","" }));

	ui->drugView->setHorizontalHeader(drupHeader);
	ui->pastView->setHorizontalHeader(pastHeader);
	ui->familyView->setHorizontalHeader(familyHeader);
	ui->geneticView->setHorizontalHeader(geneticHeader);

	drupHeader->setSectionResizeMode(0, QHeaderView::Stretch);
	drupHeader->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	pastHeader->setSectionResizeMode(0, QHeaderView::Stretch);
	pastHeader->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	familyHeader->setSectionResizeMode(0, QHeaderView::Stretch);
	familyHeader->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	geneticHeader->setSectionResizeMode(0, QHeaderView::Stretch);
	geneticHeader->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	ui->drugView->horizontalHeader()->setVisible(false);
	ui->pastView->horizontalHeader()->setVisible(false);
	ui->familyView->horizontalHeader()->setVisible(false);
	ui->geneticView->horizontalHeader()->setVisible(false);

	connect(ui->adddrugBtn, &QAbstractButton::clicked, this, &HistoryDialog::addDrugClicked);
	connect(ui->addpastBtn, &QAbstractButton::clicked, this, &HistoryDialog::addPastClecked);
	connect(ui->addFamilyBtn, &QAbstractButton::clicked, this, &HistoryDialog::addFamilyClicked);
	connect(ui->addgeneticBtn, &QAbstractButton::clicked, this, &HistoryDialog::addGeneticClicked);
}

HistoryDialog::~HistoryDialog()
{
	delete ui;
}

void HistoryDialog::setData(IllHistoryResponse const& hisData)
{
	auto createItem = [](QString const& content, QString const& datetime)->QList<QStandardItem*>
	{
		QList<QStandardItem*> row;
		QStandardItem* contentItem = new QStandardItem(content);
		QStandardItem* datetimeItem = new QStandardItem(datetime);
		contentItem->setEditable(false);
		datetimeItem->setEditable(false);
		QFont font("MicrosoftYaHei");
		font.setPixelSize(16);
		contentItem->setFont(font);
		datetimeItem->setFont(font);
		contentItem->setForeground(QBrush(QColor(51, 51, 51)));
		datetimeItem->setForeground(QBrush(QColor(136, 136, 136)));
		row << contentItem << datetimeItem;
		return row;
	};
	auto everyHistory = [&](std::list<ListContent> const& list, QStandardItemModel* model)
	{
		model->removeRows(0, model->rowCount());
		for (auto&& value : list)
		{
			auto row = createItem(String2QString(value.content), String2QString(value.datetime));
			model->appendRow(row);
		}
	};
	everyHistory(hisData.drug, drupModel);
	everyHistory(hisData.past, pastModel);
	everyHistory(hisData.family, familyModel);
	everyHistory(hisData.genetic, geneticModel);
}

void HistoryDialog::setIndex(WindowIndex index)
{
	ui->tabWidget->setCurrentIndex(index);
}

void HistoryDialog::setVisiableAppend(bool bVisiable)
{
	ui->adddrugBtn->setVisible(bVisiable);
	ui->addpastBtn->setVisible(bVisiable);
	ui->addFamilyBtn->setVisible(bVisiable);
	ui->addgeneticBtn->setVisible(bVisiable);
}

#include "stable.h"
#include "LeftExpandWidget.h"

LeftExpandWidget::LeftExpandWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	chanageTabWidget(ui.selectWaitLab);
	ui.gridLayout_2->setAlignment(ui.selectWaitLab, Qt::AlignHCenter);
	ui.gridLayout_2->setAlignment(ui.selectPassLab, Qt::AlignHCenter);
	ui.gridLayout_2->setAlignment(ui.selectPauselab, Qt::AlignHCenter);
	ui.gridLayout_2->setAlignment(ui.selectComplete, Qt::AlignHCenter);
	connect(ui.waitPageBtn, &QAbstractButton::clicked, [this]() { chanageTabWidget(ui.selectWaitLab);});
	connect(ui.passPageBtn, &QAbstractButton::clicked, [this]() { chanageTabWidget(ui.selectPassLab); });
	connect(ui.pausePageBtn, &QAbstractButton::clicked, [this]() { chanageTabWidget(ui.selectPauselab); });
	connect(ui.completePageBtn, &QAbstractButton::clicked, [this]() { chanageTabWidget(ui.selectComplete); });
}

LeftExpandWidget::~LeftExpandWidget()
{
}

void LeftExpandWidget::chanageTabWidget(QLabel* lab)
{
	std::array<QLabel*, 4> tabLabArray{ ui.selectWaitLab , ui.selectPassLab, ui.selectPauselab, ui.selectComplete };
	for (QLabel* it : tabLabArray)
	{
		if (lab == it)
		{
			it->setPixmap(QPixmap(":/res/leftExpand/selectarrow.png"));
		}
		else
		{
			it->setPixmap(QPixmap());
		}
	}
}

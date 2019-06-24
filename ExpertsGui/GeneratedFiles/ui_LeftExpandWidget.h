/********************************************************************************
** Form generated from reading UI file 'LeftExpandWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTEXPANDWIDGET_H
#define UI_LEFTEXPANDWIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../MedicalWidget/TitleBar.h"
#include "LeftExpandLine.h"

QT_BEGIN_NAMESPACE

class Ui_LeftExpandWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    TitleBar *expandTitlebar;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLabel *label_11;
    LeftExpandLine *widget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *startService;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *leaveService;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *stopService;
    QWidget *displayWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QLabel *currentPatlab;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QLabel *nextNameLab;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *preDaybtn;
    QDateEdit *dateEdit;
    QToolButton *nextDaybtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *historyBtn;
    QGridLayout *gridLayout_2;
    QPushButton *waitPageBtn;
    QPushButton *passPageBtn;
    QPushButton *pausePageBtn;
    QPushButton *completePageBtn;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *selectWaitLab;
    QLabel *selectPassLab;
    QLabel *selectPauselab;
    QLabel *selectComplete;
    QTableView *tableView;

    void setupUi(QWidget *LeftExpandWidget)
    {
        if (LeftExpandWidget->objectName().isEmpty())
            LeftExpandWidget->setObjectName(QStringLiteral("LeftExpandWidget"));
        LeftExpandWidget->resize(633, 920);
        LeftExpandWidget->setMinimumSize(QSize(600, 920));
        LeftExpandWidget->setMaximumSize(QSize(2550, 4800));
        LeftExpandWidget->setStyleSheet(QLatin1String("QWidget#LeftExpandWidget\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(LeftExpandWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        expandTitlebar = new TitleBar(LeftExpandWidget);
        expandTitlebar->setObjectName(QStringLiteral("expandTitlebar"));
        expandTitlebar->setMinimumSize(QSize(600, 60));
        expandTitlebar->setMaximumSize(QSize(4800, 65));
        expandTitlebar->setStyleSheet(QLatin1String("QWidget#expandTitlebar\n"
"{\n"
"	border-image: url(:/res/leftExpand/expandTitle.png);\n"
"}"));
        horizontalLayout_14 = new QHBoxLayout(expandTitlebar);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(9, 0, 0, 0);
        label_10 = new QLabel(expandTitlebar);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(40, 40));
        label_10->setMaximumSize(QSize(40, 40));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/res/leftShutup/logo.png")));

        horizontalLayout_14->addWidget(label_10);

        label_11 = new QLabel(expandTitlebar);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setEnabled(false);
        label_11->setMinimumSize(QSize(176, 24));
        label_11->setStyleSheet(QLatin1String("QLabel#label_11\n"
"{	font-family: MicrosoftYaHei-Bold;\n"
"	font-size: 24px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_11);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 20);

        verticalLayout_4->addWidget(expandTitlebar);

        widget_3 = new LeftExpandLine(LeftExpandWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 6, 20, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 0, -1);
        startService = new QToolButton(widget_3);
        startService->setObjectName(QStringLiteral("startService"));
        startService->setEnabled(true);
        startService->setMinimumSize(QSize(160, 60));
        startService->setMaximumSize(QSize(160, 60));
        startService->setStyleSheet(QLatin1String("QToolButton#startService\n"
"{\n"
"	border-image: url(:/res/leftExpand/startService_normal.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QToolButton#startService:hover\n"
"{	\n"
"	border-image: url(:/res/leftExpand/startService_hover.png);\n"
"border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#startService:pressed\n"
"{	\n"
"	border-image: url(:/res/leftExpand/startService_pressed.png);\n"
"border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#startService:disabled\n"
"{		\n"
"	border-image: url(:/res/leftExpand/left_disable_expand_btn.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout->addWidget(startService);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        leaveService = new QToolButton(widget_3);
        leaveService->setObjectName(QStringLiteral("leaveService"));
        leaveService->setEnabled(false);
        leaveService->setMinimumSize(QSize(160, 60));
        leaveService->setMaximumSize(QSize(160, 60));
        leaveService->setStyleSheet(QLatin1String("QToolButton#leaveService\n"
"{		\n"
"	border-image: url(:/res/leftExpand/leaveService_nomal.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveService:hover\n"
"{		\n"
"	border-image: url(:/res/leftExpand/leaveService_hover.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveService:pressed\n"
"{		\n"
"	\n"
"	border-image: url(:/res/leftExpand/leaveService_hover.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveService:disabled\n"
"{		\n"
"	border-image: url(:/res/leftExpand/left_disable_expand_btn.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveService:checked\n"
"{		\n"
"	\n"
"	bor"
                        "der-image: url(:/res/leftExpand/leave_normal.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveService:checked:hover\n"
"{		\n"
"	\n"
"	border-image: url(:/res/leftExpand/leave_hover.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        leaveService->setCheckable(true);

        horizontalLayout->addWidget(leaveService);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        stopService = new QToolButton(widget_3);
        stopService->setObjectName(QStringLiteral("stopService"));
        stopService->setEnabled(false);
        stopService->setMinimumSize(QSize(160, 60));
        stopService->setMaximumSize(QSize(160, 60));
        stopService->setStyleSheet(QLatin1String("QToolButton#stopService\n"
"{	\n"
"	border-image: url(:/res/leftExpand/stopService_normal.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#stopService:hover\n"
"{		\n"
"	border-image: url(:/res/leftExpand/stopService_hover.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#stopService:pressed\n"
"{		\n"
"	\n"
"	border-image: url(:/res/leftExpand/stopService_pressed.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#stopService:disabled\n"
"{		\n"
"	border-image: url(:/res/leftExpand/left_disable_expand_btn.png);\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout->addWidget(stopService);


        verticalLayout_2->addLayout(horizontalLayout);

        displayWidget = new QWidget(widget_3);
        displayWidget->setObjectName(QStringLiteral("displayWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayWidget->sizePolicy().hasHeightForWidth());
        displayWidget->setSizePolicy(sizePolicy);
        displayWidget->setMinimumSize(QSize(530, 130));
        displayWidget->setMaximumSize(QSize(2550, 130));
        displayWidget->setStyleSheet(QLatin1String("QWidget#displayWidget\n"
"{\n"
"	\n"
"	border-image: url(:/res/leftExpand/displayCard.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(displayWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_11 = new QSpacerItem(18, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(18, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 2, 0, 1, 1);

        currentPatlab = new QLabel(displayWidget);
        currentPatlab->setObjectName(QStringLiteral("currentPatlab"));
        currentPatlab->setMinimumSize(QSize(80, 20));
        currentPatlab->setMaximumSize(QSize(16777215, 16777215));
        currentPatlab->setStyleSheet(QLatin1String("QLabel#currentPatlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 26px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}"));
        currentPatlab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(currentPatlab, 2, 1, 1, 1);

        label = new QLabel(displayWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 26));
        label->setStyleSheet(QLatin1String("QLabel#label\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 3);

        label_2 = new QLabel(displayWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 30));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setStyleSheet(QLatin1String("QLabel#label_2\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(121, 73, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 6, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 3);

        nextNameLab = new QLabel(displayWidget);
        nextNameLab->setObjectName(QStringLiteral("nextNameLab"));
        nextNameLab->setMinimumSize(QSize(80, 30));
        nextNameLab->setStyleSheet(QLatin1String("QLabel#nextNameLab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 26px;\n"
"	font-weight: normal;\n"
"	color: #ffffff;\n"
"}"));
        nextNameLab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nextNameLab, 2, 5, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(121, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 6, 1, 3);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(displayWidget);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalSpacer_9 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(530, 24));
        widget->setMaximumSize(QSize(530, 24));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"	border-image: url(:/res/leftExpand/listLine.png);\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(214, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(96, 24));
        label_5->setMaximumSize(QSize(96, 24));
        label_5->setStyleSheet(QLatin1String("QLabel#label_5\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 23.79px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_6->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(214, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        horizontalLayout_16->addWidget(widget);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(35, -1, 35, -1);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        preDaybtn = new QToolButton(widget_3);
        preDaybtn->setObjectName(QStringLiteral("preDaybtn"));
        preDaybtn->setEnabled(true);
        preDaybtn->setMinimumSize(QSize(40, 40));
        preDaybtn->setMaximumSize(QSize(40, 40));
        preDaybtn->setStyleSheet(QLatin1String("QToolButton#preDaybtn\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;\n"
"	border-image: url(:/res/leftExpand/preDay_Normal.png);\n"
"}\n"
"\n"
"QToolButton#preDaybtn:hover\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	border-image: url(:/res/leftExpand/preDay_hover.png);\n"
"}\n"
"QToolButton#preDaybtn:pressed\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	border-image: url(:/res/leftExpand/preDay_pressed.png);\n"
"}\n"
"QToolButton#preDaybtn:disabled\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	border-image: url(:/res/leftExpand/preDay_disabled.png);\n"
"}"));

        horizontalLayout_7->addWidget(preDaybtn);

        dateEdit = new QDateEdit(widget_3);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(135, 40));
        dateEdit->setMaximumSize(QSize(135, 40));
        dateEdit->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: #c1c2c6;\n"
"spacing: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down \n"
"{\n"
"	width: 16px;\n"
"	height: 16px;\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position:right;\n"
"	border-image: url(:/res/leftExpand/datetime_indicator.png); \n"
"}"));
        dateEdit->setWrapping(false);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        dateEdit->setProperty("showGroupSeparator", QVariant(false));
        dateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2019, 4, 9));

        horizontalLayout_7->addWidget(dateEdit);

        nextDaybtn = new QToolButton(widget_3);
        nextDaybtn->setObjectName(QStringLiteral("nextDaybtn"));
        nextDaybtn->setEnabled(true);
        nextDaybtn->setMinimumSize(QSize(40, 40));
        nextDaybtn->setMaximumSize(QSize(40, 40));
        nextDaybtn->setStyleSheet(QLatin1String("QToolButton#nextDaybtn\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	border-image: url(:/res/leftExpand/nextDay_Normal.png);\n"
"}\n"
"\n"
"QToolButton#nextDaybtn:hover\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	border-image: url(:/res/leftExpand/nextDay_hover.png);\n"
"}\n"
"QToolButton#nextDaybtn:pressed\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	border-image: url(:/res/leftExpand/nextDay_pressed.png);	\n"
"}\n"
"QToolButton#nextDaybtn:disabled\n"
"{\n"
"	background-color: #ffffff;\n"
"	border: solid 1px #c1c2c6;	\n"
"	\n"
"	border-image: url(:/res/leftExpand/nextDay_disable.png);\n"
"}"));

        horizontalLayout_7->addWidget(nextDaybtn);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalSpacer_5 = new QSpacerItem(183, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        historyBtn = new QPushButton(widget_3);
        historyBtn->setObjectName(QStringLiteral("historyBtn"));
        historyBtn->setMinimumSize(QSize(130, 40));
        historyBtn->setMaximumSize(QSize(130, 40));
        historyBtn->setStyleSheet(QLatin1String("QPushButton#historyBtn\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: solid 1px #c1c2c6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"	border-image: url(:/res/leftExpand/history_nomal.png);\n"
"}\n"
"QPushButton#historyBtn:hover\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: solid 1px #c1c2c6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;	\n"
"	border-image: url(:/res/leftExpand/history_hover.png);\n"
"}\n"
"QPushButton#historyBtn:pressed\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: solid 1px #c1c2c6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;	\n"
"	border-image: url(:/res/leftExpand/history_pressed.png);\n"
"}"));

        horizontalLayout_8->addWidget(historyBtn);


        verticalLayout_2->addLayout(horizontalLayout_8);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        waitPageBtn = new QPushButton(widget_3);
        waitPageBtn->setObjectName(QStringLiteral("waitPageBtn"));
        waitPageBtn->setMinimumSize(QSize(100, 100));
        waitPageBtn->setMaximumSize(QSize(100, 100));
        waitPageBtn->setStyleSheet(QLatin1String("\n"
"QPushButton#waitPageBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"	border-image: url(:/res/leftExpand/wait_normal.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton#waitPageBtn:hover\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;	\n"
"	border-image: url(:/res/leftExpand/wait_hover.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton#waitPageBtn:pressed\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;		\n"
"	border-image: url(:/res/leftExpand/wait_pressed.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        gridLayout_2->addWidget(waitPageBtn, 0, 0, 1, 1);

        passPageBtn = new QPushButton(widget_3);
        passPageBtn->setObjectName(QStringLiteral("passPageBtn"));
        passPageBtn->setMinimumSize(QSize(100, 100));
        passPageBtn->setMaximumSize(QSize(100, 100));
        passPageBtn->setStyleSheet(QLatin1String("\n"
"QPushButton#passPageBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;	\n"
"	border-image: url(:/res/leftExpand/pass_normal.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton#passPageBtn:hover\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;	\n"
"	border-image: url(:/res/leftExpand/pass_hover.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton#waitPageBtn:pressed\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;		\n"
"	border-image: url(:/res/leftExpand/pass_pressed.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        gridLayout_2->addWidget(passPageBtn, 0, 1, 1, 1);

        pausePageBtn = new QPushButton(widget_3);
        pausePageBtn->setObjectName(QStringLiteral("pausePageBtn"));
        pausePageBtn->setMinimumSize(QSize(100, 100));
        pausePageBtn->setMaximumSize(QSize(100, 100));
        pausePageBtn->setStyleSheet(QLatin1String("\n"
"QPushButton#pausePageBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;	\n"
"	border-image: url(:/res/leftExpand/pause_nornal.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton#pausePageBtn:hover\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;	\n"
"	border-image: url(:/res/leftExpand/pause_hover.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton#pausePageBtn:pressed\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;		\n"
"	border-image: url(:/res/leftExpand/pause_hover.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        gridLayout_2->addWidget(pausePageBtn, 0, 2, 1, 1);

        completePageBtn = new QPushButton(widget_3);
        completePageBtn->setObjectName(QStringLiteral("completePageBtn"));
        completePageBtn->setMinimumSize(QSize(100, 100));
        completePageBtn->setMaximumSize(QSize(100, 100));
        completePageBtn->setStyleSheet(QLatin1String("\n"
"QPushButton#completePageBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;		\n"
"	border-image: url(:/res/leftExpand/complete_normal.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton#completePageBtn:hover\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;	\n"
"	border-image: url(:/res/leftExpand/complete_hover.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QPushButton#completePageBtn:pressed\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 50px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;		\n"
"	border-image: url(:/res/leftExpand/complete_pressed.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        gridLayout_2->addWidget(completePageBtn, 0, 3, 1, 1);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(40, 20));
        label_6->setMaximumSize(QSize(200, 20));
        label_6->setStyleSheet(QLatin1String("QLabel#label_6\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #333333;\n"
"}"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(40, 20));
        label_7->setMaximumSize(QSize(200, 20));
        label_7->setStyleSheet(QLatin1String("QLabel#label_7\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #333333;\n"
"}"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(40, 20));
        label_8->setMaximumSize(QSize(200, 20));
        label_8->setStyleSheet(QLatin1String("QLabel#label_8\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #333333;\n"
"}"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(40, 20));
        label_9->setMaximumSize(QSize(200, 20));
        label_9->setStyleSheet(QLatin1String("QLabel#label_9\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #333333;\n"
"}"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 1, 3, 1, 1);

        selectWaitLab = new QLabel(widget_3);
        selectWaitLab->setObjectName(QStringLiteral("selectWaitLab"));
        selectWaitLab->setMaximumSize(QSize(20, 15));
        selectWaitLab->setPixmap(QPixmap(QString::fromUtf8(":/res/leftExpand/selectarrow.png")));
        selectWaitLab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(selectWaitLab, 2, 0, 1, 1);

        selectPassLab = new QLabel(widget_3);
        selectPassLab->setObjectName(QStringLiteral("selectPassLab"));
        selectPassLab->setMaximumSize(QSize(20, 15));
        selectPassLab->setPixmap(QPixmap(QString::fromUtf8(":/res/leftExpand/selectarrow.png")));
        selectPassLab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(selectPassLab, 2, 1, 1, 1);

        selectPauselab = new QLabel(widget_3);
        selectPauselab->setObjectName(QStringLiteral("selectPauselab"));
        selectPauselab->setMaximumSize(QSize(20, 15));
        selectPauselab->setPixmap(QPixmap(QString::fromUtf8(":/res/leftExpand/selectarrow.png")));
        selectPauselab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(selectPauselab, 2, 2, 1, 1);

        selectComplete = new QLabel(widget_3);
        selectComplete->setObjectName(QStringLiteral("selectComplete"));
        selectComplete->setMaximumSize(QSize(20, 15));
        selectComplete->setPixmap(QPixmap(QString::fromUtf8(":/res/leftExpand/selectarrow.png")));
        selectComplete->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(selectComplete, 2, 3, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);
        gridLayout_2->setColumnMinimumWidth(0, 1);
        gridLayout_2->setColumnMinimumWidth(1, 1);
        gridLayout_2->setColumnMinimumWidth(2, 1);
        gridLayout_2->setColumnMinimumWidth(3, 1);
        gridLayout_2->setRowMinimumHeight(0, 10);
        gridLayout_2->setRowMinimumHeight(1, 2);
        gridLayout_2->setRowMinimumHeight(2, 2);

        verticalLayout_2->addLayout(gridLayout_2);

        tableView = new QTableView(widget_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(530, 200));
        tableView->setMaximumSize(QSize(2550, 2550));
        tableView->setStyleSheet(QLatin1String("QTableView#tableView::item\n"
"{\n"
"	height:50px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #666666;\n"
"}\n"
"\n"
"QTableView#tableView::item:selected\n"
"{\n"
"	background-color: rgb(230, 244, 255);\n"
"}\n"
"	\n"
"\n"
""));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->verticalHeader()->setDefaultSectionSize(50);
        tableView->verticalHeader()->setMinimumSectionSize(50);

        verticalLayout_2->addWidget(tableView);


        verticalLayout_4->addWidget(widget_3);


        retranslateUi(LeftExpandWidget);

        QMetaObject::connectSlotsByName(LeftExpandWidget);
    } // setupUi

    void retranslateUi(QWidget *LeftExpandWidget)
    {
        LeftExpandWidget->setWindowTitle(QApplication::translate("LeftExpandWidget", "LeftExpandWidget", nullptr));
        label_10->setText(QString());
        label_11->setText(QApplication::translate("LeftExpandWidget", "\350\277\234\347\250\213\344\270\223\345\256\266\345\267\245\344\275\234\347\253\231", nullptr));
        startService->setText(QApplication::translate("LeftExpandWidget", "\345\274\200\345\247\213\351\227\250\350\257\212", nullptr));
        leaveService->setText(QApplication::translate("LeftExpandWidget", "\347\246\273\345\274\200", nullptr));
        stopService->setText(QApplication::translate("LeftExpandWidget", "\347\273\223\346\235\237\351\227\250\350\257\212", nullptr));
        currentPatlab->setText(QApplication::translate("LeftExpandWidget", "--", nullptr));
        label->setText(QApplication::translate("LeftExpandWidget", "\345\275\223\345\211\215\345\260\261\350\257\212", nullptr));
        label_2->setText(QApplication::translate("LeftExpandWidget", "\344\270\213\344\270\200\344\275\215", nullptr));
        nextNameLab->setText(QApplication::translate("LeftExpandWidget", "------", nullptr));
        label_5->setText(QApplication::translate("LeftExpandWidget", "\345\260\261\350\257\212\345\210\227\350\241\250", nullptr));
        preDaybtn->setText(QString());
        nextDaybtn->setText(QString());
        historyBtn->setText(QApplication::translate("LeftExpandWidget", "\345\216\206\345\217\262\345\260\261\350\257\212\347\273\237\350\256\241", nullptr));
        waitPageBtn->setText(QApplication::translate("LeftExpandWidget", "0", nullptr));
        passPageBtn->setText(QApplication::translate("LeftExpandWidget", "0", nullptr));
        pausePageBtn->setText(QApplication::translate("LeftExpandWidget", "0", nullptr));
        completePageBtn->setText(QApplication::translate("LeftExpandWidget", "0", nullptr));
        label_6->setText(QApplication::translate("LeftExpandWidget", "\345\200\231\350\257\212", nullptr));
        label_7->setText(QApplication::translate("LeftExpandWidget", "\350\277\207\345\217\267", nullptr));
        label_8->setText(QApplication::translate("LeftExpandWidget", "\346\232\202\345\201\234", nullptr));
        label_9->setText(QApplication::translate("LeftExpandWidget", "\345\256\214\346\210\220", nullptr));
        selectWaitLab->setText(QString());
        selectPassLab->setText(QString());
        selectPauselab->setText(QString());
        selectComplete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LeftExpandWidget: public Ui_LeftExpandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTEXPANDWIDGET_H

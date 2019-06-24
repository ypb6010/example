/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout_14;
    QWidget *titleBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dateTimelab;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *expertshospital;
    QLabel *doctorNamelab;
    QToolButton *dropupBtn;
    QToolButton *exitBtn;
    QLabel *label;
    QToolButton *minBtn;
    QToolButton *maxBtn;
    QToolButton *closeBtn;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QToolButton *expandBtn;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_13;
    QWidget *centreWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *patientStatelab;
    QToolButton *callNextBtn;
    QSpacerItem *horizontalSpacer_9;
    QToolButton *videoBtn;
    QSpacerItem *horizontalSpacer_12;
    QToolButton *completeBtn;
    QSpacerItem *horizontalSpacer_13;
    QToolButton *pauseBtn;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *headImagelab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *patNamelab;
    QLabel *patSex;
    QSpacerItem *horizontalSpacer_4;
    QLabel *patAgelab;
    QLabel *dateOfBirthlab;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *allergyBtn;
    QPushButton *pastHistorylab;
    QPushButton *familuyHistorylab;
    QPushButton *heredityHistorylab;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTabWidget *reportTabWidget;
    QWidget *lately;
    QVBoxLayout *verticalLayout_15;
    QTableView *lately_tableview;
    QWidget *history;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QToolButton *typeBtn;
    QLabel *label_19;
    QComboBox *typeCombox;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_20;
    QDateEdit *his_fromDate;
    QLabel *label_21;
    QDateEdit *his_toDate;
    QTableView *history_tableview;
    QWidget *remote;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_22;
    QComboBox *departCombox;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_23;
    QDateEdit *rmt_fromDate;
    QLabel *label_24;
    QDateEdit *rmt_fromDate_3;
    QTableView *remote_tableview;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *docImagelab;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *phoneBtn;
    QLabel *phoneLab;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *hospitalBtn;
    QLabel *hospitallab;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget_2;
    QWidget *telltionWidget;
    QVBoxLayout *verticalLayout_9;
    QTextEdit *telltionEdit;
    QWidget *diagnoseWidget;
    QVBoxLayout *verticalLayout_16;
    QTextEdit *remark;
    QWidget *disposeWidget;
    QVBoxLayout *verticalLayout_17;
    QTextEdit *disposeEdit;
    QWidget *prescriptionWidget;
    QVBoxLayout *verticalLayout_20;
    QTextEdit *prescription;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_19;
    QToolButton *templateBtn;
    QSpacerItem *horizontalSpacer_10;
    QToolButton *templateBtn_2;
    QSpacerItem *horizontalSpacer_11;
    QToolButton *templateBtn_3;
    QWidget *versionWidget;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1607, 1062);
        MainWindow->setMinimumSize(QSize(1350, 0));
        MainWindow->setMaximumSize(QSize(4800, 1440));
        MainWindow->setStyleSheet(QLatin1String("QWidget#MainWindow\n"
"{\n"
"	background-color: #f1f2f6;\n"
"}"));
        verticalLayout_14 = new QVBoxLayout(MainWindow);
        verticalLayout_14->setSpacing(20);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        titleBar = new QWidget(MainWindow);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        titleBar->setMinimumSize(QSize(0, 60));
        titleBar->setMaximumSize(QSize(16777215, 60));
        titleBar->setStyleSheet(QLatin1String("QWidget#titleBar\n"
"{\n"
"background-color: #ffffff;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 0, 0, 0);
        dateTimelab = new QLabel(titleBar);
        dateTimelab->setObjectName(QStringLiteral("dateTimelab"));
        dateTimelab->setStyleSheet(QLatin1String("QLabel#dateTimelab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_2->addWidget(dateTimelab);

        horizontalSpacer = new QSpacerItem(662, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 6, -1);
        expertshospital = new QLabel(titleBar);
        expertshospital->setObjectName(QStringLiteral("expertshospital"));
        expertshospital->setStyleSheet(QLatin1String("QLabel#expertshospital\n"
"{	\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout->addWidget(expertshospital);

        doctorNamelab = new QLabel(titleBar);
        doctorNamelab->setObjectName(QStringLiteral("doctorNamelab"));
        doctorNamelab->setStyleSheet(QLatin1String("QLabel#doctorNamelab\n"
"{	\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 23.79px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout->addWidget(doctorNamelab);

        dropupBtn = new QToolButton(titleBar);
        dropupBtn->setObjectName(QStringLiteral("dropupBtn"));
        dropupBtn->setStyleSheet(QLatin1String("QToolButton#dropupBtn\n"
"{	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	image: url(:/res/MainWindow/dropup.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(dropupBtn);

        exitBtn = new QToolButton(titleBar);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setStyleSheet(QLatin1String("QToolButton#exitBtn\n"
"{	\n"
"	height:16;\n"
"	width:16;\n"
"	color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/res/MainWindow/exit_normal.png);\n"
"}\n"
"QToolButton#exitBtn:hover\n"
"{	\n"
"	height:16;\n"
"	width:16;\n"
"	color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/res/MainWindow/exit_hover.png);\n"
"}\n"
"QToolButton#exitBtn:pressed\n"
"{	\n"
"	height:16;\n"
"	width:16;\n"
"	color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/res/MainWindow/exit_pressed.png);\n"
"}"));

        horizontalLayout->addWidget(exitBtn);

        label = new QLabel(titleBar);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(1, 20));
        label->setStyleSheet(QLatin1String("QLabel#label\n"
"{	\n"
"	background-color: rgb(193, 194, 198);\n"
"}\n"
""));

        horizontalLayout->addWidget(label);

        minBtn = new QToolButton(titleBar);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMinimumSize(QSize(20, 20));
        minBtn->setStyleSheet(QLatin1String("QToolButton#minBtn\n"
"{\n"
"border-image: url(:/res/MainWindow/min_normal.png);\n"
"}\n"
"QToolButton#minBtn:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/min_hover.png);\n"
"}\n"
"QToolButton#minBtn:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/min_pressed.png);\n"
"}"));

        horizontalLayout->addWidget(minBtn);

        maxBtn = new QToolButton(titleBar);
        maxBtn->setObjectName(QStringLiteral("maxBtn"));
        maxBtn->setMinimumSize(QSize(20, 20));
        maxBtn->setStyleSheet(QLatin1String("QToolButton#maxBtn\n"
"{\n"
"border-image: url(:/res/MainWindow/max_normal.png);\n"
"}\n"
"QToolButton#maxBtn:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/max_hover.png);\n"
"}\n"
"QToolButton#maxBtn:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/max_pressed.png);\n"
"}\n"
"QToolButton#maxBtn:checked\n"
"{\n"
"border-image: url(:/res/MainWindow/recover_normal.png);\n"
"}\n"
"QToolButton#maxBtn:checked:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/recover_hover.png);\n"
"}\n"
"QToolButton#maxBtn:checked:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/recover_pressed.png);\n"
"}"));
        maxBtn->setCheckable(true);

        horizontalLayout->addWidget(maxBtn);

        closeBtn = new QToolButton(titleBar);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(20, 20));
        closeBtn->setStyleSheet(QLatin1String("QToolButton#closeBtn\n"
"{\n"
"border-image: url(:/res/MainWindow/close_normal.png);\n"
"}\n"
"QToolButton#closeBtn:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/close_hover.png);\n"
"}\n"
"QToolButton#closeBtn:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/close_pressed.png);\n"
"}"));

        horizontalLayout->addWidget(closeBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_14->addWidget(titleBar);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, -1, -1, -1);
        expandBtn = new QToolButton(MainWindow);
        expandBtn->setObjectName(QStringLiteral("expandBtn"));
        expandBtn->setMinimumSize(QSize(12, 100));
        expandBtn->setMaximumSize(QSize(12, 100));
        expandBtn->setStyleSheet(QLatin1String("QToolButton#expandBtn\n"
"{\n"
"border-image: url(:/res/leftExpand/expand.png);\n"
"}\n"
"QToolButton#expandBtn:checked\n"
"{\n"
"border-image: url(:/res/leftExpand/shutup.png);\n"
"}"));
        expandBtn->setCheckable(true);

        horizontalLayout_14->addWidget(expandBtn);

        horizontalSpacer_5 = new QSpacerItem(1, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(20);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        centreWidget = new QWidget(MainWindow);
        centreWidget->setObjectName(QStringLiteral("centreWidget"));
        centreWidget->setMinimumSize(QSize(700, 600));
        centreWidget->setMaximumSize(QSize(2500, 16777215));
        centreWidget->setStyleSheet(QLatin1String("QWidget#centreWidget\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(centreWidget);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centreWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 200));
        widget->setMaximumSize(QSize(16777215, 230));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 20, 20, 20);
        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(600, 0));
        frame->setMaximumSize(QSize(970, 36));
        frame->setStyleSheet(QLatin1String("QFrame#frame\n"
"{\n"
"	border:1px;\n"
"	border-bottom: 1px solid #e9eaef;\n"
"}"));
        frame->setLineWidth(1);
        frame->setMidLineWidth(0);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(6, 36));
        label_2->setMaximumSize(QSize(6, 36));
        label_2->setStyleSheet(QLatin1String("QLabel#label_2\n"
"{\n"
"	background-color: #6489d9;\n"
"}"));

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(101, 40));
        label_3->setMaximumSize(QSize(16777215, 36));
        label_3->setStyleSheet(QLatin1String("QLabel#label_3\n"
"{\n"
"	width: 96px;\n"
"	height: 23px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_3->addWidget(label_3);

        patientStatelab = new QLabel(frame);
        patientStatelab->setObjectName(QStringLiteral("patientStatelab"));
        patientStatelab->setMinimumSize(QSize(71, 36));
        patientStatelab->setMaximumSize(QSize(16777215, 36));
        patientStatelab->setStyleSheet(QLatin1String("QLabel#patientStatelab\n"
"{\n"
"	width: 71px;\n"
"	height: 22px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_3->addWidget(patientStatelab);

        callNextBtn = new QToolButton(frame);
        callNextBtn->setObjectName(QStringLiteral("callNextBtn"));
        callNextBtn->setMinimumSize(QSize(71, 36));
        callNextBtn->setMaximumSize(QSize(60, 36));
        callNextBtn->setStyleSheet(QLatin1String("QToolButton#callNextBtn\n"
"{	\n"
"	border-image: url(:/res/MainWindow/button_normal.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QToolButton#callNextBtn:hover\n"
"{	\n"
"	\n"
"	border-image: url(:/res/MainWindow/video_hover.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(callNextBtn);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        videoBtn = new QToolButton(frame);
        videoBtn->setObjectName(QStringLiteral("videoBtn"));
        videoBtn->setMinimumSize(QSize(71, 36));
        videoBtn->setMaximumSize(QSize(60, 36));
        videoBtn->setStyleSheet(QLatin1String("QToolButton#videoBtn\n"
"{	\n"
"	border-image: url(:/res/MainWindow/button_normal.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QToolButton#videoBtn:hover\n"
"{	\n"
"	\n"
"	border-image: url(:/res/MainWindow/video_hover.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(videoBtn);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        completeBtn = new QToolButton(frame);
        completeBtn->setObjectName(QStringLiteral("completeBtn"));
        completeBtn->setMinimumSize(QSize(71, 36));
        completeBtn->setMaximumSize(QSize(60, 36));
        completeBtn->setStyleSheet(QLatin1String("QToolButton#completeBtn\n"
"{		\n"
"	border-image: url(:/res/MainWindow/complete_normal.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#completeBtn:hover\n"
"{		\n"
"	border-image: url(:/res/MainWindow/complete_hover.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(completeBtn);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        pauseBtn = new QToolButton(frame);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));
        pauseBtn->setMinimumSize(QSize(71, 36));
        pauseBtn->setMaximumSize(QSize(60, 36));
        pauseBtn->setStyleSheet(QLatin1String("QToolButton#pauseBtn\n"
"{		\n"
"	border-image: url(:/res/MainWindow/pause_normal.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#pauseBtn:hover\n"
"{		\n"
"	\n"
"	border-image: url(:/res/MainWindow/pause_hover.png);\n"
"	width: 63px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pauseBtn);

        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);


        verticalLayout_3->addWidget(frame);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        headImagelab = new QLabel(widget);
        headImagelab->setObjectName(QStringLiteral("headImagelab"));
        headImagelab->setMinimumSize(QSize(80, 110));
        headImagelab->setMaximumSize(QSize(80, 110));
        headImagelab->setPixmap(QPixmap(QString::fromUtf8(":/res/MainWindow/Patdef.png")));

        horizontalLayout_7->addWidget(headImagelab);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        patNamelab = new QLabel(widget);
        patNamelab->setObjectName(QStringLiteral("patNamelab"));
        patNamelab->setMinimumSize(QSize(81, 39));
        patNamelab->setMaximumSize(QSize(81, 39));
        patNamelab->setStyleSheet(QLatin1String("QLabel#patNamelab\n"
"{\n"
"	width: 110px;\n"
"	height: 24px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_4->addWidget(patNamelab);

        patSex = new QLabel(widget);
        patSex->setObjectName(QStringLiteral("patSex"));
        patSex->setMaximumSize(QSize(60, 39));
        patSex->setStyleSheet(QLatin1String("QLabel#patSex\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	color: #333333;\n"
"}"));
        patSex->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(patSex);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        patAgelab = new QLabel(widget);
        patAgelab->setObjectName(QStringLiteral("patAgelab"));
        patAgelab->setMinimumSize(QSize(30, 15));
        patAgelab->setMaximumSize(QSize(30, 15));
        patAgelab->setStyleSheet(QLatin1String("QLabel#patAgelab\n"
"{\n"
"	width: 33px;\n"
"	height: 15px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        verticalLayout->addWidget(patAgelab);

        dateOfBirthlab = new QLabel(widget);
        dateOfBirthlab->setObjectName(QStringLiteral("dateOfBirthlab"));
        dateOfBirthlab->setMinimumSize(QSize(88, 12));
        dateOfBirthlab->setMaximumSize(QSize(88, 20));
        dateOfBirthlab->setStyleSheet(QLatin1String("QLabel#dateOfBirthlab\n"
"{\n"
"	width: 88px;\n"
"	height: 12px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        verticalLayout->addWidget(dateOfBirthlab);


        horizontalLayout_7->addLayout(verticalLayout);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(1, 90));
        label_4->setMaximumSize(QSize(1, 90));
        label_4->setStyleSheet(QLatin1String("QLabel#label_4\n"
"{\n"
"	background-color: #e1e2e6\n"
"}"));

        horizontalLayout_7->addWidget(label_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(40);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        allergyBtn = new QPushButton(widget);
        allergyBtn->setObjectName(QStringLiteral("allergyBtn"));
        allergyBtn->setMinimumSize(QSize(60, 60));
        allergyBtn->setMaximumSize(QSize(60, 60));
        allergyBtn->setStyleSheet(QLatin1String("QPushButton#allergyBtn\n"
"{\n"
"border-image: url(:/res/MainWindow/allergy_normal.png);\n"
"}\n"
"QPushButton#allergyBtn:hover\n"
"{\n"
"	\n"
"	border-image: url(:/res/MainWindow/allergy_hover.png);\n"
"}\n"
"QPushButton#allergyBtn:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/allergy_pressed.png);\n"
"}"));

        horizontalLayout_6->addWidget(allergyBtn);

        pastHistorylab = new QPushButton(widget);
        pastHistorylab->setObjectName(QStringLiteral("pastHistorylab"));
        pastHistorylab->setMinimumSize(QSize(60, 60));
        pastHistorylab->setMaximumSize(QSize(60, 60));
        pastHistorylab->setStyleSheet(QLatin1String("QPushButton#pastHistorylab\n"
"{\n"
"border-image: url(:/res/MainWindow/pastHistory_normal.png);\n"
"}\n"
"QPushButton#pastHistorylab:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/pastHistory_hover.png);\n"
"}\n"
"QPushButton#pastHistorylab:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/pastHistory_pressed.png);\n"
"}"));

        horizontalLayout_6->addWidget(pastHistorylab);

        familuyHistorylab = new QPushButton(widget);
        familuyHistorylab->setObjectName(QStringLiteral("familuyHistorylab"));
        familuyHistorylab->setMinimumSize(QSize(60, 60));
        familuyHistorylab->setMaximumSize(QSize(60, 60));
        familuyHistorylab->setStyleSheet(QLatin1String("QPushButton#familuyHistorylab\n"
"{\n"
"border-image: url(:/res/MainWindow/familyHistory_normal.png);\n"
"}\n"
"QPushButton#familuyHistorylab:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/familyHistory_hover.png);\n"
"}\n"
"QPushButton#familuyHistorylab:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/familyHistory_pressed.png);\n"
"}"));

        horizontalLayout_6->addWidget(familuyHistorylab);

        heredityHistorylab = new QPushButton(widget);
        heredityHistorylab->setObjectName(QStringLiteral("heredityHistorylab"));
        heredityHistorylab->setMinimumSize(QSize(60, 60));
        heredityHistorylab->setMaximumSize(QSize(60, 60));
        heredityHistorylab->setStyleSheet(QLatin1String("QPushButton#heredityHistorylab\n"
"{\n"
"border-image: url(:/res/MainWindow/heredityHistory_normal.png);\n"
"}\n"
"QPushButton#heredityHistorylab:hover\n"
"{\n"
"border-image: url(:/res/MainWindow/heredityHistory_hover.png);\n"
"}\n"
"QPushButton#heredityHistorylab:pressed\n"
"{\n"
"border-image: url(:/res/MainWindow/heredityHistory_pressed.png);\n"
"}"));

        horizontalLayout_6->addWidget(heredityHistorylab);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(40);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(80, 20));
        label_5->setMaximumSize(QSize(80, 20));
        label_5->setStyleSheet(QLatin1String("QLabel#label_5\n"
"{\n"
"	width: 80px;\n"
"	height: 17px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_5->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(50, 20));
        label_6->setMaximumSize(QSize(60, 20));
        label_6->setStyleSheet(QLatin1String("QLabel#label_6\n"
"{\n"
"	width: 80px;\n"
"	height: 17px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_5->addWidget(label_6);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(50, 20));
        label_7->setMaximumSize(QSize(60, 20));
        label_7->setStyleSheet(QLatin1String("QLabel#label_7\n"
"{\n"
"	width: 80px;\n"
"	height: 17px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_5->addWidget(label_7);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(60, 20));
        label_8->setMaximumSize(QSize(65, 20));
        label_8->setStyleSheet(QLatin1String("QLabel#label_8\n"
"{\n"
"	width: 65px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_5->addWidget(label_8);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(widget);

        reportTabWidget = new QTabWidget(centreWidget);
        reportTabWidget->setObjectName(QStringLiteral("reportTabWidget"));
        reportTabWidget->setMinimumSize(QSize(0, 0));
        reportTabWidget->setMaximumSize(QSize(4800, 2000));
        reportTabWidget->setStyleSheet(QLatin1String("QTabWidget:pane{ \n"
"border: 1px solid #e9eaef; \n"
"top: -1px;\n"
"background-color:white;\n"
"}\n"
"QTabWidget::tab-bar\n"
"{\n"
"width:360;\n"
"}\n"
"QTabBar::tab{\n"
"left:4px;\n"
"font-family: MicrosoftYaHei;\n"
"font-size: 16px;\n"
"line-height: 20px;\n"
"color: #666666;\n"
"height:40px; \n"
"width:100px;\n"
"margin-right: 2px;\n"
"margin-bottom:-2px;\n"
"}\n"
"QTabBar::tab:hover{\n"
"background:rgb(255, 255, 255, 100);\n"
"}\n"
"QTabBar::tab:selected{\n"
"border:1px solid #e9eaef;\n"
"border-top-right-radius: 4px;\n"
"border-top-left-radius: 4px;\n"
"color: #6489d9;\n"
"border-bottom-color: none;\n"
"background:white;\n"
"}\n"
"QTabBar::tab:!selected{\n"
"border-bottom: 1px solid #e9eaef;;\n"
"}\n"
"\n"
"QWidget#focus\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#offline\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#lately\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#history\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidge"
                        "t#remote\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        lately = new QWidget();
        lately->setObjectName(QStringLiteral("lately"));
        verticalLayout_15 = new QVBoxLayout(lately);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 15, 0, 0);
        lately_tableview = new QTableView(lately);
        lately_tableview->setObjectName(QStringLiteral("lately_tableview"));
        lately_tableview->setStyleSheet(QStringLiteral(""));

        verticalLayout_15->addWidget(lately_tableview);

        reportTabWidget->addTab(lately, QString());
        history = new QWidget();
        history->setObjectName(QStringLiteral("history"));
        verticalLayout_18 = new QVBoxLayout(history);
        verticalLayout_18->setSpacing(20);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, -1);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(15);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(20, -1, 20, -1);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(15);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_18 = new QLabel(history);
        label_18->setObjectName(QStringLiteral("label_18"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(65, 20));
        label_18->setStyleSheet(QLatin1String("QLabel#label_18\n"
"{\n"
"font-family: MicrosoftYaHei;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"color:#333333;\n"
"}"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(label_18);

        typeBtn = new QToolButton(history);
        typeBtn->setObjectName(QStringLiteral("typeBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(typeBtn->sizePolicy().hasHeightForWidth());
        typeBtn->setSizePolicy(sizePolicy1);
        typeBtn->setMinimumSize(QSize(16, 8));
        typeBtn->setMaximumSize(QSize(20, 36));
        typeBtn->setStyleSheet(QLatin1String("QToolButton#typeBtn\n"
"{\n"
"width:200;\n"
"height:10;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"image: url(:/res/MainWindow/dropup.png);\n"
"}"));

        horizontalLayout_16->addWidget(typeBtn);

        label_19 = new QLabel(history);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(65, 20));
        label_19->setStyleSheet(QLatin1String("QLabel#label_19\n"
"{\n"
"font-family: MicrosoftYaHei;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"color:#333333;\n"
"}"));

        horizontalLayout_16->addWidget(label_19);

        typeCombox = new QComboBox(history);
        typeCombox->addItem(QString());
        typeCombox->addItem(QString());
        typeCombox->setObjectName(QStringLiteral("typeCombox"));
        typeCombox->setMinimumSize(QSize(150, 36));
        typeCombox->setMaximumSize(QSize(150, 16777215));
        typeCombox->setStyleSheet(QLatin1String("QComboBox#typeCombox\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: 1px solid #c1c2c6;\n"
"	color: #333333;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 24px;\n"
"}\n"
"\n"
"QComboBox#typeCombox::down-arrow\n"
"{\n"
"image: url(:/res/MainWindow/dropup.png);\n"
"}\n"
"\n"
"QComboBox#typeCombox::drop-down\n"
"{\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position:right center;\n"
"  width: 15px;\n"
"	height:8px;\n"
"      border-left-width: 1px;\n"
"      border-left-color: darkgray;\n"
"      border-left-style: solid;\n"
"      border-top-right-radius: 3px;\n"
"      border-bottom-right-radius: 3px;\n"
"	border-image: url(:/res/MainWindow/dropup.png);\n"
"}\n"
"QComboBox QAbstractItemView \n"
"{\n"
"	border: 2px solid darkgray;\n"
"    selection-background-color: lightgray;\n"
"	height:200\n"
"\n"
"    background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: 1px solid #c1c2c6;\n"
"	color: #333333;\n"
"	font-family: MicrosoftYaHei;\n"
"	fon"
                        "t-size: 14px;\n"
"	line-height: 24px;\n"
"}"));

        horizontalLayout_16->addWidget(typeCombox);


        horizontalLayout_17->addLayout(horizontalLayout_16);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(15);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_20 = new QLabel(history);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(30, 20));
        label_20->setMaximumSize(QSize(60, 16777215));
        label_20->setStyleSheet(QLatin1String("QLabel#label_19\n"
"{\n"
"font-family: MicrosoftYaHei;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"color:#333333;\n"
"}"));

        horizontalLayout_15->addWidget(label_20);

        his_fromDate = new QDateEdit(history);
        his_fromDate->setObjectName(QStringLiteral("his_fromDate"));
        his_fromDate->setMinimumSize(QSize(135, 40));
        his_fromDate->setMaximumSize(QSize(135, 40));
        his_fromDate->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: #c1c2c6;\n"
"spacing: 5px;\n"
"border-radius: 4px;\n"
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
        his_fromDate->setWrapping(false);
        his_fromDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        his_fromDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        his_fromDate->setProperty("showGroupSeparator", QVariant(false));
        his_fromDate->setCurrentSection(QDateTimeEdit::DaySection);
        his_fromDate->setCalendarPopup(true);
        his_fromDate->setDate(QDate(2019, 4, 9));

        horizontalLayout_15->addWidget(his_fromDate);

        label_21 = new QLabel(history);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(21, 0));
        label_21->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_15->addWidget(label_21);

        his_toDate = new QDateEdit(history);
        his_toDate->setObjectName(QStringLiteral("his_toDate"));
        his_toDate->setMinimumSize(QSize(135, 40));
        his_toDate->setMaximumSize(QSize(135, 40));
        his_toDate->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: #c1c2c6;\n"
"spacing: 5px;\n"
"border-radius: 4px;\n"
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
        his_toDate->setWrapping(false);
        his_toDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        his_toDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        his_toDate->setProperty("showGroupSeparator", QVariant(false));
        his_toDate->setCurrentSection(QDateTimeEdit::DaySection);
        his_toDate->setCalendarPopup(true);
        his_toDate->setDate(QDate(2019, 4, 9));

        horizontalLayout_15->addWidget(his_toDate);


        horizontalLayout_17->addLayout(horizontalLayout_15);


        verticalLayout_18->addLayout(horizontalLayout_17);

        history_tableview = new QTableView(history);
        history_tableview->setObjectName(QStringLiteral("history_tableview"));
        history_tableview->setStyleSheet(QStringLiteral(""));

        verticalLayout_18->addWidget(history_tableview);

        reportTabWidget->addTab(history, QString());
        remote = new QWidget();
        remote->setObjectName(QStringLiteral("remote"));
        verticalLayout_5 = new QVBoxLayout(remote);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(20);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(20, -1, 20, -1);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_22 = new QLabel(remote);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(65, 20));
        label_22->setStyleSheet(QLatin1String("QLabel#label_22\n"
"{\n"
"font-family: MicrosoftYaHei;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"color:#333333;\n"
"}"));

        horizontalLayout_10->addWidget(label_22);

        departCombox = new QComboBox(remote);
        departCombox->setObjectName(QStringLiteral("departCombox"));
        departCombox->setMinimumSize(QSize(150, 36));
        departCombox->setMaximumSize(QSize(150, 16777215));
        departCombox->setStyleSheet(QLatin1String("QComboBox#departCombox\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: 1px solid #c1c2c6;\n"
"	color: #333333;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 24px;\n"
"}\n"
"\n"
"QComboBox#departCombox::down-arrow\n"
"{\n"
"image: url(:/res/MainWindow/dropup.png);\n"
"}\n"
"QComboBox#departCombox::drop-down\n"
"{\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position:right center;\n"
"  width: 15px;\n"
"	height:8px;\n"
"      border-left-width: 1px;\n"
"      border-left-color: darkgray;\n"
"      border-left-style: solid;\n"
"      border-top-right-radius: 3px;\n"
"      border-bottom-right-radius: 3px;\n"
"	border-image: url(:/res/MainWindow/dropup.png);\n"
"}\n"
"QComboBox QAbstractItemView \n"
"{\n"
"height:50\n"
"\n"
"    background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border: 1px solid #c1c2c6;\n"
"	color: #333333;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 24px;\n"
"}"));

        horizontalLayout_10->addWidget(departCombox);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);


        horizontalLayout_20->addLayout(horizontalLayout_10);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_7);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_23 = new QLabel(remote);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setMinimumSize(QSize(65, 20));
        label_23->setMaximumSize(QSize(60, 16777215));
        label_23->setStyleSheet(QLatin1String("QLabel#label_23\n"
"{\n"
"font-family: MicrosoftYaHei;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"color:#333333;\n"
"}"));
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_23);

        rmt_fromDate = new QDateEdit(remote);
        rmt_fromDate->setObjectName(QStringLiteral("rmt_fromDate"));
        rmt_fromDate->setMinimumSize(QSize(135, 40));
        rmt_fromDate->setMaximumSize(QSize(135, 40));
        rmt_fromDate->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: #c1c2c6;\n"
"spacing: 5px;\n"
"border-radius: 4px;\n"
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
        rmt_fromDate->setWrapping(false);
        rmt_fromDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        rmt_fromDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        rmt_fromDate->setProperty("showGroupSeparator", QVariant(false));
        rmt_fromDate->setCurrentSection(QDateTimeEdit::DaySection);
        rmt_fromDate->setCalendarPopup(true);
        rmt_fromDate->setDate(QDate(2019, 4, 9));

        horizontalLayout_18->addWidget(rmt_fromDate);

        label_24 = new QLabel(remote);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(21, 0));
        label_24->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_18->addWidget(label_24);

        rmt_fromDate_3 = new QDateEdit(remote);
        rmt_fromDate_3->setObjectName(QStringLiteral("rmt_fromDate_3"));
        rmt_fromDate_3->setMinimumSize(QSize(135, 40));
        rmt_fromDate_3->setMaximumSize(QSize(135, 40));
        rmt_fromDate_3->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: #c1c2c6;\n"
"spacing: 5px;\n"
"border-radius: 4px;\n"
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
        rmt_fromDate_3->setWrapping(false);
        rmt_fromDate_3->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        rmt_fromDate_3->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        rmt_fromDate_3->setProperty("showGroupSeparator", QVariant(false));
        rmt_fromDate_3->setCurrentSection(QDateTimeEdit::DaySection);
        rmt_fromDate_3->setCalendarPopup(true);
        rmt_fromDate_3->setDate(QDate(2019, 4, 9));

        horizontalLayout_18->addWidget(rmt_fromDate_3);


        horizontalLayout_20->addLayout(horizontalLayout_18);


        verticalLayout_5->addLayout(horizontalLayout_20);

        remote_tableview = new QTableView(remote);
        remote_tableview->setObjectName(QStringLiteral("remote_tableview"));

        verticalLayout_5->addWidget(remote_tableview);

        reportTabWidget->addTab(remote, QString());

        verticalLayout_4->addWidget(reportTabWidget);


        horizontalLayout_13->addWidget(centreWidget);

        rightWidget = new QWidget(MainWindow);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setMinimumSize(QSize(579, 891));
        rightWidget->setMaximumSize(QSize(2500, 166666));
        rightWidget->setStyleSheet(QLatin1String("QWidget#rightWidget\n"
"{\n"
"background-color: #f1f2f6;\n"
"}"));
        verticalLayout_11 = new QVBoxLayout(rightWidget);
        verticalLayout_11->setSpacing(20);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(rightWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(20);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(20, 20, 20, 20);
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(600, 0));
        frame_2->setMaximumSize(QSize(970, 50));
        frame_2->setStyleSheet(QLatin1String("QFrame#frame_2\n"
"{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	border:1px;\n"
"	border-bottom: 1px solid #e9eaef;\n"
"}"));
        frame_2->setLineWidth(1);
        frame_2->setMidLineWidth(0);
        horizontalLayout_8 = new QHBoxLayout(frame_2);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(6, 30));
        label_9->setMaximumSize(QSize(6, 150));
        label_9->setStyleSheet(QLatin1String("QLabel#label_9\n"
"{\n"
"	background-color: #6489d9;\n"
"}"));

        horizontalLayout_8->addWidget(label_9);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(101, 36));
        label_10->setStyleSheet(QLatin1String("QLabel#label_10\n"
"{\n"
"	width: 96px;\n"
"	height: 23px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_8->addWidget(label_10);

        horizontalSpacer_2 = new QSpacerItem(590, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_7->addWidget(frame_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(20);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        docImagelab = new QLabel(widget_2);
        docImagelab->setObjectName(QStringLiteral("docImagelab"));
        docImagelab->setMinimumSize(QSize(80, 110));
        docImagelab->setMaximumSize(QSize(80, 110));
        docImagelab->setStyleSheet(QStringLiteral(""));
        docImagelab->setPixmap(QPixmap(QString::fromUtf8(":/res/MainWindow/doctor.png")));

        horizontalLayout_12->addWidget(docImagelab);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(1, 90));
        label_11->setMaximumSize(QSize(1, 90));
        label_11->setStyleSheet(QLatin1String("QLabel#label_11\n"
"{\n"
"	background-color: #e1e2e6\n"
"}"));

        horizontalLayout_12->addWidget(label_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(20);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(20);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        phoneBtn = new QPushButton(widget_2);
        phoneBtn->setObjectName(QStringLiteral("phoneBtn"));
        phoneBtn->setMinimumSize(QSize(40, 40));
        phoneBtn->setMaximumSize(QSize(40, 40));
        phoneBtn->setStyleSheet(QLatin1String("QPushButton#phoneBtn\n"
"{	\n"
"	border-image: url(:/res/MainWindow/phone_normal.png);\n"
"}\n"
"QPushButton#phoneBtn:hover\n"
"{	\n"
"	border-image: url(:/res/MainWindow/phone_hover.png);\n"
"}\n"
"QPushButton#phoneBtn:pressed\n"
"{	\n"
"	border-image: url(:/res/MainWindow/phone_pressed.png);\n"
"}"));

        horizontalLayout_9->addWidget(phoneBtn);

        phoneLab = new QLabel(widget_2);
        phoneLab->setObjectName(QStringLiteral("phoneLab"));
        phoneLab->setMinimumSize(QSize(149, 21));
        phoneLab->setStyleSheet(QLatin1String("QLabel#phoneLab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_9->addWidget(phoneLab);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(20);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        hospitalBtn = new QPushButton(widget_2);
        hospitalBtn->setObjectName(QStringLiteral("hospitalBtn"));
        hospitalBtn->setMinimumSize(QSize(40, 40));
        hospitalBtn->setMaximumSize(QSize(40, 40));
        hospitalBtn->setStyleSheet(QLatin1String("QPushButton#hospitalBtn\n"
"{		\n"
"	border-image: url(:/res/MainWindow/hospital_normal.png);\n"
"}\n"
"QPushButton#hospitalBtn:hover\n"
"{	\n"
"	border-image: url(:/res/MainWindow/hospital_hover.png);\n"
"}\n"
"QPushButton#hospitalBtn:pressed\n"
"{	\n"
"	border-image: url(:/res/MainWindow/hospital_pressed.png);\n"
"}"));

        horizontalLayout_11->addWidget(hospitalBtn);

        hospitallab = new QLabel(widget_2);
        hospitallab->setObjectName(QStringLiteral("hospitallab"));
        hospitallab->setMinimumSize(QSize(111, 21));
        hospitallab->setStyleSheet(QLatin1String("QLabel#hospitallab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_11->addWidget(hospitallab);


        verticalLayout_6->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(83, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);


        verticalLayout_7->addLayout(horizontalLayout_12);


        verticalLayout_11->addWidget(widget_2);

        widget_4 = new QWidget(rightWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QLatin1String("QWidget#widget_4\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(widget_4);
        verticalLayout_10->setSpacing(20);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(20, 0, 20, 20);
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(2550, 16777215));
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3\n"
"{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(widget_3);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(widget_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setStyleSheet(QLatin1String("QTabWidget#tabWidget_2\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QTabWidget::pane \n"
"{ \n"
"   	border-top: 1px solid #C2C7CB;\n"
"}\n"
"\n"
"QTabWidget::tab-bar \n"
"{ \n"
"    width:400;\n"
"}\n"
"QTabBar::tab \n"
"{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #666666;\n"
"    min-width:10ex;\n"
"    padding:1px;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;	\n"
"	width:100;\n"
"	height:40;\n"
"	border-bottom: 4px solid 6489d9;\n"
"}\n"
"QWidget#telltionWidget\n"
"{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#diagnoseWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#disposeWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#prescriptionWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
""
                        "}"));
        telltionWidget = new QWidget();
        telltionWidget->setObjectName(QStringLiteral("telltionWidget"));
        verticalLayout_9 = new QVBoxLayout(telltionWidget);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 25, 0, 0);
        telltionEdit = new QTextEdit(telltionWidget);
        telltionEdit->setObjectName(QStringLiteral("telltionEdit"));
        telltionEdit->setStyleSheet(QLatin1String("QTextEdit#telltionEdit\n"
"{\n"
"	background-color: #f1f2f6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #c1c2c6;\n"
"}"));

        verticalLayout_9->addWidget(telltionEdit);

        tabWidget_2->addTab(telltionWidget, QString());
        diagnoseWidget = new QWidget();
        diagnoseWidget->setObjectName(QStringLiteral("diagnoseWidget"));
        verticalLayout_16 = new QVBoxLayout(diagnoseWidget);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 25, 0, 0);
        remark = new QTextEdit(diagnoseWidget);
        remark->setObjectName(QStringLiteral("remark"));
        remark->setStyleSheet(QLatin1String("QTextEdit#remark\n"
"{\n"
"background-color: #f1f2f6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #c1c2c6;\n"
"}"));

        verticalLayout_16->addWidget(remark);

        tabWidget_2->addTab(diagnoseWidget, QString());
        disposeWidget = new QWidget();
        disposeWidget->setObjectName(QStringLiteral("disposeWidget"));
        verticalLayout_17 = new QVBoxLayout(disposeWidget);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 25, 0, 0);
        disposeEdit = new QTextEdit(disposeWidget);
        disposeEdit->setObjectName(QStringLiteral("disposeEdit"));
        disposeEdit->setStyleSheet(QLatin1String("QTextEdit#disposeEdit\n"
"{\n"
"background-color: #f1f2f6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #c1c2c6;\n"
"}"));

        verticalLayout_17->addWidget(disposeEdit);

        tabWidget_2->addTab(disposeWidget, QString());
        prescriptionWidget = new QWidget();
        prescriptionWidget->setObjectName(QStringLiteral("prescriptionWidget"));
        verticalLayout_20 = new QVBoxLayout(prescriptionWidget);
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(0, 25, 0, 0);
        prescription = new QTextEdit(prescriptionWidget);
        prescription->setObjectName(QStringLiteral("prescription"));
        prescription->setStyleSheet(QLatin1String("QTextEdit#prescription\n"
"{\n"
"	background-color: #f1f2f6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #c1c2c6;\n"
"}"));

        verticalLayout_20->addWidget(prescription);

        tabWidget_2->addTab(prescriptionWidget, QString());

        verticalLayout_8->addWidget(tabWidget_2);


        verticalLayout_10->addWidget(widget_3);

        label_12 = new QLabel(widget_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setStyleSheet(QLatin1String("QLabel#label_12\n"
"{\n"
"	width: 135px;\n"
"	height: 17px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        verticalLayout_10->addWidget(label_12);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        templateBtn = new QToolButton(widget_4);
        templateBtn->setObjectName(QStringLiteral("templateBtn"));
        templateBtn->setMinimumSize(QSize(150, 36));
        templateBtn->setMaximumSize(QSize(16777215, 36));
        templateBtn->setStyleSheet(QLatin1String("QToolButton#templateBtn\n"
"{		\n"
"	\n"
"	border-image: url(:/res/MainWindow/btemplate_normal.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QToolButton#templateBtn:hover\n"
"{	\n"
"border-image: url(:/res/MainWindow/btemplate_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
""));

        horizontalLayout_19->addWidget(templateBtn);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_10);

        templateBtn_2 = new QToolButton(widget_4);
        templateBtn_2->setObjectName(QStringLiteral("templateBtn_2"));
        templateBtn_2->setMinimumSize(QSize(150, 36));
        templateBtn_2->setMaximumSize(QSize(16777215, 36));
        templateBtn_2->setStyleSheet(QLatin1String("QToolButton#templateBtn_2\n"
"{		\n"
"	border-image: url(:/res/MainWindow/ytemplate_normal.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#templateBtn_2:hover\n"
"{			\n"
"	\n"
"	border-image: url(:/res/MainWindow/ytemplate_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
""));

        horizontalLayout_19->addWidget(templateBtn_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_11);

        templateBtn_3 = new QToolButton(widget_4);
        templateBtn_3->setObjectName(QStringLiteral("templateBtn_3"));
        templateBtn_3->setMinimumSize(QSize(150, 36));
        templateBtn_3->setMaximumSize(QSize(16777215, 36));
        templateBtn_3->setStyleSheet(QLatin1String("QToolButton#templateBtn_3\n"
"{		\n"
"border-image: url(:/res/MainWindow/rtemplate_normal.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#templateBtn_3:hover\n"
"{		\n"
"border-image: url(:/res/MainWindow/rtemplaste_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.79px;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
""));

        horizontalLayout_19->addWidget(templateBtn_3);


        verticalLayout_10->addLayout(horizontalLayout_19);

        verticalLayout_10->setStretch(0, 20);
        verticalLayout_10->setStretch(1, 1);
        verticalLayout_10->setStretch(2, 3);

        verticalLayout_11->addWidget(widget_4);


        horizontalLayout_13->addWidget(rightWidget);


        verticalLayout_12->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_12);


        verticalLayout_13->addLayout(horizontalLayout_14);

        versionWidget = new QWidget(MainWindow);
        versionWidget->setObjectName(QStringLiteral("versionWidget"));
        versionWidget->setMinimumSize(QSize(0, 25));
        versionWidget->setMaximumSize(QSize(1920, 25));
        versionWidget->setStyleSheet(QLatin1String("QWidget#versionWidget\n"
"{\n"
"border-image: url(:/res/MainWindow/version.png);\n"
"}"));

        verticalLayout_13->addWidget(versionWidget);


        verticalLayout_14->addLayout(verticalLayout_13);


        retranslateUi(MainWindow);

        reportTabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        dateTimelab->setText(QApplication::translate("MainWindow", "YYYY-MM-DD hh-mm-ss", nullptr));
        expertshospital->setText(QApplication::translate("MainWindow", "\346\237\220\346\237\220\351\225\207\345\215\253\347\224\237\351\231\242", nullptr));
        doctorNamelab->setText(QApplication::translate("MainWindow", "\344\271\241\351\225\207\345\214\273\347\224\237", nullptr));
        dropupBtn->setText(QString());
        exitBtn->setText(QString());
        label->setText(QString());
        minBtn->setText(QString());
        maxBtn->setText(QString());
        closeBtn->setText(QString());
        expandBtn->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        patientStatelab->setText(QApplication::translate("MainWindow", "\345\200\231\350\257\212\346\227\266\351\225\277 00:00", nullptr));
        callNextBtn->setText(QApplication::translate("MainWindow", "\345\217\253\345\217\267", nullptr));
        videoBtn->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        completeBtn->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220", nullptr));
        pauseBtn->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        headImagelab->setText(QString());
        patNamelab->setText(QApplication::translate("MainWindow", "------", nullptr));
        patSex->setText(QApplication::translate("MainWindow", "\357\274\210\346\234\252\347\237\245\357\274\211", nullptr));
        patAgelab->setText(QApplication::translate("MainWindow", "----", nullptr));
        dateOfBirthlab->setText(QApplication::translate("MainWindow", "---------", nullptr));
        label_4->setText(QString());
        allergyBtn->setText(QString());
        pastHistorylab->setText(QString());
        familuyHistorylab->setText(QString());
        heredityHistorylab->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\350\215\257\347\211\251\350\277\207\346\225\217\345\217\262", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\227\242\345\276\200\345\217\262", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\256\266\346\227\217\345\217\262", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\351\201\227\344\274\240\347\227\205\345\217\262", nullptr));
        reportTabWidget->setTabText(reportTabWidget->indexOf(lately), QApplication::translate("MainWindow", "\350\277\221\346\234\237\346\243\200\346\237\245\346\212\245\345\221\212", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\345\244\247\347\261\273\345\220\215\347\247\260", nullptr));
        typeBtn->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\261\273\345\236\213", nullptr));
        typeCombox->setItemText(0, QApplication::translate("MainWindow", "\345\205\250\351\203\250", nullptr));
        typeCombox->setItemText(1, QApplication::translate("MainWindow", "\347\254\254\344\272\214\351\241\271", nullptr));

        label_20->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237:", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "--", nullptr));
        reportTabWidget->setTabText(reportTabWidget->indexOf(history), QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\243\200\346\237\245\346\212\245\345\221\212", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\345\260\261\350\257\212\347\247\221\345\256\244\357\274\232", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237\357\274\232", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "--", nullptr));
        reportTabWidget->setTabText(reportTabWidget->indexOf(remote), QApplication::translate("MainWindow", "\350\277\234\347\250\213\351\227\250\350\257\212\346\212\245\345\221\212", nullptr));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\344\270\223\345\256\266\344\277\241\346\201\257", nullptr));
        docImagelab->setText(QString());
        label_11->setText(QString());
        phoneBtn->setText(QString());
        phoneLab->setText(QApplication::translate("MainWindow", "-----------", nullptr));
        hospitalBtn->setText(QString());
        hospitallab->setText(QApplication::translate("MainWindow", "--------", nullptr));
        telltionEdit->setPlaceholderText(QApplication::translate("MainWindow", "\346\202\243\350\200\205\344\270\273\350\257\211", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(telltionWidget), QApplication::translate("MainWindow", "\346\202\243\350\200\205\344\270\273\350\257\211", nullptr));
        remark->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MicrosoftYaHei'; font-size:16px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        remark->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\257\212\346\226\255\345\273\272\350\256\256", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(diagnoseWidget), QApplication::translate("MainWindow", "\350\257\212\346\226\255\345\273\272\350\256\256", nullptr));
        disposeEdit->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\244\204\347\220\206\345\273\272\350\256\256", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(disposeWidget), QApplication::translate("MainWindow", "\345\244\204\347\220\206\345\273\272\350\256\256", nullptr));
        prescription->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\244\204\346\226\271\345\273\272\350\256\256", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(prescriptionWidget), QApplication::translate("MainWindow", "\345\244\204\346\226\271\345\273\272\350\256\256", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\345\270\270\347\224\250\346\202\243\350\200\205\344\270\273\350\257\211\346\250\241\347\211\210\357\274\232", nullptr));
        templateBtn->setText(QApplication::translate("MainWindow", "\346\250\241\346\235\277\344\270\200", nullptr));
        templateBtn_2->setText(QApplication::translate("MainWindow", "\346\250\241\346\235\277\344\272\214", nullptr));
        templateBtn_3->setText(QApplication::translate("MainWindow", "\346\250\241\346\235\277\344\270\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

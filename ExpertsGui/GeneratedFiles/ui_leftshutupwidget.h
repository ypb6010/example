/********************************************************************************
** Form generated from reading UI file 'LeftShutupWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTSHUTUPWIDGET_H
#define UI_LEFTSHUTUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../MedicalWidget/TitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_LeftShutupWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    TitleBar *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QToolButton *startShutStateBtn;
    QToolButton *leaveShutStateBtn;
    QToolButton *stopShutStateBtn;
    QLabel *label;
    QWidget *shutupShowWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *currentNamelab;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLabel *nextNamelab;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *LeftShutupWidget)
    {
        if (LeftShutupWidget->objectName().isEmpty())
            LeftShutupWidget->setObjectName(QStringLiteral("LeftShutupWidget"));
        LeftShutupWidget->resize(120, 980);
        LeftShutupWidget->setMinimumSize(QSize(75, 980));
        LeftShutupWidget->setMaximumSize(QSize(120, 4800));
        LeftShutupWidget->setStyleSheet(QLatin1String("QWidget#LeftShutupWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(LeftShutupWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(LeftShutupWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new TitleBar(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"border-image: url(:/res/leftShutup/shutupTitle.png);\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(40, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(40, 40));
        label_4->setMaximumSize(QSize(40, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/res/login/logo.png")));

        verticalLayout_3->addWidget(label_4);


        verticalLayout_4->addWidget(widget);

        verticalSpacer_2 = new QSpacerItem(20, 280, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        startShutStateBtn = new QToolButton(widget_2);
        startShutStateBtn->setObjectName(QStringLiteral("startShutStateBtn"));
        startShutStateBtn->setEnabled(true);
        startShutStateBtn->setMinimumSize(QSize(60, 40));
        startShutStateBtn->setMaximumSize(QSize(60, 40));
        startShutStateBtn->setStyleSheet(QLatin1String("QToolButton#startShutStateBtn\n"
"{\n"
"	border-image: url(:/res/leftShutup/startShutState_normal.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#startShutStateBtn:hover\n"
"{\n"
"	border-image: url(:/res/leftShutup/startShutState_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButtonn#startShutStateBtn:pressed\n"
"{\n"
"border-image: url(:/res/leftShutup/startShutState_pressed.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#startShutStateBtn:disabled\n"
"{\n"
"	border-image: url(:/res/leftShutup/shutup_disabled.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}"));

        verticalLayout_2->addWidget(startShutStateBtn);

        leaveShutStateBtn = new QToolButton(widget_2);
        leaveShutStateBtn->setObjectName(QStringLiteral("leaveShutStateBtn"));
        leaveShutStateBtn->setEnabled(false);
        leaveShutStateBtn->setMinimumSize(QSize(60, 40));
        leaveShutStateBtn->setMaximumSize(QSize(60, 40));
        leaveShutStateBtn->setStyleSheet(QLatin1String("QToolButton#leaveShutStateBtn\n"
"{		\n"
"	border-image: url(:/res/leftShutup/leaverShutState_normal.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;	\n"
"	line-height: 20px;	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveShutStateBtn:hover\n"
"{\n"
"	border-image: url(:/res/leftShutup/leaverShutState_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;	\n"
"	line-height: 20px;	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveShutStateBtn:pressed\n"
"{\n"
"	border-image: url(:/res/leftShutup/leaverShutState_pressed.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;	\n"
"	line-height: 20px;	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveShutStateBtn:disabled\n"
"{\n"
"	border-image: url(:/res/leftShutup/shutup_disabled.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;	\n"
"	line-height: 20px;	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveShutStateBtn:checked\n"
"{	\n"
"	border-image: url(:/res/leftShutup/leave_checked_normal.png);\n"
"	font-family: Micro"
                        "softYaHei;\n"
"	font-size: 16px;	\n"
"	line-height: 20px;	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#leaveShutStateBtn:checked:hover\n"
"{	\n"
"	border-image: url(:/res/leftShutup/leave_checked_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;	\n"
"	line-height: 20px;	\n"
"	color: #ffffff;\n"
"}"));
        leaveShutStateBtn->setCheckable(true);

        verticalLayout_2->addWidget(leaveShutStateBtn);

        stopShutStateBtn = new QToolButton(widget_2);
        stopShutStateBtn->setObjectName(QStringLiteral("stopShutStateBtn"));
        stopShutStateBtn->setEnabled(false);
        stopShutStateBtn->setMinimumSize(QSize(60, 40));
        stopShutStateBtn->setMaximumSize(QSize(60, 40));
        stopShutStateBtn->setStyleSheet(QLatin1String("QToolButton#stopShutStateBtn\n"
"{\n"
"	border-image: url(:/res/leftShutup/startShutState_normal.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#stopShutStateBtn:hover\n"
"{	\n"
"	border-image: url(:/res/leftShutup/startShutState_hover.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#stopShutStateBtn:pressed\n"
"{\n"
"	border-image: url(:/res/leftShutup/startShutState_pressed.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}\n"
"QToolButton#stopShutStateBtn:disabled\n"
"{\n"
"	border-image: url(:/res/leftShutup/shutup_disabled.png);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	\n"
"	\n"
"	line-height: 20px;\n"
"	\n"
"	color: #ffffff;\n"
"}"));

        verticalLayout_2->addWidget(stopShutStateBtn);

        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 5));
        label->setMaximumSize(QSize(60, 5));
        label->setStyleSheet(QLatin1String("QLabel#label\n"
"{\n"
"background-color: #e1e2e6;\n"
"}"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/leftShutup/line.png")));

        verticalLayout_2->addWidget(label);

        shutupShowWidget = new QWidget(widget_2);
        shutupShowWidget->setObjectName(QStringLiteral("shutupShowWidget"));
        shutupShowWidget->setMinimumSize(QSize(60, 130));
        shutupShowWidget->setMaximumSize(QSize(60, 130));
        shutupShowWidget->setStyleSheet(QLatin1String("QWidget#shutupShowWidget\n"
"{\n"
"	\n"
"	border-image: url(:/res/leftShutup/display_card.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(shutupShowWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(shutupShowWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(29, 12));
        label_2->setMaximumSize(QSize(60, 12));
        label_2->setStyleSheet(QLatin1String("QLabel#label_2\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        currentNamelab = new QLabel(shutupShowWidget);
        currentNamelab->setObjectName(QStringLiteral("currentNamelab"));
        currentNamelab->setStyleSheet(QLatin1String("QLabel#currentNamelab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        currentNamelab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(currentNamelab);

        verticalSpacer = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(shutupShowWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("QLabel#label_3\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        nextNamelab = new QLabel(shutupShowWidget);
        nextNamelab->setObjectName(QStringLiteral("nextNamelab"));
        nextNamelab->setStyleSheet(QLatin1String("QLabel#nextNamelab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        nextNamelab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nextNamelab);


        verticalLayout_2->addWidget(shutupShowWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 287, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        verticalLayout_5->addWidget(widget_2);


        retranslateUi(LeftShutupWidget);

        QMetaObject::connectSlotsByName(LeftShutupWidget);
    } // setupUi

    void retranslateUi(QWidget *LeftShutupWidget)
    {
        LeftShutupWidget->setWindowTitle(QApplication::translate("LeftShutupWidget", "LeftShutupWidget", nullptr));
        label_4->setText(QString());
        startShutStateBtn->setText(QApplication::translate("LeftShutupWidget", "\345\274\200\345\247\213", nullptr));
        leaveShutStateBtn->setText(QApplication::translate("LeftShutupWidget", "\347\246\273\345\274\200", nullptr));
        stopShutStateBtn->setText(QApplication::translate("LeftShutupWidget", "\347\273\223\346\235\237", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("LeftShutupWidget", "\345\275\223\345\211\215", nullptr));
        currentNamelab->setText(QApplication::translate("LeftShutupWidget", "-------", nullptr));
        label_3->setText(QApplication::translate("LeftShutupWidget", "\344\270\213\344\270\200\344\275\215", nullptr));
        nextNamelab->setText(QApplication::translate("LeftShutupWidget", "------", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeftShutupWidget: public Ui_LeftShutupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTSHUTUPWIDGET_H

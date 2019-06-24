/********************************************************************************
** Form generated from reading UI file 'ExpertsCallDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERTSCALLDIALOG_H
#define UI_EXPERTSCALLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "../MedicalWidget/TitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_CallAssistDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    TitleBar *titlewidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *titlelab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QFrame *patientFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *patientheadImage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *patName;
    QLabel *patSex;
    QSpacerItem *horizontalSpacer_8;
    QLabel *patAgelab;
    QLabel *patBirthlab;
    QSpacerItem *horizontalSpacer;
    QFrame *doctorFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *doctorheadImage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *doctorNamelab;
    QLabel *doctorSexlab;
    QSpacerItem *horizontalSpacer_6;
    QLabel *phonelab;
    QLabel *hospitallab;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *waitlab;
    QLabel *textlab;
    QLabel *waitlab_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QPushButton *doneBtn;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *CallAssistDialog)
    {
        if (CallAssistDialog->objectName().isEmpty())
            CallAssistDialog->setObjectName(QStringLiteral("CallAssistDialog"));
        CallAssistDialog->resize(1000, 393);
        CallAssistDialog->setMinimumSize(QSize(1000, 393));
        CallAssistDialog->setMaximumSize(QSize(16777215, 393));
        CallAssistDialog->setStyleSheet(QLatin1String("QDialog#CallAssistDialog\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        CallAssistDialog->setModal(false);
        verticalLayout_5 = new QVBoxLayout(CallAssistDialog);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        titlewidget = new TitleBar(CallAssistDialog);
        titlewidget->setObjectName(QStringLiteral("titlewidget"));
        titlewidget->setMaximumSize(QSize(16777215, 60));
        titlewidget->setStyleSheet(QLatin1String("QWidget#titlewidget\n"
"{\n"
"background-color: #6489d9;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(titlewidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titlelab = new QLabel(titlewidget);
        titlelab->setObjectName(QStringLiteral("titlelab"));
        titlelab->setStyleSheet(QLatin1String("QLabel#titlelab\n"
"{\n"
"	width: 96px;\n"
"	height: 23px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        titlelab->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(titlelab);


        verticalLayout_5->addWidget(titlewidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        patientFrame = new QFrame(CallAssistDialog);
        patientFrame->setObjectName(QStringLiteral("patientFrame"));
        patientFrame->setMinimumSize(QSize(480, 152));
        patientFrame->setStyleSheet(QLatin1String("QFrame#patientFrame\n"
"{\n"
"	border-right-color:none;\n"
"	border:1px solid #e1e2e6;\n"
"}"));
        patientFrame->setFrameShape(QFrame::StyledPanel);
        patientFrame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_2 = new QHBoxLayout(patientFrame);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 20, 0, 20);
        patientheadImage = new QLabel(patientFrame);
        patientheadImage->setObjectName(QStringLiteral("patientheadImage"));
        patientheadImage->setMinimumSize(QSize(80, 110));
        patientheadImage->setMaximumSize(QSize(80, 110));
        patientheadImage->setPixmap(QPixmap(QString::fromUtf8(":/res/MainWindow/Patdef.png")));

        horizontalLayout_2->addWidget(patientheadImage);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        patName = new QLabel(patientFrame);
        patName->setObjectName(QStringLiteral("patName"));
        patName->setMaximumSize(QSize(80, 30));
        patName->setStyleSheet(QLatin1String("QLabel#patName\n"
"{\n"
"	width: 110px;\n"
"	height: 24px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        patName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(patName);

        patSex = new QLabel(patientFrame);
        patSex->setObjectName(QStringLiteral("patSex"));
        patSex->setMaximumSize(QSize(50, 16777215));
        patSex->setStyleSheet(QLatin1String("QLabel#patSex\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	color: #333333;\n"
"}"));
        patSex->setScaledContents(false);
        patSex->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(patSex);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);

        patAgelab = new QLabel(patientFrame);
        patAgelab->setObjectName(QStringLiteral("patAgelab"));
        patAgelab->setMaximumSize(QSize(40, 20));
        patAgelab->setStyleSheet(QLatin1String("QLabel#patAgelab\n"
"{\n"
"	width: 33px;\n"
"	height: 15px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        patAgelab->setOpenExternalLinks(false);

        verticalLayout->addWidget(patAgelab);

        patBirthlab = new QLabel(patientFrame);
        patBirthlab->setObjectName(QStringLiteral("patBirthlab"));
        patBirthlab->setMinimumSize(QSize(81, 41));
        patBirthlab->setMaximumSize(QSize(100, 41));
        patBirthlab->setStyleSheet(QLatin1String("QLabel#patBirthlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        verticalLayout->addWidget(patBirthlab);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_5->addWidget(patientFrame);

        doctorFrame = new QFrame(CallAssistDialog);
        doctorFrame->setObjectName(QStringLiteral("doctorFrame"));
        doctorFrame->setMinimumSize(QSize(480, 152));
        doctorFrame->setStyleSheet(QLatin1String("QFrame#doctorFrame\n"
"{\n"
"	border:1px solid #e1e2e6;\n"
"}"));
        doctorFrame->setFrameShape(QFrame::StyledPanel);
        doctorFrame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(doctorFrame);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, 20, 0, 20);
        doctorheadImage = new QLabel(doctorFrame);
        doctorheadImage->setObjectName(QStringLiteral("doctorheadImage"));
        doctorheadImage->setMinimumSize(QSize(80, 110));
        doctorheadImage->setMaximumSize(QSize(80, 110));
        doctorheadImage->setPixmap(QPixmap(QString::fromUtf8(":/res/MainWindow/doctor.png")));

        horizontalLayout_3->addWidget(doctorheadImage);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(9);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        doctorNamelab = new QLabel(doctorFrame);
        doctorNamelab->setObjectName(QStringLiteral("doctorNamelab"));
        doctorNamelab->setMaximumSize(QSize(81, 30));
        doctorNamelab->setStyleSheet(QLatin1String("QLabel#doctorNamelab\n"
"{\n"
"	width: 110px;\n"
"	height: 24px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        doctorNamelab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(doctorNamelab);

        doctorSexlab = new QLabel(doctorFrame);
        doctorSexlab->setObjectName(QStringLiteral("doctorSexlab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doctorSexlab->sizePolicy().hasHeightForWidth());
        doctorSexlab->setSizePolicy(sizePolicy);
        doctorSexlab->setMaximumSize(QSize(50, 16777215));
        doctorSexlab->setStyleSheet(QLatin1String("QLabel#doctorSexlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	color: #333333;\n"
"}"));
        doctorSexlab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(doctorSexlab);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        phonelab = new QLabel(doctorFrame);
        phonelab->setObjectName(QStringLiteral("phonelab"));
        phonelab->setMinimumSize(QSize(80, 25));
        phonelab->setMaximumSize(QSize(80, 25));
        phonelab->setStyleSheet(QLatin1String("QLabel#phonelab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        phonelab->setOpenExternalLinks(false);

        verticalLayout_2->addWidget(phonelab);

        hospitallab = new QLabel(doctorFrame);
        hospitallab->setObjectName(QStringLiteral("hospitallab"));
        hospitallab->setMinimumSize(QSize(81, 41));
        hospitallab->setMaximumSize(QSize(230, 41));
        hospitallab->setStyleSheet(QLatin1String("QLabel#hospitallab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        verticalLayout_2->addWidget(hospitallab);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        horizontalLayout_5->addWidget(doctorFrame);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        waitlab = new QLabel(CallAssistDialog);
        waitlab->setObjectName(QStringLiteral("waitlab"));
        sizePolicy.setHeightForWidth(waitlab->sizePolicy().hasHeightForWidth());
        waitlab->setSizePolicy(sizePolicy);
        waitlab->setMinimumSize(QSize(0, 0));
        waitlab->setStyleSheet(QLatin1String("QLabel#waitlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        waitlab->setTextFormat(Qt::AutoText);
        waitlab->setWordWrap(false);

        horizontalLayout_6->addWidget(waitlab);

        textlab = new QLabel(CallAssistDialog);
        textlab->setObjectName(QStringLiteral("textlab"));
        textlab->setStyleSheet(QLatin1String("QLabel#textlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	color: #6489d9;\n"
"}\n"
""));

        horizontalLayout_6->addWidget(textlab);

        waitlab_2 = new QLabel(CallAssistDialog);
        waitlab_2->setObjectName(QStringLiteral("waitlab_2"));
        waitlab_2->setStyleSheet(QLatin1String("QLabel#waitlab_2\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_6->addWidget(waitlab_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        cancelBtn = new QPushButton(CallAssistDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setEnabled(false);
        cancelBtn->setMinimumSize(QSize(150, 36));
        cancelBtn->setMaximumSize(QSize(150, 36));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton#cancelBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #6489d9;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton#cancelBtn:disabled\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #c1c2c6;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout_7->addWidget(cancelBtn);

        okBtn = new QPushButton(CallAssistDialog);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setEnabled(true);
        okBtn->setMinimumSize(QSize(150, 36));
        okBtn->setMaximumSize(QSize(150, 36));
        okBtn->setStyleSheet(QLatin1String("QPushButton#okBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #6489d9;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton#okBtn:disabled\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #c1c2c6;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout_7->addWidget(okBtn);

        doneBtn = new QPushButton(CallAssistDialog);
        doneBtn->setObjectName(QStringLiteral("doneBtn"));
        doneBtn->setEnabled(true);
        doneBtn->setMinimumSize(QSize(150, 36));
        doneBtn->setMaximumSize(QSize(150, 36));
        doneBtn->setStyleSheet(QLatin1String("QPushButton#doneBtn\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #6489d9;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton#doneBtn:disabled\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #c1c2c6;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout_7->addWidget(doneBtn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(CallAssistDialog);
        QObject::connect(cancelBtn, SIGNAL(clicked()), CallAssistDialog, SLOT(reject()));
        QObject::connect(okBtn, SIGNAL(clicked()), CallAssistDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(CallAssistDialog);
    } // setupUi

    void retranslateUi(QDialog *CallAssistDialog)
    {
        CallAssistDialog->setWindowTitle(QApplication::translate("CallAssistDialog", "ExpertsCallDialog", nullptr));
        titlelab->setText(QApplication::translate("CallAssistDialog", "\345\260\261\350\257\212\345\272\224\347\255\224", nullptr));
        patientheadImage->setText(QString());
        patName->setText(QApplication::translate("CallAssistDialog", "\345\247\223\345\220\215", nullptr));
        patSex->setText(QApplication::translate("CallAssistDialog", "\357\274\210\345\245\263\357\274\211", nullptr));
        patAgelab->setText(QApplication::translate("CallAssistDialog", "\345\271\264\351\276\204", nullptr));
        patBirthlab->setText(QApplication::translate("CallAssistDialog", "yyyy-mm-dd", nullptr));
        doctorheadImage->setText(QString());
        doctorNamelab->setText(QApplication::translate("CallAssistDialog", "\345\247\223\345\220\215", nullptr));
        doctorSexlab->setText(QApplication::translate("CallAssistDialog", "\357\274\210\345\245\263\357\274\211", nullptr));
        phonelab->setText(QApplication::translate("CallAssistDialog", "18000000000", nullptr));
        hospitallab->setText(QApplication::translate("CallAssistDialog", "\346\211\200\345\261\236\345\214\273\351\231\242", nullptr));
        waitlab->setText(QApplication::translate("CallAssistDialog", "\346\202\250\345\260\232\351\234\200\347\255\211\345\276\205", nullptr));
        textlab->setText(QApplication::translate("CallAssistDialog", "60\347\247\222", nullptr));
        waitlab_2->setText(QApplication::translate("CallAssistDialog", "\346\226\271\345\217\257\350\277\207\345\217\267\350\257\245\346\202\243\350\200\205", nullptr));
        cancelBtn->setText(QApplication::translate("CallAssistDialog", "\350\277\207\345\217\267", nullptr));
        okBtn->setText(QApplication::translate("CallAssistDialog", "\347\241\256\345\256\232", nullptr));
        doneBtn->setText(QApplication::translate("CallAssistDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CallAssistDialog: public Ui_CallAssistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERTSCALLDIALOG_H

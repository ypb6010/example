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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpertsCallDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *titlewidget;
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
    QSpacerItem *horizontalSpacer_9;
    QLabel *depAndlev;
    QLabel *hospitallab;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *textlab;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *ExpertsCallDialog)
    {
        if (ExpertsCallDialog->objectName().isEmpty())
            ExpertsCallDialog->setObjectName(QStringLiteral("ExpertsCallDialog"));
        ExpertsCallDialog->resize(1000, 393);
        ExpertsCallDialog->setMinimumSize(QSize(1000, 393));
        ExpertsCallDialog->setMaximumSize(QSize(16777215, 393));
        ExpertsCallDialog->setStyleSheet(QLatin1String("QDialog#ExpertsCallDialog\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(ExpertsCallDialog);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        titlewidget = new QWidget(ExpertsCallDialog);
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
        patientFrame = new QFrame(ExpertsCallDialog);
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
        horizontalLayout_2->setContentsMargins(20, 20, 20, 20);
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
        patName->setMaximumSize(QSize(81, 30));
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
        patSex->setMaximumSize(QSize(35, 16777215));
        patSex->setStyleSheet(QLatin1String("QLabel#patSex\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	color: #333333;\n"
"}"));
        patSex->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(patSex);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);

        patAgelab = new QLabel(patientFrame);
        patAgelab->setObjectName(QStringLiteral("patAgelab"));
        patAgelab->setMaximumSize(QSize(100, 20));
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
        patBirthlab->setMaximumSize(QSize(130, 41));
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

        doctorFrame = new QFrame(ExpertsCallDialog);
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
        horizontalLayout_3->setContentsMargins(20, 20, 20, 20);
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
        doctorSexlab->setMaximumSize(QSize(40, 16777215));
        doctorSexlab->setStyleSheet(QLatin1String("QLabel#doctorSexlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	color: #333333;\n"
"}"));
        doctorSexlab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(doctorSexlab);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_4);

        depAndlev = new QLabel(doctorFrame);
        depAndlev->setObjectName(QStringLiteral("depAndlev"));
        depAndlev->setMinimumSize(QSize(130, 25));
        depAndlev->setMaximumSize(QSize(16777215, 25));
        depAndlev->setStyleSheet(QLatin1String("QLabel#depAndlev\n"
"{\n"
"	width: 33px;\n"
"	height: 15px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        depAndlev->setOpenExternalLinks(false);

        verticalLayout_2->addWidget(depAndlev);

        hospitallab = new QLabel(doctorFrame);
        hospitallab->setObjectName(QStringLiteral("hospitallab"));
        hospitallab->setMinimumSize(QSize(81, 41));
        hospitallab->setMaximumSize(QSize(150, 41));
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

        textlab = new QLabel(ExpertsCallDialog);
        textlab->setObjectName(QStringLiteral("textlab"));
        textlab->setMinimumSize(QSize(440, 30));
        textlab->setStyleSheet(QLatin1String("QLabel#textlab\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-bold;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_6->addWidget(textlab);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        cancelBtn = new QPushButton(ExpertsCallDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(150, 36));
        cancelBtn->setMaximumSize(QSize(150, 36));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #f4b452;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout_7->addWidget(cancelBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        okBtn = new QPushButton(ExpertsCallDialog);
        okBtn->setObjectName(QStringLiteral("okBtn"));
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
"}"));

        horizontalLayout_7->addWidget(okBtn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(ExpertsCallDialog);
        QObject::connect(cancelBtn, SIGNAL(clicked()), ExpertsCallDialog, SLOT(reject()));
        QObject::connect(okBtn, SIGNAL(clicked()), ExpertsCallDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(ExpertsCallDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpertsCallDialog)
    {
        ExpertsCallDialog->setWindowTitle(QApplication::translate("ExpertsCallDialog", "ExpertsCallDialog", nullptr));
        titlelab->setText(QApplication::translate("ExpertsCallDialog", "\345\260\261\350\257\212\345\272\224\347\255\224", nullptr));
        patientheadImage->setText(QString());
        patName->setText(QApplication::translate("ExpertsCallDialog", "\345\247\223\345\220\215", nullptr));
        patSex->setText(QApplication::translate("ExpertsCallDialog", "\357\274\210\345\245\263\357\274\211", nullptr));
        patAgelab->setText(QApplication::translate("ExpertsCallDialog", "\345\271\264\351\276\204", nullptr));
        patBirthlab->setText(QApplication::translate("ExpertsCallDialog", "yyyy-mm-dd", nullptr));
        doctorheadImage->setText(QString());
        doctorNamelab->setText(QApplication::translate("ExpertsCallDialog", "\345\247\223\345\220\215", nullptr));
        doctorSexlab->setText(QApplication::translate("ExpertsCallDialog", "\357\274\210\345\245\263\357\274\211", nullptr));
        depAndlev->setText(QApplication::translate("ExpertsCallDialog", "\345\277\203\345\244\226\347\247\221-\344\270\273\344\273\273\345\214\273\345\270\210", nullptr));
        hospitallab->setText(QApplication::translate("ExpertsCallDialog", "\346\211\200\345\261\236\345\214\273\351\231\242", nullptr));
        textlab->setText(QApplication::translate("ExpertsCallDialog", "\350\277\234\347\250\213\344\270\223\345\256\266\346\255\243\345\234\250\347\255\211\345\276\205\346\202\250\347\232\204\345\272\224\347\255\224\357\274\214\350\257\267\345\217\212\346\227\266\345\233\236\345\244\215\357\274\201", nullptr));
        cancelBtn->setText(QApplication::translate("ExpertsCallDialog", "\346\227\240\345\272\224\347\255\224", nullptr));
        okBtn->setText(QApplication::translate("ExpertsCallDialog", "\347\253\213\345\215\263\345\260\261\350\257\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpertsCallDialog: public Ui_ExpertsCallDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERTSCALLDIALOG_H

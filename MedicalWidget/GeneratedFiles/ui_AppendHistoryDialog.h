/********************************************************************************
** Form generated from reading UI file 'AppendHistoryDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPENDHISTORYDIALOG_H
#define UI_APPENDHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "../MedicalWidget/TitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_AppendHistoryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    TitleBar *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *titleText;
    QToolButton *closeBtn;
    QVBoxLayout *verticalLayout;
    QTextEdit *maskEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *okBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AppendHistoryDialog)
    {
        if (AppendHistoryDialog->objectName().isEmpty())
            AppendHistoryDialog->setObjectName(QStringLiteral("AppendHistoryDialog"));
        AppendHistoryDialog->resize(600, 256);
        AppendHistoryDialog->setMinimumSize(QSize(600, 256));
        AppendHistoryDialog->setStyleSheet(QLatin1String("QDialog#AppendHistoryDialog\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(AppendHistoryDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new TitleBar(AppendHistoryDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"background-color: #6489d9;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 20, 0);
        titleText = new QLabel(widget);
        titleText->setObjectName(QStringLiteral("titleText"));
        titleText->setMinimumSize(QSize(0, 0));
        titleText->setStyleSheet(QLatin1String("QLabel#titleText\n"
"{	\n"
"	width: 144px;\n"
"	height: 24px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        titleText->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(titleText);

        closeBtn = new QToolButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(40, 40));
        closeBtn->setStyleSheet(QLatin1String("QToolButton#closeBtn\n"
"{		\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        maskEdit = new QTextEdit(AppendHistoryDialog);
        maskEdit->setObjectName(QStringLiteral("maskEdit"));
        maskEdit->setMinimumSize(QSize(560, 100));
        maskEdit->setStyleSheet(QLatin1String("QTextEdit#maskEdit\n"
"{\n"
"	background-color: #f1f2f6;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 20px;\n"
"	color: #c1c2c6;\n"
"}"));

        verticalLayout->addWidget(maskEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QToolButton(AppendHistoryDialog);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setMinimumSize(QSize(150, 36));
        okBtn->setMaximumSize(QSize(150, 36));
        okBtn->setStyleSheet(QLatin1String("QToolButton#okBtn\n"
"{\n"
"	border:none;\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"	background-color: #6489d9;\n"
"}"));

        horizontalLayout_2->addWidget(okBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AppendHistoryDialog);
        QObject::connect(closeBtn, SIGNAL(clicked()), AppendHistoryDialog, SLOT(close()));
        QObject::connect(okBtn, SIGNAL(clicked()), AppendHistoryDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(AppendHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *AppendHistoryDialog)
    {
        AppendHistoryDialog->setWindowTitle(QApplication::translate("AppendHistoryDialog", "AppendHistoryDialog", nullptr));
        titleText->setText(QApplication::translate("AppendHistoryDialog", "\346\202\243\350\200\205\347\227\205\345\217\262\350\257\246\346\203\205", nullptr));
        closeBtn->setText(QString());
        maskEdit->setHtml(QApplication::translate("AppendHistoryDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MicrosoftYaHei'; font-size:16px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        maskEdit->setPlaceholderText(QApplication::translate("AppendHistoryDialog", "\350\257\267\350\276\223\345\205\245\345\242\236\345\212\240\347\232\204\345\206\205\345\256\271", nullptr));
        okBtn->setText(QApplication::translate("AppendHistoryDialog", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppendHistoryDialog: public Ui_AppendHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPENDHISTORYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'PopupTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPTITLEBAR_H
#define UI_POPUPTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopupTitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *titlelab;
    QPushButton *closeBtn;

    void setupUi(QWidget *PopupTitleBar)
    {
        if (PopupTitleBar->objectName().isEmpty())
            PopupTitleBar->setObjectName(QStringLiteral("PopupTitleBar"));
        PopupTitleBar->resize(1000, 60);
        PopupTitleBar->setMinimumSize(QSize(1000, 60));
        PopupTitleBar->setMaximumSize(QSize(16777215, 60));
        PopupTitleBar->setStyleSheet(QLatin1String("QWidget#PopupTitleBar\n"
"{\n"
"background-color:#6489d9;\n"
"}"));
        horizontalLayout = new QHBoxLayout(PopupTitleBar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        titlelab = new QLabel(PopupTitleBar);
        titlelab->setObjectName(QStringLiteral("titlelab"));
        titlelab->setStyleSheet(QLatin1String("QLabel#titlelab\n"
"{\n"
"	width: 144px;\n"
"	height: 23px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        titlelab->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(titlelab);

        closeBtn = new QPushButton(PopupTitleBar);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(36, 36));
        closeBtn->setMaximumSize(QSize(36, 60));
        closeBtn->setStyleSheet(QLatin1String("QPushButton#closeBtn\n"
"{\n"
"border-image: url(:/res/popUp/close.png);\n"
"background-color:transparent;\n"
"}"));

        horizontalLayout->addWidget(closeBtn);


        retranslateUi(PopupTitleBar);

        QMetaObject::connectSlotsByName(PopupTitleBar);
    } // setupUi

    void retranslateUi(QWidget *PopupTitleBar)
    {
        PopupTitleBar->setWindowTitle(QApplication::translate("PopupTitleBar", "PopupTitleBar", nullptr));
        titlelab->setText(QApplication::translate("PopupTitleBar", "\345\274\271\346\241\206\346\240\207\351\242\230", nullptr));
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PopupTitleBar: public Ui_PopupTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPTITLEBAR_H

/********************************************************************************
** Form generated from reading UI file 'TitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labIcon;
    QLabel *tileText;
    QSpacerItem *horizontalSpacer;
    QToolButton *minButton;
    QToolButton *closeButton;

    void setupUi(QWidget *TitleBar)
    {
        if (TitleBar->objectName().isEmpty())
            TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->resize(860, 60);
        TitleBar->setMinimumSize(QSize(860, 60));
        TitleBar->setMaximumSize(QSize(860, 65));
        TitleBar->setStyleSheet(QLatin1String("QWidget#TitleBar{\n"
"background-color: #6489d9;\n"
"}"));
        horizontalLayout = new QHBoxLayout(TitleBar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 0, 6, 0);
        labIcon = new QLabel(TitleBar);
        labIcon->setObjectName(QStringLiteral("labIcon"));
        labIcon->setMinimumSize(QSize(40, 40));
        labIcon->setMaximumSize(QSize(40, 40));
        labIcon->setPixmap(QPixmap(QString::fromUtf8(":/res/login/logo.png")));
        labIcon->setAlignment(Qt::AlignCenter);
        labIcon->setMargin(0);

        horizontalLayout->addWidget(labIcon);

        tileText = new QLabel(TitleBar);
        tileText->setObjectName(QStringLiteral("tileText"));
        tileText->setMinimumSize(QSize(0, 65));
        tileText->setMaximumSize(QSize(16777215, 65));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        tileText->setFont(font);
        tileText->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tileText->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(tileText);

        horizontalSpacer = new QSpacerItem(518, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minButton = new QToolButton(TitleBar);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setMinimumSize(QSize(30, 29));
        minButton->setMaximumSize(QSize(30, 29));
        minButton->setStyleSheet(QLatin1String("QToolButton#minButton\n"
"{	\n"
"	border-image: url(:/res/login/min.png);\n"
"}\n"
"QToolButton#minButton:hover\n"
"{\n"
"	border-image: url(:/res/login/min_hover.png);\n"
"}\n"
"QToolButton#minButton:hover\n"
"{	\n"
"	border-image: url(:/res/login/min_pressed.png);\n"
"}\n"
""));

        horizontalLayout->addWidget(minButton);

        closeButton = new QToolButton(TitleBar);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QLatin1String("QToolButton#closeButton{\n"
"border-image: url(:/res/login/close.png);\n"
"}\n"
"QToolButton#closeButton:hover{\n"
"border-image: url(:/res/login/close_hover.png);\n"
"}\n"
"QToolButton#closeButton:pressed{\n"
"border-image: url(:/res/login/close_pressed.png);\n"
"}"));

        horizontalLayout->addWidget(closeButton);


        retranslateUi(TitleBar);

        QMetaObject::connectSlotsByName(TitleBar);
    } // setupUi

    void retranslateUi(QWidget *TitleBar)
    {
        TitleBar->setWindowTitle(QApplication::translate("TitleBar", "TitleBar", nullptr));
        labIcon->setText(QString());
        tileText->setText(QApplication::translate("TitleBar", "\345\212\251\350\257\212\345\214\273\347\224\237\345\267\245\344\275\234\347\253\231", nullptr));
        minButton->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleBar: public Ui_TitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H

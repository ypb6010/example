/********************************************************************************
** Form generated from reading UI file 'HistoryStatisWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYSTATISWIDGET_H
#define UI_HISTORYSTATISWIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "../MedicalWidget/TitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_HistoryStatisDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    TitleBar *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titlelab;
    QPushButton *closeBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *exportExcelBtn;
    QLabel *label;
    QDateEdit *rmt_fromDate;
    QLabel *label_24;
    QDateEdit *rmt_toDate;
    QLabel *label_2;
    QLineEdit *patEdit;
    QToolButton *sreachBtn;
    QToolButton *resetBtn;
    QTableView *tableView;

    void setupUi(QDialog *HistoryStatisDialog)
    {
        if (HistoryStatisDialog->objectName().isEmpty())
            HistoryStatisDialog->setObjectName(QStringLiteral("HistoryStatisDialog"));
        HistoryStatisDialog->resize(1000, 701);
        HistoryStatisDialog->setMinimumSize(QSize(1000, 700));
        HistoryStatisDialog->setStyleSheet(QLatin1String("QDialog#HistoryStatisDialog\n"
"{\n"
"background-color:rgb(255,255,255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(HistoryStatisDialog);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 20);
        widget = new TitleBar(HistoryStatisDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(1000, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"background-color:#6489d9;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        titlelab = new QLabel(widget);
        titlelab->setObjectName(QStringLiteral("titlelab"));
        titlelab->setStyleSheet(QLatin1String("QLabel#titlelab\n"
"{\n"
"	background-color:transparent;\n"
"	width: 144px;\n"
"	height: 23px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        titlelab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(titlelab);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(36, 36));
        closeBtn->setMaximumSize(QSize(36, 60));
        closeBtn->setStyleSheet(QLatin1String("QPushButton#closeBtn\n"
"{\n"
"border-image: url(:/res/popUp/close.png);\n"
"background-color:transparent;\n"
"}"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, -1, 20, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        exportExcelBtn = new QToolButton(HistoryStatisDialog);
        exportExcelBtn->setObjectName(QStringLiteral("exportExcelBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exportExcelBtn->sizePolicy().hasHeightForWidth());
        exportExcelBtn->setSizePolicy(sizePolicy);
        exportExcelBtn->setMinimumSize(QSize(175, 35));
        exportExcelBtn->setStyleSheet(QLatin1String("QToolButton#exportExcelBtn\n"
"{\n"
"	background-color:transparent;\n"
"	width: 128px;\n"
"	height: 20px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/popUp/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportExcelBtn->setIcon(icon);
        exportExcelBtn->setIconSize(QSize(30, 30));
        exportExcelBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(exportExcelBtn);

        label = new QLabel(HistoryStatisDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(30, 35));

        horizontalLayout->addWidget(label);

        rmt_fromDate = new QDateEdit(HistoryStatisDialog);
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

        horizontalLayout->addWidget(rmt_fromDate);

        label_24 = new QLabel(HistoryStatisDialog);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(21, 0));
        label_24->setMaximumSize(QSize(15, 16777215));

        horizontalLayout->addWidget(label_24);

        rmt_toDate = new QDateEdit(HistoryStatisDialog);
        rmt_toDate->setObjectName(QStringLiteral("rmt_toDate"));
        rmt_toDate->setMinimumSize(QSize(135, 40));
        rmt_toDate->setMaximumSize(QSize(135, 40));
        rmt_toDate->setStyleSheet(QLatin1String("QDateEdit\n"
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
        rmt_toDate->setWrapping(false);
        rmt_toDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        rmt_toDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        rmt_toDate->setProperty("showGroupSeparator", QVariant(false));
        rmt_toDate->setCurrentSection(QDateTimeEdit::DaySection);
        rmt_toDate->setCalendarPopup(true);
        rmt_toDate->setDate(QDate(2019, 4, 9));

        horizontalLayout->addWidget(rmt_toDate);

        label_2 = new QLabel(HistoryStatisDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(30, 35));

        horizontalLayout->addWidget(label_2);

        patEdit = new QLineEdit(HistoryStatisDialog);
        patEdit->setObjectName(QStringLiteral("patEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(patEdit->sizePolicy().hasHeightForWidth());
        patEdit->setSizePolicy(sizePolicy1);
        patEdit->setMinimumSize(QSize(0, 40));
        patEdit->setStyleSheet(QLatin1String("QLineEdit#patEdit\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #c1c2c6;\n"
"	background-color: #ffffff;\n"
"	border-radius: 4px;\n"
"	border:1px solid #c1c2c6;\n"
"}"));

        horizontalLayout->addWidget(patEdit);

        sreachBtn = new QToolButton(HistoryStatisDialog);
        sreachBtn->setObjectName(QStringLiteral("sreachBtn"));
        sreachBtn->setMinimumSize(QSize(60, 36));
        sreachBtn->setMaximumSize(QSize(16777215, 36));
        sreachBtn->setStyleSheet(QLatin1String("QToolButton#sreachBtn\n"
"{\n"
"	width: 32px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #fefefe;\n"
"	border-image: url(:/res/popUp/blue_normal.png);\n"
"	border-radius: 4px;\n"
"}\n"
"QToolButton#sreachBtn:hover\n"
"{\n"
"	width: 32px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #fefefe;	\n"
"	border-image: url(:/res/popUp/blue_normal.png);\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout->addWidget(sreachBtn);

        resetBtn = new QToolButton(HistoryStatisDialog);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        resetBtn->setMinimumSize(QSize(60, 36));
        resetBtn->setMaximumSize(QSize(16777215, 36));
        resetBtn->setStyleSheet(QLatin1String("QToolButton#resetBtn\n"
"{\n"
"	width: 32px;\n"
"	height: 16px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;	\n"
"	border-image: url(:/res/popUp/blue2_normal.png);\n"
"	color: #fefefe;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout->addWidget(resetBtn);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(HistoryStatisDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
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
        tableView->verticalHeader()->setDefaultSectionSize(50);
        tableView->verticalHeader()->setMinimumSectionSize(50);

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(HistoryStatisDialog);

        QMetaObject::connectSlotsByName(HistoryStatisDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoryStatisDialog)
    {
        HistoryStatisDialog->setWindowTitle(QApplication::translate("HistoryStatisDialog", "HistoryStatisWidget", nullptr));
        titlelab->setText(QApplication::translate("HistoryStatisDialog", "\345\216\206\345\217\262\345\260\261\350\257\212\350\256\260\345\275\225", nullptr));
        closeBtn->setText(QString());
        exportExcelBtn->setText(QApplication::translate("HistoryStatisDialog", "\345\257\274\345\207\272Excel\350\241\250\346\240\274", nullptr));
        label->setText(QApplication::translate("HistoryStatisDialog", "\346\227\245\346\234\237", nullptr));
        label_24->setText(QApplication::translate("HistoryStatisDialog", "--", nullptr));
        label_2->setText(QApplication::translate("HistoryStatisDialog", "\346\202\243\350\200\205", nullptr));
        patEdit->setInputMask(QString());
        patEdit->setPlaceholderText(QApplication::translate("HistoryStatisDialog", "\346\202\243\350\200\205\345\247\223\345\220\215/\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201", nullptr));
        sreachBtn->setText(QApplication::translate("HistoryStatisDialog", "\346\220\234\347\264\242", nullptr));
        resetBtn->setText(QApplication::translate("HistoryStatisDialog", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryStatisDialog: public Ui_HistoryStatisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYSTATISWIDGET_H

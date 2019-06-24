/********************************************************************************
** Form generated from reading UI file 'HistoryDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYDIALOG_H
#define UI_HISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../MedicalWidget/TitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_HistoryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    TitleBar *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *closeBtn;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *drugWidget;
    QVBoxLayout *verticalLayout_3;
    QToolButton *adddrugBtn;
    QTableView *drugView;
    QWidget *pastWidget;
    QVBoxLayout *verticalLayout_4;
    QToolButton *addpastBtn;
    QTableView *pastView;
    QWidget *familyWidget;
    QVBoxLayout *verticalLayout_5;
    QToolButton *addFamilyBtn;
    QTableView *familyView;
    QWidget *geneticWidget;
    QVBoxLayout *verticalLayout_6;
    QToolButton *addgeneticBtn;
    QTableView *geneticView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *okBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *HistoryDialog)
    {
        if (HistoryDialog->objectName().isEmpty())
            HistoryDialog->setObjectName(QStringLiteral("HistoryDialog"));
        HistoryDialog->resize(1000, 600);
        HistoryDialog->setMinimumSize(QSize(1000, 600));
        HistoryDialog->setMaximumSize(QSize(1000, 600));
        HistoryDialog->setStyleSheet(QLatin1String("QDialog#HistoryDialog\n"
"{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(HistoryDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new TitleBar(HistoryDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"background-color: #6489d9;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("QLabel#label\n"
"{	\n"
"	width: 144px;\n"
"	height: 24px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        closeBtn = new QToolButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setStyleSheet(QLatin1String("QToolButton#toolButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/login/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        tabWidget = new QTabWidget(HistoryDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget#tabWidget_2\n"
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
"    width:500;\n"
"	height:41;\n"
"}\n"
"QTabBar::tab \n"
"{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #888888;\n"
"    min-width:10ex;\n"
"    padding:1px;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;	\n"
"	width:100;\n"
"	height:40;\n"
"	border-bottom: 4px solid 6489d9;\n"
"}\n"
"QWidget#drugWidget\n"
"{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#pastWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#familyWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#geneticWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        tabWidget->setElideMode(Qt::ElideNone);
        drugWidget = new QWidget();
        drugWidget->setObjectName(QStringLiteral("drugWidget"));
        verticalLayout_3 = new QVBoxLayout(drugWidget);
        verticalLayout_3->setSpacing(25);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 25, 0, 0);
        adddrugBtn = new QToolButton(drugWidget);
        adddrugBtn->setObjectName(QStringLiteral("adddrugBtn"));
        adddrugBtn->setMinimumSize(QSize(180, 36));
        adddrugBtn->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;\n"
"	background-color: rgba(255,255,255,0);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/popup/addOffLine.png"), QSize(), QIcon::Normal, QIcon::Off);
        adddrugBtn->setIcon(icon1);
        adddrugBtn->setIconSize(QSize(32, 32));
        adddrugBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_3->addWidget(adddrugBtn);

        drugView = new QTableView(drugWidget);
        drugView->setObjectName(QStringLiteral("drugView"));
        drugView->setStyleSheet(QLatin1String("QTableView#drugView::item\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #333333;\n"
"}\n"
"\n"
"QTableView#drugView::item:selected\n"
"{\n"
"	background-color: rgb(230, 244, 255);\n"
"}\n"
"	"));
        drugView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        drugView->setAlternatingRowColors(false);
        drugView->setSelectionMode(QAbstractItemView::NoSelection);
        drugView->setSelectionBehavior(QAbstractItemView::SelectRows);
        drugView->horizontalHeader()->setVisible(false);
        drugView->horizontalHeader()->setHighlightSections(false);
        drugView->horizontalHeader()->setStretchLastSection(false);
        drugView->verticalHeader()->setVisible(false);
        drugView->verticalHeader()->setDefaultSectionSize(50);
        drugView->verticalHeader()->setHighlightSections(false);
        drugView->verticalHeader()->setMinimumSectionSize(50);

        verticalLayout_3->addWidget(drugView);

        tabWidget->addTab(drugWidget, QString());
        pastWidget = new QWidget();
        pastWidget->setObjectName(QStringLiteral("pastWidget"));
        verticalLayout_4 = new QVBoxLayout(pastWidget);
        verticalLayout_4->setSpacing(25);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 25, 0, 0);
        addpastBtn = new QToolButton(pastWidget);
        addpastBtn->setObjectName(QStringLiteral("addpastBtn"));
        addpastBtn->setMinimumSize(QSize(180, 36));
        addpastBtn->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;\n"
"	background-color: rgba(255,255,255,0);\n"
"}"));
        addpastBtn->setIcon(icon1);
        addpastBtn->setIconSize(QSize(32, 32));
        addpastBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_4->addWidget(addpastBtn);

        pastView = new QTableView(pastWidget);
        pastView->setObjectName(QStringLiteral("pastView"));
        pastView->setStyleSheet(QLatin1String("QTableView#pastView::item\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #333333;\n"
"}\n"
"\n"
"QTableView#pastView::item:selected\n"
"{\n"
"	background-color: rgb(230, 244, 255);\n"
"}\n"
"	"));
        pastView->setEditTriggers(QAbstractItemView::DoubleClicked);
        pastView->setSelectionMode(QAbstractItemView::NoSelection);
        pastView->setSelectionBehavior(QAbstractItemView::SelectRows);
        pastView->horizontalHeader()->setVisible(false);
        pastView->horizontalHeader()->setHighlightSections(false);
        pastView->horizontalHeader()->setStretchLastSection(false);
        pastView->verticalHeader()->setVisible(false);
        pastView->verticalHeader()->setDefaultSectionSize(50);
        pastView->verticalHeader()->setHighlightSections(false);
        pastView->verticalHeader()->setMinimumSectionSize(50);

        verticalLayout_4->addWidget(pastView);

        tabWidget->addTab(pastWidget, QString());
        familyWidget = new QWidget();
        familyWidget->setObjectName(QStringLiteral("familyWidget"));
        verticalLayout_5 = new QVBoxLayout(familyWidget);
        verticalLayout_5->setSpacing(25);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 25, 0, 0);
        addFamilyBtn = new QToolButton(familyWidget);
        addFamilyBtn->setObjectName(QStringLiteral("addFamilyBtn"));
        addFamilyBtn->setMinimumSize(QSize(180, 36));
        addFamilyBtn->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;\n"
"	background-color: rgba(255,255,255,0);\n"
"}"));
        addFamilyBtn->setIcon(icon1);
        addFamilyBtn->setIconSize(QSize(32, 32));
        addFamilyBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_5->addWidget(addFamilyBtn);

        familyView = new QTableView(familyWidget);
        familyView->setObjectName(QStringLiteral("familyView"));
        familyView->setStyleSheet(QLatin1String("QTableView#familyView::item\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #333333;\n"
"}\n"
"\n"
"QTableView#familyView::item:selected\n"
"{\n"
"	background-color: rgb(230, 244, 255);\n"
"}\n"
"	"));
        familyView->setSelectionMode(QAbstractItemView::NoSelection);
        familyView->setSelectionBehavior(QAbstractItemView::SelectRows);
        familyView->horizontalHeader()->setVisible(false);
        familyView->horizontalHeader()->setHighlightSections(false);
        familyView->horizontalHeader()->setStretchLastSection(false);
        familyView->verticalHeader()->setVisible(false);
        familyView->verticalHeader()->setDefaultSectionSize(50);
        familyView->verticalHeader()->setHighlightSections(false);
        familyView->verticalHeader()->setMinimumSectionSize(50);

        verticalLayout_5->addWidget(familyView);

        tabWidget->addTab(familyWidget, QString());
        geneticWidget = new QWidget();
        geneticWidget->setObjectName(QStringLiteral("geneticWidget"));
        verticalLayout_6 = new QVBoxLayout(geneticWidget);
        verticalLayout_6->setSpacing(25);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 25, 0, 0);
        addgeneticBtn = new QToolButton(geneticWidget);
        addgeneticBtn->setObjectName(QStringLiteral("addgeneticBtn"));
        addgeneticBtn->setMinimumSize(QSize(180, 36));
        addgeneticBtn->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 20px;\n"
"	line-height: 20px;\n"
"	color: #6489d9;\n"
"	background-color: rgba(255,255,255,0);\n"
"}"));
        addgeneticBtn->setIcon(icon1);
        addgeneticBtn->setIconSize(QSize(32, 32));
        addgeneticBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_6->addWidget(addgeneticBtn);

        geneticView = new QTableView(geneticWidget);
        geneticView->setObjectName(QStringLiteral("geneticView"));
        geneticView->setStyleSheet(QLatin1String("QTableView#geneticView::item\n"
"{\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #333333;\n"
"}\n"
"\n"
"QTableView#geneticView::item:selected\n"
"{\n"
"	background-color: rgb(230, 244, 255);\n"
"}\n"
"	"));
        geneticView->setSelectionMode(QAbstractItemView::NoSelection);
        geneticView->setSelectionBehavior(QAbstractItemView::SelectRows);
        geneticView->horizontalHeader()->setVisible(false);
        geneticView->horizontalHeader()->setHighlightSections(false);
        geneticView->horizontalHeader()->setStretchLastSection(false);
        geneticView->verticalHeader()->setVisible(false);
        geneticView->verticalHeader()->setDefaultSectionSize(50);
        geneticView->verticalHeader()->setHighlightSections(false);
        geneticView->verticalHeader()->setMinimumSectionSize(50);

        verticalLayout_6->addWidget(geneticView);

        tabWidget->addTab(geneticWidget, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QToolButton(HistoryDialog);
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


        retranslateUi(HistoryDialog);
        QObject::connect(okBtn, SIGNAL(clicked()), HistoryDialog, SLOT(accept()));
        QObject::connect(closeBtn, SIGNAL(clicked()), HistoryDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(HistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoryDialog)
    {
        HistoryDialog->setWindowTitle(QApplication::translate("HistoryDialog", "HistoryDialog", nullptr));
        label->setText(QApplication::translate("HistoryDialog", "\346\202\243\350\200\205\347\227\205\345\217\262\350\257\246\346\203\205", nullptr));
        closeBtn->setText(QString());
        adddrugBtn->setText(QApplication::translate("HistoryDialog", "\345\242\236\345\212\240\350\215\257\347\211\251\350\277\207\346\225\217\345\217\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(drugWidget), QApplication::translate("HistoryDialog", "\350\215\257\347\211\251\350\277\207\346\225\217\345\217\262", nullptr));
        addpastBtn->setText(QApplication::translate("HistoryDialog", "\345\242\236\345\212\240\346\227\242\345\276\200\345\217\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pastWidget), QApplication::translate("HistoryDialog", "\346\227\242\345\276\200\345\217\262", nullptr));
        addFamilyBtn->setText(QApplication::translate("HistoryDialog", "\345\242\236\345\212\240\346\227\242\345\276\200\345\217\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(familyWidget), QApplication::translate("HistoryDialog", "\345\256\266\346\227\217\345\217\262", nullptr));
        addgeneticBtn->setText(QApplication::translate("HistoryDialog", "\345\242\236\345\212\240\351\201\227\344\274\240\347\227\205\345\217\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(geneticWidget), QApplication::translate("HistoryDialog", "\351\201\227\344\274\240\347\227\205\345\217\262", nullptr));
        okBtn->setText(QApplication::translate("HistoryDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryDialog: public Ui_HistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'MedicalGui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICALGUI_H
#define UI_MEDICALGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MedicalGuiClass
{
public:

    void setupUi(QWidget *MedicalGuiClass)
    {
        if (MedicalGuiClass->objectName().isEmpty())
            MedicalGuiClass->setObjectName(QStringLiteral("MedicalGuiClass"));
        MedicalGuiClass->resize(600, 400);

        retranslateUi(MedicalGuiClass);

        QMetaObject::connectSlotsByName(MedicalGuiClass);
    } // setupUi

    void retranslateUi(QWidget *MedicalGuiClass)
    {
        MedicalGuiClass->setWindowTitle(QApplication::translate("MedicalGuiClass", "MedicalGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedicalGuiClass: public Ui_MedicalGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICALGUI_H

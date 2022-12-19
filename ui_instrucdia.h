/********************************************************************************
** Form generated from reading UI file 'instrucdia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCDIA_H
#define UI_INSTRUCDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_InstrucDia
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *InstrucDia)
    {
        if (InstrucDia->objectName().isEmpty())
            InstrucDia->setObjectName(QString::fromUtf8("InstrucDia"));
        InstrucDia->resize(769, 458);
        listWidget = new QListWidget(InstrucDia);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 561, 151));

        retranslateUi(InstrucDia);

        QMetaObject::connectSlotsByName(InstrucDia);
    } // setupUi

    void retranslateUi(QDialog *InstrucDia)
    {
        InstrucDia->setWindowTitle(QApplication::translate("InstrucDia", "Dialog", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("InstrucDia", "Welcome to SANDA!", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("InstrucDia", "To use the Alarm, click on a alarm and set an alarm.", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("InstrucDia", "To use the calendar function, click on calendar and add/view/modify events.", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("InstrucDia", "To view news, click on news and select the number of news you want to view.", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("InstrucDia", "To view weather, click on weather and enter a city (eg Toronto).", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class InstrucDia: public Ui_InstrucDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCDIA_H

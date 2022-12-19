/********************************************************************************
** Form generated from reading UI file 'weathdia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHDIA_H
#define UI_WEATHDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WeathDia
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *WeathDia)
    {
        if (WeathDia->objectName().isEmpty())
            WeathDia->setObjectName(QString::fromUtf8("WeathDia"));
        WeathDia->resize(530, 397);
        label = new QLabel(WeathDia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 181, 41));
        lineEdit = new QLineEdit(WeathDia);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 130, 113, 28));
        pushButton = new QPushButton(WeathDia);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 130, 171, 31));
        label_2 = new QLabel(WeathDia);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 121, 20));

        retranslateUi(WeathDia);

        QMetaObject::connectSlotsByName(WeathDia);
    } // setupUi

    void retranslateUi(QDialog *WeathDia)
    {
        WeathDia->setWindowTitle(QApplication::translate("WeathDia", "Dialog", nullptr));
        label->setText(QApplication::translate("WeathDia", "Today's weather", nullptr));
        pushButton->setText(QApplication::translate("WeathDia", "Input weather", nullptr));
        label_2->setText(QApplication::translate("WeathDia", "Enter City Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeathDia: public Ui_WeathDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHDIA_H

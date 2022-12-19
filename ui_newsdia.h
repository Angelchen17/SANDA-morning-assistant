/********************************************************************************
** Form generated from reading UI file 'newsdia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSDIA_H
#define UI_NEWSDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewsDia
{
public:
    QSpinBox *spinBox;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *NewsDia)
    {
        if (NewsDia->objectName().isEmpty())
            NewsDia->setObjectName(QString::fromUtf8("NewsDia"));
        NewsDia->resize(400, 300);
        spinBox = new QSpinBox(NewsDia);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(80, 100, 51, 31));
        label = new QLabel(NewsDia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 271, 16));
        pushButton = new QPushButton(NewsDia);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 100, 101, 32));

        retranslateUi(NewsDia);

        QMetaObject::connectSlotsByName(NewsDia);
    } // setupUi

    void retranslateUi(QWidget *NewsDia)
    {
        NewsDia->setWindowTitle(QApplication::translate("NewsDia", "Form", nullptr));
        label->setText(QApplication::translate("NewsDia", "Please input number of news for today:", nullptr));
        pushButton->setText(QApplication::translate("NewsDia", "Get News", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewsDia: public Ui_NewsDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSDIA_H

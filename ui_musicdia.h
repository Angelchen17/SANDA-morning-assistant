/********************************************************************************
** Form generated from reading UI file 'musicdia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICDIA_H
#define UI_MUSICDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MusicDia
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *MusicDia)
    {
        if (MusicDia->objectName().isEmpty())
            MusicDia->setObjectName(QString::fromUtf8("MusicDia"));
        MusicDia->resize(400, 300);
        lineEdit = new QLineEdit(MusicDia);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 70, 191, 25));
        pushButton = new QPushButton(MusicDia);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 70, 93, 29));
        label = new QLabel(MusicDia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 191, 20));

        retranslateUi(MusicDia);

        QMetaObject::connectSlotsByName(MusicDia);
    } // setupUi

    void retranslateUi(QDialog *MusicDia)
    {
        MusicDia->setWindowTitle(QApplication::translate("MusicDia", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("MusicDia", "Play", nullptr));
        label->setText(QApplication::translate("MusicDia", "Please enter music name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicDia: public Ui_MusicDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICDIA_H

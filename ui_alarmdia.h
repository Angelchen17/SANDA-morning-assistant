/********************************************************************************
** Form generated from reading UI file 'alarmdia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMDIA_H
#define UI_ALARMDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmDia
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QSpinBox *spinBox_hr;
    QSpinBox *spinBox_min;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QDialog *AlarmDia)
    {
        if (AlarmDia->objectName().isEmpty())
            AlarmDia->setObjectName(QString::fromUtf8("AlarmDia"));
        AlarmDia->resize(721, 498);
        layoutWidget = new QWidget(AlarmDia);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 250, 421, 131));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        layoutWidget1 = new QWidget(AlarmDia);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 50, 421, 141));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 3);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 2);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox_hr = new QSpinBox(layoutWidget1);
        spinBox_hr->setObjectName(QString::fromUtf8("spinBox_hr"));
        spinBox_hr->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_hr->setMaximum(23);
        spinBox_hr->setValue(8);

        gridLayout->addWidget(spinBox_hr, 1, 1, 1, 1);

        spinBox_min = new QSpinBox(layoutWidget1);
        spinBox_min->setObjectName(QString::fromUtf8("spinBox_min"));
        spinBox_min->setMaximum(59);
        spinBox_min->setValue(30);

        gridLayout->addWidget(spinBox_min, 1, 4, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 3);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 3, 1, 1);


        retranslateUi(AlarmDia);

        QMetaObject::connectSlotsByName(AlarmDia);
    } // setupUi

    void retranslateUi(QDialog *AlarmDia)
    {
        AlarmDia->setWindowTitle(QApplication::translate("AlarmDia", "Dialog", nullptr));
        label_3->setText(QApplication::translate("AlarmDia", "Enter the name", nullptr));
        pushButton->setText(QApplication::translate("AlarmDia", "Delete", nullptr));
        label_4->setText(QApplication::translate("AlarmDia", "Enter the alarm name", nullptr));
        label->setText(QApplication::translate("AlarmDia", "Hour", nullptr));
        pushButton_2->setText(QApplication::translate("AlarmDia", "Add", nullptr));
        label_2->setText(QApplication::translate("AlarmDia", "Minute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmDia: public Ui_AlarmDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMDIA_H

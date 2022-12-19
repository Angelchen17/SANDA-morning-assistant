/********************************************************************************
** Form generated from reading UI file 'sanda.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SANDA_H
#define UI_SANDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SANDA
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SANDA)
    {
        if (SANDA->objectName().isEmpty())
            SANDA->setObjectName(QString::fromUtf8("SANDA"));
        SANDA->resize(956, 600);
        centralwidget = new QWidget(SANDA);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_5, 5, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_2, 5, 0, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_6, 0, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        SANDA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SANDA);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 956, 32));
        SANDA->setMenuBar(menubar);
        statusbar = new QStatusBar(SANDA);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SANDA->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButton_6, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_5);

        retranslateUi(SANDA);

        QMetaObject::connectSlotsByName(SANDA);
    } // setupUi

    void retranslateUi(QMainWindow *SANDA)
    {
        SANDA->setWindowTitle(QApplication::translate("SANDA", "SANDA", nullptr));
        pushButton->setText(QApplication::translate("SANDA", "Alarm", nullptr));
        pushButton_3->setText(QApplication::translate("SANDA", "Weather", nullptr));
        pushButton_5->setText(QApplication::translate("SANDA", "News", nullptr));
        pushButton_2->setText(QApplication::translate("SANDA", "Calendar", nullptr));
        pushButton_6->setText(QApplication::translate("SANDA", "Instructions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SANDA: public Ui_SANDA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SANDA_H

#ifndef ALARMDIA_H
#define ALARMDIA_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <qstring.h>
#include "alarmClock.hpp"

namespace Ui {
class AlarmDia;
}

class AlarmDia : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmDia(QWidget *parent = nullptr);
    ~AlarmDia();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AlarmDia *ui;
    int spinboxvalue;
    int spinboxvalue2;
    QString alarmName;
    //alarmClock newAlarm1;
    //std::vector<alarmClock> alarmList;
};

#endif // ALARMDIA_H

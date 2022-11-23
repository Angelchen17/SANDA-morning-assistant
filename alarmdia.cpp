#include "alarmdia.h"
#include "ui_alarmdia.h"

AlarmDia::AlarmDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDia)
{
    ui->setupUi(this);

}

AlarmDia::~AlarmDia()
{
    delete ui;
}

/*
add button clicked and notify the user that the alarm is added successfully.
*/
void AlarmDia::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Message", "The alarm is added", QMessageBox::Ok);
    spinboxvalue= ui->spinBox_hr->value();
    spinboxvalue2= ui->spinBox_min->value();
    qDebug() << "Alarm hour" << spinboxvalue;
    qDebug() << "Alarm min" << spinboxvalue2;
}

/*
delete button clicked and notify the user that the alarm is added successfully.
*/
void AlarmDia::on_pushButton_clicked()
{
    QMessageBox::information(this,"Message", "The alarm is deleted  ", QMessageBox::Ok);
}


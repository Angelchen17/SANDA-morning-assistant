#include "alarmdia.h"
#include "ui_alarmdia.h"
#include "alarmClock.hpp"
//#include "Qvector"

alarmClock newAlarm;
QString name;

/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
AlarmDia::AlarmDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDia)
{
    ui->setupUi(this);
}

/**
 * @brief      Destroys the object.
 */
AlarmDia::~AlarmDia()
{
    delete ui;
}


/**
 * @brief      Called when push button 2 clicked.
 */
void AlarmDia::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Message", "The alarm is added", QMessageBox::Ok);
    spinboxvalue= ui->spinBox_hr->value();
    spinboxvalue2= ui->spinBox_min->value();
    qDebug() << "Alarm hour" << spinboxvalue;
    qDebug() << "Alarm min" << spinboxvalue2;
    std::vector<std::string> alarmTime = {std::to_string(spinboxvalue),std::to_string(spinboxvalue2)};
    qDebug() << "Alarm name" << ui->lineEdit_2->text();
    name= ui->lineEdit_2->text();
    alarmClock* newAlarm = new alarmClock(ui->lineEdit_2->text().toStdString(), alarmTime);
    //alarmList.push_back(newAlarm1);
    //newAlarm.display();
    //newAlarm.startAlarm();
    qDebug() << "alarm startedi\n";
    //alarmList.push_back(newAlarm);
//    while (newAlarm->getResult() != 1) {
//        continue;
//    }
//    QMessageBox::information(this,"Message", "Time is UP !!!!", QMessageBox::Ok);
}


/**
 * @brief      Called when push button clicked.
 */
void AlarmDia::on_pushButton_clicked()
{
    alarmName= ui->lineEdit->text();
    qDebug() << "Delete name" << alarmName;
    if(alarmName != name){
        QMessageBox::information(this,"Message", "Alarm name not found. Please try again", QMessageBox::Ok);
        //alarmName= ui->lineEdit->text();
        //continue;
    }else{
        newAlarm.deleteAlarm(alarmName.toStdString());
        //alarmList[0].deleteAlarm(alarmName.toStdString());
        QMessageBox::information(this,"Message", "The alarm is deleted.", QMessageBox::Ok);
    }
}


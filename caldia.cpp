#include "caldia.h"
#include "ui_caldia.h"
#include <vector>
#include "event.h"
//#include "calendar.hpp"
#include "getGCal.h"





/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
CalDia::CalDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalDia)
{
    ui->setupUi(this);
    //Calendar* myCal = new Calendar();
    //ui->label->setText(get);

}

/**
 * @brief      Destroys the object.
 */
CalDia::~CalDia()
{
    delete ui;
}

/**
 * @brief      Called on push add.
 */
void CalDia::on_push_add_clicked(){
    QMessageBox::information(this,"Message", "The event is added", QMessageBox::Ok);
    eventName = ui->lineEdit->text();
    eventDate = ui->lineEdit_2->text();
    eventDescription = ui->lineEdit_3->text();
    curCal->AddEvent(eventName.toStdString(), eventDate.toStdString(), eventDescription.toStdString());
}

/**
 * @brief      Called on push remove.
 */
void CalDia::on_push_remove_clicked(){
    mylist = curCal->ViewEvents();
    int correct = 0;
    QString EName = ui->lineEdit_13->text();
    for (int i = 0; i < mylist.size(); i++){
        if(mylist[i].get_name() == EName.toStdString()){
            correct = 1;
        }
    }
    if (correct == 1){
        QMessageBox::information(this,"Message", "The event is removed!", QMessageBox::Ok);
        curCal->DeleteEvent(ui->lineEdit_13->text().toStdString());
    }else{
        QMessageBox::information(this,"Message", "The event name is not found! Please try again", QMessageBox::Ok);
    }
}


/**
 * @brief      Called on push view.
 */
void CalDia::on_push_view_clicked(){
    //std::vector<event> list;
    mylist = curCal->ViewEvents();
    string eventout;
    for (int i = 0; i < mylist.size(); i++)
    {
       cout << "\nEvent name: " << mylist[i].get_name() <<"\nEvent date: " << mylist[i].get_date() << "\nEvent description: " << mylist[i].get_description() <<"\nDays until event: " << mylist[i].daysUntil() <<"\n";
       eventout += "\nEvent name: " + mylist[i].get_name() +"\nEvent date: " + mylist[i].get_date() + "\nEvent description: " + mylist[i].get_description() +"\nDays until event: " + to_string(mylist[i].daysUntil()) +"\n";

    }
    const QString msg = QString::fromStdString(eventout);
    QMessageBox::information(this,"Message", msg, QMessageBox::Ok);
}

/**
 * @brief      Called on push edit.
 */
void CalDia::on_push_edit_clicked(){
    QMessageBox::information(this,"Message", "The event is edited succefully!", QMessageBox::Ok);
    eventName = ui->lineEdit_7->text();
    eventDate = ui->lineEdit_8->text();
    eventDescription = ui->lineEdit_9->text();
    QString newName = ui->lineEdit_10->text();
    curCal->EditEvent(eventName.toStdString(),newName.toStdString(),eventDate.toStdString(),eventDescription.toStdString());

}

/**
 * @brief      Called on push view 2.
 */
void CalDia::on_push_view_2_clicked(){
    vector<myevent> gcal = ListGCal();
    string eventout;
    for (int i = 0; i < gcal.size(); i++)
    {
       cout << "\nEvent name: " << gcal[i].get_name() <<"\nEvent date: " << gcal[i].get_date() << "\nEvent description: " << gcal[i].get_description() <<"\nDays until event: " << gcal[i].daysUntil() <<"\n";
       eventout += "\nEvent name: " + gcal[i].get_name() +"\nEvent date: " + gcal[i].get_date() + "\nEvent description: " + gcal[i].get_description() +"\nDays until event: " + to_string(gcal[i].daysUntil()) +"\n";

    }
    const QString msg = QString::fromStdString(eventout);
    QMessageBox::information(this,"Message", msg, QMessageBox::Ok);

}

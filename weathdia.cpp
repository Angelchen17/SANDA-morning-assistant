#include "weathdia.h"
#include "ui_weathdia.h"

/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
WeathDia::WeathDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeathDia)
{
    ui->setupUi(this);
}

/**
 * @brief      Destroys the object.
 */
WeathDia::~WeathDia()
{
    delete ui;
}

/**
 * @brief      Destroys the object.
 */
void WeathDia::on_pushButton_clicked()
{
    //QMessageBox::information(this,"Message", "msg", QMessageBox::Ok);
    location = ui->lineEdit->text();
    weather curWea(location.toStdString());
    std::string weainfo = "\nCity: " + curWea.get_city() + "\nFeel: " + curWea.get_feel() + "\nTemperature: " + curWea.get_temp() + "\nTime: " +curWea.get_time();
    //ui->pushButton->setText(QString::fromStdString(curWea.get_city()) + "\n");
    //ui->pushButton->setText(QString::fromStdString(curWea.get_feel()) + "\n");
    //ui->pushButton->setText(QString::fromStdString(curWea.get_temp()) + "\n");
    //ui->pushButton->setText(QString::fromStdString(curWea.get_time()) + "\n");
    const QString msg = QString::fromStdString(weainfo);
    QMessageBox::information(this,"Message", msg, QMessageBox::Ok);
}

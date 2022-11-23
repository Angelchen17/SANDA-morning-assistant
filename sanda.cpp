#include "sanda.h"
#include "ui_sanda.h"

SANDA::SANDA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SANDA)
{
    ui->setupUi(this);
    ui->pushButton->setText("Alarm");
    ui->pushButton_2->setText("Calendar");
    ui->pushButton_3->setText("Weather");
    ui->pushButton_4->setText("Music");
    ui->pushButton_5->setText("News");

}

SANDA::~SANDA()
{
    delete ui;
}


void SANDA::on_pushButton_clicked()
{
    alrmdia = new AlarmDia(this);
    alrmdia->setWindowTitle("Alarm Clock");
    alrmdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    alrmdia->show();
}



void SANDA::on_pushButton_2_clicked()
{
    calendia = new CalDia(this);
    calendia->setWindowTitle("Calendar");
    calendia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    calendia->show();
}



void SANDA::on_pushButton_3_clicked()
{
    weathdia = new WeathDia(this);
    weathdia->setWindowTitle("Weather");
    weathdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    weathdia->show();
}



void SANDA::on_pushButton_6_clicked()
{
    insdia = new InstrucDia(this);
    insdia->setWindowTitle("Instruction");
    insdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    insdia->show();
}


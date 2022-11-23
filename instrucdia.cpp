#include "instrucdia.h"
#include "ui_instrucdia.h"

InstrucDia::InstrucDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstrucDia)
{
    ui->setupUi(this);
}

InstrucDia::~InstrucDia()
{
    delete ui;
}

#include "caldia.h"
#include "ui_caldia.h"

CalDia::CalDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalDia)
{
    ui->setupUi(this);
}

CalDia::~CalDia()
{
    delete ui;
}

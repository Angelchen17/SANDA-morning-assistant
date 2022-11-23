#include "weathdia.h"
#include "ui_weathdia.h"

WeathDia::WeathDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeathDia)
{
    ui->setupUi(this);
}

WeathDia::~WeathDia()
{
    delete ui;
}

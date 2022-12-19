#include "alarmwidget.h"
#include "ui_alarmwidget.h"

/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
alarmWidget::alarmWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::alarmWidget)
{
    ui->setupUi(this);
}

/**
 * @brief      Destroys the object.
 */
alarmWidget::~alarmWidget()
{
    delete ui;
}

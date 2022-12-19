#include "instrucdia.h"
#include "ui_instrucdia.h"

/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
InstrucDia::InstrucDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstrucDia)
{
    ui->setupUi(this);
}

/**
 * @brief      Destroys the object.
 */
InstrucDia::~InstrucDia()
{
    delete ui;
}

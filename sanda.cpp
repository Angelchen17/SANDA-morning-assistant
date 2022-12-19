#include "sanda.h"
#include "ui_sanda.h"

/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
SANDA::SANDA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SANDA)
{
    ui->setupUi(this);
    ui->pushButton->setText("Alarm");
    ui->pushButton_2->setText("Calendar");
    ui->pushButton_3->setText("Weather");
    //ui->pushButton_4->setText("Music");
    ui->pushButton_5->setText("News");

}

/**
 * @brief      Destroys the object.
 */
SANDA::~SANDA()
{
    delete ui;
}


/**
 * @brief      Alarm is Called when push button clicked.
 */
void SANDA::on_pushButton_clicked()
{
    alrmdia = new AlarmDia(this);
    alrmdia->setWindowTitle("Alarm Clock");
    alrmdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    alrmdia->show();
}



/**
 * @brief      Calendar is Called when push button 2 clicked.
 */
void SANDA::on_pushButton_2_clicked()
{
    calendia = new CalDia(this);
    calendia->setWindowTitle("Calendar");
    calendia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    calendia->show();
}



/**
 * @brief      Weather is Called when push button 3 clicked.
 */
void SANDA::on_pushButton_3_clicked()
{
    weathdia = new WeathDia(this);
    weathdia->setWindowTitle("Weather");
    weathdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    weathdia->show();
}



/**
 * @brief      Instruction box is Called when push button 6 clicked.
 */
void SANDA::on_pushButton_6_clicked()
{
    insdia = new InstrucDia(this);
    insdia->setWindowTitle("Instruction");
    insdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    insdia->show();
}

/**
 * @brief      News is Called when push button 5 clicked.
 */
void SANDA::on_pushButton_5_clicked()
{
    newsdia = new NewsDia(this);
    newsdia->setWindowTitle("News");
    newsdia->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    newsdia->show();
}

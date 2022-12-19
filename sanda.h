#ifndef SANDA_H
#define SANDA_H

#include <QMainWindow>
#include <QDebug>
#include "alarmdia.h"
#include "caldia.h"
#include "weathdia.h"
#include "instrucdia.h"
#include "newsdia.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SANDA; }
QT_END_NAMESPACE

class SANDA : public QMainWindow
{
    Q_OBJECT

public:
    SANDA(QWidget *parent = nullptr);
    ~SANDA();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::SANDA *ui;
    AlarmDia *alrmdia;
    CalDia *calendia;
    WeathDia *weathdia;
    InstrucDia *insdia;
    NewsDia *newsdia;
};
#endif // SANDA_H

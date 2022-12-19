#ifndef WEATHDIA_H
#define WEATHDIA_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "weather.hpp"

namespace Ui {
class WeathDia;
}

class WeathDia : public QDialog
{
    Q_OBJECT

public:
    explicit WeathDia(QWidget *parent = nullptr);
    ~WeathDia();


private:
    Ui::WeathDia *ui;
    QString location;

private slots:
    void on_pushButton_clicked();
};

#endif // WEATHDIA_H

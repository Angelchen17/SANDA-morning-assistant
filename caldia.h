#ifndef CALDIA_H
#define CALDIA_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "calendar.hpp"

namespace Ui {
class CalDia;
}

class CalDia : public QDialog
{
    Q_OBJECT

public:
    explicit CalDia(QWidget *parent = nullptr);
    ~CalDia();

private:
    Ui::CalDia *ui;
    QString eventName;
    QString eventDate;
    QString eventDescription;
    Calendar* curCal = new Calendar();
    std::vector<myevent> mylist;

private slots:
    void on_push_add_clicked();

    void on_push_remove_clicked();

    void on_push_edit_clicked();

    void on_push_view_clicked();

    void on_push_view_2_clicked();

};

#endif // CALDIA_H

#ifndef NEWSDIA_H
#define NEWSDIA_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "news.hpp"
#include "NewsObj.hpp"

namespace Ui {
class NewsDia;
}

class NewsDia : public QDialog
{
    Q_OBJECT

public:
    explicit NewsDia(QWidget *parent = nullptr);
    ~NewsDia();


private:
    Ui::NewsDia *ui;
    int newsnum;

private slots:
    void on_pushButton_clicked();
};

#endif // NEWSDIA_H

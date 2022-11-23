#ifndef CALDIA_H
#define CALDIA_H

#include <QDialog>

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
};

#endif // CALDIA_H

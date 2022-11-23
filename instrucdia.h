#ifndef INSTRUCDIA_H
#define INSTRUCDIA_H

#include <QDialog>

namespace Ui {
class InstrucDia;
}

class InstrucDia : public QDialog
{
    Q_OBJECT

public:
    explicit InstrucDia(QWidget *parent = nullptr);
    ~InstrucDia();

private:
    Ui::InstrucDia *ui;
};

#endif // INSTRUCDIA_H

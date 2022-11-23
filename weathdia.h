#ifndef WEATHDIA_H
#define WEATHDIA_H

#include <QDialog>

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
};

#endif // WEATHDIA_H

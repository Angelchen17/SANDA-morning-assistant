#ifndef MUSICDIA_H
#define MUSICDIA_H

#include <QDialog>
#include "music.cpp"

namespace Ui {
class MusicDia;
}

class MusicDia : public QDialog
{
    Q_OBJECT

public:
    explicit MusicDia(QWidget *parent = nullptr);
    ~MusicDia();
    void on_push_button();

private:
    Ui::MusicDia *ui;
    QString songName;
};

#endif // MUSICDIA_H

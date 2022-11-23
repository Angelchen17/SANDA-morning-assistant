#include "sanda.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SANDA w;
    w.show();
    return a.exec();
}

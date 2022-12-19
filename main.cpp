#include "sanda.h"
#include <QApplication>

/**
 * @brief      { function_description }
 *
 * @param[in]  argc  The count of arguments
 * @param      argv  The arguments array
 *
 * @return     { description_of_the_return_value }
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SANDA w;
    w.show();

    return a.exec();
}

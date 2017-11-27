#include "sistema.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sistema w;
    w.show();

    return a.exec();
}

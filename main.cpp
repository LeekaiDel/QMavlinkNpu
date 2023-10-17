#include "qmavlinknpu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMavlinkNpu w;
    w.show();
    return a.exec();
}

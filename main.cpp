#include "bumblebox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BumbleBox w;
    w.show();
    return a.exec();
}

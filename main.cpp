#include "mainplayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPlayer w;
    w.show();
    return a.exec();
}

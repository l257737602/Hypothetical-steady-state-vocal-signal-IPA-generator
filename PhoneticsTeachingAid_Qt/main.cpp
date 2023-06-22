#include "widget.h"

#include <QApplication>

#define MAXLENGTH_resultToOutput 256

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}


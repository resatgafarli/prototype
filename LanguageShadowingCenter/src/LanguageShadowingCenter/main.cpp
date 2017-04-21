#include "languageshadowingcenter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LanguageShadowingCenter w;
    w.show();

    return a.exec();
}

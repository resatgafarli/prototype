/******************************************************
Author: resat.gafarli@gmail.com
File: %{Cpp:License:FileName}
Date: 5/30/2017
License: GPL-3.0
*******************************************************/
#include <QCoreApplication>
#include "../LDAF/ldafmain.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LDAFMain ldafMain;
    return a.exec();
}

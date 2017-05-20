/******************************************************
Author: resat.gafarli@gmail.com
File: main.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include <QCoreApplication>
#include "ldafmain.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LDAFMain ldafMain;
    return a.exec();
}

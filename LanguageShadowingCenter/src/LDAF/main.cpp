/******************************************************
Author: resat.gafarli@gmail.com
File: main.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include <QGuiApplication>
#include "ldafmain.h"
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    LDAFMain ldafMain;
    return a.exec();
}

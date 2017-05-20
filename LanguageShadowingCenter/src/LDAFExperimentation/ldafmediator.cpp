/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafmediator.h"
#include <QDebug>
LDAFMediator::LDAFMediator(QObject *parent) : QObject(parent)
{
    qDebug()<<"LDAFMediator are constructed"<<endl;
}

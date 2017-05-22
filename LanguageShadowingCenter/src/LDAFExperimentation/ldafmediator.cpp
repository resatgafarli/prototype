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
    LDAFCommand command1(new LDAFRequestResponse(1) ,LDAFRequestResponse::sendUrl);
    command1.executeCommand();

    LDAFCommand command2(new LDAFRequestResponse(2) ,LDAFRequestResponse::sendUrl);
    command2.executeCommand();

}

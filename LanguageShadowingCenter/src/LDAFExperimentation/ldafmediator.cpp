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
}

void LDAFMediator::sendURL(QUrl url){
    qDebug()<<"LDAF Send URL "<<this<<url.toString()<<endl;
}

void LDAFMediator::sendJson(QJsonObject jsonObject){
    QJsonDocument doc(jsonObject);
    qDebug()<<"LDAF Send JSON "<<this<<doc.toJson()<<endl;

}


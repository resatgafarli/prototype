/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafmediator.h"
#include <QDebug>


LDAFMediator::LDAFMediator(QObject *parent, QPointer<LDAFCommandListProcessor> commandListProcessor) :
    LDAFBase(parent,commandListProcessor)
{

}

void LDAFMediator::setURLMessage(QUrl url){

    url.setPath("../../../src/LanguageShadowingCenter/"+url.path()+".qml");
    addCommand(url);
    processForwardByOne();
}

void LDAFMediator::setJsonMessage(QJsonObject jsonObject){
    QJsonDocument doc(jsonObject);
    qDebug()<<"JSON received from browser"<<this<<doc.toJson()<<endl;

}



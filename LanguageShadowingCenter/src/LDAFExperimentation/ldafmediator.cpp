/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafmediator.h"
#include <QDebug>


LDAFMediator::LDAFMediator(QObject *parent, LDAFCommandListProcessor * commandListProcessor) :
    LDAFBasic(parent)
{
    m_commandListProcessor = commandListProcessor;
}

void LDAFMediator::setURLMessage(QUrl url){
    qDebug()<<"URL received from browser "<<this<<url.toString()<<endl;
}

void LDAFMediator::setJsonMessage(QJsonObject jsonObject){
    QJsonDocument doc(jsonObject);
    qDebug()<<"JSON received from browser"<<this<<doc.toJson()<<endl;

}




void LDAFMediator::testCalls(){
    QUrl url;
    url.setPath("from/mediator");
    url.setUserName("resat");
    url.setPassword("resatpass");

    m_commandListProcessor->addCommand(url,m_object);

    QJsonObject jsonobject
    {
        {"from", 1},
        {"mediator", 2}
    };

    m_commandListProcessor->addCommand(jsonobject,m_object);
    m_commandListProcessor->processAllForward();
}

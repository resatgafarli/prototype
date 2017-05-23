/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafbrowser.h"
#include "ldafmediator.h"
#include <QDebug>
LDAFBrowser::LDAFBrowser(QObject * parent, LDAFCommandListProcessor * commandListProcessor) :
    LDAFBasic(parent)
{
    m_commandListProcessor = commandListProcessor;

}

void LDAFBrowser::setURLMessage(QUrl url){
    qDebug()<<"URL received from mediator "<<this<<url.toString()<<endl;
}

void LDAFBrowser::setJsonMessage(QJsonObject jsonObject){
    QJsonDocument doc(jsonObject);
    qDebug()<<"JSON received from mediator"<<this<<doc.toJson()<<endl;

}


void LDAFBrowser::testCalls(){
    QUrl url;
    url.setPath("from/browser");
    url.setUserName("resat");
    url.setPassword("resatpass");

    m_commandListProcessor->addCommand(url,m_object);

    QJsonObject jsonobject
    {
        {"from", 1},
        {"browser", 2}
    };

    m_commandListProcessor->addCommand(jsonobject,m_object);
    m_commandListProcessor->processAllForward();
}

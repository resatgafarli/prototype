/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafbrowser.h"
#include "ldafmediator.h"
#include <QDebug>
#include <QFile>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>


LDAFBrowser::LDAFBrowser(QObject * parent, QPointer<LDAFCommandListProcessor> commandListProcessor) :
    LDAFBase(parent,commandListProcessor),
    m_engine(new QQmlEngine),
    m_component (new QQmlComponent(m_engine)),
    m_appWindowRoot(nullptr)
{
    m_engine->rootContext()->setContextProperty("ldafbrowser",this);
    loadApplicationWindow();
}

void LDAFBrowser::loadApplicationWindow(){
    QUrl url("../../../src/LDAFExperimentation/ldafbrowser.qml");
    QFile file (url.path());
    if(file.exists()){
        m_component->loadUrl(url);
        m_appWindowRoot = m_component->create();
        for (auto e: m_component->errors()){
               qDebug()<<e.description()<<endl;
        }
        if (!m_appWindowRoot.isNull()){
           // connect(rootObject,SIGNAL(exampleQmlToCppSignal(QVariant)),this, SLOT(exampleQmlToCppSlot(QVariant)));
        }
    }
}

void LDAFBrowser::setURLMessage(QUrl url){

}

void LDAFBrowser::setJsonMessage(QJsonObject jsonObject){
    QJsonDocument doc(jsonObject);
    qDebug()<<"JSON received from mediator"<<this<<doc.toJson()<<endl;
}

void LDAFBrowser::openPage(QString path){
    QUrl url;
    url.setPath(path);
    addCommand(url);
    processForwardByOne();
}



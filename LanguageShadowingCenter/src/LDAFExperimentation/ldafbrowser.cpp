/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafbrowser.h"
#include "ldafmediator.h"
#include <QDebug>
LDAFBrowser::LDAFBrowser(QObject *parent, QPointer<LDAFMediator> ldafMediator) : QObject(parent),
    m_ldafmediator(ldafMediator)
{
    qDebug()<<"LDAFBrowser are constructed"<<endl;
}

void LDAFBrowser::sendURL(QUrl url){
    qDebug()<<"LDAF Send URL "<<this<<url.toString()<<endl;
}

void LDAFBrowser::sendJson(QJsonObject jsonObject){
    QJsonDocument doc(jsonObject);
    qDebug()<<"LDAF Send JSON "<<this<<doc.toJson()<<endl;

}

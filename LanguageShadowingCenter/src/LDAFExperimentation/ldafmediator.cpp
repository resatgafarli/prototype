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
    QUrl url;
    url.setPath("root/homeppage");
    url.setUserName("resat");
    url.setPassword("resatpass");

    LDAFCommand command1(new LDAFUrl(url), &LDAFMessageType::send);


    url.setPath("root/nextpage");
    LDAFCommand command2(new LDAFUrl(url), &LDAFMessageType::send);


    QJsonObject jsonobject
    {
        {"property1", 1},
        {"property2", 2}
    };
    LDAFCommand command3(new LDAFJson(jsonobject) ,&LDAFMessageType::send);

    command3.executeCommand();
    command2.executeCommand();
    command1.executeCommand();
}

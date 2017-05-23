/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmain.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafmain.h"
#include "ldafbrowser.h"
#include "ldafmediator.h"
#include <QDebug>


LDAFMain::LDAFMain(QObject *parent) : QObject(parent),
    m_ldafmediator(new LDAFMediator),
    m_ldafbrowser(new LDAFBrowser(m_ldafmediator))
{

    /*TODO:
        Complete Command List Processor
        Pass it to  Browser and Mediator as central command dispatcher
        Implement commands generation in Browser and Mediator according to use cases.

    */
   qDebug()<<"LDAFMain are constructed"<<endl;

   qDebug()<<"LDAFMediator are constructed"<<endl;
   QUrl url;
   url.setPath("root/homeppage");
   url.setUserName("resat");
   url.setPassword("resatpass");

   LDAFCommand command1(new LDAFUrl(url,m_ldafmediator), &LDAFMessageType::send);


   url.setPath("root/nextpage");
   LDAFCommand command2(new LDAFUrl(url,m_ldafbrowser), &LDAFMessageType::send);


   QJsonObject jsonobject
   {
       {"property1", 1},
       {"property2", 2}
   };
   LDAFCommand command3(new LDAFJson(jsonobject,m_ldafbrowser) ,&LDAFMessageType::send);

   command3.executeCommand();
   command2.executeCommand();
   command1.executeCommand();

}

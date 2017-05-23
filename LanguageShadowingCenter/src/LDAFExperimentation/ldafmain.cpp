/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmain.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafmain.h"
#include "ldafbasic.h"
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


   QUrl url;
   url.setPath("root/homeppage");
   url.setUserName("resat");
   url.setPassword("resatpass");

   LDAFCommandListProcessor messprocessor;
   messprocessor.addCommand(url,m_ldafmediator);

   url.setPath("root/nextpage");
   messprocessor.addCommand(url,m_ldafbrowser);

   QJsonObject jsonobject
   {
       {"property1", 1},
       {"property2", 2}
   };

   messprocessor.addCommand(jsonobject,m_ldafbrowser);
   messprocessor.processForwardByOne();
   messprocessor.processForwardByOne();
   messprocessor.processForwardByOne();

   messprocessor.processBackwardByOne();
   messprocessor.processBackwardByOne();
   messprocessor.processBackwardByOne();


}

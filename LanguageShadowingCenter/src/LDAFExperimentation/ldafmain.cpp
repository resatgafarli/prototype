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
   qDebug()<<"LDAFMain are constructed"<<endl;
}

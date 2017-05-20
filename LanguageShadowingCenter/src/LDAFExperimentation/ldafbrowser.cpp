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

/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmain.cpp
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#include "ldafmain.h"
#include "ldafbase.h"
#include "ldafbrowser.h"
#include "ldafmediator.h"
#include <QDebug>


LDAFMain::LDAFMain(QObject *parent) : QObject(parent),
    m_browserCLP(new LDAFCommandListProcessor),
    m_mediatorCLP(new LDAFCommandListProcessor),
    m_ldafmediator(new LDAFMediator(this,m_mediatorCLP)),
    m_ldafbrowser(new LDAFBrowser(this,m_browserCLP))
{

    m_ldafmediator->setReceiverObject(m_ldafbrowser);
    m_ldafbrowser->setReceiverObject(m_ldafmediator);
    m_ldafbrowser->openPage("../../src/LanguageShadowingCenter/FirstPage.qml");
}

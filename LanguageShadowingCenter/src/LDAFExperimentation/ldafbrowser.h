/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFBROWSER_H
#define LDAFBROWSER_H


#include "ldafbasic.h"

class LDAFMediator;

class LDAFBrowser : public LDAFBasic
{
    Q_OBJECT
public:
    explicit LDAFBrowser(QObject * parent, LDAFCommandListProcessor * commandListProcessor=nullptr);
    void testCalls();
private:
    void setURLMessage(QUrl);
    void setJsonMessage(QJsonObject);
};

#endif // LDAFBROWSER_H

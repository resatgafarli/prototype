/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFBROWSER_H
#define LDAFBROWSER_H


#include "ldafbase.h"

class LDAFMediator;
class QQmlEngine;
class QQmlComponent;

class LDAFBrowser : public LDAFBase
{
    Q_OBJECT
public:
    explicit LDAFBrowser(QObject * parent, QPointer<LDAFCommandListProcessor> commandListProcessor=nullptr);
    Q_INVOKABLE void openPage(QString path);
private:
    QPointer<QQmlEngine> m_engine;
    QPointer<QQmlComponent> m_component;

    void setURLMessage(QUrl);
    void setJsonMessage(QJsonObject);


};

#endif // LDAFBROWSER_H

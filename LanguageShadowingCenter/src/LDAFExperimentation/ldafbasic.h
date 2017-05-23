/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbasic
Date: 5/23/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFBASIC_H
#define LDAFBASIC_H
#include <QDebug>
#include <QQueue>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QPointer>


class LDAFBasic{
public:
   virtual void sendURL(QUrl) = 0;
   virtual void sendJson(QJsonObject) = 0;
};


class LDAFMessageType{
public:
    explicit LDAFMessageType(LDAFBasic * basicObject=nullptr):m_basicObject(basicObject){}
    virtual ~LDAFMessageType(){}
    virtual void send()=0;

protected:
    LDAFBasic * m_basicObject;
};

class LDAFUrl:public LDAFMessageType{
public:
    explicit LDAFUrl(QUrl url, LDAFBasic * basicObject):
    LDAFMessageType(basicObject),
    m_url(url){}
    virtual ~LDAFUrl(){}

    void send(){
        if (m_basicObject!=nullptr) m_basicObject->sendURL(m_url);
    }

private:
    QUrl m_url;
};

class LDAFJson:public LDAFMessageType{
public:
    explicit LDAFJson(QJsonObject jsonobject, LDAFBasic * basicObject):
        LDAFMessageType(basicObject),
        m_jsonobject(jsonobject){}
    virtual ~LDAFJson(){}
    void send(){
        if (m_basicObject!=nullptr) m_basicObject->sendJson(m_jsonobject);
    }

private:
    QJsonObject m_jsonobject;
};


class LDAFCommand{
    typedef void(LDAFMessageType:: *Method)();
public:
   explicit LDAFCommand(LDAFMessageType * object=nullptr, Method method=nullptr):
        m_object(object),
        m_method(method){  }
    virtual ~LDAFCommand(){
        if (m_object != nullptr)
            delete m_object;
    }
    void executeCommand(){
        if ((m_object!=nullptr)&&(m_method!=nullptr))
            (m_object->*m_method)();
    }
private:
    LDAFMessageType * m_object;
    Method m_method;
};

/* TODO:
 * Complete List processor.
 * implement addCommand interface methods
 * implement processListForward and processListBackward interface methods
*/

class LDAFCommandListProcessor {
public:

private:
    QQueue<LDAFCommand> m_processedQueue;
    QQueue<LDAFCommand> m_unprocessedQueue;
};

#endif // LDAFBASIC_H


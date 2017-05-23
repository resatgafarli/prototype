/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFMEDIATOR_H
#define LDAFMEDIATOR_H

#include <QObject>
#include <QPointer>
#include <QDebug>
#include <QQueue>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>


class LDAFMessageType{
public:
    virtual ~LDAFMessageType(){}
    virtual void send()=0;
};

class LDAFUrl:public LDAFMessageType{
public:
    explicit LDAFUrl(QUrl url):m_url(url){}
    virtual ~LDAFUrl(){}

    void send(){
        //TODO:
        //Browser and Mediator would have same base class with virtual method with argument QUrl.
        //This method would be called in hear and QUrl to
        //the object (browser or mediator) would be set in the constructor
        qDebug()<<"LDAF Send URL "<<this<<m_url.toString()<<endl;
    }

private:
    QUrl m_url;
};

class LDAFJson:public LDAFMessageType{
public:
    explicit LDAFJson(QJsonObject jsonobject):m_jsonobject(jsonobject){}
    virtual ~LDAFJson(){}
    void send(){
        //TODO:
        //Browser and Mediator would have same base class with virtual method with argument QUrl.
        //This method would be called in hear and QJson to
        //the object (browser or mediator) would be set in the constructor
        QJsonDocument doc(m_jsonobject);
        qDebug()<<"LDAF Send JSON "<<this<<doc.toJson()<<endl;

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

class LDAFMediator : public QObject
{
    Q_OBJECT
public:
    explicit LDAFMediator(QObject *parent = 0);



signals:

public slots:
};

#endif // LDAFMEDIATOR_H

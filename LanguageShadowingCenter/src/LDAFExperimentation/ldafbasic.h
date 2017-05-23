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
#include <QStack>


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
    void addCommand(QUrl message, LDAFBasic * toObject)
    {
        addUrlMessage(message,toObject);
    }

    void addCommand(QJsonObject message, LDAFBasic * toObject)
    {
        addJsonObjectMessage(message,toObject);
    }

    void processForwardByOne(){
        if (!m_activeQueue.isEmpty()){
            LDAFCommand * command  = m_activeQueue.dequeue();
            command->executeCommand();
            m_processedStack.push(command);
        }
    }

    void processBackwardByOne(){
        if (!m_processedStack.isEmpty()){
            LDAFCommand * command  = m_processedStack.top();
            command->executeCommand();
            m_processedStack.pop();
            m_activeQueue.enqueue(command);
        }
    }

    void processAllForward(){
        while (!m_activeQueue.isEmpty()){
            processForwardByOne();
        }
    }

    void processAllBackward(){
        while (!m_processedStack.isEmpty()){
            processBackwardByOne();
        }
    }

private:
    void addUrlMessage(QUrl & message, LDAFBasic * toObject){
        m_activeQueue.enqueue(new LDAFCommand(new LDAFUrl(message,toObject), &LDAFMessageType::send));
    }

    void addJsonObjectMessage(QJsonObject & message, LDAFBasic * toObject){
        m_activeQueue.enqueue(new LDAFCommand(new LDAFJson(message,toObject) ,&LDAFMessageType::send));
    }

    QQueue<LDAFCommand*> m_activeQueue;
    QStack<LDAFCommand*> m_processedStack;

};

#endif // LDAFBASIC_H


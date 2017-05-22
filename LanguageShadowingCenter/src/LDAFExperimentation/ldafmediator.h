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

/* TODO: add QURL and QJSON as function parameters.
*/
class LDAFRequestResponse{

public:

    explicit LDAFRequestResponse(int id):m_id(id){
    }
    void sendUrl(){
        //Browser and Mediator would havei same same base class with same virtual method name.
        //This method would be called in hear with QUrl
        qDebug()<<m_id<<":"<<"LDAF Send URL"<<this<<endl;
    }

    void sendJson(){
        //Browser and Mediator would have same same base class with same virtual method name.
        //This method would be called in hear with QUrl
        qDebug()<<m_id<<":"<<"LDAF Send JSON"<<this<<endl;
    }
private:
    int m_id;
};

class LDAFCommand{
    typedef void(LDAFRequestResponse:: *Method)();
public:
   explicit LDAFCommand(LDAFRequestResponse * object=nullptr, Method method=nullptr):
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
    LDAFRequestResponse * m_object;
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

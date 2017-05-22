/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFMEDIATOR_H
#define LDAFMEDIATOR_H

#include <QObject>


class LDAFUri{
//TODO: BIG 5 of this class should be implemented
private:
    QString m_method;
    QString m_resourceTree;
    QString m_resourceName;
    QString m_operation;
    QList<QPair<QString,QString>> m_operationParsVals;

public:
    explicit LDAFUri(QString method="", QString resource_tree="", QString resoruce_name="", QString operation=""):
        m_method(method),
        m_resourceTree(resource_tree),
        m_resourceName(resoruce_name),
        m_operation(operation){}

    void setOperationParsVals(QString par, QString val){
        m_operationParsVals.append(QPair<QString,QString>(par,val));
    }
};

class LDAFCommand{
    virtual void executeMethod() =0;
};

class LDAFRequest:public LDAFCommand {

};

class LDAFResponse:public LDAFCommand {

};


class LDAFProtocol {
public:


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

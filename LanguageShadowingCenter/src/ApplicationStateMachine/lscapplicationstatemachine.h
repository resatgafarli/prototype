/******************************************************
Author: resat.gafarli@gmail.com
File: lscapplicationstatemachine.h
Date: 4/21/2017
License: GPL-3.0
*******************************************************/


#ifndef LSCAPPLICATIONSTATEMACHINE_H
#define LSCAPPLICATIONSTATEMACHINE_H

#include "applicationstatemachine_global.h"
#include <QObject>
#include <QStateMachine>
#include <QPointer>
#include <QState>
#include <QList>
#include <QMap>
#include <QEventTransition>

/*---------------------- General Application State Machine Library --------------------------*/
#ifdef APPLICATIONSTATEMACHINE_LIBRARY
class APPLICATIONSTATEMACHINESHARED_EXPORT LSCApplicationStateMachine: public QObject
#else
class LSCApplicationStateMachine: public QObject
#endif
{
Q_OBJECT


public:
    LSCApplicationStateMachine();
    bool checkStarted();
    bool checkIfInState1();
    bool checkIfInState2();
    bool checkIfInState3();
    void switchToState(QString fromToState);
    void setObjectStateProperty(QObject & obj, QString property);
    Q_SLOT void start();

private:
    QStateMachine m_stateMachine;
    QPointer<QState> s1;
    QPointer<QState> s2;
    QPointer<QState> s3;

public:
};

/*---------------------- Custom Event Type Generator -------------------------------*/
#ifdef APPLICATIONSTATEMACHINE_LIBRARY
class APPLICATIONSTATEMACHINESHARED_EXPORT LSCCustomEventTypeGenereator: public QObject
#else
class LSCCustomEventTypeGenereator: public QObject
#endif
{
private:
    LSCCustomEventTypeGenereator(){}

public:
    static QEvent::Type getEventType(QString eventName);
};



#endif // LSCAPPLICATIONSTATEMACHINE_H


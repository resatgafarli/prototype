/******************************************************
Author: resat.gafarli@gmail.com
File: lscapplicationstatemachine.h
Date: 4/21/2017
License: GPL-3.0
*******************************************************/
#ifndef LSCAPPLICATIONSTATEMACHINE_H
#define LSCAPPLICATIONSTATEMACHINE_H

#include "lscapplicationstatemachine_global.h"
#include <QObject>
#include <QStateMachine>
#include <QPointer>
#include <QState>
#include <QList>
#include <QEventTransition>

/*---------------------- General Application State Machine Library --------------------------*/
#ifdef LSC_APPLICATIONSTATEMACHINE_LIBRARY
class LSC_APPLICATIONSTATEMACHINESHARED_EXPORT LSCApplicationStateMachine: public QObject
#else
class LSCApplicationStateMachine: public QObject
#endif
{
Q_OBJECT


public:
    LSCApplicationStateMachine();
    bool checkStarted();
    bool checkIfInState(QString state);
    void switchToState(QString toState);
    void setObjectStateProperty(QObject * obj, QString state, QString propertyName, QVariant propertyValue);
    Q_SLOT void start();
    void addStatesTransition(QString fromState, QString toState);
    void setInitialState(QString initialState);
    QString getCurrentState() const;

private:
    QPointer<QStateMachine> m_stateMachine;
    QMap<QString,QPointer<QState>> m_states;
    QPointer<QState> getState(QString stateName);


public:
};

/*---------------------- Custom Event Type Generator -------------------------------*/
#ifdef LSC_APPLICATIONSTATEMACHINE_LIBRARY
class LSC_APPLICATIONSTATEMACHINESHARED_EXPORT LSCCustomEventTypeGenereator: public QObject
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


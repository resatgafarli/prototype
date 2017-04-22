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
#include <QState>
#include <QStateMachine>
#include <QSharedPointer>


#ifdef APPLICATIONSTATEMACHINE_LIBRARY
class APPLICATIONSTATEMACHINESHARED_EXPORT LSCApplicationStateMachine: public QObject
#else
class LSCApplicationStateMachine: public QObject
#endif
{
Q_OBJECT


public:
    LSCApplicationStateMachine();
    Q_SLOT void start();

private:
    QSharedPointer<QState> s1;
    QSharedPointer<QState> s2;
    QSharedPointer<QStateMachine> m_stateMachine;

public:
    bool checkIfInState2();
    Q_SIGNAL void toState2();
};

#endif // LSCAPPLICATIONSTATEMACHINE_H

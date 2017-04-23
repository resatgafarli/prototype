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
#include <QPointer>


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
    QStateMachine m_stateMachine;
    QPointer<QState> s1;
    QPointer<QState> s2;


public:
    bool checkStarted();
    bool checkIfInState2();
    bool checkIfInState1();
    Q_SIGNAL void toState2();
    Q_SIGNAL void toState1();
};

#endif // LSCAPPLICATIONSTATEMACHINE_H


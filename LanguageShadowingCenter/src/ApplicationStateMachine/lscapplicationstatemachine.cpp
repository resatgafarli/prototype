/******************************************************
Author: resat.gafarli@gmail.com
File: lscapplicationstatemachine.cpp
Date: 4/21/2017
License: GPL-3.0
*******************************************************/

#include "lscapplicationstatemachine.h"
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QTimer>

LSCApplicationStateMachine::LSCApplicationStateMachine()
{
    s1 = new QState();
    s2 = new QState();
    m_stateMachine.addState(s1);
    m_stateMachine.addState(s2);
    s1->addTransition(this,SIGNAL(toState2()),s2);
    s2->addTransition(this,SIGNAL(toState1()),s1);
    m_stateMachine.setInitialState(s1);
}

void LSCApplicationStateMachine::start(){
    m_stateMachine.start();
    QCoreApplication::processEvents();
}
bool LSCApplicationStateMachine::checkStarted(){
    return m_stateMachine.isRunning();
}


bool LSCApplicationStateMachine::checkIfInState2() {
    if (m_stateMachine.configuration().contains(s2))
        return true;
    else
        return false;
}

bool LSCApplicationStateMachine::checkIfInState1() {
    if (m_stateMachine.configuration().contains(s1))
        return true;
    else
        return false;
}

/******************************************************
Author: resat.gafarli@gmail.com
File: lscapplicationstatemachine.cpp
Date: 4/21/2017
License: GPL-3.0
*******************************************************/

#include "lscapplicationstatemachine.h"


LSCApplicationStateMachine::LSCApplicationStateMachine()
{
    m_stateMachine = QSharedPointer<QStateMachine> (new QStateMachine);
    s1 = QSharedPointer<QState>(new QState(m_stateMachine.data()));
    s2 = QSharedPointer<QState>(new QState(m_stateMachine.data()));

    m_stateMachine->setInitialState(s1.data());
    s1->addTransition(this,SIGNAL(toState2()),s2.data());

}

void LSCApplicationStateMachine::start(){
    m_stateMachine->start();
}

bool LSCApplicationStateMachine::checkIfInState2() {
    if (!m_stateMachine.isNull())
        return m_stateMachine->configuration().contains(s2.data());
}

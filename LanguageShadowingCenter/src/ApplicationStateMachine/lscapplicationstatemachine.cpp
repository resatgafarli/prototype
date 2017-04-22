/******************************************************
Author: resat.gafarli@gmail.com
File: lscapplicationstatemachine.cpp
Date: 4/21/2017
License: GPL-3.0
*******************************************************/

#include "lscapplicationstatemachine.h"
#include <QDebug>
#include <QtWidgets/QApplication>
LSCApplicationStateMachine::LSCApplicationStateMachine()
{
    m_stateMachine = QSharedPointer<QStateMachine> (new QStateMachine);
    connect(m_stateMachine.data(),SIGNAL(started()),this,SLOT(started()));

    s1 = QSharedPointer<QState>(new QState(m_stateMachine.toWeakRef().data()));
    s2 = QSharedPointer<QState>(new QState(m_stateMachine.toWeakRef().data()));

    m_stateMachine->setInitialState(s1.data());
    s1->addTransition(this,SIGNAL(toState2()),s2.data());
}

void LSCApplicationStateMachine::start(){
    m_stateMachine->start();
    QApplication::processEvents();
}

bool LSCApplicationStateMachine::checkIfInState2() {
    if (!m_stateMachine.isNull())
        return m_stateMachine->configuration().contains(s2.data());
}

void LSCApplicationStateMachine::started(){
    qDebug()<<"started"<<endl;
}

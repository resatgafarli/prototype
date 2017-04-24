/******************************************************
Author: resat.gafarli@gmail.com
File: lscapplicationstatemachine.cpp
Date: 4/21/2017
License: GPL-3.0
*******************************************************/

#include "lscapplicationstatemachine.h"
#include <QDebug>
#include <QtWidgets/QApplication>

class EventTransition : public QAbstractTransition
{
    public:
        EventTransition(QEvent::Type type, QAbstractState *target, QState *parent = 0)
            : QAbstractTransition(parent), m_type(type)
            { setTargetState(target); }
        EventTransition(QEvent::Type type, const QList<QAbstractState *> &targets, QState *parent = 0)
            : QAbstractTransition(parent), m_type(type)
        { setTargetStates(targets); }
      protected:
      virtual bool eventTest(QEvent *e) {
            return (e->type() == m_type);
        }
      virtual void onTransition(QEvent *) {}
    private:
        QEvent::Type m_type;
};


LSCApplicationStateMachine::LSCApplicationStateMachine()
{
    s1 = new QState();
    s2 = new QState();
    s3 = new QState();

    //Forward transition
    s1->addTransition(new EventTransition(QEvent::Type(QEvent::User+1), s2));
    s2->addTransition(new EventTransition(QEvent::Type(QEvent::User+2), s3));
    s3->addTransition(new EventTransition(QEvent::Type(QEvent::User+3), s1));

    //Backward transition
    s1->addTransition(new EventTransition(QEvent::Type(QEvent::User+4), s3));
    s3->addTransition(new EventTransition(QEvent::Type(QEvent::User+5), s2));
    s2->addTransition(new EventTransition(QEvent::Type(QEvent::User+6), s1));


    m_stateMachine.addState(s1);
    m_stateMachine.addState(s2);
    m_stateMachine.addState(s3);
    m_stateMachine.setInitialState(s1);
}

void LSCApplicationStateMachine::start(){
    m_stateMachine.start();
    QCoreApplication::processEvents();
}
bool LSCApplicationStateMachine::checkStarted(){
    return m_stateMachine.isRunning();
}

void LSCApplicationStateMachine::switchToState(int stateNum){
    m_stateMachine.postEvent(new QEvent(QEvent::Type(QEvent::User+stateNum)));
}



bool LSCApplicationStateMachine::checkIfInState1() {
    if (m_stateMachine.configuration().contains(s1))
        return true;
    else
        return false;
}

bool LSCApplicationStateMachine::checkIfInState2() {
    if (m_stateMachine.configuration().contains(s2))
        return true;
    else
        return false;
}

bool LSCApplicationStateMachine::checkIfInState3(){
    if (m_stateMachine.configuration().contains(s3))
        return true;
    else
        return false;
}

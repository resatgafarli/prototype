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
    int t = QEvent::registerEventType();//65535
    s1->addTransition(new EventTransition(QEvent::Type(t), s2));
    t = QEvent::registerEventType();//65534
    s2->addTransition(new EventTransition(QEvent::Type(t), s3));
    t = QEvent::registerEventType();//65533
    s3->addTransition(new EventTransition(QEvent::Type(t), s1));

    //Backward transition
    t = QEvent::registerEventType();//65532
    s1->addTransition(new EventTransition(QEvent::Type(t), s3));
    t = QEvent::registerEventType();//65531
    s3->addTransition(new EventTransition(QEvent::Type(t), s2));
    t = QEvent::registerEventType();//65530
    s2->addTransition(new EventTransition(QEvent::Type(t), s1));


    m_stateMachine.addState(s1);
    m_stateMachine.addState(s2);
    m_stateMachine.addState(s3);
    m_stateMachine.setInitialState(s1);
}

void LSCApplicationStateMachine::setObjectStateProperty(QObject & obj, QString property){

    s1->assignProperty(&obj,property.toStdString().c_str(),"STATE1");
    s2->assignProperty(&obj,property.toStdString().c_str(),"STATE2");
    s3->assignProperty(&obj,property.toStdString().c_str(),"STATE3");
}

void LSCApplicationStateMachine::start(){
    m_stateMachine.start();
    QCoreApplication::processEvents();
}
bool LSCApplicationStateMachine::checkStarted(){
    return m_stateMachine.isRunning();
}

void LSCApplicationStateMachine::switchToState(int eventNum){
    m_stateMachine.postEvent(new QEvent(QEvent::Type(eventNum)));
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

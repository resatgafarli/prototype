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


LSCApplicationStateMachine::LSCApplicationStateMachine():
    m_stateMachine (new QStateMachine)
{
}

void LSCApplicationStateMachine::addStatesTransition(QString fromState, QString toState){

    QPointer<QState> stateFrom = getState(fromState);
    QPointer<QState> stateTo = getState(toState);
    stateFrom->addTransition(new EventTransition(LSCCustomEventTypeGenereator::getEventType(fromState+toState), stateTo));
}


QPointer<QState> LSCApplicationStateMachine::getState(QString stateName){
    QPointer<QState> retS;
    if (m_states.contains(stateName))
        retS = m_states[stateName];
    else {
            retS = new QState;
            m_stateMachine->addState(retS);
            m_states[stateName] = retS;
            retS->setObjectName(stateName);
    }

    return retS;
}


void LSCApplicationStateMachine::setInitialState(QString initialState){
    m_stateMachine->setInitialState(getState(initialState));
}

void LSCApplicationStateMachine::setObjectStateProperty(QObject & obj, QString state, QString propertyName, QVariant propertyValue){
    getState(state)->assignProperty(&obj,propertyName.toStdString().c_str(),propertyValue);
}

void LSCApplicationStateMachine::start(){
    m_stateMachine->start();
    QCoreApplication::processEvents();
}
bool LSCApplicationStateMachine::checkStarted(){
    return m_stateMachine->isRunning();
}

void LSCApplicationStateMachine::switchToState(QString fromState, QString toState){
    m_stateMachine->postEvent(new QEvent(LSCCustomEventTypeGenereator::getEventType(fromState+toState)));
}

bool LSCApplicationStateMachine::checkIfInState(QString state) {
    if (m_stateMachine->configuration().contains(getState(state)))
        return true;
    else
        return false;

}

/*---------------------- Custom Event Type Generator -------------------------------*/
QEvent::Type LSCCustomEventTypeGenereator::getEventType(QString eventName){
    static QMap<QString,QEvent::Type> m_eventMap;
    QEvent::Type et = static_cast<QEvent::Type> (-1);
    if(m_eventMap.contains(eventName))
            et = m_eventMap[eventName];
    else {
            et = static_cast<QEvent::Type> (QEvent::registerEventType());
            m_eventMap[eventName] = et;
    }

    return et;
}

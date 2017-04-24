/******************************************************
Author: resat.gafarli@gmail.com
File: tst_AppStateMachine.h
Date: 4/21/2017
License: GPL-3.0
*******************************************************/

#include "lscapplicationstatemachine.h"
#include <QString>
#include <QtTest>

class tst_AppStateMachine: public QObject
{
    Q_OBJECT

public:
    tst_AppStateMachine (){}

private Q_SLOTS:

    /*State machine creation and state switch test*/
    void stateMachineTransitionTest()
    {
        LSCApplicationStateMachine stateMachine;
        stateMachine.addStatesTransition("s1","s2");
        stateMachine.addStatesTransition("s2","s3");
        stateMachine.addStatesTransition("s3","s1");
        stateMachine.addStatesTransition("s1","s3");
        stateMachine.addStatesTransition("s3","s2");
        stateMachine.addStatesTransition("s2","s1");
        stateMachine.setInitialState("s1");
        stateMachine.start();

        QVERIFY(stateMachine.checkStarted());
        QVERIFY(stateMachine.checkIfInState("s1"));

        //Forward
        stateMachine.switchToState("s1","s2");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState("s2"));

        stateMachine.switchToState("s2","s3");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState("s3"));

        stateMachine.switchToState("s3","s1");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState("s1"));

        //Backward
        stateMachine.switchToState("s1","s3");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState("s3"));

        stateMachine.switchToState("s3","s2");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState("s2"));

        stateMachine.switchToState("s2","s1");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState("s1"));
    }

    /*State machine creation and state switch test, object property assigmnet test*/
    void stateMachinePropertyAssignmentTest()
    {
  /*      LSCApplicationStateMachine stateMachine;
        QObject obj1,obj2,obj3;
        obj1.setProperty("property","INITIAL");
        obj2.setProperty("property","INITIAL");
        obj3.setProperty("property","INITIAL");

        stateMachine.setObjectStateProperty(obj1,"property");
        stateMachine.setObjectStateProperty(obj2,"property");
        stateMachine.setObjectStateProperty(obj3,"property");

        stateMachine.start();
        QVERIFY(stateMachine.checkStarted());
        QVERIFY(stateMachine.checkIfInState1());
        QCOMPARE(obj1.property("property"),QVariant("STATE1"));
        QCOMPARE(obj2.property("property"),QVariant("STATE1"));
        QCOMPARE(obj3.property("property"),QVariant("STATE1"));

        //Forward
        stateMachine.switchToState("fromState1toState2");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());
        QCOMPARE(obj1.property("property"),QVariant("STATE2"));
        QCOMPARE(obj2.property("property"),QVariant("STATE2"));
        QCOMPARE(obj3.property("property"),QVariant("STATE2"));


        stateMachine.switchToState("fromState2toState3");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());
        QCOMPARE(obj1.property("property"),QVariant("STATE3"));
        QCOMPARE(obj2.property("property"),QVariant("STATE3"));
        QCOMPARE(obj3.property("property"),QVariant("STATE3"));

        stateMachine.switchToState("fromState3toState1");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());
        QCOMPARE(obj1.property("property"),QVariant("STATE1"));
        QCOMPARE(obj2.property("property"),QVariant("STATE1"));
        QCOMPARE(obj3.property("property"),QVariant("STATE1"));


        //Backward
        stateMachine.switchToState("fromState1toState3");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());
        QCOMPARE(obj1.property("property"),QVariant("STATE3"));
        QCOMPARE(obj2.property("property"),QVariant("STATE3"));
        QCOMPARE(obj3.property("property"),QVariant("STATE3"));


        stateMachine.switchToState("fromState3toState2");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());
        QCOMPARE(obj1.property("property"),QVariant("STATE2"));
        QCOMPARE(obj2.property("property"),QVariant("STATE2"));
        QCOMPARE(obj3.property("property"),QVariant("STATE2"));


        stateMachine.switchToState("fromState2toState1");QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());
        QCOMPARE(obj1.property("property"),QVariant("STATE1"));
        QCOMPARE(obj2.property("property"),QVariant("STATE1"));
        QCOMPARE(obj3.property("property"),QVariant("STATE1"));
*/
    }

};


class tst_CustomEventTypeGenerator: public QObject
{
    Q_OBJECT

public:
    tst_CustomEventTypeGenerator (){}

private Q_SLOTS:

     void customEventTypeGeneratorTest(){
        //First get test type map insertion
        QCOMPARE(LSCCustomEventTypeGenereator::getEventType("event1"),static_cast<QEvent::Type>(65535));
        QCOMPARE(LSCCustomEventTypeGenereator::getEventType("event2"),static_cast<QEvent::Type>(65534));

        //Second get test getting already inserted event types
        QCOMPARE(LSCCustomEventTypeGenereator::getEventType("event1"),static_cast<QEvent::Type>(65535));
        QCOMPARE(LSCCustomEventTypeGenereator::getEventType("event2"),static_cast<QEvent::Type>(65534));
     }
};




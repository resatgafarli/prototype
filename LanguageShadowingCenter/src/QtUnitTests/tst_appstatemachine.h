#include "lscapplicationstatemachine.h"
#include <QString>
#include <QtTest>

class AppStateMachineTests : public QObject
{
    Q_OBJECT

public:
    AppStateMachineTests (){}

private Q_SLOTS:

    void AppStateMachineTestsTest1()
    {
        LSCApplicationStateMachine stateMachine;
        stateMachine.start();
        QVERIFY(stateMachine.checkStarted());
        QVERIFY(stateMachine.checkIfInState1());

        //Forward
        stateMachine.switchToState(65535);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());

        stateMachine.switchToState(65534);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());

        stateMachine.switchToState(65533);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());

        //Backward
        stateMachine.switchToState(65532);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());

        stateMachine.switchToState(65531);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());

        stateMachine.switchToState(65530);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());
    }

    void AppStateMachineTestsTest2()
    {
        LSCApplicationStateMachine stateMachine;
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
        stateMachine.switchToState(65529);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());
        QCOMPARE(obj1.property("property"),QVariant("STATE2"));
        QCOMPARE(obj2.property("property"),QVariant("STATE2"));
        QCOMPARE(obj3.property("property"),QVariant("STATE2"));


        stateMachine.switchToState(65528);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());
        QCOMPARE(obj1.property("property"),QVariant("STATE3"));
        QCOMPARE(obj2.property("property"),QVariant("STATE3"));
        QCOMPARE(obj3.property("property"),QVariant("STATE3"));

        stateMachine.switchToState(65527);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());
        QCOMPARE(obj1.property("property"),QVariant("STATE1"));
        QCOMPARE(obj2.property("property"),QVariant("STATE1"));
        QCOMPARE(obj3.property("property"),QVariant("STATE1"));


        //Backward
        stateMachine.switchToState(65526);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());
        QCOMPARE(obj1.property("property"),QVariant("STATE3"));
        QCOMPARE(obj2.property("property"),QVariant("STATE3"));
        QCOMPARE(obj3.property("property"),QVariant("STATE3"));


        stateMachine.switchToState(65525);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());
        QCOMPARE(obj1.property("property"),QVariant("STATE2"));
        QCOMPARE(obj2.property("property"),QVariant("STATE2"));
        QCOMPARE(obj3.property("property"),QVariant("STATE2"));


        stateMachine.switchToState(65524);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());
        QCOMPARE(obj1.property("property"),QVariant("STATE1"));
        QCOMPARE(obj2.property("property"),QVariant("STATE1"));
        QCOMPARE(obj3.property("property"),QVariant("STATE1"));

    }

};





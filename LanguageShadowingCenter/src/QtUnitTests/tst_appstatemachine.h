#include "lscapplicationstatemachine.h"
#include <QString>
#include <QtTest>

class AppStateMachineTests : public QObject
{
    Q_OBJECT

public:
    AppStateMachineTests (){}

private Q_SLOTS:

    void AppStateMachineTestsTest()
    {
        LSCApplicationStateMachine stateMachine;
        stateMachine.start();
        QVERIFY(stateMachine.checkStarted());
        QVERIFY(stateMachine.checkIfInState1());

        //Forward
        stateMachine.switchToState(1);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());

        stateMachine.switchToState(2);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());

        stateMachine.switchToState(3);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());

        //Backward
        stateMachine.switchToState(4);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState3());

        stateMachine.switchToState(5);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState2());

        stateMachine.switchToState(6);QCoreApplication::processEvents();
        QVERIFY(stateMachine.checkIfInState1());


    }
};





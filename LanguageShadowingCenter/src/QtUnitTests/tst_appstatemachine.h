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
        emit stateMachine.toState2();
        QVERIFY(stateMachine.checkIfInState2());
        emit stateMachine.toState1();
        QVERIFY(stateMachine.checkIfInState1());

    }
};





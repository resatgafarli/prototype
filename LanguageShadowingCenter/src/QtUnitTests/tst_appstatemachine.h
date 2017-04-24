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
};





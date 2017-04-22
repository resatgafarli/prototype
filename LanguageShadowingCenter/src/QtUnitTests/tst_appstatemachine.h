#include <QString>
#include <QtTest>
#include <QSignalSpy>

#include "lscapplicationstatemachine.h"

class AppStateMachineTests : public QObject
{
    Q_OBJECT

public:
    AppStateMachineTests (){};

private Q_SLOTS:

    void AppStateMachineTestsTest()
    {
        LSCApplicationStateMachine stateMachine;
        stateMachine.start();
        QVERIFY2(stateMachine.checkIfInState2(), "Failure");
        emit stateMachine.toState2();
        //QVERIFY2(stateMachine.checkIfInState2(), "Succcess");
/*
        QCOMPARE(spy.count(), 1);
        QVERIFY2(spy.count() != 1, "Failure");
        QVERIFY2(spy.count() == 1, "Success");
*/
    }
};





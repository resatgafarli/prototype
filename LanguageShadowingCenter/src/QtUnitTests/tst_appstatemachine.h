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
        emit stateMachine.toState2();
        QCOMPARE(stateMachine.checkIfInState2(), true);
    }
};





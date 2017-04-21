#include <QString>
#include <QtTest>

class EpisdoPreparationTests : public QObject
{
    Q_OBJECT

public:
    EpisdoPreparationTests();

private Q_SLOTS:
    void episodePlayerStateMachineTest();
};

EpisdoPreparationTests::EpisdoPreparationTests()
{
}

void EpisdoPreparationTests::episodePlayerStateMachineTest()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(EpisdoPreparationTests)

#include "tst_episdopreparationtests.moc"

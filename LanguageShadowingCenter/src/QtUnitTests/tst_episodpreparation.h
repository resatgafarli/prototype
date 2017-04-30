/******************************************************
Author: resat.gafarli@gmail.com
File: tst_episodpreparation.h
Date: 4/21/2017
License: GPL-3.0
*******************************************************/
#include <QString>
#include <QtTest>
#include "lscepisodepreparationsm.h"
#include "lscepisodepreparation.h"


class tst_EpisodePreparationSM : public QObject
{
    Q_OBJECT

public:
    tst_EpisodePreparationSM(){};

private Q_SLOTS:
    void testCase1()
    {
        QPointer<LSCEpisodePreparation> ep = new LSCEpisodePreparation;
        QPointer<LSCEpisodePreparationSM> epSM = new
                LSCEpisodePreparationSM(static_cast<QPointer<LSCEpisodePreparationAtcsProps>>(ep));

        ep->state1Ac->trigger(); QApplication::processEvents();
        //TODO COMPARE UI STATES
        ep->state2Ac->trigger();QApplication::processEvents();
        //TODO COMPARE UI STATES

    }
};

class tst_EpisdoPreparation : public QObject
{
    Q_OBJECT

public:
    tst_EpisdoPreparation(){};

private Q_SLOTS:
    void testCase1()
    {
        QVERIFY2(true, "Failure");
    }
};







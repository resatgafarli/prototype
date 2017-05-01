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
#include "lscapplicationstatemachine.h"


class tst_LSCEpisodePreparationActsProps :public LSCEpisodePreparationActsProps{

public:
    tst_LSCEpisodePreparationActsProps(){}

    void startStopDoSomeThing(bool s){
        QVERIFY (do_some_thing != s);
        do_some_thing = s;
    }

    bool isDoSomeThing(){
        return do_some_thing;
    }
};

class tst_EpisodePreparationSM : public QObject
{
    Q_OBJECT

public:
    tst_EpisodePreparationSM(){};

private Q_SLOTS:
    void testCase1()
    {
        QPointer<tst_LSCEpisodePreparationActsProps> ep = new tst_LSCEpisodePreparationActsProps;
        QPointer<LSCEpisodePreparationSM> epSM = new
                LSCEpisodePreparationSM(static_cast<QPointer<LSCEpisodePreparationActsProps>>(ep));


        QCOMPARE(epSM->m_applicationSM->getCurrentState(),QString("INITIAL"));
        QCOMPARE(ep->pbSt1Ac->isVisible(),true);
        QCOMPARE(ep->pbSt2Ac->isVisible(),false);


        ep->pbSt1Ac->trigger(); QApplication::processEvents();
        ep->pbSt2Ac->trigger(); QApplication::processEvents();
        ep->pbSt3Ac->trigger(); QApplication::processEvents();

/*        QCOMPARE(epSM->m_applicationSM->getCurrentState(),QString("STATE1"));
        QCOMPARE(ep->pbSt1Ac->isVisible(),true);
        QCOMPARE(ep->pbSt2Ac->isVisible(),false);


        ep->pbSt2Ac->trigger();QApplication::processEvents();
        QCOMPARE(epSM->m_applicationSM->getCurrentState(),QString("STATE2"));
*/
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







/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#include "lscepisodepreparationsm.h"
#include "lscepisodepreparation.h"
#include "lscapplicationstatemachine.h"
#include <QCoreApplication>
#include <QDebug>



LSCEpisodePreparationSM::LSCEpisodePreparationSM(QPointer<LSCEpisodePreparationAtcsProps> uiActsProps) :  m_uiActsProps(uiActsProps),
    m_applicationSM(new LSCApplicationStateMachine)
{

    m_applicationSM->addStatesTransition("INITIAL","STATE1");
    m_applicationSM->addStatesTransition("STATE1","STATE2");
    m_applicationSM->addStatesTransition("STATE2","STATE3");
    m_applicationSM->addStatesTransition("STATE3","STATE4");
    m_applicationSM->addStatesTransition("STATE4","STATE5");
    m_applicationSM->addStatesTransition("STATE5","STATE1");

    connect(m_uiActsProps->pbSt1Ac,SIGNAL(triggered(bool)),SLOT(state1Triggered(bool)));
    connect(m_uiActsProps->pbSt2Ac,SIGNAL(triggered(bool)),SLOT(state2Triggered(bool)));
    connect(m_uiActsProps->pbSt3Ac,SIGNAL(triggered(bool)),SLOT(state3Triggered(bool)));
    connect(m_uiActsProps->pbSt4Ac,SIGNAL(triggered(bool)),SLOT(state4Triggered(bool)));
    connect(m_uiActsProps->pbSt5Ac,SIGNAL(triggered(bool)),SLOT(state5Triggered(bool)));


    //INITIAL
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt1Ac,"INITIAL","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt2Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt3Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt4Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt5Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"INITIAL","visible",false);

    //STATE1
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt1Ac,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt2Ac,"STATE1","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt3Ac,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt4Ac,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt5Ac,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE1","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE1","visible",true);


    //STATE2
    m_applicationSM->setObjectStateProperty(m_uiActsProps,"STATE2","do_some_thing",true);

    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt1Ac,"STATE2","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt2Ac,"STATE2","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt3Ac,"STATE2","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt4Ac,"STATE2","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt5Ac,"STATE2","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE2","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE2","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE2","visible",true);

    //STATE3
    m_applicationSM->setObjectStateProperty(m_uiActsProps,"STATE3","do_some_thing",false);

    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt1Ac,"STATE3","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt2Ac,"STATE3","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt3Ac,"STATE3","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt4Ac,"STATE3","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt5Ac,"STATE3","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE3","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE3","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE3","visible",false);

    //STATE4
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt1Ac,"STATE4","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt2Ac,"STATE4","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt3Ac,"STATE4","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt4Ac,"STATE4","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt5Ac,"STATE4","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE4","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE4","enabled",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE4","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE4","enabled",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE4","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE4","enabled",false);

    //STATE5
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt1Ac,"STATE5","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt2Ac,"STATE5","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt3Ac,"STATE5","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt4Ac,"STATE5","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->pbSt5Ac,"STATE5","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE5","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->lineEAc,"STATE5","enabled",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE5","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->comboAc,"STATE5","enabled",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE5","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->plainTextEAc,"STATE5","enabled",true);

    m_applicationSM->setInitialState("INITIAL");
    m_applicationSM->start();
}


void LSCEpisodePreparationSM::state1Triggered(bool){
    m_applicationSM->switchToState("STATE1");
}

void LSCEpisodePreparationSM::state2Triggered(bool){
    m_applicationSM->switchToState("STATE2");

}

void LSCEpisodePreparationSM::state3Triggered(bool){
    m_applicationSM->switchToState("STATE3");
}

void LSCEpisodePreparationSM::state4Triggered(bool){
    m_applicationSM->switchToState("STATE4");
}

void LSCEpisodePreparationSM::state5Triggered(bool){
    m_applicationSM->switchToState("STATE5");
}



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


    connect(m_uiActsProps->state1Ac,SIGNAL(changed()),SLOT(actionChanged()));
    connect(m_uiActsProps->state1Ac,SIGNAL(triggered(bool)),SLOT(state1Triggered(bool)));

    connect(m_uiActsProps->state2Ac,SIGNAL(changed()),SLOT(actionChanged()));
    connect(m_uiActsProps->state2Ac,SIGNAL(triggered(bool)),SLOT(state2Triggered(bool)));

    connect(m_uiActsProps->state3Ac,SIGNAL(changed()),SLOT(actionChanged()));
    connect(m_uiActsProps->state3Ac,SIGNAL(triggered(bool)),SLOT(state3Triggered(bool)));

    connect(m_uiActsProps->state4Ac,SIGNAL(changed()),SLOT(actionChanged()));
    connect(m_uiActsProps->state4Ac,SIGNAL(triggered(bool)),SLOT(state4Triggered(bool)));


    connect(m_uiActsProps->state5Ac,SIGNAL(changed()),SLOT(actionChanged()));
    connect(m_uiActsProps->state5Ac,SIGNAL(triggered(bool)),SLOT(state5Triggered(bool)));


    //INITIAL
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state1Ac,"INITIAL","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state2Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state3Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state4Ac,"INITIAL","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state5Ac,"INITIAL","visible",false);



    //STATE1
    m_applicationSM->setObjectStateProperty(m_uiActsProps->generalAc,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state1Ac,"STATE1","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state1Ac,"STATE1","enabled",false);

    //STATE2
    m_applicationSM->setObjectStateProperty(m_uiActsProps->generalAc,"STATE2","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state2Ac,"STATE2","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state2Ac,"STATE2","enabled",true);

    //STATE3
    m_applicationSM->setObjectStateProperty(m_uiActsProps->generalAc,"STATE3","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state3Ac,"STATE3","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state3Ac,"STATE3","enabled",true);

    //STATE4
    m_applicationSM->setObjectStateProperty(m_uiActsProps->generalAc,"STATE4","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state4Ac,"STATE4","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state4Ac,"STATE4","enabled",true);

    //STATE5
    m_applicationSM->setObjectStateProperty(m_uiActsProps->generalAc,"STATE5","visible",false);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state5Ac,"STATE5","visible",true);
    m_applicationSM->setObjectStateProperty(m_uiActsProps->state5Ac,"STATE5","enabled",false);

    m_applicationSM->setInitialState("INITIAL");
    m_applicationSM->start();
}


void LSCEpisodePreparationSM::actionChanged(){
    QAction * senderAction = static_cast<QAction *> (sender());
    for (QWidget * w: senderAction->associatedWidgets()){
        w->setVisible(senderAction->isVisible());
        w->setEnabled(senderAction->isEnabled());
    }
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



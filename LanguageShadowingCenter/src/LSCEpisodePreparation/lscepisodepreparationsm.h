/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/

#ifndef LSCEPISODEPREPARATIONSM_H
#define LSCEPISODEPREPARATIONSM_H
#include "lscepisodepreparation_global.h"
#include <QObject>
#include <QPointer>


class LSCApplicationStateMachine;
class LSCEpisodePreparationActsProps;


/************** Episode Preparation State Machine ************************/
#ifdef LSC_EPISODEPREPARATION_LIBRARY
class LSC_EPISODEPREPARATIONSHARED_EXPORT LSCEpisodePreparationSM : public QObject
#else
class LSCEpisodePreparationSM : public QObject
#endif
{
    Q_OBJECT
public:
    LSCEpisodePreparationSM(QPointer<LSCEpisodePreparationActsProps> uiActsProps);

private:
    QPointer<LSCEpisodePreparationActsProps> m_uiActsProps;
    QPointer<LSCApplicationStateMachine> m_applicationSM;


private:
        Q_SLOT void state1Triggered(bool);
        Q_SLOT void state2Triggered(bool);
        Q_SLOT void state3Triggered(bool);
        Q_SLOT void state4Triggered(bool);
        Q_SLOT void state5Triggered(bool);

    friend class tst_EpisodePreparationSM;

};

#endif // LSCEPISODEPREPARATIONSM_H

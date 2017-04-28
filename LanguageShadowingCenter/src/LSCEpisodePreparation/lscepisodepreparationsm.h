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
class LSCEpisodePreparationAtcsProps;


/************** Episode Preparation State Machine ************************/
#ifdef LSC_EPISODEPREPARATION_LIBRARY
class LSC_EPISODEPREPARATIONSHARED_EXPORT LSCEpisodePreparationSM : public QObject
#else
class LSCEpisodePreparationSM : public QObject
#endif
{
    Q_OBJECT
public:
    LSCEpisodePreparationSM(QPointer<LSCEpisodePreparationAtcsProps> uiActsProps);
    void switchToFirstState();
private:
    QPointer<LSCEpisodePreparationAtcsProps> m_uiActsProps;
    QPointer<LSCApplicationStateMachine> m_applicationSM;


private:
        Q_SLOT void actionChanged();

};

#endif // LSCEPISODEPREPARATIONSM_H

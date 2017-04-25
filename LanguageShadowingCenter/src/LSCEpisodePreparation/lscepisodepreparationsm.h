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

class tst_EpisodePreparationSM;
/************** Episode Preparation State Machine ************************/
class LSCEpisodePreparationSM : public QObject
{
    Q_OBJECT
public:
    explicit LSCEpisodePreparationSM(QObject *parent = 0);

private:
    bool den;

signals:

public slots:
    friend class tst_EpisodePreparationSM;

};

#endif // LSCEPISODEPREPARATIONSM_H

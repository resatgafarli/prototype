/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.h
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#ifndef LSC_EPISODEPREPARATION_H
#define LSC_EPISODEPREPARATION_H
#include "lscepisodepreparation_global.h"
#include <QWidget>

namespace Ui {
class LSCEpisodePreparation;
}

#ifdef LSC_EPISODEPREPARATION_LIBRARY
class LSC_EPISODEPREPARATIONSHARED_EXPORT LSCEpisodePreparation : public QWidget
#else
class LSCEpisodePreparation : public QWidget
#endif
{
    Q_OBJECT

public:
    explicit LSCEpisodePreparation(QWidget *parent = 0);
    ~LSCEpisodePreparation();
    void showEvent(QShowEvent*w);
Q_SLOT void actionChanged();

private:
    Ui::LSCEpisodePreparation *ui;
};

#endif // LSC_EPISODEPREPARATION_H

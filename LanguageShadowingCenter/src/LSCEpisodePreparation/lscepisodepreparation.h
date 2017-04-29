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
#include <QAction>
#include <QPointer>

namespace Ui {
class LSCEpisodePreparation;
}

class LSCEpisodePreparationSM;

class LSCEpisodePreparationAtcsProps: public QWidget{

public:
    explicit LSCEpisodePreparationAtcsProps(QWidget *parent = 0):QWidget(parent),
        generalAc(new QAction),
        state1Ac(new QAction),
        state2Ac(new QAction),
        state3Ac(new QAction),
        state4Ac(new QAction),
        state5Ac(new QAction)
    {

    }

protected:
    QPointer<QAction> generalAc;
    QPointer<QAction> state1Ac;
    QPointer<QAction> state2Ac;
    QPointer<QAction> state3Ac;
    QPointer<QAction> state4Ac;
    QPointer<QAction> state5Ac;

    friend class LSCEpisodePreparationSM;
    friend class tst_EpisodePreparationSM;
};

#ifdef LSC_EPISODEPREPARATION_LIBRARY
class LSC_EPISODEPREPARATIONSHARED_EXPORT LSCEpisodePreparation : public LSCEpisodePreparationAtcsProps
#else
class LSCEpisodePreparation : public LSCEpisodePreparationAtcsProps
#endif
{
    Q_OBJECT

public:
    explicit LSCEpisodePreparation(QWidget *parent = 0);
    ~LSCEpisodePreparation();
    void showEvent(QShowEvent*w);


private:
    Ui::LSCEpisodePreparation *ui;
};

#endif // LSC_EPISODEPREPARATION_H

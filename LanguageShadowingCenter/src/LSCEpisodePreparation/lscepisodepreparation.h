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



class LSCEpisodePreparationAtcsProps: public QWidget{
    Q_OBJECT
public:
    explicit LSCEpisodePreparationAtcsProps(QWidget *parent = 0):QWidget(parent),
        pbSt1Ac(new QAction(this)),
        pbSt2Ac(new QAction(this)),
        pbSt3Ac(new QAction(this)),
        pbSt4Ac(new QAction(this)),
        pbSt5Ac(new QAction(this)),
        comboAc(new QAction(this)),
        lineEAc(new QAction(this)),
        plainTextEAc(new QAction(this))
    {
        setActionsChangeSignals();
    }
    Q_SLOT void actionChanged();
protected:

    /*TODO: This actions should be clarified in terms of SM Trigger or UseCase !!!!*/
    QPointer<QAction> pbSt1Ac;
    QPointer<QAction> pbSt2Ac;
    QPointer<QAction> pbSt3Ac;
    QPointer<QAction> pbSt4Ac;
    QPointer<QAction> pbSt5Ac;
    QPointer<QAction> comboAc;
    QPointer<QAction> lineEAc;
    QPointer<QAction> plainTextEAc;

    void setActionsChangeSignals();


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


private slots:
    void on_pbSt1_clicked();
    void on_pbSt2_clicked();
    void on_pbSt3_clicked();
    void on_pbSt4_clicked();
    void on_pbSt5_clicked();

private:
    Ui::LSCEpisodePreparation *ui;
};

#endif // LSC_EPISODEPREPARATION_H

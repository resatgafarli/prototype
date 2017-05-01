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



class LSCEpisodePreparationActsProps: public QWidget{
    Q_OBJECT
    Q_PROPERTY (bool do_some_thing READ isDoSomeThing  WRITE startStopDoSomeThing)

public:
    explicit LSCEpisodePreparationActsProps(QWidget *parent = 0):QWidget(parent),
        pbSt1Ac(new QAction(this)),
        pbSt2Ac(new QAction(this)),
        pbSt3Ac(new QAction(this)),
        pbSt4Ac(new QAction(this)),
        pbSt5Ac(new QAction(this)),
        comboAc(new QAction(this)),
        lineEAc(new QAction(this)),
        plainTextEAc(new QAction(this)),
        do_some_thing (false)
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

    bool do_some_thing;
    virtual void startStopDoSomeThing(bool)=0;
    virtual bool isDoSomeThing() = 0;


    friend class LSCEpisodePreparationSM;
    friend class tst_EpisodePreparationSM;
};

#ifdef LSC_EPISODEPREPARATION_LIBRARY
class LSC_EPISODEPREPARATIONSHARED_EXPORT LSCEpisodePreparation : public LSCEpisodePreparationActsProps
#else
class LSCEpisodePreparation : public LSCEpisodePreparationActsProps
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
    void startStopDoSomeThing(bool);
    bool isDoSomeThing();


    Ui::LSCEpisodePreparation *ui;
};

#endif // LSC_EPISODEPREPARATION_H

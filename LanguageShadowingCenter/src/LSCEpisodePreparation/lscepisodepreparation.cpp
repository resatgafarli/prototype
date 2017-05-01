/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#include "lscepisodepreparation.h"
#include "ui_lscepisodepreparation.h"
#include <QDebug>

/*------------------------ LSCEpisodePreparationAtcsProps ----------------------------------*/
void LSCEpisodePreparationAtcsProps::setActionsChangeSignals(){
   QList<QAction*> actionList = findChildren<QAction*>(QString(""),Qt::FindDirectChildrenOnly);
   for (auto c :actionList){
       connect(c,SIGNAL(changed()),this,SLOT(actionChanged()));
   }
}

void LSCEpisodePreparationAtcsProps::actionChanged(){
    QAction * senderAction = static_cast<QAction *> (sender());
    for (QWidget * w: senderAction->associatedWidgets()){
        w->setVisible(senderAction->isVisible());
        w->setEnabled(senderAction->isEnabled());
    }
}


/*------------------------ LSCEpisodePreparation ----------------------------------*/
LSCEpisodePreparation::LSCEpisodePreparation(QWidget *parent):LSCEpisodePreparationAtcsProps(parent),
    ui(new Ui::LSCEpisodePreparation)
{
    ui->setupUi(this);

   //In order to disable all UI'S all widgets should be added in generalAc assotiation list.
    ui->pbSt1->addAction(pbSt1Ac);
    ui->pbSt2->addAction(pbSt2Ac);
    ui->pbSt3->addAction(pbSt3Ac);
    ui->pbSt4->addAction(pbSt4Ac);
    ui->pbSt5->addAction(pbSt5Ac);

    ui->lineEdit->addAction(lineEAc);
    ui->comboBox->addAction(comboAc);
    ui->plainTextEdit->addAction(plainTextEAc);
}

LSCEpisodePreparation::~LSCEpisodePreparation()
{
    delete ui;
}



void LSCEpisodePreparation::on_pbSt1_clicked()
{
    pbSt1Ac->trigger();
}

void LSCEpisodePreparation::on_pbSt2_clicked()
{
    pbSt2Ac->trigger();
}

void LSCEpisodePreparation::on_pbSt3_clicked()
{
    pbSt3Ac->trigger();
}

void LSCEpisodePreparation::on_pbSt4_clicked()
{
    pbSt4Ac->trigger();
}

void LSCEpisodePreparation::on_pbSt5_clicked()
{
    pbSt5Ac->trigger();
}

void LSCEpisodePreparation::startStopDoSomeThing(bool s){
    do_some_thing = s;
    if (do_some_thing == true)
        qDebug()<<"Start do something"<<endl;
    else
        qDebug()<<"Stop do something"<<endl;
}

bool LSCEpisodePreparation::isDoSomeThing(){
    return do_some_thing;
}


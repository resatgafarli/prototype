/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#include "lscepisodepreparation.h"
#include "ui_lscepisodepreparation.h"
#include <QGraphicsWidget>

LSCEpisodePreparation::LSCEpisodePreparation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LSCEpisodePreparation)
{
    ui->setupUi(this);
    ui->comboBox->addAction(ui->actionExample_action);
    ui->lineEdit->addAction(ui->actionExample_action);
    ui->plainTextEdit->addAction(ui->actionExample_action);
    connect (ui->actionExample_action,SIGNAL(changed()),this,SLOT(actionChanged()));
    ui->actionExample_action->setVisible(true);
    ui->actionExample_action->setEnabled(false);

}

LSCEpisodePreparation::~LSCEpisodePreparation()
{
    delete ui;
}

void LSCEpisodePreparation::actionChanged(){
    QAction * senderAction = static_cast<QAction *> (sender());
    for (QWidget * w: senderAction->associatedWidgets()){
        w->setVisible(senderAction->isVisible());
        w->setEnabled(senderAction->isEnabled());
    }

}

void LSCEpisodePreparation::showEvent(QShowEvent*w){

}

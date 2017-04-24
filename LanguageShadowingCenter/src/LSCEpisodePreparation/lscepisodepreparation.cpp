/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#include "lscepisodepreparation.h"
#include "ui_lscepisodepreparation.h"

LSCEpisodePreparation::LSCEpisodePreparation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LSCEpisodePreparation)
{
    ui->setupUi(this);
}

LSCEpisodePreparation::~LSCEpisodePreparation()
{
    delete ui;
}

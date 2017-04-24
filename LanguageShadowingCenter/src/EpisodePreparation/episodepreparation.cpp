/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#include "episodepreparation.h"
#include "ui_episodepreparation.h"

EpisodePreparation::EpisodePreparation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EpisodePreparation)
{
    ui->setupUi(this);
}

EpisodePreparation::~EpisodePreparation()
{
    delete ui;
}

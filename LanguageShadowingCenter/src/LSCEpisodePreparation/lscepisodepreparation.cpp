/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.cpp
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#include "lscepisodepreparation.h"
#include "ui_lscepisodepreparation.h"
#include <QGraphicsWidget>

LSCEpisodePreparation::LSCEpisodePreparation(QWidget *parent):LSCEpisodePreparationAtcsProps(parent),
    ui(new Ui::LSCEpisodePreparation)
{
    ui->setupUi(this);

   //In order to disable all UI'S all widgets should be added in generalAc assotiation list.
   ui->comboBox->addAction(generalAc);
   ui->lineEdit->addAction(generalAc);
   ui->plainTextEdit->addAction(generalAc);

   ui->pbSt1->addAction(generalAc);
   ui->pbSt2->addAction(generalAc);
   ui->pbSt3->addAction(generalAc);
   ui->pbSt4->addAction(generalAc);
   ui->pbSt5->addAction(generalAc);

   //STATE1
   ui->pbSt1->addAction(state1Ac);
   ui->comboBox->addAction(state1Ac);
   ui->lineEdit->addAction(state1Ac);

   //STATE2
   ui->pbSt2->addAction(state2Ac);
   ui->lineEdit->addAction(state2Ac);
   ui->plainTextEdit->addAction(state2Ac);

   //STATE3
   ui->pbSt3->addAction(state3Ac);
   ui->comboBox->addAction(state3Ac);
   ui->plainTextEdit->addAction(state3Ac);

   //STATE4
   ui->pbSt4->addAction(state4Ac);
   ui->comboBox->addAction(state4Ac);
   ui->plainTextEdit->addAction(state4Ac);
   ui->lineEdit->addAction(state4Ac);

   //STATE5
   ui->pbSt5->addAction(state5Ac);
   ui->comboBox->addAction(state5Ac);
   ui->plainTextEdit->addAction(state5Ac);
   ui->lineEdit->addAction(state5Ac);

}

LSCEpisodePreparation::~LSCEpisodePreparation()
{
    delete ui;
}



void LSCEpisodePreparation::showEvent(QShowEvent*w){

}

void LSCEpisodePreparation::on_pbSt1_clicked()
{
    state1Ac->trigger();
}

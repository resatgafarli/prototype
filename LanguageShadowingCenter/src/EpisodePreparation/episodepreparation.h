/******************************************************
Author: resat.gafarli@gmail.com
File: episodepreparation.h
Date: 4/24/2017
License: GPL-3.0
*******************************************************/
#ifndef EPISODEPREPARATION_H
#define EPISODEPREPARATION_H

#include <QWidget>

namespace Ui {
class EpisodePreparation;
}

class EpisodePreparation : public QWidget
{
    Q_OBJECT

public:
    explicit EpisodePreparation(QWidget *parent = 0);
    ~EpisodePreparation();

private:
    Ui::EpisodePreparation *ui;
};

#endif // EPISODEPREPARATION_H

/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFMEDIATOR_H
#define LDAFMEDIATOR_H

#include <QObject>

class LDAFMediator : public QObject
{
    Q_OBJECT
public:
    explicit LDAFMediator(QObject *parent = 0);

signals:

public slots:
};

#endif // LDAFMEDIATOR_H
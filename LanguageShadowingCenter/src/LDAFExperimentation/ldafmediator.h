/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmediator.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFMEDIATOR_H
#define LDAFMEDIATOR_H

#include <QObject>
#include <QPointer>
#include "ldafbasic.h"


class LDAFMediator : public QObject, public LDAFBasic
{
    Q_OBJECT
public:
    explicit LDAFMediator(QObject *parent = 0);

private:
    void sendURL(QUrl);
    void sendJson(QJsonObject);
};

#endif // LDAFMEDIATOR_H

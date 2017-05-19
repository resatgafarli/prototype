/******************************************************
Author: resat.gafarli@gmail.com
File: ldafmain.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFMAIN_H
#define LDAFMAIN_H

#include <QObject>

class LDAFMain : public QObject
{
    Q_OBJECT
public:
    explicit LDAFMain(QObject *parent = 0);

signals:

public slots:
};

#endif // LDAFMAIN_H
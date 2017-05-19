/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFBROWSER_H
#define LDAFBROWSER_H

#include <QObject>

class LDAFBrowser : public QObject
{
    Q_OBJECT
public:
    explicit LDAFBrowser(QObject *parent = 0);

signals:

public slots:
};

#endif // LDAFBROWSER_H
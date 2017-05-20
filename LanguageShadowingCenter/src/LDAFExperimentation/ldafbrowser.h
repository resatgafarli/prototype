/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbrowser.h
Date: 5/19/2017
License: GPL-3.0
*******************************************************/
#ifndef LDAFBROWSER_H
#define LDAFBROWSER_H

#include <QObject>
#include <QPointer>
class LDAFMediator;

class LDAFBrowser : public QObject
{
    Q_OBJECT
public:
    explicit LDAFBrowser(QObject *parent = 0, QPointer<LDAFMediator> ldafMediator=nullptr);

private:
    QPointer<LDAFMediator> m_ldafmediator;
signals:

public slots:
};

#endif // LDAFBROWSER_H

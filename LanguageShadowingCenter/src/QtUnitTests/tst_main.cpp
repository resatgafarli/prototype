/******************************************************
Author: resat.gafarli@gmail.com
File: tst_main.cpp
Date: 4/21/2017
License: GPL-3.0
*******************************************************/

#include <QString>
#include <QtTest>
#include <tst_appstatemachine.h>
#include <tst_episodpreparation.h>

int main(int argc, char** argv)
{
    QCoreApplication a(argc, argv);

   { tst_CustomEventTypeGenerator tc; QTest::qExec(&tc, argc, argv);}
   { tst_AppStateMachine tc; QTest::qExec(&tc, argc, argv);}

   //{ EpisdoPreparationTests tc; QTest::qExec(&tc, argc, argv);}

   QMetaObject::invokeMethod(&a, "quit", Qt::QueuedConnection);
   return a.exec();

}




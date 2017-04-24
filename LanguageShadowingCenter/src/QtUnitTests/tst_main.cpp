#include <QString>
#include <QtTest>
#include <tst_appstatemachine.h>
#include <tst_episodpreparation.h>

int main(int argc, char** argv)
{
    QCoreApplication a(argc, argv);

   { AppStateMachineTests tc; QTest::qExec(&tc, argc, argv);}
   //{ EpisdoPreparationTests tc; QTest::qExec(&tc, argc, argv);}

   QMetaObject::invokeMethod(&a, "quit", Qt::QueuedConnection);
   return a.exec();

}




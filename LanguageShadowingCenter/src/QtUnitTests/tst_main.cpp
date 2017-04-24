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




#include <QString>
#include <QtTest>
#include <tst_appstatemachine.h>
#include <tst_episodpreparation.h>

int main(int argc, char** argv)
{
   int status = 0;
   { AppStateMachineTests tc;status |= QTest::qExec(&tc, argc, argv);}
   { EpisdoPreparationTests tc; status |= QTest::qExec(&tc, argc, argv);}

   return status;
}




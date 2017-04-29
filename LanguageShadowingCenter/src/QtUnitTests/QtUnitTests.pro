#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T12:34:07
#
#-------------------------------------------------

QT       += widgets testlib
TARGET = tst_application_unit_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

include(../LanguageShadowingCenter.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(QtUnitTests.pri)

SOURCES +=  tst_main.cpp

HEADERS += tst_episodpreparation.h \
           tst_appstatemachine.h \
           tst_example_mediator_isolation.h



DEFINES += SRCDIR=\\\"$$PWD/\\\"



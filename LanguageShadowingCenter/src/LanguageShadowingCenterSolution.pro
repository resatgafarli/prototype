TEMPLATE = subdirs
include(LanguageShadowingCenter.pri)
SUBDIRS += LanguageShadowingCenter \
    QtUnitTests \
    ApplicationStateMachine 
    
CONFIG += debug_and_release

TEMPLATE = subdirs
include(LanguageShadowingCenter.pri)
SUBDIRS += LanguageShadowingCenter \
    ApplicationStateMachine
    #QtUnitTests
    
CONFIG += debug_and_release

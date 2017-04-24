TEMPLATE = subdirs
include(LanguageShadowingCenter.pri)
SUBDIRS += LanguageShadowingCenter \
    LSCApplicationStateMachine \
    LSCEpisodePreparation  \
    QtUnitTests
    
CONFIG += debug_and_release

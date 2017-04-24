TEMPLATE = subdirs
include(LanguageShadowingCenter.pri)
SUBDIRS += LanguageShadowingCenter \
    ApplicationStateMachine \
    QtUnitTests \
    EpisodePreparation
    
CONFIG += debug_and_release

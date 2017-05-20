TEMPLATE = subdirs
include(LanguageShadowingCenter.pri)
SUBDIRS +=  \
    LSCApplicationStateMachine \
    LSCEpisodePreparation  \
    QtUnitTests \
    LDAFExperimentation
    #LanguageShadowingCenter

#Example dependency definition
#SUBDIRS += my_executable my_library - above defined
#my_executable.subdir = app
#my_executable.depends = my_library
#my_library.subdir = lib

LanguageShadowingCenter.depends = LSCEpisodePreparation
LSCEpisodePreparation.depends = LSCApplicationStateMachine
    
CONFIG += debug_and_release

TEMPLATE = subdirs
include(LanguageShadowingCenter.pri)
SUBDIRS += LanguageShadowingCenter \
    LSCApplicationStateMachine \
    LSCEpisodePreparation  \
    QtUnitTests

#Example dependency definition
#SUBDIRS += my_executable my_library - above defined
#my_executable.subdir = app
#my_executable.depends = my_library
#my_library.subdir = lib

LanguageShadowingCenter.depends = LSCEpisodePreparation
LSCEpisodePreparation.depends = LSCApplicationStateMachine
    
CONFIG += debug_and_release

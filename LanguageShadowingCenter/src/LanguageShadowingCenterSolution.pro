TEMPLATE = subdirs
SUBDIRS += \
    LDAF \
    QtUnitTests \

#Example dependency definition
#SUBDIRS += my_executable my_library - above defined
#my_executable.subdir = app
#my_executable.depends = my_library
#my_library.subdir = lib

    
CONFIG += debug_and_release

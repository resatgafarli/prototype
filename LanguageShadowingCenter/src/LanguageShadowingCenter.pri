include(BuildPath.pri)

CONFIG += debug_and_release
DESTDIR = $$PROJECT_ROOT_DIRECTORY/destdir

CONFIG(debug, debug|release) {
    TARGET =        $$join(TARGET,,build/debug/,_D)
    OBJECTS_DIR =   $$DESTDIR/outputs/debug/obj
    MOC_DIR =       $$DESTDIR/outputs/debug/moc
    RCC_DIR =       $$DESTDIR/outputs/debug/rcc
    UI_DIR =        $$DESTDIR/outputs/debug/ui
    LIBS +=         "-L$$DESTDIR/build/debug"

} else {
    TARGET = $$join(TARGET,,build/release/,)
    OBJECTS_DIR =   $$DESTDIR/outputs/release/obj
    MOC_DIR =       $$DESTDIR/outputs/release/moc
    RCC_DIR =       $$DESTDIR/outputs/release/rcc
    UI_DIR =        $$DESTDIR/outputs/release/ui
    LIBS +=         "-L$$DESTDIR/build/release"
}

INCLUDEPATH += $$PROJECT_ROOT_DIRECTORY/src/QtUnitTests \
               $$PROJECT_ROOT_DIRECTORY/src/LSCEpisodePreparation


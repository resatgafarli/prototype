PROJECT_ROOT_DIRECTORY = $$PWD/..
PROJECT_BUILD_PATH = $$PROJECT_ROOT_DIRECTORY/build
CONFIG += debug_and_release

CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,$$PROJECT_BUILD_PATH/debug/,_D)
} else {
    TARGET = $$join(TARGET,,$$PROJECT_BUILD_PATH/release/,)
}

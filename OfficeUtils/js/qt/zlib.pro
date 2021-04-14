QT -= core
QT -= gui

TARGET = zlib
TEMPLATE = lib

CONFIG += staticlib
CONFIG += build_all_zlib

DEFINES += ZLIB_USE_DYNAMIC_LIBRARY

CORE_ROOT_DIR = $$PWD/../../..
PWD_ROOT_DIR = $$PWD
include($$CORE_ROOT_DIR/Common/base.pri)

INCLUDEPATH += \
    $$PWD/../../src/zlib-1.2.11/contrib/minizip \
    $$PWD/../../src/zlib-1.2.11

ADD_DEPENDENCY(OfficeUtils)

SOURCES += ../wasm/src/base.cpp \
    ../wasm/src/ioapibuf.c

HEADERS += ../wasm/src/base.h \
    ../wasm/src/ioapibuf.h \
    ../wasm/src/engine.h

#-------------------------------------------------
#
# Project created by QtCreator 2017-12-03T17:01:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = osces
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include/

DEFINES += NEEDS_OSCES_MAIN
CONFIG += nes

HEADERS += \
    Simulator.h \
    core/keyboard/Keyboard.h \
    core/keyboard/KeyboardInterface.h \
    core/keyboard/KeyCode.h \
    core/video/AbstractDisplay.h \
    core/video/Color.h \
    core/video/Display.h \
    core/video/PaintEngine.h \
    core/video/VideoSystem.h \
    core/OscesCore.h \
    drivers/irq/InterruptManager.h

SOURCES += \
    main.cpp \
    Simulator.cpp \
    core/keyboard/Keyboard.cpp \
    core/video/AbstractDisplay.cpp \
    core/video/Color.cpp \
    core/video/Display.cpp \
    core/video/PaintEngine.cpp \
    core/video/VideoSystem.cpp \
    core/OscesCore.cpp \
    drivers/irq/InterruptManager.cpp


nes {
include($$PWD/apps/nes_emulator/nes.pri)
}

snake {
include($$PWD/apps/snake/snake.pri)
}
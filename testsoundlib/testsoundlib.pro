#-------------------------------------------------
#
# Project created by QtCreator 2016-12-29T21:13:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testsoundlib
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp

HEADERS  +=

FORMS    +=

DISTFILES += \
    license.txt \
    readme.txt


INCLUDEPATH += $$PWD/../uiforms $$PWD/../soundlv2lib
DEPENDPATH += $$PWD/../uiforms

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../uiforms/release/ -luiforms
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../uiforms/debug/ -luiforms
else:unix: LIBS += -L$$OUT_PWD/../uiforms/ -luiforms

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../uiforms/release/libuiforms.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../uiforms/debug/libuiforms.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../uiforms/release/uiforms.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../uiforms/debug/uiforms.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../uiforms/libuiforms.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-soundlv2-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/soundlv2lib/release/ -lsoundlv2lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-soundlv2-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/soundlv2lib/debug/ -lsoundlv2lib
else:unix: LIBS += -L$$PWD/../../build-soundlv2-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/soundlv2lib/ -lsoundlv2lib

INCLUDEPATH += $$PWD/../soundlv2lib
DEPENDPATH += $$PWD/../soundlv2lib


#Following is needed for copying translation files
CONFIG(release, debug|release) {
    MYDESTDIR = $$OUT_PWD/release
} else {
    MYDESTDIR = $$OUT_PWD/debug
}

FILESTOCOPY2=$$PWD/../uiforms/*.qm
copydata.commands = $(COPY_FILE) $$shell_path($$FILESTOCOPY2) $$shell_path($$MYDESTDIR)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

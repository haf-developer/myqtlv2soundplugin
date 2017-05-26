QT += testlib
QT += gui
QT += widgets

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_firstguitest.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../uiforms/release/ -luiforms
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../uiforms/debug/ -luiforms
else:unix: LIBS += -L$$OUT_PWD/../../../../uiforms/ -luiforms

INCLUDEPATH += $$PWD/../../../../uiforms
DEPENDPATH += $$PWD/../../../../uiforms

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../uiforms/release/libuiforms.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../uiforms/debug/libuiforms.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../uiforms/release/uiforms.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../uiforms/debug/uiforms.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../../uiforms/libuiforms.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../build-soundlv2-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/soundlv2lib/release/ -lsoundlv2lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../build-soundlv2-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/soundlv2lib/debug/ -lsoundlv2lib
else:unix: LIBS += -L$$PWD/../../../../../build-soundlv2-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug/soundlv2lib/ -lsoundlv2lib

INCLUDEPATH += $$PWD/../../../../soundlv2lib
DEPENDPATH += $$PWD/../../../../soundlv2lib

#For copying translation files
message("Project config debugging messages")
message($$OUT_PWD)
message($$PWD)
COPYSOURCE=$$PWD/../../../../uiforms/
message($$COPYSOURCE)
FILESTOCOPY *= $$files($$COPYSOURCE*.qm)
message($$FILESTOCOPY)

CONFIG(release, debug|release) {
    MYDESTDIR = $$OUT_PWD/release
} else {
    MYDESTDIR = $$OUT_PWD/debug
}

FILESTOCOPY2=$$PWD/../../../../uiforms/*.qm
copydata.commands = $(COPY_FILE) $$shell_path($$FILESTOCOPY2) $$shell_path($$MYDESTDIR)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

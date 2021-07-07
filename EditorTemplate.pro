QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AssetDataBase.cpp \
    Events.hpp \
    CommandExecuter.cpp \
    ProjectFileType.cpp \
    ProjectManager.cpp \
    Window/Dialog/WindowNewFile.cpp \
    Window/Dialog/WindowNewProject.cpp \
    Window/WindowOutliner.cpp \
    Window/WindowProject.cpp \
    Window/WindowPropertyControls.cpp \
    Window/WindowStage.cpp \
    Window/WindowWorker.cpp \
    WindowManager.cpp \
    main.cpp

HEADERS += \
    AssetDataBase.h \
    CommandExecuter.h \
    ProjectFileType.h \
    ProjectManager.h \
    Window/Dialog/WindowNewFile.h \
    Window/Dialog/WindowNewProject.h \
    Window/EditorWindow.h \
    Window/WindowOutliner.h \
    Window/WindowProject.h \
    Window/WindowPropertyControls.h \
    Window/WindowStage.h \
    Window/WindowWorker.h \
    WindowManager.h

FORMS += \
    Window/Dialog/WindowNewFile.ui \
    Window/Dialog/WindowNewProject.ui \
    Window/WindowOutliner.ui \
    Window/WindowProject.ui \
    Window/WindowPropertyControls.ui \
    Window/WindowStage.ui \
    Window/WindowWorker.ui

UI_DIR = Window/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lqtadvanceddocking
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lqtadvanceddockingd

INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src


win32-msvc* {
  QMAKE_CXXFLAGS += /utf-8
}

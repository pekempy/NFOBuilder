QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
QT += webenginewidgets
QT += xml
CONFIG += c++11

QMAKE_INFO_PLIST

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filedownloader.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    filedownloader.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Icon Rules
ICON = "resources/plex-nfo.icns"
RC_ICONS = "resources/plex-nfo.ico"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/plex-nfo.ico \
    resources/plex-nfo.png

RESOURCES += \
    resources.qrc

VERSION = 1.3.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

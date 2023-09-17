QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    documentwindow.cpp \
    filemanager.cpp \
    finddialog.cpp \
    hyperlinkdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
    documentwindow.h \
    filemanager.h \
    finddialog.h \
    hyperlinkdialog.h \
    mainwindow.h \
    settings.h

TRANSLATIONS += \
    TextEditor_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    teresources.qrc

FORMS += \
    finddialog.ui \
    hyperlinkdialog.ui

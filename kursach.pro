QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bot.cpp \
    card.cpp \
    carddealer.cpp \
    cardgraphics.cpp \
    combination.cpp \
    deck.cpp \
    infowidget.cpp \
    main.cpp \
    menu.cpp \
    namings.cpp \
    playarena.cpp \
    player.cpp \
    playersmanager.cpp \
    settings.cpp

HEADERS += \
    bot.h \
    card.h \
    cardEnums.h \
    carddealer.h \
    cardgraphics.h \
    combination.h \
    deck.h \
    infowidget.h \
    menu.h \
    namings.h \
    playarena.h \
    player.h \
    playersmanager.h \
    settings.h

FORMS += \
    infowidget.ui \
    menu.ui \
    playarena.ui \
    playersmanager.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    table_resourse.qrc

QT       += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    account.cpp \
    content.cpp \
    creator.cpp \
    creatorlist.cpp \
    landingwindow.cpp \
    main.cpp \
    model.cpp \
    persona.cpp \
    sociallist.cpp \
    stats.cpp \
    stats_account.cpp \
    stats_content.cpp \
    stats_facebook.cpp \
    stats_instagram.cpp \
    stats_youtube.cpp

HEADERS += \
    account.h \
    content.h \
    creator.h \
    creatorlist.h \
    landingwindow.h \
    model.h \
    persona.h \
    sociallist.h \
    stats.h \
    stats_account.h \
    stats_content.h \
    stats_facebook.h \
    stats_instagram.h \
    stats_youtube.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=

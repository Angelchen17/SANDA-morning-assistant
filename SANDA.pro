QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NewsObj.cpp \
    alarmClock.cpp \
    alarmdia.cpp \
    caldia.cpp \
    calendar.cpp \
    event.cpp \
    getGCal.cpp \
    instrucdia.cpp \
    main.cpp \
    news.cpp \
    newsdia.cpp \
    sanda.cpp \
    weathdia.cpp \
    weather.cpp

HEADERS += \
    NewsObj.hpp \
    alarmClock.hpp \
    alarmdia.h \
    caldia.h \
    calendar.hpp \
    event.h \
    getGCal.h \
    instrucdia.h \
    news.hpp \
    newsdia.h \
    nlohmann/json.hpp \
    nlohmann/json_fwd.hpp \
    sanda.h \
    weathdia.h \
    weather.hpp

FORMS += \
    alarmdia.ui \
    caldia.ui \
    instrucdia.ui \
    newsdia.ui \
    sanda.ui \
    weathdia.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
#INCLUDEPATH += curl-7.86.0_2-win32-mingw/include

DISTFILES +=

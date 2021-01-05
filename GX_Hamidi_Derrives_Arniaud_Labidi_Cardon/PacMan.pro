TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Nos_fichiers/game.cpp \
    Nos_fichiers/gridmanagement.cpp \
    Nos_fichiers/nsutil.cpp \
    Nos_fichiers/params.cpp \
    main.cpp

DISTFILES += \
    Nos_fichiers/config.yaml

HEADERS += \
    Nos_fichiers/game.h \
    Nos_fichiers/gridmanagement.h \
    Nos_fichiers/nsutil.h \
    Nos_fichiers/params.h \
    Nos_fichiers/type.h \

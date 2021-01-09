TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(../MinGL2_IUT_AIX/mingl.pri)

SOURCES += \
    Nos_fichiers/game.cpp \
    Nos_fichiers/game2d.cpp \
    Nos_fichiers/gameLogic.cpp \
    Nos_fichiers/gridmanagement.cpp \
    Nos_fichiers/logicManager.cpp \
    Nos_fichiers/mainMenuLogic.cpp \
    Nos_fichiers/nsutil.cpp \
    Nos_fichiers/params.cpp \
    Nos_fichiers/player.cpp \
    main.cpp

DISTFILES += \
    Nos_fichiers/config.yaml \
    Nos_fichiers/res/gui/Bouton Option.png \
    Nos_fichiers/res/gui/Bouton Quitter.png \
    Nos_fichiers/res/gui/Bouton jouer curseur.png \
    Nos_fichiers/res/gui/Bouton jouer.png \
    Nos_fichiers/res/gui/Bouton option curseur.png \
    Nos_fichiers/res/gui/Bouton quitter curseur.png \
    Nos_fichiers/res/gui/Fond.png \
    Nos_fichiers/res/gui/background.i2s \
    Nos_fichiers/res/gui/img2si.py \
    Nos_fichiers/res/img2si.py \
    Nos_fichiers/res/tile000.png \
    Nos_fichiers/res/tile001.i2s \
    Nos_fichiers/res/tile001.png \
    Nos_fichiers/res/tile002.i2s \
    Nos_fichiers/res/tile002.png \
    Nos_fichiers/res/tile003.i2s \
    Nos_fichiers/res/tile003.png \
    Nos_fichiers/res/tile004.i2s \
    Nos_fichiers/res/tile004.png \
    Nos_fichiers/res/tile005.i2s \
    Nos_fichiers/res/tile005.png \
    Nos_fichiers/res/tile006.i2s \
    Nos_fichiers/res/tile006.png \
    Nos_fichiers/res/tile007.i2s \
    Nos_fichiers/res/tile007.png \
    Nos_fichiers/res/tile008.i2s \
    Nos_fichiers/res/tile008.png \
    Nos_fichiers/res/tile009.i2s \
    Nos_fichiers/res/tile009.png \
    Nos_fichiers/res/tile010.i2s \
    Nos_fichiers/res/tile010.png \
    Nos_fichiers/res/tile011.i2s \
    Nos_fichiers/res/tile011.png \
    Nos_fichiers/res/tile012.i2s \
    Nos_fichiers/res/tile012.png \
    Nos_fichiers/res/tile013.i2s \
    Nos_fichiers/res/tile013.png \
    Nos_fichiers/res/tile014.i2s \
    Nos_fichiers/res/tile014.png \
    Nos_fichiers/res/tile015.i2s \
    Nos_fichiers/res/tile015.png \
    Nos_fichiers/res/tile016.i2s \
    Nos_fichiers/res/tile016.png \
    Nos_fichiers/res/tile017.i2s \
    Nos_fichiers/res/tile017.png \
    Nos_fichiers/res/tile018.i2s \
    Nos_fichiers/res/tile018.png \
    Nos_fichiers/res/tile019.i2s \
    Nos_fichiers/res/tile019.png \
    Nos_fichiers/res/tile020.i2s \
    Nos_fichiers/res/tile020.png \
    Nos_fichiers/res/tile021.i2s \
    Nos_fichiers/res/tile021.png \
    Nos_fichiers/res/tile022.png \
    Nos_fichiers/res/tile023.png \
    Nos_fichiers/res/tile024.png \
    Nos_fichiers/res/tile025.png \
    Nos_fichiers/res/tile026.png \
    Nos_fichiers/res/tile027.png \
    Nos_fichiers/res/tile028.png \
    Nos_fichiers/res/tile029.png

HEADERS += \
    Nos_fichiers/game.h \
    Nos_fichiers/game2d.h \
    Nos_fichiers/gridmanagement.h \
    Nos_fichiers/logic.h \
    Nos_fichiers/logicManager.h \
    Nos_fichiers/nsutil.h \
    Nos_fichiers/params.h \
    Nos_fichiers/player.h \
    Nos_fichiers/type.h \

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(../MinGL2_IUT_AIX/mingl.pri)

SOURCES += \
    Nos_fichiers/animation.cpp \
    Nos_fichiers/cooldowns.cpp \
    Nos_fichiers/creditState.cpp \
    Nos_fichiers/entity.cpp \
    Nos_fichiers/game2d.cpp \
    Nos_fichiers/gameState.cpp \
    Correc_Prof/gridmanagement.cpp \
    Nos_fichiers/loadingState.cpp \
    Nos_fichiers/mainMenuState.cpp \
    Nos_fichiers/map.cpp \
    Nos_fichiers/nsutil.cpp \
    Correc_Prof/params.cpp \
    Nos_fichiers/player.cpp \
    Nos_fichiers/stateManager.cpp \
    main.cpp

DISTFILES += \
    Nos_fichiers/config.yaml \
    Nos_fichiers/level_1.map \
    Nos_fichiers/res/audio/3-2-1-go.wav \
    Nos_fichiers/res/audio/button-click.wav \
    Nos_fichiers/res/audio/player-hit-1.wav \
    Nos_fichiers/res/audio/player-moving-1.wav \
    Nos_fichiers/res/gui/APPUYER_A.png \
    Nos_fichiers/res/gui/Bouton Option.png \
    Nos_fichiers/res/gui/Bouton Option.png \
    Nos_fichiers/res/gui/Bouton Option.png \
    Nos_fichiers/res/gui/Bouton Quitter.png \
    Nos_fichiers/res/gui/Bouton Quitter.png \
    Nos_fichiers/res/gui/Bouton Quitter.png \
    Nos_fichiers/res/gui/Bouton jouer curseur.png \
    Nos_fichiers/res/gui/Bouton jouer curseur.png \
    Nos_fichiers/res/gui/Bouton jouer curseur.png \
    Nos_fichiers/res/gui/Bouton jouer.png \
    Nos_fichiers/res/gui/Bouton jouer.png \
    Nos_fichiers/res/gui/Bouton jouer.png \
    Nos_fichiers/res/gui/Bouton option curseur.png \
    Nos_fichiers/res/gui/Bouton option curseur.png \
    Nos_fichiers/res/gui/Bouton option curseur.png \
    Nos_fichiers/res/gui/Bouton quitter curseur.png \
    Nos_fichiers/res/gui/Bouton quitter curseur.png \
    Nos_fichiers/res/gui/Bouton quitter curseur.png \
    Nos_fichiers/res/gui/CREDITS.png \
    Nos_fichiers/res/gui/Fond.png \
    Nos_fichiers/res/gui/appuyer_a.i2s \
    Nos_fichiers/res/gui/background.i2s \
    Nos_fichiers/res/gui/btn_credits.i2s \
    Nos_fichiers/res/gui/btn_credits_hover.i2s \
    Nos_fichiers/res/gui/btn_options.i2s \
    Nos_fichiers/res/gui/btn_play.i2s \
    Nos_fichiers/res/gui/btn_play_hover.i2s \
    Nos_fichiers/res/gui/btn_quit.i2s \
    Nos_fichiers/res/gui/btn_quit_hover.i2s \
    Nos_fichiers/res/gui/credits.i2s \
    Nos_fichiers/res/gui/curseur.png \
    Nos_fichiers/res/gui/cursor.i2s \
    Nos_fichiers/res/gui/img2si.py \
    Nos_fichiers/res/gui/numbers/0.i2s \
    Nos_fichiers/res/gui/numbers/0.png \
    Nos_fichiers/res/gui/numbers/1.i2s \
    Nos_fichiers/res/gui/numbers/1.png \
    Nos_fichiers/res/gui/numbers/2.i2s \
    Nos_fichiers/res/gui/numbers/2.png \
    Nos_fichiers/res/gui/numbers/3.i2s \
    Nos_fichiers/res/gui/numbers/3.png \
    Nos_fichiers/res/gui/numbers/4.i2s \
    Nos_fichiers/res/gui/numbers/4.png \
    Nos_fichiers/res/gui/numbers/5.i2s \
    Nos_fichiers/res/gui/numbers/5.png \
    Nos_fichiers/res/gui/numbers/6.i2s \
    Nos_fichiers/res/gui/numbers/6.png \
    Nos_fichiers/res/gui/numbers/7.i2s \
    Nos_fichiers/res/gui/numbers/7.png \
    Nos_fichiers/res/gui/numbers/8.i2s \
    Nos_fichiers/res/gui/numbers/8.png \
    Nos_fichiers/res/gui/numbers/Sans titre.png \
    Nos_fichiers/res/gui/numbers/img2si.py \
    Nos_fichiers/res/gui/sidebar/gamescore.png \
    Nos_fichiers/res/gui/sidebar/hearts_0.i2s \
    Nos_fichiers/res/gui/sidebar/hearts_0.png \
    Nos_fichiers/res/gui/sidebar/hearts_1.i2s \
    Nos_fichiers/res/gui/sidebar/hearts_1.png \
    Nos_fichiers/res/gui/sidebar/hearts_2.i2s \
    Nos_fichiers/res/gui/sidebar/hearts_2.png \
    Nos_fichiers/res/gui/sidebar/hearts_3.i2s \
    Nos_fichiers/res/gui/sidebar/hearts_3.png \
    Nos_fichiers/res/gui/sidebar/panel.i2s \
    Nos_fichiers/res/gui/victory_screen/equal.i2s \
    Nos_fichiers/res/gui/victory_screen/equality.png \
    Nos_fichiers/res/gui/victory_screen/player1.i2s \
    Nos_fichiers/res/gui/victory_screen/player1.png \
    Nos_fichiers/res/gui/victory_screen/player2.i2s \
    Nos_fichiers/res/gui/victory_screen/player2.png \
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
    Nos_fichiers/animation.h \
    Nos_fichiers/cooldowns.h \
    Nos_fichiers/ennemy.h \
    Nos_fichiers/entity.h \
    Nos_fichiers/game2d.h \
    Correc_Prof/gridmanagement.h \
    Nos_fichiers/gameState.h \
    Nos_fichiers/map.h \
    Nos_fichiers/nsutil.h \
    Correc_Prof/params.h \
    Nos_fichiers/player.h \
    Nos_fichiers/state.h \
    Nos_fichiers/stateManager.h \
    Nos_fichiers/type.h \

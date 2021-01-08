#include "game2d.h"

#define FPS_LIMIT 60

#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "gameLogic.cpp"
#include "mainMenuLogic.cpp"

using namespace std;

MainMenuLogic mainMenuLogic;
GameLogic gameLogic;

/* 0 = MainMenu, 1 = Game, 2 = loading */
int state = 0;

int update(MinGL & window) {
    if (window.isPressed({ 27, false }))
        return -1;
    else if (window.isPressed({ 13, false })) {
        state = 2;
        gameLogic.load();
        state = 1;
    }

    if (state == 0)
        return mainMenuLogic.update();
    else if (state == 1)
        return gameLogic.update();

    return 0;
}

void render(MinGL & window) {
    if (state == 0) mainMenuLogic.render(window);
    else if (state == 1) gameLogic.render(window);
    else window.setBackgroundColor(nsGraphics::RGBAcolor(255, 0, 0, 0));
}

int load()
{
    bool userRequestedClose = false;

    // Initialise le système
    MinGL window("Double Trouble", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    // Chargement des ressources
    mainMenuLogic.load();

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen() && !userRequestedClose)
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        /*
         * Ici, écrivez votre logique d'affichage et de gestion des évènements
         */
        int ret = update(window);
        if (ret == -1) userRequestedClose = true;

        render(window);

        // On finit la frame en cours
        window.finishFrame();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }

    cout << "Fermeture du jeu!" << endl;

    return 0;
}

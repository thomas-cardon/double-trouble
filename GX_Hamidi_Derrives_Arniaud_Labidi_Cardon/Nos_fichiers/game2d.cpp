#include "game2d.h"

#include <iostream>
#include <thread>

#include "stateManager.cpp"

/**
 *
 * \file    game2d.cpp
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Method definitions for game2d.h
 */

using namespace std;
StateManager stateManager;

void update(MinGL & window, unsigned delta) {
    if (window.isPressed({ 27, true }))
        window.stopGaphic();

    stateManager.update(window, delta);
}

void render(MinGL & window) {
    stateManager.render(window);
}

int timeElapsed = 0, frames = 0;
int load()
{
    // Initialise le système
    MinGL window("Double Trouble", nsGraphics::Vec2D(900, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    // Chargement des ressources
    stateManager.load();

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        timeElapsed += frameTime.count() / 1000;
        ++frames;

        if (timeElapsed >= 1000) {
            cout << "FPS: " << frames << endl;
            timeElapsed = 0;
            frames = 0;
        }

        // On fait tourner les procédures
        Cooldowns::updateCooldowns(frameTime.count() / 1000 /* delta */);
        update(window, frameTime.count() / 1000 /* delta */);
        render(window);

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }

    cout << "Fermeture du jeu!" << endl;

    return 0;
}

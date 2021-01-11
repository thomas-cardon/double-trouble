#include "game2d.h"

#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <sys/time.h>

#include "mingl/mingl.h"
#include <GL/glut.h>

#include "stateManager.cpp"

using namespace std;

StateManager stateManager = StateManager();

int update(MinGL & window, int delta) {
    if (window.isPressed({ 27, true }))
        return -1;

    stateManager.update(window, delta);

    return 0;
}

void render(MinGL & window) {
    stateManager.render(window);
}

bool userRequestedClose = false;

int load()
{
    // Initialise le système
    MinGL window("Double Trouble", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    // Chargement des ressources
    stateManager.load();

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen() && !userRequestedClose)
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        // On fait tourner les procédures
        int ret = update(window, frameTime.count() / 1000 /* delta */);
        if (ret == -1) userRequestedClose = true;

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

#include "game2d.h"

#define FPS_LIMIT 60

#include <iostream>
#include <thread>

#include "mingl/mingl.h"
#include <GL/glut.h>

#include "logicManager.cpp"

using namespace std;

LogicManager logicManager = LogicManager();
int update(MinGL & window) {
    if (window.isPressed({ 27, false }))
        return -1;

    logicManager.update(window);

    return 0;
}

void render(MinGL & window) {
    logicManager.render(window);
}

bool userRequestedClose = false;
std::map< unsigned char, bool > state;
void keyboard_down( unsigned char key, int x, int y )
{
    if(key == 27)
        userRequestedClose = !userRequestedClose;
    else logicManager.onKeyDown(key);

    cout << key << endl;

    state[ key ] = true;
}

void keyboard_up( unsigned char key, int x, int y )
{
    state[ key ] = false;
}

void timer( int extra )
{
    glutPostRedisplay();
    glutTimerFunc( 64, timer, 0 );
}

int load()
{
    // Initialise le système
    MinGL window("Double Trouble", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    // Chargement des ressources
    logicManager.load();

    glutKeyboardFunc( keyboard_down );
    glutKeyboardUpFunc( keyboard_up );
    glutTimerFunc( 0, timer, 0 );
    glutIgnoreKeyRepeat( GL_TRUE );

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

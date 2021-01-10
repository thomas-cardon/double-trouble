#include <mingl/mingl.h>

#include "stateManager.h"

#include "mainMenuState.cpp"
#include "gameState.cpp"

#define N 2

using namespace nsGame;

int StateManager::current = 0;

MainMenuState menu;
GameState game;

/*
 * Allocation dynamique de tableau de State de taille N avec malloc()
 */

void StateManager::load() {
    std::cout << "[StateManager] Loading" << std::endl;

    menu.load();
    game.load();
}

void StateManager::events(MinGL & window) {
    while(window.getEventManager().hasEvent()) {
        if (current == 0) menu.events(window.getEventManager().pullEvent());
        else if (current == 1) game.events(window.getEventManager().pullEvent());
    }
}

int StateManager::update(MinGL & window) {
    if (current == 0) menu.update(window);
    else if (current == 1) game.update(window);

    events(window);

    return 0;
}

void StateManager::render(MinGL & window) {
    if (current == 0) menu.render(window);
    else if (current == 1) game.render(window);
}

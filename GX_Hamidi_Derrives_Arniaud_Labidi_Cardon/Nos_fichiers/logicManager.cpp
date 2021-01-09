#include <mingl/mingl.h>

#include "logicManager.h"

#include "mainMenuLogic.cpp"
#include "gameLogic.cpp"

#define N 2

using namespace nsGame;

int LogicManager::current = 0;

MainMenuLogic menu;
GameLogic game;

/*
 * Allocation dynamique de tableau de Logic de taille N avec malloc()
 */

void LogicManager::load() {
    LogicManager::current = 0;
    std::cout << "[LogicManager] Loading" << std::endl;

    menu.load();
    game.load();
}

void LogicManager::events(MinGL & window) {
    while(window.getEventManager().hasEvent()) {
        if (current == 0) menu.events(window.getEventManager().pullEvent());
        else if (current == 1) game.events(window.getEventManager().pullEvent());
    }
}

int LogicManager::update(MinGL & window) {
    if (current == 0) menu.update(window);
    else if (current == 1) game.update(window);

    events(window);

    return 0;
}

void LogicManager::render(MinGL & window) {
    if (current == 0) menu.render(window);
    else if (current == 1) game.render(window);
}

void LogicManager::onKeyDown(char key) {
    if (current == 0) menu.onKeyDown(key);
    else if (current == 1) game.onKeyDown(key);
}

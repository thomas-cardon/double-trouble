#include <mingl/mingl.h>

#include "stateManager.h"

#include "loadingState.cpp"
#include "mainMenuState.cpp"
#include "gameState.cpp"

using namespace nsGame;

int StateManager::current = -1;

LoadingState loader;
MainMenuState menu;
GameState game;

void StateManager::load() {
    std::cout << "[StateManager] Loading" << std::endl;

    menu.load();
    game.load();

    StateManager::current = 0;
}

void StateManager::events(MinGL & window) {
    while(window.getEventManager().hasEvent()) {
        const nsEvent::Event_t actualEvent = window.getEventManager().pullEvent();

        std::cout << "pulling event" << std::endl;
        if (current == 0) menu.events(actualEvent);
        else if (current == 1) game.events(actualEvent);
    }
}

int StateManager::update(MinGL & window, int delta) {
    events(window);

    if (current == 0) return menu.update(window, delta);
    else if (current == 1) return game.update(window, delta);


    return 0;
}

void StateManager::render(MinGL & window) {
    if (current == 0) menu.render(window);
    else if (current == 1) game.render(window);
    else loader.render(window);
}
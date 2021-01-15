#include <mingl/mingl.h>

#include "stateManager.h"

#include "loadingState.cpp"
#include "mainMenuState.cpp"
#include "gameState.cpp"
#include "creditState.cpp"

/**
 *
 * \file    stateManager.cpp
 * \author  Thomas Cardon
 * \date    9 janvier 2020
 * \version 1.0
 * \brief   Method definitions for stateManager.h
 */

using namespace nsGame;

int StateManager::current = 0;

void StateManager::load() {
    std::cout << "[StateManager] Loading" << std::endl;

    //this->states.insert(std::make_pair(-1, new LoadingState()));
    this->states.insert(std::make_pair(0, new MainMenuState()));
    this->states.insert(std::make_pair(1, new GameState()));
    this->states.insert(std::make_pair(99, new CreditState()));

    for (auto & state : states)
        state.second->load();
}

void StateManager::events(MinGL & window) {
    while(window.getEventManager().hasEvent()) {
        const nsEvent::Event_t actualEvent = window.getEventManager().pullEvent();
        states.at(current)->events(actualEvent);
    }
}

void StateManager::update(MinGL & window, unsigned delta) {
    events(window);
    State* state = states.at(current);

    state->update(window, delta);
}

void StateManager::render(MinGL & window) {
    if (states.size() > 0) states.at(current)->render(window);
}

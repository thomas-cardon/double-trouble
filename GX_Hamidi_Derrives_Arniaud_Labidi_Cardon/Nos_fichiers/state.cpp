#include "state.h"
#include "stateManager.h"

/**
 * @file    state.cpp
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Method definitions for State.h
 **/

using namespace nsGame;

void State::setState(int logic) {
    StateManager::current = logic;
}

int State::getState() {
    return StateManager::current;
}

#include "gameState.h"

/**
 *
 * \file    gameState.cpp
 * \author  Thomas Cardon, Alexandre Arniaud, Angèle Derrives, Mohamed Labidi, Ines Hamidi
 * \date    12 janvier 2021
 * \version 1.0
 * \brief   Method definitions for gameState.h
 */

using namespace nsGame;

void GameState::load() {
    this->hasLoaded = true;

    // Parameters loading
    int RetVal = LoadParams(this->Params, "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/config.yaml");
    if (RetVal != 0) throw "Une erreur s'est produite lors de la lecture du fichier YAML";

    // Map loading
    map = new Map();
    map->load();

    // Sounds loading
    audio.loadSound(RES_PATH + "/audio/game-over.wav");
    audio.loadSound(RES_PATH + "/audio/button-select.wav");

    // Scoreboard numbers loading
    numbers.resize(10);

    int i = 9; // 160 x 31
    while (i >= 0)
    {
        numbers[i] = new nsGui::Sprite(RES_PATH + "/gui/numbers/" + std::to_string(i) + ".i2s");
        i -= 1;
    }

    // Players loading
    player1 = new Player(1);
    player2 = new Player(2);

    player1->load(Params);
    player2->load(Params);
}

void GameState::destroy() {
    delete map;

    delete player1;
    delete player2;

    win = -1;

    this->hasLoaded = false;
}

void GameState::checkForWin(Player *p1, Player *p2) {
    if (player1->hearts == 0 && player2->hearts == 0 && player1->score == player2->score) win = 3;
    else if (player1->hearts == 0 && player2->hearts == 0 && player1->score > player2->score) win = 1;
    else if (player1->hearts == 0 && player2->hearts == 0 && player1->score < player2->score) win = 2;
    else if (player2->hearts == 0 || player1->score >= 9000) win = 1;
    else if (player1->hearts == 0 || player2->score >= 9000) win = 2;
    else if (player1->score > player2->score && map->items.size() == 0) win = 1;
    else if (player1->score < player2->score && map->items.size() == 0) win = 2;
    else {
        win = -1;
        return;
    }

    audio.playSoundFromBuffer(RES_PATH + "/audio/game-over.wav");
}

void GameState::update(MinGL & window, unsigned delta) {
    if (!hasLoaded) this->load();

    if (win == -1) {
        map->update(delta, player1, player2);

        player1->update(window, delta, map->getMat());
        player2->update(window, delta, map->getMat());

        checkForWin(player1, player2);

        player1->isAllowedToMove = player2->isAllowedToMove = true;
    }
    else player1->isAllowedToMove = player2->isAllowedToMove = false;

    if ((win != -1 && window.isPressed({ MENU_KEY, false })) || window.isPressed({ ESC_KEY, false })) {
        audio.playSoundFromBuffer(RES_PATH + "/audio/button-select.wav");

        this->destroy();
        this->setState(0);
    }

    if (player1->canBeHitBy(player2) && !player1->hasEffect(EffectType::INVINCIBLE) && player2->hasEffect(EffectType::INVINCIBLE)) { // +1 P2
        player1->damage();
        player1->spawn();

        player2->score += 1000;
    }
    else if (player2->canBeHitBy(player1) && !player2->hasEffect(EffectType::INVINCIBLE) && player1->hasEffect(EffectType::INVINCIBLE)) { // +1 P1
        player2->damage();
        player2->spawn();

        player1->score += 1000;
    }
    else if (player1->canBeHitBy(player2) && !player1->hasEffect(EffectType::INVINCIBLE) && !player2->hasEffect(EffectType::INVINCIBLE)) { // KILL !
        std::cout << "Hit ! P1 HP: " << player1->hearts << " | P2 HP: " << player2->hearts << std::endl;

        player1->damage();
        player2->damage();

        player1->spawn();
        player2->spawn();

        player1->score += 1000;
        player2->score += 1000;
    }
    else {
        for (auto & monster : this->map->monsters) {
            if (monster->slain) continue;
            int x = monster->getPosition().getX(), y = monster->getPosition().getY();

            if (x == player1->getPosition().getX() && y == player1->getPosition().getY()) {
                std::cout << "[" << monster->id()  << "] Collision P1" << std::endl;

                if (player1->hasEffect(EffectType::POWER)) {
                    monster->damage();
                    player1->score += 500;
                }
                else if (!player1->hasEffect(EffectType::INVINCIBLE)) {
                    player1->damage();
                    player1->spawn();
                }
            }
            else if (x == player2->getPosition().getX() && y == player2->getPosition().getY()) {
                std::cout << "[" << monster->id()  << "] Collision P2" << std::endl;

                if (player2->hasEffect(EffectType::POWER)) {
                    monster->damage();
                    player2->score += 500;
                }
                else if (!player2->hasEffect(EffectType::INVINCIBLE)) {
                    player2->damage();
                    player2->spawn();
                }
            }
        }
    }
}

void GameState::renderScore(MinGL & window, Player p) {
    std::string str = std::to_string(p.score);

    int i = 0;
    for (char & c : str) {
        // We're getting the ASCII version of the numbers
        numbers.at(c - '0')->setPosition(nsGraphics::Vec2D(692 + (i * 35), p.N == 1 ? 225 : 427));
        numbers.at(c - '0')->draw(window);

        i++;
    }
}

void GameState::renderVictoryScreen(MinGL & window) {
    if (win == 1) victoryScreen1.draw(window);
    else if (win == 2) victoryScreen2.draw(window);
    else if (win == 3) equalScreen.draw(window);
}

void GameState::render(MinGL & window) {
    if (!this->hasLoaded) return;

    map->render(window);

    window << sidebar;

    /*
     * Affichage coeurs (joueur 1)
     */
    if (player1->hearts == 3) {
        h3.setPosition(nsGraphics::Vec2D(677, 291));
        window << h3;
    }
    else if (player1->hearts == 2) {
        h2.setPosition(nsGraphics::Vec2D(677, 291));
        window << h2;
    }
    else if (player1->hearts == 1) {
        h1.setPosition(nsGraphics::Vec2D(677, 291));
        window << h1;
    }
    else {
        h0.setPosition(nsGraphics::Vec2D(677, 291));
        window << h0;
    }

    /*
     * Affichage coeurs (joueur 2)
     */
    if (player2->hearts == 3) {
        h3.setPosition(nsGraphics::Vec2D(677, 491));
        window << h3;
    }
    else if (player2->hearts == 2) {
        h2.setPosition(nsGraphics::Vec2D(677, 491));
        window << h2;
    }
    else if (player2->hearts == 1) {
        h1.setPosition(nsGraphics::Vec2D(677, 491));
        window << h1;
    }
    else {
        h0.setPosition(nsGraphics::Vec2D(677, 491));
        window << h0;
    }

    player1->render(window);
    player2->render(window);

    renderScore(window, *player1);
    renderScore(window, *player2);

    if (win > -1) renderVictoryScreen(window);
}

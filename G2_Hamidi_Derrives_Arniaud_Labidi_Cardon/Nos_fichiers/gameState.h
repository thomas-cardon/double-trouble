#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <mingl/audio/audioengine.h>
#include <mingl/gui/sprite.h>

#include "type.h"
#include "params.h"

#include "map.h"
#include "state.h"
#include "player.h"

#include "definitions.h"

/**
 * \file    gameState.h
 * \author  Thomas Cardon, Alexandre Arniaud, Angèle Derrives, Mohamed Labidi, Ines Hamidi
 * \date    12 janvier 2021
 * \version 1.0
 * \brief   gameState
 */

namespace nsGame {
    /**
     * @class GameState
     * @brief Defines the game logic
     * @author Thomas Cardon, Alexandre Arniaud, Angèle Derrives, Mohamed Labidi, Ines Hamidi
     */
    class GameState: public State {
        public:
            /** \brief Victory status: -1 = not yet, 0 = equal, 1 = player 1, 2 = player 2 */
            int win = -1;

            /** \brief The game map, and its grid */
            Map* map;

            /** \brief The game configuration file */
            CMyParam Params;

            /** \brief Players */
            Player* player1;
            Player* player2;

            /** \brief minGL 2 audio engine */
            nsAudio::AudioEngine audio;

            /** \brief Sidebar resources */
            nsGui::Sprite sidebar = nsGui::Sprite(RES_PATH + "/gui/sidebar/panel.i2s"),
            h0 = nsGui::Sprite(RES_PATH + "/gui/sidebar/hearts_0.i2s"),
            h1 = nsGui::Sprite(RES_PATH + "/gui/sidebar/hearts_1.i2s"),
            h2 = nsGui::Sprite(RES_PATH + "/gui/sidebar/hearts_2.i2s"),
            h3 = nsGui::Sprite(RES_PATH + "/gui/sidebar/hearts_3.i2s");

            /** \brief Victory screens */
            nsGui::Sprite victoryScreen1 = nsGui::Sprite(RES_PATH + "/gui/victory_screen/player1.i2s"),
            victoryScreen2 = nsGui::Sprite(RES_PATH + "/gui/victory_screen/player2.i2s"),
            equalScreen = nsGui::Sprite(RES_PATH + "/gui/victory_screen/equal.i2s");

            /** \brief Set of numbers from 0 to 9, used for the scoreboard, since minGL 2 doesn't allow custom fonts... */
            std::vector<nsGui::Sprite*> numbers;

            /**
             * @brief Loads State resources
             * @fn virtual void load();
             */
            virtual void load() override;

            /**
             * @brief Destroys state (and resets it)
             * @fn virtual void destroy();
             */
            virtual void destroy() override;

            /**
             * @brief Updates state
             * @fn virtual int update(MinGL & window, unsigned delta);
             */
            virtual void update(MinGL & window, unsigned delta) override;

            /**
             * @brief Checks every tick (State#update()) if one of the players have won (or not).
             * @param Player player1 - Le joueur 1
             * @param Player player2 - Le joueur 2
             * @fn void checkForWin(Player *p1, Player *p2);
             */
            void checkForWin(Player *p1, Player *p2);

            /**
             * @brief Renders resources
             * @fn virtual void render(MinGL & window);
             */
            virtual void render(MinGL & window) override;

            /**
             * @brief Renders the score on the sidebar for a given player
             * @param MinGL & window
             * @param Player p
             * @fn void renderScore(MinGL & window, Player p);
             */
            void renderScore(MinGL & window, Player p);

            /**
             * @brief Renders the victory screen
             * @param MinGL & window
             * @fn void renderVictoryScreen(MinGL & window);
             */
            void renderVictoryScreen(MinGL & window);
    };
};

#endif // GAMESTATE_H

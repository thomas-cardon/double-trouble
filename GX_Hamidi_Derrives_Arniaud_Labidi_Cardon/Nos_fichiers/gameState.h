#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <mingl/audio/audioengine.h>
#include <mingl/gui/sprite.h>

#include "type.h"
#include "params.h"


#include "map.h"
#include "state.h"
#include "player.cpp"

namespace nsGame {
    /**
     * @class GameState
     * @brief Defines the game logic
     * @author Thomas Cardon
     */
    class GameState: public State {
        public:
            int win = -1;

            /** \brief La grille du jeu */
            Map map;
            /** \brief Le fichier de configuration du jeu */
            CMyParam Params;

            Player player1 = Player(1), player2 = Player(2);

            /** \brief minGL 2 audio engine */
            nsAudio::AudioEngine audio;

            nsGui::Sprite sidebar = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/panel.i2s"),
            h0 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_0.i2s"),
            h1 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_1.i2s"),
            h2 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_2.i2s"),
            h3 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_3.i2s");

            nsGui::Sprite victoryScreen1 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player1.i2s"),
            victoryScreen2 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player2.i2s"),
            equalScreen = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/equal.i2s");

            /** \brief Set of numbers from 0 to 9, used for the scoreboard, since minGL 2 doesn't allow custom fonts... */
            std::vector<nsGui::Sprite*> numbers;

            /**
             * @brief Loads State resources
             * @fn virtual void load();
             */
            virtual void load() override;

            /**
             * @brief Updates state
             * @fn virtual int update(MinGL & window, unsigned delta);
             */
            virtual void update(MinGL & window, unsigned delta) override;

            /**
             * @brief Renders resources
             * @fn virtual void render(MinGL & window);
             */
            virtual void render(MinGL & window) override;

            /**
             * @brief Checks every tick (State#update()) if one of the players have won (or not).
             * @param Player player1 - Le joueur 1
             * @param Player player2 - Le joueur 2
             * @fn void checkForWin(Player player1, Player player2);
             */
            void checkForWin(Player player1, Player player2);

            /**
             * @brief Renders the score on the sidebar for a given player
             * @param MinGL & window
             * @param Player p
             * @fn void renderScore(MinGL & window, Player p);
             */
            void renderScore(MinGL & window, Player p);
    };
};

#endif // GAMESTATE_H
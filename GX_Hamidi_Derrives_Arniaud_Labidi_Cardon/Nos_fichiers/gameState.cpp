#include "state.h"

#include "type.h"
#include "gridmanagement.h"
#include "params.h"

#include <mingl/audio/audioengine.h>
#include <mingl/gui/sprite.h>
#include <mingl/gui/text.h>

#include "map.h"
#include "player.cpp"

using namespace nsGame;

class GameState: public State {
    public:
        int win = -1;
        bool canMove = true;

        Map map;
        CMyParam Params;

        Player player1 = Player(1), player2 = Player(2);

        nsGui::Sprite sidebar,
        h0 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_0.i2s"),
        h1 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_1.i2s"),
        h2 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_2.i2s"),
        h3 = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/hearts_3.i2s");

        nsGui::Sprite victoryScreen1, victoryScreen2, equalScreen;

nsAudio::AudioEngine audioEngine;


        GameState() : sidebar("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/sidebar/panel.i2s"), victoryScreen1("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player1.i2s", nsGraphics::Vec2D(0, 0)), victoryScreen2("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player2.i2s", nsGraphics::Vec2D(0, 0)), equalScreen("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/equal.i2s", nsGraphics::Vec2D(0, 0)) {}

        void load() override {
            int RetVal = LoadParams(Params, "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/config.yaml");
            if (RetVal != 0) throw "Une erreur s'est produite lors de la lecture du fichier YAML";

            map.load();

            audioEngine.loadSound("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");

            player1.load(Params);
            player2.load(Params);
        }

        void checkForWin(Player player1, Player player2) {
            if (player1.hearts == 0 && player2.hearts == 0)
                win = 3;
            else if (player1.hearts == 0) win = 2;
            else if (player2.hearts == 0) win = 1;
            else {
                win = -1;
                return;
            }

            canMove = false;
        }

        void update(MinGL & window, unsigned delta) override {
            map.update(delta);

            player1.update(window, delta, map.getMat());
            player2.update(window, delta, map.getMat());

            checkForWin(player1, player2);

            if (player1.canBeHitBy(player2)) { // KILL !
                std::cout << "Hit ! P1 HP: " << player1.hearts << " | P2 HP: " << player2.hearts << std::endl;

                audioEngine.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");

                player1.damage();
                player2.damage();

                player1.spawn();
                player2.spawn();

                player1.score += 1000;
                player2.score += 1000;
            }
        }

        void render(MinGL & window) override {
            window << sidebar;

            /*
             * Affichage coeurs (joueur 1)
             */
            if (player1.hearts == 3) {
                h3.setPosition(nsGraphics::Vec2D(677, 291));
                window << h3;
            }
            else if (player1.hearts == 2) {
                h2.setPosition(nsGraphics::Vec2D(677, 291));
                window << h2;
            }
            else if (player1.hearts == 1) {
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
            if (player2.hearts == 3) {
                h3.setPosition(nsGraphics::Vec2D(677, 491));
                window << h3;
            }
            else if (player2.hearts == 2) {
                h2.setPosition(nsGraphics::Vec2D(677, 491));
                window << h2;
            }
            else if (player2.hearts == 1) {
                h1.setPosition(nsGraphics::Vec2D(677, 491));
                window << h1;
            }
            else {
                h0.setPosition(nsGraphics::Vec2D(677, 491));
                window << h0;
            }

            map.render(window);

            player1.render(window);
            player2.render(window);

            window << nsGui::Text(nsGraphics::Vec2D(740, 96), std::to_string(player1.score), nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
            window << nsGui::Text(nsGraphics::Vec2D(740, 112), std::to_string(player2.score), nsGraphics::KWhite, nsGui::GlutFont::BITMAP_9_BY_15);

            if (win == 1) {
                victoryScreen1.draw(window);
            }
            else if (win == 2) {
                victoryScreen2.draw(window);
            }
            else if (win == 3) {
                equalScreen.draw(window);
            }
        }
};

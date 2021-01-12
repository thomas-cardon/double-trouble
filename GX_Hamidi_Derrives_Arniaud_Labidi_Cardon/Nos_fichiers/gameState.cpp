#include "state.h"

#include "type.h"
#include "gridmanagement.h"
#include "params.h"

#include "mingl/gui/sprite.h"
#include "mingl/gui/text.h"

#include "mingl/transition/transition_engine.h"

#include "player.cpp"

using namespace nsGame;

class GameState: public State {
    public:
        int win = -1;
        bool canMove = true;

        Map map;
        CMyParam Params;

        Player player1 = Player(1), player2 = Player(2);
        nsGui::Sprite victoryScreen1, victoryScreen2;

        GameState() : victoryScreen1("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player1.i2s", nsGraphics::Vec2D(0, 0)), victoryScreen2("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player2.i2s", nsGraphics::Vec2D(0, 0)) {}

        void load() override {
            int RetVal = LoadParams(Params, "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/config.yaml");
            if (RetVal != 0) throw "Une erreur s'est produite lors de la lecture du fichier YAML";

            map.load(Params);

            player1.load(Params);
            player2.load(Params);
        }

        void checkForWin(Player player1, Player player2) {
            if (player1.hearts == 0) win = 2;
            else if (player2.hearts == 0) win = 1;
            else {
                win = -1;
                return;
            }

            canMove = false;
        }

        int update(MinGL & window, int delta) override {
            player1.update(window, delta, map.getMat());
            player2.update(window, delta, map.getMat());

            checkForWin(player1, player2);

            if (player1.canBeHitBy(player2)) {
                std::cout << "Hit ! P1 HP: " << player1.hearts << " | P2 HP: " << player2.hearts << std::endl;
                player1.damage();
                player2.damage();

                player1.spawn(Params);
                player2.spawn(Params);
            }

            return 0;
        }

        void render(MinGL & window) override {
            window.clearScreen();

            map.render(window);

            player1.render(window);
            player2.render(window);

            window << nsGui::Text(nsGraphics::Vec2D(0, 16), "Score: " + std::to_string(player1.score), nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
            window << nsGui::Text(nsGraphics::Vec2D(0, 48), "Score: " + std::to_string(player1.score), nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);

            if (win == 1) {
                victoryScreen1.draw(window);
            }
            else if (win == 2) {
                victoryScreen2.draw(window);
            }
        }
};

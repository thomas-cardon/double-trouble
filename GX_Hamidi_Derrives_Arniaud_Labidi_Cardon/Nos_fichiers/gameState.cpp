#include "state.h"

#include "type.h"
#include "gridmanagement.h"
#include "params.h"

#include "mingl/gui/sprite.h"
#include "mingl/transition/transition_engine.h"

#include "player.cpp"

using namespace nsGame;

class GameState: public State {
    public:
        int won = -1;

        Map map;
        CMyParam Params;

        Player player1 = Player(1), player2 = Player(2);
        nsGui::Sprite victoryScreen1, victoryScreen2;

        GameState() : victoryScreen1("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player1.i2s", nsGraphics::Vec2D(-1000, 0)), victoryScreen2("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/victory_screen/player2.i2s", nsGraphics::Vec2D(-1000, 0)) {}

        void load() override {
            int RetVal = LoadParams(Params, "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/config.yaml");
            if (RetVal != 0) throw "Une erreur s'est produite lors de la lecture du fichier YAML";

            map.load(Params);

            player1.load(Params);
            player2.load(Params);
        }

        int update(MinGL & window, int delta) override {
            player1.update(window, delta, map.getMat());
            player2.update(window, delta , map.getMat());

            return 0;
        }

        void render(MinGL & window) override {
            window.clearScreen();

            map.render(window);

            player1.render(window);
            player2.render(window);

            if (won == 1) {
                victoryScreen1.draw(window);
            }
            else if (won == 2) {
                victoryScreen2.draw(window);
            }
        }
};

#include "state.h"

#include "type.h"
#include "gridmanagement.h"
#include "params.h"

#include "mingl/gui/sprite.h"

#include "player.cpp"

using namespace nsGame;

class GameState: public State {
    public:
    const unsigned KSize = 10;
    const unsigned PartyNum = 10;
    const unsigned KMaxPartyNum = KSize * KSize;

    const std::string BLOCK = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile011.i2s";

    const std::string WALL_X_1 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile007.i2s";
    const std::string WALL_X_2 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile008.i2s";
    const std::string WALL_X_3 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile009.i2s";

    const std::string WALL_Y_1 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile006.i2s";
    const std::string WALL_Y_2 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile016.i2s";
    const std::string WALL_Y_3 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile026.i2s";

    const std::string WALL_XY_1 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile003.i2s";
    const std::string WALL_XY_2 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile005.i2s";
    const std::string WALL_XY_3 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile023.i2s";
    const std::string WALL_XY_4 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile025.i2s";

    std::vector<nsGui::Sprite> sprites;

    bool Player1Turn = true;
    bool Victory = false;

    CMat Mat;
    CMyParam Params;

    Player player1 = Player(1), player2 = Player(2);

    void initSprites() {
        const unsigned nbLines = Mat.size ();
        const unsigned nbColumns = Mat[0].size ();

        for (unsigned i (0); i < nbLines; i = i + 1) {
            for (unsigned j (0); j < Mat[i].size(); ++j) {
                sprites.push_back(nsGui::Sprite(BLOCK, nsGraphics::Vec2D(i * 32, j * 32)));

                if (j > 0 && j < nbColumns - 1) {
                    /* Murs verticaux d'à gauche */
                    sprites.push_back(nsGui::Sprite(WALL_Y_2, nsGraphics::Vec2D(0, j * 32)));
                    /* Murs verticaux d'à droite */
                    sprites.push_back(nsGui::Sprite(WALL_Y_2, nsGraphics::Vec2D((nbColumns - 1) * 32, j * 32)));
                }
            }

            if (i > 0 && i < nbLines - 1) {
                /* Murs horizontaux du haut */
                sprites.push_back(nsGui::Sprite(i == 0 ? WALL_X_1 : (i != nbLines - 1 ? WALL_X_2 : WALL_X_3), nsGraphics::Vec2D(i * 32, 0)));
                /* Murs horizontaux du bas */
                sprites.push_back(nsGui::Sprite(i == 0 ? WALL_X_1 : (i != nbLines - 1 ? WALL_X_2 : WALL_X_3), nsGraphics::Vec2D(i * 32, (nbLines - 1) * 32)));
            }
        }

        /* Recoins */
        sprites.push_back(nsGui::Sprite(WALL_XY_1, nsGraphics::Vec2D(0, 0)));
        sprites.push_back(nsGui::Sprite(WALL_XY_2, nsGraphics::Vec2D((nbLines - 1) * 32, 0)));
        sprites.push_back(nsGui::Sprite(WALL_XY_3, nsGraphics::Vec2D(0, (nbLines - 1) * 32)));
        sprites.push_back(nsGui::Sprite(WALL_XY_4, nsGraphics::Vec2D((nbLines - 1) * 32, (nbLines - 1) * 32)));
    }

    void load() override {
        int RetVal = LoadParams(Params, "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/config.yaml");
        if (RetVal != 0) throw "Une erreur s'est produite lors de la lecture du fichier YAML";

        InitGrid(Mat, Params, player1.pos, player2.pos);
        initSprites();

        player1.load(Params);
        player2.load(Params);
    }

    int update(MinGL & window, int delta) override {
        player1.update(window, delta, Mat);
        player2.update(window, delta , Mat);

        return 0;
    }

    void renderGrid(MinGL & window) {
        for (auto &sprite : sprites)
            window << sprite;
    }

    void render(MinGL & window) override {
        window.clearScreen();

        renderGrid(window);

        player1.render(window);
        player2.render(window);
    }
};

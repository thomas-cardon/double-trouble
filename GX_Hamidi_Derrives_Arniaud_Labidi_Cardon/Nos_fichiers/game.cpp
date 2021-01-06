#include <iostream>

#include "./game.h"
#include "./params.h"
#include "./gridmanagement.h"

#include <map>
using namespace std;
template <class T, class U>
void ShowMap (const map<T,U> & AMap){
    for (const pair <T,U> & Val : AMap)                cout << "Cle : " << Val.first << "   "             << "Valeur : " << Val.second << endl;
    cout << endl;
}// ShowMap ()

/*
 * -> Vérification hors tableau (ajout de paramètres)
 * -> Possibilité de retourner des erreurs si besoin
 */
int MoveToken (CMat & Mat, const char & Move, CPosition & Pos, unsigned nbRows, unsigned nbColumns)
{
    int errors = 0;
    unsigned oldX = Pos.second, oldY = Pos.first;

    char car = Mat [Pos.first][Pos.second];

    switch (Move)
    {
    case 'A':
        if (Pos.first <= 0 || Pos.second <= 0) {
            errors = 1;
            break;
        }

        -- Pos.first;
        -- Pos.second;
        break;
    case 'Z':
        if (Pos.first <= 0) {
            errors = 1;
            break;
        }

        --Pos.first;
        break;
    case 'E':
        if (Pos.first <= 0 || Pos.second + 1 >= nbColumns) {
            errors = 1;
            break;
        }

        --Pos.first;
        ++Pos.second;
        break;
    case 'Q':
        if (Pos.second <= 0) {
            errors = 1;
            break;
        }

        --Pos.second;
        break;
    case 'D':
        if (Pos.second + 1 >= nbColumns) {
            errors = 1;
            break;
        }

        ++Pos.second;
        break;
    case 'W':
        if (Pos.first >= nbRows || Pos.second <= 0) {
            errors = 1;
            break;
        }

        ++Pos.first;
        --Pos.second;
        break;
    case 'X':
        if (Pos.first + 1 >= nbRows) {
            errors = 1;
            break;
        }

        ++Pos.first;
        break;
    case 'C':
        if (Pos.first + 1 >= nbRows || Pos.second + 1 >= nbColumns) {
            errors = 1;
            break;
        }

        ++Pos.first;
        ++Pos.second;
        break;
    default:
        errors = 2;
        break;
    }

    Mat [oldY][oldX] = KEmpty;
    Mat [Pos.first][Pos.second] = car;

    return errors;
} //MoveToken ()

/*
 * -> Meilleur affichage texte
 * -> Réflection des changements de paramètres de #MoveToken
 * -> En cas d'erreur de #MoveToken (erreur humaine du moins), le tour suivant devra être refait par le même joueur
 */
int ppal (void)
{

    const unsigned KSize (10);
    unsigned PartyNum (1);
    const unsigned KMaxPartyNum (KSize * KSize);
    CMat Mat;

    bool Player1Turn (true);
    bool Victory (false);

    CPosition PosPlayer1, PosPlayer2;

    CMyParam Param;
    int RetVal = LoadParams(Param, "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/config.yaml");
    if (RetVal != 0)
    {
        return RetVal;
    }

    InitGrid(Mat, Param, PosPlayer1, PosPlayer2);

    DisplayGrid (Mat, Param);

    while (PartyNum <= KMaxPartyNum && ! Victory)
    {

        cout << "Tour n° -> " << PartyNum << " | Joueur "
             << (Player1Turn ? '1' : '2') << endl << "Entrez un déplacement : ";

        char Move;

        /*
         * Mode non-canonique en deux lignes, peut-être à changer?
         * */
        system("stty raw"); // Terminal en mode raw
        cin >> Move;
        system("stty cooked"); // Terminal en mode par défaut

        Move = toupper (Move);

        int errors = MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2),
                   Param.MapParamUnsigned["NbRow"],
                   Param.MapParamUnsigned["NbColumn"]);

        ClearScreen();
        DisplayGrid (Mat, Param);

        if (errors == 1)
            cout << "Erreur de déplacement !" << endl;
        else if (errors == 2)
            cout << "Touche inconnue !" << endl << "Actions possibles: A, Z, E, Q, D, W, X, C" << endl;

        /* Victiry test -> Victory test ( :)))))))) ) */
        // Victory test
        if (PosPlayer1 == PosPlayer2) Victory = true;

        //Increase party's number
        ++PartyNum;

        //Player changing
        if (errors == 0)
        Player1Turn = !Player1Turn;
    }//while (no victory)

    if (!Victory)
    {
        Color (KColor.find("KMAgenta")->second);
        cout << "Aucun vainqueur" << endl;
        return 1;
    }

    Color (KColor.find("KGreen")->second);
    cout << "Félicitations Joueur" << (Player1Turn ? '2' : '1')
         << " vous avez gagné :)" << endl;
    Color (KColor.find("KReset")->second);
    return 0;
} //ppal ()

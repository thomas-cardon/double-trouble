/*!
 * \file   main.cpp
 * \authors Thomas Cardon, Alexandre Arniaud, Ines Hamidi, Mohamed Labidi, Angèle Derrives
 * \date december 8 2016
 * \brief   Terminal's color management
 *          beginning of the project titled "catch me if you can"
 */

#include <iostream>
#include "Nos_fichiers/game2d.h"

using namespace std;

int main()
{
    try {
        return load();
    }  catch (...) {
        cout << "Erreur" << endl;
    }
} // main ()

/*!
 * \file   main.cpp
 * \authors Alain Casali, Marc Laporte
 * \date december 8 2016
 * \brief   Terminal's color management
 *          beginning of the project titled "catch me if you can"
 */

#include <iostream>
#include "Nos_fichiers/game2d.h"

using namespace std;

/**
 * @brief main
 * @return return 0 if everything is OK, 1 if we have an exception, 2 if we can't load the params' file
 */
int main()
{
    try {
        return load();
    }  catch (...) {
        cout << "Thomas a encore cassé un truc" << endl;
    }
} //main ()

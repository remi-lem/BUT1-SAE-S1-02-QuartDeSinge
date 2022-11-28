//
// Created by remi on 28/11/22.
//
#include <iostream>

using namespace std;

void verif_arguments(int argc, const char* argv[]) {
    // parametre sur la ligne de commande
    if (argc >= 2)
        cout << "le 1er parametre est '" << argv[1] << "'" << endl;
    else
        cout << "il n'y a pas de parametre" << endl;

}
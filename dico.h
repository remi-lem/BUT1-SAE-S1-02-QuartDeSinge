//
// Created by remi on 29/11/22.
//

#ifndef BUT1_SAE_S1_02_DICO_H
#define BUT1_SAE_S1_02_DICO_H

/*Remi : problème d'emplacement de l'executable*/
#define HOME_DICO "../ods4.txt"

#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>

using namespace std;

enum {
    ERR_OUVERTURE_DICO
};

void fonc_prof_dico_test();

#endif //BUT1_SAE_S1_02_DICO_H

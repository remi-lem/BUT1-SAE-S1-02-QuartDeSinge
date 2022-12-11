/**
 * @file dico.h
 * @author Hamza
 */

#ifndef BUT1_SAE_S1_02_DICO_H
#define BUT1_SAE_S1_02_DICO_H

/*Remi : problème d'emplacement de l'executable*/
#define HOME_DICO "../ods4.txt"

#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>

#include "partie.h"

using namespace std;

/**
 * DOC A FAIRE
 */
enum {
    ERR_OUVERTURE_DICO
};

/**
 * DOC A FAIRE
 * @param mot_manche
 * @return
 */
bool recherche_existence_mot(const char mot[]);

/**
 * DOC A FAIRE
 * @param mot_manche
 * @return
 */
char choix_lettre_robot(const char mot[]);

/**
 * DOC A FAIRE
 * @param mot_manche
 * @return
 */
bool le_mot_peut_continuer(const char mot[]);

#endif //BUT1_SAE_S1_02_DICO_H

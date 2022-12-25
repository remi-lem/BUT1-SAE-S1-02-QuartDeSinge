/**
 * @file dico.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_DICO_H
#define BUT1_SAE_S1_02_DICO_H

/*
 * Remi : problème d'emplacement de l'executable
 * mettre ../ods4 pour compiler dans CLion
 * mettre direct ods4 pour compiler avec g++
*/
#define HOME_DICO "ods4.txt"

#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>
using namespace std;

#include "conteneurTDE.h"


/**
 * @brief Nombre de lettre composant le mot le plus long du dictionnaire
 */
enum {
    MAX_LETTRES_MOT = 25
};

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
ConteneurTDE dico_dans_conteneur();

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
char* choix_mot_robot(const char mot[]);

/**
 * DOC A FAIRE
 * @param mot_manche
 * @return
 */
bool le_mot_peut_continuer(const char mot[]);

#endif //BUT1_SAE_S1_02_DICO_H

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
//#define HOME_DICO "../ods4.txt"
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
 * @brief Enregistrement du dictionnaire dans un ConteneurTDE
 * @return le conteneurTDE qui contient le dictionnaire
 */
ConteneurTDE dico_dans_conteneur();

/**
 * recherche de l'existence d'un mot dans le dictionnaire
 * @param mot_manche le mot courant de la manche
 * @param conteneur_dico le conteneur du dictionnaire
 * @return vrai ou faux
 */
bool recherche_existence_mot(const char mot[], const ConteneurTDE& conteneur_dico);

/**
 * choix de la lettre complétnt le mot courant, utilisé par les robots
 * @param mot_manche le mot en cours de construction
 * @param conteneur_dico le conteneur du dictionnaire
 * @return la lettre choisie
 */
char choix_lettre_robot(const char mot[], const ConteneurTDE& conteneur_dico);

/**
 * choix du mot qui complète celui de la manche
 * @param mot_manche le mot en cours de construction
 * @param conteneur_dico le conteneur du dictionnaire
 * @return un pointeur vers le permier caractère d'une chaine de caractères
 */
char* choix_mot_robot(const char mot[], const ConteneurTDE& conteneur_dico);

/**
 * @brief Vérification de la correspondance des lettres entre le mot en cours de construction et le mot proposé
 * @param mot_propose mot proposé par le joueur
 * @param mot_manche mot en construction
 * @return la correspondance : vrai ou faux
 */
bool verif_correspondance_mot(const char mot_long[], const char mot_court[]);

#endif //BUT1_SAE_S1_02_DICO_H

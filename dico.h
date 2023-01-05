/**
 * @file dico.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_DICO_H
#define BUT1_SAE_S1_02_DICO_H

// modifier pour CLion en "../ods4.txt"
#define HOME_DICO "ods4.txt"

#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>
using namespace std;

#include "conteneurTDEdico.h"


/**
 * @brief Nombre de lettre composant le mot le plus long du dictionnaire
 */
enum {
    MAX_LETTRES_MOT = 25
};

enum {
    CAPA_CONTENEUR_DICO = 100,
    PAS_CONTENEUR_DICO = 2
};

/**
 * @brief Enregistrement du dictionnaire dans un ConteneurTDEDico
 * @return le conteneurTDE qui contient le dictionnaire
 */
ConteneurTDEDico dico_dans_conteneur();

/**
 * recherche de l'existence d'un mot dans le dictionnaire
 * @param[in] mot_manche le mot courant de la manche
 * @param[in] conteneur_dico le conteneur du dictionnaire
 * @return vrai ou faux
 */
bool recherche_existence_mot(const char mot[], const ConteneurTDEDico& conteneur_dico);

/**
 * choix de la lettre complétnt le mot courant, utilisé par les robots
 * @param[in] mot_manche le mot en cours de construction
 * @param[in] conteneur_dico le conteneur du dictionnaire
 * @return la lettre choisie
 */
char choix_lettre_robot(const char mot[], const ConteneurTDEDico& conteneur_dico);

/**
 * choix du mot qui complète celui de la manche
 * @param[in] mot_manche le mot en cours de construction
 * @param[in] conteneur_dico le conteneur du dictionnaire
 * @return un pointeur vers le permier caractère d'une chaine de caractères
 */
char* choix_mot_robot(const char mot[], char mot_dico[], const ConteneurTDEDico& conteneur_dico);

/**
 * @brief Vérification de la correspondance des lettres entre le mot en cours de construction et le mot proposé
 * @param[in] mot_propose mot proposé par le joueur
 * @param[in] mot_manche mot en construction
 * @return la correspondance : vrai ou faux
 */
bool verif_correspondance_mot(const char mot_long[], const char mot_court[]);

#endif //BUT1_SAE_S1_02_DICO_H

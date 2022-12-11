/**
 * @file joueurs.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_JOUEURS_H
#define BUT1_SAE_S1_02_JOUEURS_H

#include <iostream>
#include <cstring>

#include "dico.h"

/**
 * @brief pour éviter d'écrire std::cin et std::cout
 */
using namespace std;

/**
 * @brief déclaration de type uint pour ne pas avoir à écrire unsigned int
 */
typedef unsigned int uint;

/**
 * @brief Pour chaque joueur : stockage des points
 */
struct PointsSinge {
    float pointsDeSinge = 00.00f;
};

/**
 * @brief Stucture de stokage des joueurs et de leurs points
 */
struct Joueurs {
    uint nb_humains = 0;
    uint nb_robots = 0;
    uint nb_total = 0;
    char* ordre_passage = NULL;
    PointsSinge* pointsSingeJoueur = NULL;
};

/**
 * @brief Enumération dont les valeurs sont renvoyées par la fonction de traitement des arguments
 * @see fonction traitement_arguments dans joueurs.h
 */
enum {
    DICO_PAS_OUVERT,
    PAS_DE_PARAM,
    NB_JOUEURS_PAS_CORRECT,
    JOUEUR_NI_H_NI_R,
    CORRECT
};

/**
 * Au moins deux joueurs (au total) jouent
 */
const int MIN_JOUEURS = 2;

/**
 * @brief Initialisation de la structure des joueurs
 * @param struct_joueurs une référence vers la structure
 * @param taille_char_args la taille de la chaine des caractères contenant les H et les R
 */
void initialiser_struct_joueurs(Joueurs &struct_joueurs, const uint taille_char_args);

/**
 * @brief Traitement des arguments passés en ligne de commande pour lancer le programme
 * @param argc le nombre d'arguments
 * @param argv le tableau contenant les arguments
 * @param struct_joueurs une référence vers la structure des joueurs
 * @return une valeur de l'énumération des joueurs
 * @see énumération dans joueurs.h
 */
int traitement_arguments(const int argc, const char* argv[], Joueurs& struct_joueurs);

/**
 * @brief Recherche de l'indice du joueur précédent
 * @param struct_joueurs une référence vers la structure des étudiants
 * @param indice_joueur l'indice du joueur actuel
 * @return l'indice du joueur précédent, sinon -1
 */
uint indice_joueur_precedent(Joueurs& struct_joueurs, uint indice_joueur);

/**
 * @brief Recherche de le numéro du joueur précédent
 * @param struct_joueurs une référence vers la structure des étudiants
 * @param indice_joueur l'indice du joueur actuel
 * @return le numero du joueur précédent, sinon -1
 */
uint numero_joueur_precedent(Joueurs& struct_joueurs, uint indice_joueur);

#endif //BUT1_SAE_S1_02_JOUEURS_H

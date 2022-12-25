/**
 * @file partie.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_PARTIE_H
#define BUT1_SAE_S1_02_PARTIE_H

#include "manche.h"

/**
 * @brief Enumération utilisée par la fonction verif_points_singe
 * @see fonction verif_points_singe dans partie.h
 */
enum {
    MAX_PT_SINGE = 1,
    PT_SINGE_OK = -1
};

/**
 * @brief Lancement d'une partie de Quart de Singe
 * @param struct_joueurs une référence vers la structure des joueurs
 */
void lancement_partie(Joueurs& struct_joueurs);

/**
 * @brief Vérification des points pour chaque joueur
 * @param struct_joueurs
 * @return int : soit l'indice du premier joueur à 4 quarts de singe, sinon PT_SINGE_OK
 * @see énumération de la vérification des points dans partie.h
 */
int verif_points_singe(const Joueurs& struct_joueurs);

/**
 * @brief Affichage des points pour chaque joueur
 * @param struct_joueurs une référence vers la structure des joueurs
 */
void aff_points_singe(const Joueurs& struct_joueurs);

#endif //BUT1_SAE_S1_02_PARTIE_H

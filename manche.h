/**
 * @file manche.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_MANCHE_H
#define BUT1_SAE_S1_02_MANCHE_H

#include "joueurs.h"
#include "partie.h"
#include "dico.h"

/**
 * @brief Lancement d'une manche de Quart de Singe
 * @param struct_joueurs une référence vers la structure des joueurs
 */
void lancement_manche(Joueurs& struct_joueurs);

/**
 * @brief ajoute un quart de point (quart de singe) à un joueur
 * @param struct_joueurs une référence vers la structure des joueurs
 * @param indice l'indice du joueur qui doit avoit un quart de point supplémentaire
 */
void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice);

/**
 * @brief Ajout d'une lettre au mot actuel
 * @param mot_manche le mot jusqu'a présent
 * @param lettre_joueur la lettre à ajouter au mot
 * @return le mot, avec la lettre ajoutée
 */
char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur);

#endif //BUT1_SAE_S1_02_MANCHE_H

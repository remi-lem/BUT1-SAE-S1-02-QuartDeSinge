/**
 * @file manche.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_MANCHE_H
#define BUT1_SAE_S1_02_MANCHE_H

#include <cassert>
#include <climits>

#include "joueurs.h"
#include "dico.h"

/**
 * @brief Lancement d'une manche de Quart de Singe
 * @param struct_joueurs une référence vers la structure des joueurs
 * @param conteneur_dico le conteneur du dictionnaire
 */
void lancement_manche(Joueurs& struct_joueurs, ConteneurTDE& conteneur_dico);

/**
 * @brief Verification du joueur perdant et attribution des points quart de singe
 * @param struct_joueurs une référence vers la structure des joueurs
 * @param mot_manche le mot de la manche actuelle
 * @param indice_joueur l'indice du joueur concerné
 * @param conteneur_dico le conteneur du dictionnaire
 * @pre indice supérieur ou egal a 0
 */
void verifie_qui_perd(Joueurs& struct_joueurs, char mot_propose[], const char mot_manche[], const uint indice_joueur, ConteneurTDE& conteneur_dico);

/**
 * @brief ajoute un quart de point (quart de singe) à un joueur
 * @param struct_joueurs une référence vers la structure des joueurs
 * @param indice l'indice du joueur qui doit recevoir un quart de point supplémentaire
 * @pre indice supérieur ou egal a 0
 */
void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice);

/**
 * @brief Vérification de la correspondance des lettres entre le mot en cours de construction et le mot proposé
 * @param mot_propose mot proposé par le joueur
 * @param mot_manche mot en construction
 * @return la correspondance : vrai ou faux
 */
bool verif_correspondance_mot(const char mot_propose[], const char mot_manche[]);

/**
 * @brief met un mot en majuscules
 * @param[in,out] mot le mot à mettre en majuscule
 * @attention le mot est directement modifié
 */
void mot_en_majuscules(char* mot);

/**
 * @brief Ajout d'une lettre au mot actuel
 * @param mot_manche le mot jusqu'a présent
 * @param lettre_joueur la lettre à ajouter au mot
 * @return le mot, avec la lettre ajoutée
 */
char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur);

#endif //BUT1_SAE_S1_02_MANCHE_H

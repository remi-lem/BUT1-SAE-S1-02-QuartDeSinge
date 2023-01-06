/**
 * @file manche.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_MANCHE_H
#define BUT1_SAE_S1_02_MANCHE_H

#include <cassert>
#include <climits>

#include "dico.h"

/**
 * @brief Lancement d'une manche de Quart de Singe
 * @param struct_joueurs une référence vers la structure des joueurs
 * @param conteneur_dico le conteneur du dictionnaire
 */
void lancement_manche(Joueurs& struct_joueurs, ConteneurTDEDico& conteneur_dico);

/**
 * @brief affichage du mot courant et recupération de la lettre du joueur
 * @param[in] struct_joueurs une référence vers la structure des joueurs
 * @param[in] conteneur_dico une référence vers le conteneur du dictionnaire
 * @param[in] mot_manche le mot courant de la manche
 * @param[in] indice l'indice du joueur
 * @pre indice compris entre 0 et le nombre de joueurs
 * @return la lettre choisie par le joueur
 */
char recup_aff_lettre(const Joueurs& struct_joueurs, const ConteneurTDEDico& conteneur_dico, const char* mot_manche, const uint indice);

/**
 * @brief Verification du joueur perdant et attribution des points quart de singe
 * @param[in,out] struct_joueurs une référence vers la structure des joueurs
 * @param[in,out] mot_propose le mot proposé par le joueur
 * @param[in] mot_manche le mot de la manche actuelle
 * @param[in] indice_joueur l'indice du joueur concerné
 * @param[in] conteneur_dico le conteneur du dictionnaire
 * @pre indice compris entre 0 et le nombre de joueurs
 */
void verifie_qui_perd(Joueurs& struct_joueurs, char mot_propose[], const char mot_manche[], const uint indice_joueur, const ConteneurTDEDico& conteneur_dico);

/**
 * @brief ajoute un quart de point (quart de singe) à un joueur
 * @param[in,out] struct_joueurs une référence vers la structure des joueurs
 * @param[in] indice l'indice du joueur qui doit recevoir un quart de point supplémentaire
 * @pre indice compris entre 0 et le nombre de joueurs
 */
void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice);

/**
 * @brief met un mot en majuscules
 * @param[in,out] mot le mot à mettre en majuscule
 * @attention le mot est directement modifié
 */
void mot_en_majuscules(char* mot);

/**
 * @brief Agrandir le mot d'une certaine taille
 * @param mot le mot à agrandir
 * @return la nouvelle taille max du mot
 */
uint agranditMot(char *&mot);

/**
 * @brief Ajout d'une lettre au mot actuel
 * @param[in,out] mot_manche le mot jusqu'a présent
 * @param[in] lettre_joueur la lettre à ajouter au mot
 * @return le mot, avec la lettre ajoutée
 */
char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur);

#endif //BUT1_SAE_S1_02_MANCHE_H

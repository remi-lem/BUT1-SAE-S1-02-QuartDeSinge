//
// Created by remi on 25/12/22.
//

#ifndef BUT1_SAE_S1_02_MAIN_H
#define BUT1_SAE_S1_02_MAIN_H

#include "partie.h"

/**
 * @brief Traitement des arguments passés en ligne de commande pour lancer le programme
 * @param argc le nombre d'arguments
 * @param argv le tableau contenant les arguments
 * @param struct_joueurs une référence vers la structure des joueurs
 * @return une valeur de l'énumération des joueurs
 * @see énumération dans joueurs.h
 */
int traitement_arguments(const int argc, const char* argv[], Joueurs& struct_joueurs);

#endif //BUT1_SAE_S1_02_MAIN_H
//
// Created by remi on 29/11/22.
//

#ifndef BUT1_SAE_S1_02_PARTIE_H
#define BUT1_SAE_S1_02_PARTIE_H

#include <cstring>

#include "joueurs.h"

enum {
    MAX_PT_SINGE = 1,
    PT_SINGE_OK = -1
};

enum {
    MAX_LETTRES_MOT = 25
};

void aff_points_singe(const Joueurs& struct_joueurs);

int verif_points_singe(const Joueurs& struct_joueurs);

/**
 * @brief Lance une partie
 * @param struct_joueurs
 */
void lancement_partie(Joueurs& struct_joueurs);

void lancement_manche(Joueurs& struct_joueurs);

void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice);

char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur);

#endif //BUT1_SAE_S1_02_PARTIE_H

//
// Created by remi on 29/11/22.
//

#ifndef BUT1_SAE_S1_02_PARTIE_H
#define BUT1_SAE_S1_02_PARTIE_H

#include "joueurs.h"

enum {
    MAX_PT_SINGE = 1,
    PT_SINGE_OK = -1
};

void aff_points_singe(Joueurs& struct_joueurs);

int verif_points_singe(Joueurs& struct_joueurs);

/**
 * @brief Lance une partie
 * @param struct_joueurs
 */
void lancement_partie(Joueurs& struct_joueurs);

void lancement_manche(Joueurs& struct_joueurs);

#endif //BUT1_SAE_S1_02_PARTIE_H

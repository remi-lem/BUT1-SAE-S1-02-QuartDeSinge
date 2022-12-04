//
// Created by remi on 29/11/22.
//

#ifndef BUT1_SAE_S1_02_JOUEURS_H
#define BUT1_SAE_S1_02_JOUEURS_H

#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int uint;

struct PointsSinge {
    float pointsDeSinge = 00.00f;
};

struct Joueurs {
    uint nb_humains = 0;
    uint nb_robots = 0;
    uint nb_total = 0;
    char* ordre_passage = NULL;
    PointsSinge* pointsSingeJoueur = NULL;
};

enum {
    PAS_DE_PARAM,
    NB_JOUEURS_PAS_CORRECT,
    JOUEUR_NI_H_NI_R,
    CORRECT
};

const int MIN_JOUEURS = 2;

void fonc_prof_traitement_arguments(int argc, const char* argv[]);

void initialiser_struct_joueurs(Joueurs &struct_joueurs);
int traitement_arguments(int argc, const char* argv[], Joueurs& struct_joueurs);

#endif //BUT1_SAE_S1_02_JOUEURS_H

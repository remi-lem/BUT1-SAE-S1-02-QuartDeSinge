/**
 * @file joueurs.cpp
 * @author Rémi
 */

#include "joueurs.h"

void initialiser_struct_joueurs(Joueurs &struct_joueurs, const uint taille_char_args) {
    struct_joueurs.nb_robots = 0;
    struct_joueurs.nb_humains = 0;
    struct_joueurs.nb_total = 0;
    struct_joueurs.ordre_passage = new char[taille_char_args];
    struct_joueurs.pointsSingeJoueur = new PointsSinge[taille_char_args];
    for(uint i=0; i<taille_char_args; i++) {
        struct_joueurs.pointsSingeJoueur[i].pointsDeSinge = 00.00f;
    }
}

int traitement_arguments(const int argc, const char* argv[], Joueurs& struct_joueurs) {
    uint taille_char_args = strlen(argv[1]);
    uint cpt_humain=0, cpt_robot=0;
    char lettre_arg;
    initialiser_struct_joueurs(struct_joueurs, taille_char_args);
    if (argc >= 2) {
        for (uint i = 0; i < strlen(argv[1]); i++) {
            lettre_arg = (char)toupper(argv[1][i]);
            switch(lettre_arg) {
                case('H'):
                    cpt_humain++;
                    struct_joueurs.ordre_passage[i] = 'H';
                    break;
                case('R'):
                    cpt_robot++;
                    struct_joueurs.ordre_passage[i] = 'R';
                    break;
                default:
                    return JOUEUR_NI_H_NI_R;
            }
        }
    }
    else {
        return PAS_DE_PARAM;
    }
    if(cpt_robot+cpt_humain < MIN_JOUEURS) {
        return NB_JOUEURS_PAS_CORRECT;
    }

    struct_joueurs.nb_humains = cpt_humain;
    struct_joueurs.nb_robots = cpt_robot;
    struct_joueurs.nb_total = cpt_humain + cpt_robot;
    return CORRECT;
}

uint indice_joueur_precedent(Joueurs& struct_joueurs, uint indice_joueur) {
    if(indice_joueur==0) {
        return struct_joueurs.nb_total-1;
    }
    else {
        return indice_joueur-1;
    }
}

uint numero_joueur_precedent(Joueurs& struct_joueurs, uint indice_joueur) {
    uint numero_joueur = indice_joueur+1;
    if(numero_joueur==1) {
        return struct_joueurs.nb_total;
    }
    else {
        return numero_joueur-1;
    }
}
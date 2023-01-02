/**
 * @file joueurs.cpp
 * @author Rémi
 */

#include "joueurs.h"

void initialiser_struct_joueurs(Joueurs &struct_joueurs, const uint taille_char_args) {
    assert(taille_char_args >= 0);
    struct_joueurs.nb_robots = 0;
    struct_joueurs.nb_humains = 0;
    struct_joueurs.nb_total = 0;
    struct_joueurs.indice_dernier_perdant = 0;
    struct_joueurs.ordre_passage = new char[taille_char_args];
    struct_joueurs.pointsSingeJoueur = new PointsSinge[taille_char_args];
    for(uint i=0; i<taille_char_args; i++) {
        struct_joueurs.pointsSingeJoueur[i].pointsDeSinge = 00.00f;
    }
}


uint indice_joueur_precedent(const Joueurs& struct_joueurs, const uint indice_joueur) {
    assert(indice_joueur >= 0 && indice_joueur < struct_joueurs.nb_total);
    if(indice_joueur==0) {
        return struct_joueurs.nb_total-1;
    }
    else {
        return indice_joueur-1;
    }
}

uint numero_joueur_precedent(const Joueurs& struct_joueurs, const uint indice_joueur) {
    assert(indice_joueur >= 0 && indice_joueur < struct_joueurs.nb_total);
    uint numero_joueur = indice_joueur+1;
    if(numero_joueur==1) {
        return struct_joueurs.nb_total;
    }
    else {
        return numero_joueur-1;
    }
}
/**
 * @file partie.cpp
 * @author Rémi
 */

#include "partie.h"

void lancement_partie(Joueurs& struct_joueurs) {
    ConteneurTDEDico conteneur_dico;
    conteneur_dico = dico_dans_conteneur();
    srand(time(NULL)); // pour le genérateur aléatoire
    while(verif_points_singe(struct_joueurs) == PT_SINGE_OK) {
        lancement_manche(struct_joueurs, conteneur_dico);
        aff_points_singe(struct_joueurs);
    }
    detruire(conteneur_dico); // on désaloue
}

int verif_points_singe(const Joueurs& struct_joueurs) {
    for(int i=0; i<struct_joueurs.nb_total; i++) {
        if(struct_joueurs.pointsSingeJoueur[i].pointsDeSinge >= MAX_PT_SINGE) {
            return i;
        }
    }
    return PT_SINGE_OK;
}


void aff_points_singe(const Joueurs& struct_joueurs) {
    for(int i=0; i<struct_joueurs.nb_total; i++) {
        cout << i+1 << struct_joueurs.ordre_passage[i] << " : ";
        cout << struct_joueurs.pointsSingeJoueur[i].pointsDeSinge;
        if(i < struct_joueurs.nb_total-1) {
            cout << "; ";
        }
    }
    cout << endl;
}

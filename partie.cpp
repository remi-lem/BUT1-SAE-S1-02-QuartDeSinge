//
// Created by remi on 29/11/22.
//

#include "partie.h"

void lancement_partie(Joueurs& struct_joueurs) {
    cout << "Lancement de la partie" << endl;
    aff_points_singe(struct_joueurs);
    while(verif_points_singe(struct_joueurs) == PT_SINGE_OK) {
        lancement_manche(struct_joueurs);
        break;//POUR LE TEMPS QUE LA MANCHE SOIT CODEE
    }
}

void lancement_manche(Joueurs& struct_joueurs) {
    cout << "MANCHE" << endl;
}

int verif_points_singe(Joueurs& struct_joueurs) {
    for(int i=0; i<struct_joueurs.nb_total; i++) {
        if(struct_joueurs.pointsSingeJoueur[i].pointsDeSinge >= MAX_PT_SINGE) {
            return i;
        }
    }
    return PT_SINGE_OK;
}


void aff_points_singe(Joueurs& struct_joueurs) {
    cout << "Points de singes des joueurs : " << endl;
    for(int i=0; i<struct_joueurs.nb_total; i++) {
        cout << struct_joueurs.ordre_passage[i] << i << " : ";
        cout << struct_joueurs.pointsSingeJoueur[i].pointsDeSinge;
        if(i < struct_joueurs.nb_total-1) {
            cout << " - ";
        }
    }
    cout << endl;
}
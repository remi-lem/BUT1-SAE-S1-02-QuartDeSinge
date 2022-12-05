//
// Created by remi on 29/11/22.
//

#include "partie.h"
#include "dico.h"

void lancement_partie(Joueurs& struct_joueurs) {
    while(verif_points_singe(struct_joueurs) == PT_SINGE_OK) {
        lancement_manche(struct_joueurs);
        aff_points_singe(struct_joueurs);
        //break;//POUR LE TEMPS QUE LA MANCHE SOIT CODEE
    }
    cout << "La partie est finie" << endl;
}

void lancement_manche(Joueurs& struct_joueurs) {
    char lettre_joueur = ' ';
    char mot_manche[MAX_LETTRES_MOT+1] = "";
    bool existence_mot = false;
    uint ind_joueur_perdant;
    for(uint h=0; h<MAX_LETTRES_MOT; h++) {
        for (uint i = 0; i < struct_joueurs.nb_total; i++) {
            cout << i + 1 << struct_joueurs.ordre_passage[i] << ", (";
            cout << mot_manche;
            cout << ") > ";
            if (struct_joueurs.ordre_passage[i] == 'H') {
                cin >> lettre_joueur;
            }
            else if (struct_joueurs.ordre_passage[i] == 'R') {
                //lettre_joueur = choix_lettre_robot(mot_manche);
                cout << lettre_joueur << endl;
            }
            else {
                cout << "Erreur pour la manche. indice joueur : " << i << endl;
            }

            lettre_joueur = toupper(lettre_joueur);
            if (lettre_joueur == '?') {
                //existence_mot = recherche_existence_mot(mot_manche);
                if (existence_mot) {
                    cout << "Le mot " << mot_manche << " existe, " << i+1 << struct_joueurs.ordre_passage[i] <<
                    " prend un quart de singe" << endl;
                    addQuartDeSinge(struct_joueurs, i);
                    return;
                }
                if(!existence_mot) {
                    if(i==0) {
                        ind_joueur_perdant = struct_joueurs.nb_total-1;
                    }
                    else {
                        ind_joueur_perdant = i-1;
                    }
                    cout << "le mot " << mot_manche << " n’existe pas, " << ind_joueur_perdant+1 << struct_joueurs.ordre_passage[ind_joueur_perdant] <<
                    " prend un quart de singe" << endl;
                    addQuartDeSinge(struct_joueurs, ind_joueur_perdant);
                    return;
                }
                else {
                    cout << "ERREUR" << endl;
                    return;
                }
            }
            else {
                strcpy(mot_manche,ajoute_lettre_au_mot(mot_manche, lettre_joueur));
            }
        }
    }
}

int verif_points_singe(const Joueurs& struct_joueurs) {
    for(uint i=0; i<struct_joueurs.nb_total; i++) {
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

void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice) {
    struct_joueurs.pointsSingeJoueur[indice].pointsDeSinge += 0.25;
}

char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur) {
    uint long_mot = strlen(mot_manche);
    mot_manche[long_mot] = lettre_joueur;
    //mot_manche[long_mot+1] = "\0";
    return mot_manche;
}
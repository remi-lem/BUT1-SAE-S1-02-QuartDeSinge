/**
 * @file manche.cpp
 * @author Rémi
 */

#include "manche.h"

void lancement_manche(Joueurs& struct_joueurs, ConteneurTDE& conteneur_dico) {
    char lettre_joueur;
    char mot_manche[MAX_LETTRES_MOT+1] = "";
    char mot_propose[MAX_LETTRES_MOT+1] = "";
    const char* ptr_mot_du_robot;
    bool premier_tour = true;

    while(strlen(mot_manche) <= MAX_LETTRES_MOT) {
        for (uint i = 0; i < struct_joueurs.nb_total; i++) {
            if(premier_tour){
                i = struct_joueurs.indice_dernier_perdant;
                premier_tour = false;
            }
            lettre_joueur = recup_aff_lettre(struct_joueurs, conteneur_dico, mot_manche, i);

            if (lettre_joueur == '?') {
                if(strlen(mot_manche) == 0){
                    cout << "ce n'est pas tres gentil, prends plutot un quart de singe !" << endl;
                    addQuartDeSinge(struct_joueurs, i);
                    struct_joueurs.indice_dernier_perdant = i;
                    return;
                }
                cout << numero_joueur_precedent(struct_joueurs, i) <<
                struct_joueurs.ordre_passage[indice_joueur_precedent(struct_joueurs, i)] <<
                ", saisir le mot > ";
                if (struct_joueurs.ordre_passage[indice_joueur_precedent(struct_joueurs, i)] == 'R') {
                    ptr_mot_du_robot = choix_mot_robot(mot_manche, mot_propose, conteneur_dico);
                    strcpy(mot_propose, ptr_mot_du_robot);
                    cout << mot_propose;
                    cout << endl;
                }
                else {
                    cin >> mot_propose;
                }
                verifie_qui_perd(struct_joueurs, mot_propose, mot_manche, i, conteneur_dico);
                return;
            }
            else if(lettre_joueur == '!') {
                cout << "le joueur " << i+1 << struct_joueurs.ordre_passage[i] <<
                     " abandonne la manche et prend un quart de singe" << endl;
                addQuartDeSinge(struct_joueurs, i);
                struct_joueurs.indice_dernier_perdant = i;
                return;
            }
            else {
                strcpy(mot_manche,ajoute_lettre_au_mot(mot_manche, lettre_joueur));
            }
            if(strlen(mot_manche) > 2){
                if(recherche_existence_mot(mot_manche, conteneur_dico)) {
                    cout << "le mot " << mot_manche << " existe, le joueur " << i+1 << struct_joueurs.ordre_passage[i] <<
                         " prend un quart de singe" << endl;
                    addQuartDeSinge(struct_joueurs, i);
                    struct_joueurs.indice_dernier_perdant = i;
                    return;
                }
            }
        }
    }
    cout << "Mot de plus de 25 lettres impossible" << endl;
}

char recup_aff_lettre(const Joueurs& struct_joueurs, const ConteneurTDE& conteneur_dico, const char* mot_manche, const uint indice) {
    char lettre_joueur = ' ';
    cout << indice + 1 << struct_joueurs.ordre_passage[indice] << ", (";
    cout << mot_manche;
    cout << ") > ";
    if (struct_joueurs.ordre_passage[indice] == 'H') {
        cin >> lettre_joueur;
        cin.ignore(INT_MAX, '\n'); // on enlève ce qui dépasse
    }
    else if (struct_joueurs.ordre_passage[indice] == 'R') {
        lettre_joueur = choix_lettre_robot(mot_manche, conteneur_dico);
        cout << lettre_joueur << endl;
    }
    else {
        cout << "Erreur pour la manche. indice joueur : " << indice << endl;
        exit(1);
    }
    lettre_joueur = (char)toupper(lettre_joueur);
    return lettre_joueur;
}

void verifie_qui_perd(Joueurs& struct_joueurs, char mot_propose[], const char mot_manche[], const uint indice_joueur, const ConteneurTDE& conteneur_dico) {
    assert(indice_joueur >= 0);
    uint ind_joueur_perdant, num_joueur_perdant;
    bool correspondance_mot = verif_correspondance_mot(mot_propose, mot_manche);

    mot_en_majuscules(mot_propose);

    if(!correspondance_mot) {
        cout << "le mot " << mot_propose << " ne commence pas par les lettres attendues, le joueur " <<
        numero_joueur_precedent(struct_joueurs, indice_joueur) <<
        struct_joueurs.ordre_passage[indice_joueur_precedent(struct_joueurs, indice_joueur)] <<
        " prend un quart de singe" << endl;
        addQuartDeSinge(struct_joueurs, indice_joueur_precedent(struct_joueurs, indice_joueur));
        struct_joueurs.indice_dernier_perdant = indice_joueur_precedent(struct_joueurs, indice_joueur);
        return;
    }
    bool existence_mot = recherche_existence_mot(mot_propose, conteneur_dico);
    if (existence_mot) {
        cout << "le mot " << mot_propose << " existe, le joueur " << indice_joueur+1 << struct_joueurs.ordre_passage[indice_joueur]
             << " prend un quart de singe" << endl;
        addQuartDeSinge(struct_joueurs, indice_joueur);
        struct_joueurs.indice_dernier_perdant = indice_joueur;
    }
    else {
        ind_joueur_perdant = indice_joueur_precedent(struct_joueurs, indice_joueur);
        num_joueur_perdant = numero_joueur_precedent(struct_joueurs, indice_joueur);
        cout << "le mot " << mot_propose << " n’existe pas, le joueur " << num_joueur_perdant <<
             struct_joueurs.ordre_passage[ind_joueur_perdant] << " prend un quart de singe" << endl;
        addQuartDeSinge(struct_joueurs, ind_joueur_perdant);
        struct_joueurs.indice_dernier_perdant = ind_joueur_perdant;
    }
}


void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice) {
    assert(indice >= 0);
    struct_joueurs.pointsSingeJoueur[indice].pointsDeSinge += 0.25;
}

void mot_en_majuscules(char* mot) {
    for(uint i=0; i<strlen(mot); i++) {
        mot[i] = (char)toupper(mot[i]);
    }
}

char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur) {
    uint long_mot = strlen(mot_manche);
    mot_manche[long_mot] = lettre_joueur;
    mot_manche[long_mot+1] = '\0';
    return mot_manche;
}
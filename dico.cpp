/**
 * @file dico.cpp
 * @author Rémi
 */

#include "dico.h"

// A UTILISER UNIQUEMENT POUR REFERENCE : SUPPRIMER QUAND LE PROGRAMME EST FONCTIONNEL
void fonc_prof_dico_test() {
    ifstream in(HOME_DICO); // on ouvre le fichier
    if (!in) {
        cout << "le dictionnaire n'a pu etre ouvert" << endl;
    }
    int nb = 0, longueur = 0;
    const int MAX = 26;
    char s[MAX];
    in >> setw(MAX) >> s; // on essaye de lire le premier mot
    while (in) {
        ++nb; // ça s'est bien passé, on le compte
        longueur += (int)strlen(s); // et on accumule sa longueur
        in >> setw(MAX) >> s; // on essaye de lire le mot suivant
    }
    in.close(); // on ferme le fichier
    cout << nb << " mots de " << (float)longueur / (float)nb << " car. en moyenne" << endl;
}

ConteneurTDE dico_dans_conteneur() {
    int capacite_cont_dico = 100, pas_cont_dico = 2; // modifier si besoin
    char mot[MAX_LETTRES_MOT];
    Item ptr_mot_courant;
    uint indice = 0;
    ConteneurTDE conteneur_dico;
    initialiser(conteneur_dico, capacite_cont_dico, pas_cont_dico);
    ifstream in(HOME_DICO);
    in >> setw(MAX_LETTRES_MOT) >> mot;
    while (in) {
        ptr_mot_courant = (Item)malloc(strlen(mot)+1);
        strcpy(ptr_mot_courant, mot);
        ecrire(conteneur_dico, indice, ptr_mot_courant);
        in >> setw(MAX_LETTRES_MOT) >> mot;
        ++indice;
    }
    in.close();
    return conteneur_dico;
}

bool recherche_existence_mot(const char mot[], const ConteneurTDE& conteneur_dico) {
    for(uint i=0; i< conteneur_dico.nb_it_sto; ++i) {
        if(strcmp(lire(conteneur_dico, i), mot) == 0) {
            //ici mettre une recherche dichotomique
            return true;
        }
    }
    return false;
}

char choix_lettre_robot(const char mot[], const ConteneurTDE& conteneur_dico) {
    char mot_dico[MAX_LETTRES_MOT+1];
    for(uint i=conteneur_dico.nb_it_sto-1 ; i >= 0; --i) {
        // a l'envers moins de parties perdues
        strcpy(mot_dico, lire(conteneur_dico, i));
        if(verif_correspondance_mot(mot_dico, mot) && (strlen(mot_dico) > strlen(mot)+1)
        /* && le mot contitué de mot + la lettre choisie existe pas */){
            //A REFAIRE : DICHOTOMIE
            //ISOLER LES MOTS QUI COMMENCENT PAR LA LETTRE ??
            //1 est ce que le mot existe
            //2 si non quel lettre parmi les 26 lettre de l alphabet.
            return mot_dico[strlen(mot)];
        }
    }
    return '?';
}

char* choix_mot_robot(const char mot[], const ConteneurTDE& conteneur_dico) {
    // a faire
    return (char*)"CHEVAL";
}

bool verif_correspondance_mot(const char mot_long[], const char mot_court[]) {
    for(uint i=0; i<strlen(mot_court); i++) {
        if(mot_court[i] != (char)toupper(mot_long[i])) {
            return false;
        }
    }
    return true;
}
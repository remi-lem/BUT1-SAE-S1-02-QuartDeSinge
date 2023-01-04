/**
 * @file dico.cpp
 * @author Rémi
 */

#include "dico.h"

ConteneurTDEDico dico_dans_conteneur() {
    int capacite_cont_dico = 100, pas_cont_dico = 2; // modifier si besoin
    char mot[MAX_LETTRES_MOT];
    Item ptr_mot_courant;
    uint indice = 0;
    ConteneurTDEDico conteneur_dico;
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

bool recherche_existence_mot(const char mot[], const ConteneurTDEDico& conteneur_dico) {
    /*
    char mot_dico[MAX_LETTRES_MOT+1];
    uint debut = 0;
    uint fin = conteneur_dico.nb_it_sto - 1; // pour avoir l'indice
    uint milieu;
    int comparaison;
    while(debut < fin) {
        milieu = (uint)((debut+fin) / 2);
        strcpy(mot_dico, lire(conteneur_dico, milieu));
        comparaison = strcmp(mot_dico, mot);
        if(comparaison == 0) {
            return true;
        }
        else if(comparaison < 0) {
            debut = milieu + 1;
        }
        else if(comparaison > 0) {
            fin = milieu - 1;
        }
        else {
            cerr << "Erreur de recherche dichotomique." << endl;
            exit(1);
        }
    }
    return false;
    */

    //TODO : recherche dicho pas fonctionelle

    for(uint i=0; i< conteneur_dico.nb_it_sto; ++i) {
        if(strcmp(lire(conteneur_dico, i), mot) == 0) {
            return true;
        }
    }
    return false;
}

char choix_lettre_robot(const char mot[], const ConteneurTDEDico& conteneur_dico) {
    char mot_dico[MAX_LETTRES_MOT+1];
    char random_letter;
    uint debut = 0;
    uint fin = conteneur_dico.nb_it_sto - 1; // pour avoir l'indice
    uint milieu;
    int comparaison;

    if(strlen(mot) == 0) {
        srand(time(NULL));
        random_letter = 'A' + (rand() % 26);
        return random_letter;
    }
    while(debut < fin) {
        milieu = (uint)((debut+fin) / 2);
        strcpy(mot_dico, lire(conteneur_dico, milieu));
        comparaison = strcmp(mot_dico, mot);
        if(verif_correspondance_mot(mot_dico, mot) && (strlen(mot_dico) > strlen(mot)+1)) {
            //TODO : si mot pas existant, ne pas le proposer
            return mot_dico[strlen(mot)];
        }
        else if(comparaison < 0) {
            debut = milieu + 1;
        }
        else if(comparaison > 0) {
            fin = milieu - 1;
        }
        else {
            cerr << "Erreur de recherche dichotomique." << endl;
            exit(1);
        }
    }
    return '?';
}

char* choix_mot_robot(const char mot[], char mot_dico[], const ConteneurTDEDico& conteneur_dico) {
    uint debut = 0;
    uint fin = conteneur_dico.nb_it_sto - 1; // pour avoir l'indice
    uint milieu;
    int comparaison;
    while(debut < fin) {
        milieu = (uint)((debut+fin) / 2);
        strcpy(mot_dico, lire(conteneur_dico, milieu));
        comparaison = strcmp(mot_dico, mot);
        if(verif_correspondance_mot(mot_dico, mot)) {
            return (char*)mot_dico;
        }
        else if(comparaison < 0) {
            debut = milieu + 1;
        }
        else if(comparaison > 0) {
            fin = milieu - 1;
        }
        else {
            cerr << "Erreur de recherche dichotomique." << endl;
            exit(1);
        }
    }
    return (char*)"BIENJOUE";
}

bool verif_correspondance_mot(const char mot_long[], const char mot_court[]) {
    for(uint i=0; i<strlen(mot_court); i++) {
        if(mot_court[i] != (char)toupper(mot_long[i])) {
            return false;
        }
    }
    return true;
}

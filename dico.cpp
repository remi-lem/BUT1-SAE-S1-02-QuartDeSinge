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
    uint indice = 0;
    ConteneurTDE conteneur_dico;
    initialiser(conteneur_dico, capacite_cont_dico, pas_cont_dico);
    ifstream in(HOME_DICO);
    in >> setw(MAX_LETTRES_MOT) >> mot;
    while (in) {
        ecrire(conteneur_dico, indice, mot);
        in >> setw(MAX_LETTRES_MOT) >> mot;
        ++indice;
    }
    in.close();
    return conteneur_dico;
}

bool recherche_existence_mot(const char mot[], ConteneurTDE& conteneur_dico) {
    for(uint i=0; i< conteneur_dico.nb_it_sto; ++i) {
        cout << lire(conteneur_dico, i);
        if(strcmp(lire(conteneur_dico, i), mot) == 0) {
            return true;
        }
    }
    return false;
}

char choix_lettre_robot(const char mot[], ConteneurTDE& conteneur_dico) {
    // A FAIRE
    return 'N';
}

char* choix_mot_robot(const char mot[], ConteneurTDE& conteneur_dico) {
    // a faire
    return (char*)"CHEVAL";
}
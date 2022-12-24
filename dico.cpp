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

bool recherche_existence_mot(const char mot[]) {
    // A FAIRE
    return true;
}

char choix_lettre_robot(const char mot[]) {
    // A FAIRE
    return 'N';
}

char* choix_mot_robot(const char mot[]) {
    // a faire
    return "CHEVAL";
}

bool le_mot_peut_continuer(const char mot[]) {
    // A FAIRE
    return true;
}
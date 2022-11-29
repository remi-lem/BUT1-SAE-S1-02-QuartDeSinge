//
// Created by remi on 28/11/22.
//

#include "dico.h"

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
        longueur += strlen(s); // et on accumule sa longueur
        in >> setw(MAX) >> s; // on essaye de lire le mot suivant
    }
    in.close(); // on ferme le fichier
    cout << nb << " mots de " << (float)longueur / nb << " car. en moyenne" << endl;
}
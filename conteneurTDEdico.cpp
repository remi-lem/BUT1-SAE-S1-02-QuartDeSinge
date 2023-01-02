/**
 * @file ConteneurTDEDico.cpp
 * @brief Composant de conteneur d'items de capacité extensible
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "conteneurTDEdico.h"

void initialiser(ConteneurTDEDico& c, unsigned int capa, unsigned int p) {
    assert((capa > 0) && (p > 0));
    c.capacite = capa;
    c.pasExtension = p;
    c.tab = new Item[capa];
    c.nb_it_sto = 0; //REMI
}

void detruire(ConteneurTDEDico& c) {
    for(uint i=0; i < c.nb_it_sto; ++i) {
        free(c.tab[i]);
    }
    delete[] c.tab;
    c.tab = NULL;
}

Item lire(const ConteneurTDEDico& c, unsigned int i) {
    assert(i < c.capacite);
    return c.tab[i];
}

void ecrire(ConteneurTDEDico& c, unsigned int i, const Item& it) {
    if (i >= c.capacite) {
        unsigned int newTaille = (i + 1) * c.pasExtension;
        Item* newT = new Item[newTaille];
        for (unsigned int i = 0; i < c.capacite; ++i)
            newT[i] = c.tab[i];
        delete[] c.tab;
        c.tab = newT;
        c.capacite = newTaille;
    }

    c.tab[i] = it;
    c.nb_it_sto += 1;//REMI
}
/**
 * @file ConteneurTDEDico.h
 * @brief Composant d'un conteneur d'items de capacité extensible.
 */

#ifndef BUT1_SAE_S1_02_CONTENEURTDEDICO_H
#define BUT1_SAE_S1_02_CONTENEURTDEDICO_H

typedef char* Item;

/** @brief Conteneur d'items alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension.
 */
struct ConteneurTDEDico {
    /// Capacité du conteneur (>0).
    unsigned int capacite;
    /// Pas d'extension du conteneur (>0).
    unsigned int pasExtension;
    /// Conteneur alloué en mémoire dynamique.
    Item* tab;
    /// nombre d'Items stockées
    unsigned int nb_it_sto; //REMI
};

/**
 * @brief Initialise un conteneur d'items.
 * Allocation en mémoire dynamique du conteneur d'items
 * de capacité (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa désallocation en fin d'utilisation.
 * @param[out] c Le conteneur d'items.
 * @param [in] capa Capacité du conteneur.
 * @param [in] p Pas d'extension de capacité.
 * @pre capa > 0 et p > 0.
 */
void initialiser(ConteneurTDEDico& c, unsigned int capa, unsigned int p);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void detruire(ConteneurTDEDico& c);

/**
 * @brief Lecture d'un item d'un conteneur d'items.
 * @param[in] c Le conteneur d'items.
 * @param[in] i La position de l'item dans le conteneur.
 * @return L'item à la position i.
 * @pre i < c.capacite
 */
Item lire(const ConteneurTDEDico& c, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position où ajouter/modifier l'item.
 * @param[in] it L'item à écrire.
 */
void ecrire(ConteneurTDEDico& c, unsigned int i, const Item& it);

#endif //BUT1_SAE_S1_02_CONTENEURTDEDICO_H

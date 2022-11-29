//
// Created by remi on 28/11/22.
//

#include "joueurs.h"
#include "dico.h"

/*
   argc -> nombre de paramètres sur la ligne de commande (+ 1)
   argv -> paramètres de la ligne de commande
           (argv[0] : la cde, argv[1] : le 1er paramètre, etc)
*/
/**
 * @brief Fonction principale
 * @return état d'execution (0 si OK)
 */
int main(int argc, const char* argv[]) {
    Joueurs struct_joueurs;
    fonc_prof_traitement_arguments(argc, argv);
    traitement_arguments(argc, argv, struct_joueurs);
    fonc_prof_dico_test();
    return 0;
}

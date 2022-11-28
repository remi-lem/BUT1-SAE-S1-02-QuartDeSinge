//
// Created by remi on 28/11/22.
//

#include "proto_fonc.h"

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
    traitement_arguments(argc, argv);
    dico_test_prof();
    return 0;
}

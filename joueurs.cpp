//
// Created by remi on 28/11/22.
//

#include "joueurs.h"

/**
 * @brief Récupération du paramètre en ligne de commande
 * @param argc
 * @param argv
 */
void traitement_arguments(int argc, const char* argv[]) {
    unsigned int cpt_humain=0, cpt_robot=0;
    if (argc >= 2)
        for(uint i=0; i < strlen(argv[1]); i++) {
            if(argv[1][i] == 'H') {
                cpt_humain++;
            }
            else if(argv[1][i] == 'R') {
                cpt_robot++;
            }
            else {
                cout << "Le joueur d'indice " << i << " n'est ni H ni R." << endl;
                break;
            }
        }
    else {
        cout << "il n'y a pas de parametre" << endl;
    }
}
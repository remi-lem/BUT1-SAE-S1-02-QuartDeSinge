//
// Created by remi on 28/11/22.
//

#include "joueurs.h"

/**
 * @brief Récupération du paramètre en ligne de commande
 * @param argc
 * @param argv
 */
void fonc_prof_traitement_arguments(int argc, const char* argv[]) {
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
    cout << cpt_humain << " humain(s) et " << cpt_robot << " robot(s)" << endl;
}

void initialiser_struct_joueurs(Joueurs &struct_joueurs) {
    struct_joueurs.nb_robots = 0;
    struct_joueurs.nb_humains = 0;
}


int traitement_arguments(int argc, const char* argv[], Joueurs& struct_joueurs) {
    initialiser_struct_joueurs(struct_joueurs);
    uint cpt_humain=0, cpt_robot=0;
    if (argc >= 2) {
        for (uint i = 0; i < strlen(argv[1]); i++) {
            if (argv[1][i] == 'H') {
                cpt_humain++;
            }
            else if (argv[1][i] == 'R') {
                cpt_robot++;
            }
            else {
                return JOUEUR_NI_H_NI_R;
            }
        }
    }
    else {
        return PAS_DE_PARAM;
    }
    if(cpt_robot+cpt_humain < MIN_JOUEURS) {
        return NB_JOUEURS_PAS_CORRECT;
    }

    struct_joueurs.nb_humains = cpt_humain;
    struct_joueurs.nb_robots = cpt_robot;
    return CORRECT;
}
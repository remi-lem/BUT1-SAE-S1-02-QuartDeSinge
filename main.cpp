//
// Created by remi on 28/11/22.
//

#include "joueurs.h"
#include "dico.h"
#include "partie.h"

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
    uint result_traitement_arguments;
    //fonc_prof_traitement_arguments(argc, argv);
    result_traitement_arguments = traitement_arguments(argc, argv, struct_joueurs);
    switch (result_traitement_arguments) {
        case(PAS_DE_PARAM):
            cout << "Il faut lancer le programme avec des paramètres" << endl;
            break;
        case(NB_JOUEURS_PAS_CORRECT):
            cout << "Le nombre de joueurs n'est pas correct (minimum de 2 joueurs)" << endl;
            break;
        case(JOUEUR_NI_H_NI_R):
            cout << "Au moins un joueur n'est ni un humain ni un robot" << endl;
            break;
        case(CORRECT):
            lancement_partie(struct_joueurs);
    }
    fonc_prof_dico_test();
    return 0;
}

/**
 * @file main.cpp
 * @author Rémi
 */

#include "main.h"

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
        case(DICO_PAS_OUVERT):
            cout << "Le dictionnaire n'a pas pu etre ouvert";
            break;
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
            cout << "La partie est finie" << endl;
    }
    return 0;
}

int traitement_arguments(const int argc, const char* argv[], Joueurs& struct_joueurs) {
    uint cpt_humain=0, cpt_robot=0;
    char lettre_arg;

    if (argc < 2) {
        return PAS_DE_PARAM;
    }
    uint taille_char_args = strlen(argv[1]);

    ifstream in(HOME_DICO);
    if (!in) {
        return DICO_PAS_OUVERT;
    }
    in.close();

    initialiser_struct_joueurs(struct_joueurs, taille_char_args);
    if (argc >= 2) {
        for (uint i = 0; i < strlen(argv[1]); i++) {
            lettre_arg = (char)toupper(argv[1][i]);
            switch(lettre_arg) {
                case('H'):
                    cpt_humain++;
                    struct_joueurs.ordre_passage[i] = 'H';
                    break;
                case('R'):
                    cpt_robot++;
                    struct_joueurs.ordre_passage[i] = 'R';
                    break;
                default:
                    return JOUEUR_NI_H_NI_R;
            }
        }
    }
    if(cpt_robot+cpt_humain < MIN_JOUEURS) {
        return NB_JOUEURS_PAS_CORRECT;
    }

    struct_joueurs.nb_humains = cpt_humain;
    struct_joueurs.nb_robots = cpt_robot;
    struct_joueurs.nb_total = cpt_humain + cpt_robot;
    return CORRECT;
}
#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>

using namespace std;

/*
   argc -> nombre de paramètres sur la ligne de commande (+ 1)
   argv -> paramètres de la ligne de commande
           (argv[0] : la cde, argv[1] : le 1er paramètre, etc)
*/
/**
 * @brief Fonction principale
 * @return éta d'execution (0 si OK)
 */

int main(int argc, const char* argv[]) {
    // parametre sur la ligne de commande
    if (argc >= 2)
        cout << "le 1er parametre est '" << argv[1] << "'" << endl;
    else
        cout << "il n'y a pas de parametre" << endl;

    // lecture du dictionnaire mot à mot
    ifstream in("../ods4.txt"); // on ouvre le fichier
    if (!in) {
        cout << "le dictionnaire n'a pu etre ouvert" << endl;
        return 2;
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

    return 0;
}

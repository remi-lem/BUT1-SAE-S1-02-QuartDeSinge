# BUT1-SAE-S1-02

Ici se trouve le projet de BUT1 - DEV, la SAE S1.02  
Projet commencé le 24/11/2022 par Rémi Lemaire  

Dans le cadre de la SAÉ S1.02 : le quart de singe

***

### Pour compter le temps d'éxécution

Mettre ca avant le main :

    #include <ctime>
    double getTime() {
        clock_t t = clock();
        if (t == (clock_t)-1)
            return 0.;
        else
            return (double)t / CLOCKS_PER_SEC;
    }

ca juste apres main(..) :

    double time1, time2;
    time1 = getTime();

ca juste avant return(0); du main :

    time2 = getTime();
    cout << time2 - time1;

***

### Pour bcp de tests automatiques :

    for i in {1..30}; do ./scripto_de_testo.sh; done


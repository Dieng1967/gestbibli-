#include <stdio.h>
#include "projet.h"

int main() {
    int choix;

    do {
        choix = afficherMenu();
        switch (choix) {
            case 1: ajouterLivre(); break;
            case 2: afficherLivres(); break;
            case 3: rechercherLivre(); break;
            case 4: supprimerLivre(); break;
            case 5: emprunterLivre(); break;
            case 6: retournerLivre(); break;
            case 7: afficherStatistiques(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n"); break;
        }
    } while (choix != 0);

    return 0;
}

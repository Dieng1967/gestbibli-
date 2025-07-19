#include <stdio.h>


#define MAX 100

struct Livre {
    char titre[100];
    char auteur[100];
    int annee;
    int isbn;
    int etat;
};

struct Emprunt {
    int isbn;
    int jour;
    int mois;
    int annee;
};


extern struct Livre livres[MAX];
extern struct Emprunt emprunts[MAX];
extern int nbLivres;
extern int nbEmprunts;


void ajouterLivre();
void afficherLivres();
void rechercherLivre();
void afficherLivre();
void supprimerLivre();
void emprunterLivre();
void retournerLivre();
void afficherStatistiques();
int afficherMenu();
void afficherLivre(struct Livre livre);



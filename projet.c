#include <stdio.h>
#include <string.h>
#include "projet.h"

#define MAX 100

struct Livre livres[MAX];
struct Emprunt emprunts[MAX];
int nbLivres = 0;
int nbEmprunts = 0;

void emprunterLivre() {
    int isbn, i, trouve = 0;
    do{
    printf("\n===== EMPRUNT D'UN LIVRE =====\n\n");
    printf("ISBN du livre à emprunter (5 chiffres): ");
    scanf("%d", &isbn);
    if (isbn < 10000 || isbn > 99999) {
        printf("ISBN invalide. Veuillez entrer un nombre à 5 chiffres.\n");
        }
    } while (isbn < 10000 || isbn > 99999);



    for (i = 0; i < nbLivres; i++) {
        if (livres[i].isbn == isbn && livres[i].etat == 0) {
            livres[i].etat = 1;
            emprunts[nbEmprunts].isbn = isbn;

            printf("Jour d'emprunt (jj) : ");
            scanf("%d", &emprunts[nbEmprunts].jour);
            printf("Mois d'emprunt (mm) : ");
            scanf("%d", &emprunts[nbEmprunts].mois);
            printf("Année d'emprunt (aaaa) : ");
            scanf("%d", &emprunts[nbEmprunts].annee);

            nbEmprunts++;

            printf("\n+---------------------------+\n");
            printf("|     Livre emprunté       |\n");
            printf("+---------------------------+\n");

            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("\n+-----------------------------------+\n");
        printf("| Livre non disponible ou introuvable |\n");
        printf("+-----------------------------------+\n");
    }
    system("pause");
}
void retournerLivre() {
    int isbn, i, trouve = 0;
    do{
    printf("\n===== RETOUR D'UN LIVRE =====\n\n");
    printf("ISBN du livre à retourner : ");
    scanf("%d", &isbn);
     if (isbn < 10000 || isbn > 99999) {
       printf("ISBN invalide. Veuillez entrer un nombre à 5 chiffres.\n");
        }
    } while (isbn < 10000 || isbn > 99999);


    for (i = 0; i < nbLivres; i++) {
        if (livres[i].isbn == isbn && livres[i].etat == 1) {
            livres[i].etat = 0;
            printf("\n+------------------------------+\n");
            printf("|   Livre retourné avec succès  |\n");
            printf("+------------------------------+\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("\n+----------------------------------+\n");
        printf("| Livre non trouvé ou déjà disponible |\n");
        printf("+----------------------------------+\n");
    }
    system("pause");
}

int afficherMenu() {
    system("cls");
    int choix;
    printf("\n+==================================+\n");
    printf("|      MENU DE LA BIBLIOTHÈQUE     |\n");
    printf("+==================================+\n");
    printf("| 1. Ajouter un livre              |\n");
    printf("| 2. Afficher les livres           |\n");
    printf("| 3. Rechercher un livre           |\n");
    printf("| 4. Supprimer un livre            |\n");
    printf("| 5. Emprunter un livre            |\n");
    printf("| 6. Retourner un livre            |\n");
    printf("| 7. Afficher les statistiques     |\n");
    printf("| 0. Quitter                       |\n");
    printf("+----------------------------------+\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}
void ajouterLivre() {
    if (nbLivres >= MAX) {
        printf("\n+---------------------------+\n");
        printf("|    Bibliothèque pleine ! |\n");
        printf("+---------------------------+\n");
        return;
    }

    printf("\n===== AJOUT D'UN NOUVEAU LIVRE =====\n\n");

    printf("Titre : ");
    scanf(" %[^\n]", livres[nbLivres].titre);

    printf("Auteur : ");
    scanf(" %[^\n]", livres[nbLivres].auteur);

    printf("Année de publication : ");
    scanf("%d", &livres[nbLivres].annee);

    do {
        printf("ISBN (5 chiffres) : ");
        scanf("%d", &livres[nbLivres].isbn);
        if (livres[nbLivres].isbn < 10000 || livres[nbLivres].isbn > 99999) {
            printf("ISBN invalide. Veuillez entrer un nombre à 5 chiffres.\n");
        }
    } while (livres[nbLivres].isbn < 10000 || livres[nbLivres].isbn > 99999);

    livres[nbLivres].etat = 0;
    nbLivres++;

    printf("\n+------------------------------+\n");
    printf("|  Livre ajouté avec succès   |\n");
    printf("+------------------------------+\n");
    system("pause:");
}
void rechercherLivre() {
    int choix;
    char terme[100];
    int trouve = 0;

    printf("\n===== RECHERCHE D'UN LIVRE =====\n\n");
    printf("Rechercher par : 1. Titre  2. Auteur : ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("\nTitre à rechercher : ");
        scanf(" %[^\n]", terme);
        for (int i = 0; i < nbLivres; i++) {
            if (strcmp(livres[i].titre, terme) == 0) {
                afficherLivre(livres[i]);
                trouve = 1;
            }
        }
    } else if (choix == 2) {
        printf("\nAuteur à rechercher : ");
        scanf(" %[^\n]", terme);
        for (int i = 0; i < nbLivres; i++) {
            if (strcmp(livres[i].auteur, terme) == 0) {
                afficherLivre(livres[i]);
                trouve = 1;
            }
        }
    } else {
        printf("Choix invalide.\n");
    }

    if (!trouve) {
        printf("\nAucun livre trouvé.\n");
    }
}
void afficherLivre(struct Livre livre) {
    printf("Titre: %s\n", livre.titre);
    printf("Auteur: %s\n", livre.auteur);
    printf("Année: %d\n", livre.annee);
    printf("ISBN: %d\n", livre.isbn);
    printf("État: %s\n\n", livre.etat ? "Emprunté" : "Disponible");
}
void afficherLivres() {
    printf("\n=== LIVRES DISPONIBLES ===\n\n");
    for (int i = 0; i < nbLivres; i++) {
        afficherLivre(livres[i]);
    }
}
void supprimerLivre() {
    int isbn, i, j, trouve = 0;

    printf("\n===== SUPPRESSION D'UN LIVRE =====\n\n");
    do{
    printf("ISBN du livre à supprimer (5 chiffres) : ");
    scanf("%d", &isbn);
    if (isbn < 10000 || isbn > 99999) {
        printf("ISBN invalide. Veuillez entrer un nombre à 5 chiffres.\n");
        }
    } while (isbn < 10000 || isbn > 99999);



    for (i = 0; i < nbLivres; i++) {
        if (livres[i].isbn == isbn) {


    for (j = i; j < nbLivres - 1; j++) {
                livres[j] = livres[j + 1];
            }
            nbLivres--;
            trouve = 1;
            printf("\n+-----------------------------+\n");
            printf("|   Livre supprimé avec succès |\n");
            printf("+-----------------------------+\n");
            break;
        }
    }

    if (!trouve) {
        printf("\n+---------------------+\n");
        printf("| Livre introuvable ! |\n");
        printf("+---------------------+\n");
    }
}



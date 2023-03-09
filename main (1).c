#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Fonctions.c"


int main () {
    Fichier_LnOF *F = malloc (sizeof(Fichier_LnOF));
    char *nomFichier = "fich_bin.bin", *nomFichierIndex = "Index_Matricule.bin";
    Buffer_LnOF *buf = calloc(1, sizeof(Buffer_LnOF));
    TableIndex *tabIndex =  calloc(1, sizeof(TableIndex));
    Fichier_TOF_Index *fich_index = malloc(sizeof(Fichier_TOF_Index));
    int nbSoldats, choix, i, stop;
    Initiation();
    ClearScrean();
    stop = 0;

    stop = Faux;
    printf("\n\t\t\t+-------------------------+");
    printf("\n\t\t\t|        TP SFSD          |");
    printf("\n\t\t\t+-------------------------+");
    printf("\n\t>> Veuillez choisir un chois parmi les deux suivants :");
    printf("\n\t>> 1. Creer un nouveau fichier");
    printf("\n\t>> 2. Ouvrir un fichier qui existe deja");
    printf("\n\t\t >> Votre choix: ");
    scanf("%d", &choix);

    switch(choix) {
        case 1:
            {
                printf("\n\t>> Veuillez inserer le nombre de soldats :");
                scanf("%d", &nbSoldats);
                CreerFichier(nomFichier, nbSoldats, tabIndex);
                Sauv_Tab_Index(tabIndex, fich_index);
                printf("\n\t>> Creation terminee\n\n\t>> ");
                system("PAUSE");
            } break;
        case 2:
             {
                F = Ouvrir(nomFichier, 'A');
                RemplirIndexFichier(nomFichierIndex, tabIndex);
                printf("\n\t >> Ouverture terminee, Index cree en MC \n\n\t>> ");
                system("PAUSE");
             } break;
        default: printf("\n   >> Erreur!!");
    }


    while(!stop){
        ClearScrean();
        printf("\n\t\t\t\t+------------------------+");
        printf("\n\t\t\t\t|     Menu Principal     |");
        printf("\n\t\t\t\t+------------------------+");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  1.Affichage de l entete du fichier                                                     |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  2.Affichage des trois premiers bloc                                                    |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  3.Insertion d un nouveau soldat                                                        |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  4.Modification de la region melitaire d un soldat                                      |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  5.Suppression d un soldat donne par son matricule                                      |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  6.Suppression de tous les soldats appartenant a une region melitaire                   |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  7.Affichage des soldats qui ont le meme grade                                          |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  8.Affichage des soldats d une region qui ont un age compris entre deux valeurs donees  |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  9.Fragmentation du fichier binaire                                                     |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t|  10. Quitter le programme                                                               |");
        printf("\n\t+-----------------------------------------------------------------------------------------+");
        printf("\n\t\t\t\t\t >> Votre choix est :     ");
        scanf("%d", &i);
    int a;
        switch(i){
            case 1: AfficherEntete(nomFichier); printf("\n\t >> "), system("PAUSE"); break;
            case 2: ClearScrean(); for (int k = 1; k <= 3 ; k++) AffichageBloc(nomFichier, k); printf("\n\t >> "); system("PAUSE"); break;
            case 3: InsererEnreg(nomFichier, tabIndex); printf("\n\t >> "); system("PAUSE"); break;
            case 4: ModifierRegion(nomFichier, tabIndex); printf("\n\t >> "); system("PAUSE"); break;
            case 5: SupprimSelonMatricule(tabIndex, nomFichier); printf("\n\t >> "); system("PAUSE"); break;
            case 6: SupprimSelonForces(nomFichier, tabIndex); printf("\n\t >> "); system("PAUSE"); break;
            case 7: AfficherSelonGrades(nomFichier); printf("\n\t >> "); system("PAUSE"); break;
            case 8: AfficherSelonRegionAge(nomFichier); printf("\n\t >> "); system("PAUSE"); break;
            case 9: Fragmentation(nomFichier); printf("\n\t >> "); system("PAUSE"); break;
            case 10: {ClearScrean();
                printf("\n\n\t\t+--------------------------------------------------------+"); printf("\n\t\t|       Le cout total:      %-5d                        |", coutTotal);
                printf("\n\t\t+--------------------------------------------------------+\n\t>> "); system("PAUSE"); Cloture(); stop = 1;} break;
            default: printf("\n\t  >>    Erreur : Numero non autorise"); printf("\n\t >> "); system("PAUSE");
        }
    }

    return 1;
}

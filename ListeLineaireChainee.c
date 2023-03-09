#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListeLineaireChainee.h"
#define Vrai 1
#define Faux 0
typedef int bool;

bool ExistMatricule(Pointeur_Maillon *tete, int val){
    Pointeur_Maillon P = calloc (1, sizeof(Maillon)), Q = calloc(1, sizeof(Maillon));
    bool trouv;

    trouv = Faux;

    if (*tete == NULL) {         // Liste vide
        Allouer_Maillon(&P);
        (*tete) = P;            // Sauvegarder la tête
        Aff_Matricule(P, val);
        Aff_Adr(P, NULL);
    }
    else{
        P = (*tete);
        while ((P != NULL) && (!trouv)){
            if (ID(P) == val){
                trouv = Vrai;
            }
            else {
                Q = P;                // Savegarder P
                P = Suivant(P);       // P = P->suiv;
            }
        }
        if (!trouv){                // si le matricule est non trouvé, on l'insère dans la liste
            Allouer_Maillon(&P);
            Aff_Adr(P, NULL);
            Aff_Matricule(P, val);
            Aff_Adr(Q, P);          // Attacher le nouveau maillon à la liste
        }
    }
    return trouv;
}

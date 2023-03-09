#ifndef LISTELINEAIRECHAINEE_H_INCLUDED
#define LISTELINEAIRECHAINEE_H_INCLUDED


        /******* Structure de Donn�es *******/
typedef struct Maillon{
    int matricule;
    struct Maillon *suiv;
}Maillon;
typedef Maillon *Pointeur_Maillon;


        /***********************************/

Pointeur_Maillon Allouer_Maillon(Pointeur_Maillon *P){
    (*P) = calloc(1, sizeof(Maillon));
    (*P)->suiv = NULL;
}

        /***********************************/

void Liberer_Maillon(Pointeur_Maillon P){
    free(P);
}

        /***********************************/

Pointeur_Maillon Suivant(Pointeur_Maillon P){
    return (P->suiv);
}

        /***********************************/

int ID(Pointeur_Maillon P){
    return(P->matricule);
}

void Aff_Matricule(Pointeur_Maillon P, int val){
    P->matricule = val;
}

void Aff_Adr(Pointeur_Maillon P, Pointeur_Maillon Q){
     P->suiv = Q;
}


Pointeur_Maillon Allouer_Maillon(Pointeur_Maillon *P);
void Liberer_Maillon(Pointeur_Maillon P);
Pointeur_Maillon Suivant(Pointeur_Maillon P);
int ID(Pointeur_Maillon P);
void Aff_Matricule(Pointeur_Maillon P, int val);
void Aff_Adr(Pointeur_Maillon P, Pointeur_Maillon Q);
bool ExistMatricule(Pointeur_Maillon *tete, int val);


#endif // LISTELIN�AIRECHAIN�E_H_INCLUDED

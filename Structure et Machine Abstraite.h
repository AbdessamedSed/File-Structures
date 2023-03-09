#ifndef STRUCTURE_ET_MACHINE_ABSTRAITE_H_INCLUDED
#define STRUCTURE_ET_MACHINE_ABSTRAITE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 60
#define Max_Tab_Index 60

typedef int bool;

/****************************************************************************************************************************************
                                                    |   LnOF    |
****************************************************************************************************************************************/

/************************************************** Les Structures des Donn�es ********************************************************/

/* D�claration d'un enregistrement */
typedef struct Tenreg_LnOF {
    int matricule;
    char nom[31];
    char prenom[31];
    char dateDeNaissance[10];
    int wilayaDeNaissance;
    int groupeSanguin;
    int grade;
    int forceArmee;
    int regionMelitaire;
} Tenreg_LnOF;

/* D�clartion d'un bloc */
typedef struct Tbloc_LnOF {
    Tenreg_LnOF tab [Max];
    int nb;     // nombre d'enregistrements remplis dans le bloc
    int suiv;   // Le num�ro du bloc suivant
} Tbloc_LnOF;

/* D�claratoin d'un buffer */
typedef struct Tbloc_LnOF Buffer_LnOF;

/* D�claration de l'ent�te du fichier */
typedef struct  {
    int numPremierBloc;     // num�ro du premier bloc
    int nbEnreg;            // nombre d'enregistements ins�r�s
    int numDernierBloc;     // num�ro du dernier bloc
} Entete_LnOF;

/* D�claration du fichier */
typedef struct {
    Entete_LnOF entete;
    FILE *fichier;
} Fichier_LnOF;

/****************************************************************************************************************************************
                                                    |   Table d'index    |
****************************************************************************************************************************************/

/* Déclaration d'un enregistrement */
typedef struct Tmatricule_TOF_index  {
int Matricule;
int NumbBloc; // i
int Depl;  // j
}Tmatricule_TOF_index ;

/* Déclaration de la table */
typedef struct TableIndex {
    int NbE;
    Tmatricule_TOF_index tabIndex[300000];
} TableIndex;

/****************************************************************************************************************************************
                                                    |   Fichier Index TOF    |
****************************************************************************************************************************************/
/* Déclar ation de l'entête */
typedef struct {
    int NbrBloc;
    int NbrEnreg;
}Entete_TOF_Index;

/* D�claration du fichier index TOF */
typedef struct {
    Entete_TOF_Index entete;
    FILE *fichier;
} Fichier_TOF_Index ;

typedef struct {
    int nb; //le nbr d'enreg par bloc
    Tmatricule_TOF_index tab[Max_Tab_Index];
} Tbloc_TOF_Index;







/****************************************************** La Machine Abstraite ***************************************************************/
//void LireDir(Fichier_LnOF *fichier, int i, Buffer_LnOF *buf);
void EcrireDir(Fichier_LnOF *fichier, int i, Buffer_LnOF buf);
Fichier_LnOF *Ouvrir(char nomFichier [10], char mode);
int Entete(Fichier_LnOF *fich,int i);
void Aff_Entete(Fichier_LnOF *fich, int i, int info);
void Fermer(Fichier_LnOF *fich);
void Ouvrir_TOF_Index(Fichier_TOF_Index *fich, char nom_fichier[260], char mode);
void Fermer_TOF_Index(Fichier_TOF_Index *fich);
void LireDir_TOF_Index(Fichier_TOF_Index fich, int i, Tbloc_TOF_Index *Buf);
void EcrireDir_TOF_Index(Fichier_TOF_Index *fich, int i, Tbloc_TOF_Index Buf);
void Aff_Entete_TOF_Index(Fichier_TOF_Index *fich, int i, int val);
int Entete_Index(Fichier_TOF_Index fich, int i);



#endif // STRUCTURE_ET_MACHINE_ABSTRAITE_H_INCLUDED

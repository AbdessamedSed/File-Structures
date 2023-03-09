#include "Structure et Machine Abstraite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************************
                                            |LireDir|
            *********************************************************************************/

/* La fonction permettant de lire le contenu du fichier dand le buffer */
void LireDir(Fichier_LnOF *fich, int i, Buffer_LnOF *buf)
{
    fseek(fich->fichier, sizeof(Entete_LnOF) + (i - 1) * sizeof(Buffer_LnOF), SEEK_SET); // positionnement � la place correspendante
    fread(buf, sizeof(Buffer_LnOF), 1, fich->fichier);                                   // lecture du bloc
};

/*********************************************************************************
                                |EcrireDir|
*********************************************************************************/
/* La fonction permettant d'�crire le contenu d'un buffer dans un fichier */
void EcrireDir(Fichier_LnOF *fich, int i, Buffer_LnOF buf)
{
    fseek(fich->fichier, sizeof(Entete_LnOF) + (i - 1) * sizeof(Buffer_LnOF), SEEK_SET); // positionnement � la place correspendante
    fwrite(&buf, sizeof(Buffer_LnOF), 1, fich->fichier);                                 // �criture
};

/*********************************************************************************
                                |Entete|
*********************************************************************************/
/* La fonction permettant d'extraire une information num�rot�e � partir de l'ent�te */
int Entete(Fichier_LnOF *fich, int i)
{
    int j;
    switch (i)
    {
    case 1:
        j = (fich->entete).numPremierBloc;
        break;
    case 2:
        j = (fich->entete).nbEnreg;
        break;
    case 3:
        j = (fich->entete).numDernierBloc;
        break;
    default:
    {
        printf(" >> Erreur: numero errone !");
        return -1;
    }
    }
    return j;
};

/*********************************************************************************
                                |Aff_Entete|
*********************************************************************************/
/* La foncion permettant d'affecter une information � un champ de l'ent�te */
void Aff_Entete(Fichier_LnOF *fich, int i, int info)
{
    switch (i)
    {
    case 1:
        (fich->entete).numPremierBloc = info;
        break;
    case 2:
        (fich->entete).nbEnreg = info;
        break;
    case 3:
        (fich->entete).numDernierBloc = info;
        break;
    default:
        printf(" >> Erreur: numero errone !");
    }
};

/*********************************************************************************
                                |Ouvrir|
*********************************************************************************/
/* La fonction permettant d'ouvrir un fichier dans un mode donn� */
Fichier_LnOF *Ouvrir(char *nomFichier, char mode)
{
    Fichier_LnOF *fich = malloc(sizeof(Fichier_LnOF)); // allocation dynamique d'une zone dans la m�moire centrale pour l'ent�te
    char s[4];

    if ((mode == 'a') || (mode == 'A'))
        sprintf(s, "rb+");
    else
        sprintf(s, "wb+");

    fich->fichier = fopen(nomFichier, s);
    if ((mode == 'a') || (mode == 'A'))
    {
        fread(&(fich->entete), sizeof(Entete_LnOF), 1, fich->fichier);
    }
    else
    {
        (fich->entete).numPremierBloc = 0;
        (fich->entete).nbEnreg = 0;
        (fich->entete).numDernierBloc = 0;
        fwrite(&(fich->entete), sizeof(Entete_LnOF), 1, fich->fichier);
    }
    return fich;
};

/*********************************************************************************
                                |Fermer|
*********************************************************************************/
/* La fonction permettant de fermer le fichier */
void Fermer(Fichier_LnOF *fich)
{
    rewind(fich->fichier);                                          // positionnement au d�but du fichier
    fwrite(&(fich->entete), sizeof(Entete_LnOF), 1, fich->fichier); // mise � jour de l'ent�te
    rewind(fich->fichier);
    fclose(fich->fichier); // fermer le fichier
    free(fich);            // lib�rer la zone r�serv� pour l'ent�te
}

/*********************************************************************************
                                |AllocBloc|
*********************************************************************************/
/* La fonction permettant d'allouer ub bloc */
void AllocBloc(Fichier_LnOF *fich)
{
    Buffer_LnOF *buf = calloc(1, sizeof(Buffer_LnOF));
    LireDir(fich, Entete(fich, 3), buf);      // Lecture du bloc queue
    buf->suiv = Entete(fich, 3) + 1;          // Attacher le nouveau bloc au celui qui le pr�c�de
    EcrireDir(fich, Entete(fich, 3), *buf);   // Ecriture du bloc lu pr�c�demment
    Aff_Entete(fich, 3, Entete(fich, 1) + 1); // Mise � jour de la queue
    buf->suiv = -1;                           // Le dernier bloc pointe vers NiL
    buf->nb = 0;                              // Initialisation du nombre d'enregistrements ins�r�s
    EcrireDir(fich, Entete(fich, 3), *buf);   // Ecriture du nouveau bloc
    Aff_Entete(fich, 1, Entete(fich, 1) + 1); // Mise � jour du nombre de blocs
};

/***********************************Machines du fichier TOF pour Index **************************************************/

void Ouvrir_TOF_Index(Fichier_TOF_Index *fich, char *nom_fichier, char mode)
{
    if ((mode == 'a') || (mode == 'A'))
    { // cas 1: ouverture d'un ancien fichier deja creer
        (*fich).fichier = fopen(nom_fichier, "rb+");
        if ((*fich).fichier == NULL) // Verification d'ouverture du fichier
        {
            fprintf(stderr, "Erreur d'ouverture fichier.\n");
            exit(EXIT_FAILURE);
        }
        fseek((*fich).fichier, 0, SEEK_SET);                                  // se positionner en debut de fichier
        fread(&(*fich).entete, sizeof(Entete_TOF_Index), 1, (*fich).fichier); // recuperatoin de l'entete dans son buffer local
    }
    else
    {
        if ((mode == 'n') || (mode == 'N'))
        { // cas 2: ouverture d'un nouveau fichier
            (*fich).fichier = fopen(nom_fichier, "wb+");
            if ((*fich).fichier == NULL) // Verification d'ouverture du fichier
            {
                fprintf(stderr, "Erreur d'ouverture fichier.\n");
                exit(EXIT_FAILURE);
            }
            (*fich).entete.NbrBloc = 0; // initialisation de l'entete
            (*fich).entete.NbrEnreg = 0;
        }
        else
        { // mauvais mode selectionne
            fprintf(stderr, "Erreur d'ouverture fichier.\n");
            exit(EXIT_FAILURE);
        }
    }
};

//**************************************************

void Fermer_TOF_Index(Fichier_TOF_Index *fich)
{
    fseek((*fich).fichier, 0, SEEK_SET);                                   // se positionner en debut de fichier
    fwrite(&(*fich).entete, sizeof(Entete_TOF_Index), 1, (*fich).fichier); // mise a jour de l'entete avant la fermeture du fichier
    fclose((*fich).fichier);
}
//**************************************************

void LireDir_TOF_Index(Fichier_TOF_Index fich, int i, Tbloc_TOF_Index *Buf)
{
    fseek(fich.fichier, sizeof(Entete_TOF_Index), SEEK_SET);
    fseek(fich.fichier, (i - 1) * sizeof(Tbloc_TOF_Index), SEEK_CUR); // se positionner juste avant le bloc conserne
    fread(Buf, sizeof(Tbloc_TOF_Index), 1, fich.fichier);             // recuperer le bloc dans le buffer
}
//*************************************************

void EcrireDir_TOF_Index(Fichier_TOF_Index *fich, int i, Tbloc_TOF_Index Buf)
{
    fseek((*fich).fichier, sizeof(Entete_TOF_Index), SEEK_SET);
    fseek((*fich).fichier, (i - 1) * sizeof(Tbloc_TOF_Index), SEEK_CUR); // se positionner juste avant le bloc conserne
    fwrite(&Buf, sizeof(Tbloc_TOF_Index), 1, (*fich).fichier);           // ecriture du contenu du buffer dans le bloc
}
//*************************************************

void Aff_Entete_TOF_Index(Fichier_TOF_Index *fich, int i, int val)
{ // affecter la valeur val a l'i eme champ de l'entete du fichier fich
    switch (i)
    {
    case 1:
        (*fich).entete.NbrBloc = val;
        break;
    case 2:
        (*fich).entete.NbrEnreg = val;
        break;
    default:
        printf(" >> Erreur: numero errone !");
    }
}
//*************************************************

int Entete_Index(Fichier_TOF_Index fich, int i)
{ // recuperation de la valeur de l'i eme champ de l'entete du fichier fich
    int j;
    switch (i)
    {
    case 1:
        j = (fich.entete.NbrBloc);
        break;
    case 2:
        j = (fich.entete.NbrEnreg);
        break;
    default:
    {
        printf(" >> Erreur: numero errone !");
        return -1;
    }
    }
    return j;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Fonctions.h"
#include "ListeLineaireChainee.c"
#define Vrai 1
#define Faux 0
Pointeur_Maillon P = NULL;
int coutTotal = 0;


            /*********************************************************************************
                    | Des fonctions générant des informations à paritr des entiers données |
            *********************************************************************************/

/* une fonction qui retourne un nom et un nom compos�s de n caract�res, avec n un entier donn� */
char *Nom(int i) {
    char *Nom = calloc(31, sizeof(char)), alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int j, random;

    for (j = 0 ; j < i; j++) {
        random = rand() %(26 - 1) + 1;
        Nom [j] = alphabet[random];
    }
    Nom [i] = '\0';
    return Nom;
}

/* une fonction qui retourne un nom et un pr�nom compos�s de n caract�res, avec n un entier donn� */
char *Prenom(int i) {
    char *Prenom = calloc(31, sizeof(char)), alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int j, random;

    for (j = 0 ; j < i; j++) {
        random = rand() %(26 - 1) + 1;
        Prenom [j] = alphabet[random];
    }
    Prenom [i] = '\0';
    return Prenom;
}

/* une fonction qui g�n�re une date de naissance */
char *DateDeNaissance() {
    int jours, mois, annee;
    char *joursStr = calloc(3, sizeof(char)), *moisStr = calloc(3, sizeof(char)),
         *anneeStr = calloc(5, sizeof(char)),*date = calloc(11,sizeof(char)),
         phalnage[] = "1 3 5 7 8 10 12", *ret = NULL;
    date[0] = '\0';

        /* g�n�rer l'ann�e */
    annee = rand() % (2003 - 1943) + 1943 ;
    itoa(annee, anneeStr, 10);  // transformer l'ann�e en une chaine
    anneeStr[5] = '\0';

        /* g�n�rer le mois */
    mois = rand() % (12 - 1) + 1;
    itoa(mois, moisStr, 10);
    moisStr[3] = '\0';

        /* g�n�rer le jours */
    if ((annee % 4 != 0) && (mois == 2)) jours = rand() % (28 - 1) + 1;   // ann�e non bissextile
    if ((annee % 4 == 0) && (mois == 2)) jours = rand() % (29 - 1) + 1;   // ann�e bissextile

    ret = strstr(phalnage, moisStr);    // tester si le mois appartient au ceux ayant 31 jours
    if (ret) {jours = rand() % (31 - 1) + 1;}  // si oui
    else {jours = rand() % (30 - 1) + 1;}  // si non
    itoa(jours, joursStr, 10);
    joursStr[3] = '\0';

    /* concat�nation des chaines afin d'obtenir la date compl�te */
    strcat(date, joursStr);
    strcat(date, " ");
    strcat(date, moisStr);
    strcat(date, " ");
    strcat(date, anneeStr);
    /* concat�nation des chaines afin d'obtenir la date compl�te */

    date[11] = '\0';
    return date;
}

            /*********************************************************************************
                    |Les modules permettant de trouver une information à partir d'un entier|
            **********************************************************************************/
/* Une fonction permettant d'afficher une wilaya à partir de son numéro */
int Wilaya(int i){
    int j;
    char Wilayas[] = "Adrar-Chlef-Laghouat-OumElBouaghi-Batna-Bejaia-biskra-Bechar-Blida-Bouira-Tamanrasset-Tebessa-Tlemcen-Tiaret-Tizi Ouzou-Alger-Djelfa-Jijel-Setif-Saida-Skikda-Sidi Bel Abbes-Annaba-Guelma-Constantine-Medea-Monstganem-Msila-Mascara-Ouargla-Oran-Bayadh-Illizi-Bordj Bou Arreridj-Boumerdes-Tarf-Tindouf-Tissemsilt-El Oued-Khenchela-Souk Ahras-Tipaza-Mila-Ain Defla-Naama-Ain Temouchent-Ghardaia-Relizane-Timimoun-Bordj Badji Mokhtar-Ouled Djellal-Beni Abbes-In Salah-In Guezzam-Touggourt-Djanet-El Mghair-El Meniaa" ;
    char s[2] = "-";
    char *token = calloc(20, sizeof(char));
    token = strtok(Wilayas,s);
    for (j = 1 ; j < i ; j++) token = strtok(NULL,s);
    printf("\n\t|  Wilaya de Naissance   |  %-50s|", token);
}

/* Une fonction permettant d'afficher un groupe sanguin à partitr d'un entier */
int GroupeSanguin(int i){
    int j=1;
    char Groupes[] = "O+/A+/B+/O+/A+/AB+/B+/AB+";
    char s[2] = "/";
    char *token = calloc(4, sizeof(char));
    token = strtok(Groupes,s);
    for (j = 2 ; j < i ; j++) token = strtok(NULL,s);
    printf("\n\t|  Groupe Sanguin        |  %-50s|", token);
}

/* La fonction permettant d'afficher une force armée à partir d'un entier */
int ForceArmee(int i){
    int j;
    char Forces[] = "Armee de terre/Armee de l air/Marine nationale/Defense aerienne du territoire/Gendarmerie nationale/Garde republicaine/Departement du renseignement et de la securite/Sante militaire";
    char s[2] = "/";
    char *token = calloc(47, sizeof(char));
    token = strtok(Forces,s );
    for (j = 1 ; j < i ; j++) token = strtok(NULL,s );
    printf("\n\t|  Force Armee           |  %-50s|", token);

}

/* La fonction permettant d'afficher une région mélitaitre à partir d'un entier */
int RegionMelitaire (int i){
    int j;
    char Regions[] = "RM Blida/RM Oran/RM Bechar/RM Ouargla/RM Constantine/RM Tamanrasset";
    char s[2] = "/";
    char *token = calloc(15, sizeof(char));
    token = strtok(Regions,s);
    for (j = 1 ; j < i ; j++) token = strtok(NULL,s);
    printf("\n\t|  Region Melitaire      |  %-50s|", token);
}


void ClearScrean(){
    system("cls");
}

            /*********************************************************************************
                        |Module permettant de remplir un enregistrement|
            **********************************************************************************/
void RemplirEnrg(Tenreg_LnOF *enrg)
{
    int random;
    bool stop = Faux;
    Pointeur_Maillon P = NULL;

    while (!stop)
    {
        random = 111111 + rand() % (999999 + 1 - 111111);
        if (!ExistMatricule(&P, random))
        {
            enrg->matricule = 111111 + rand() % (999999 + 1 - 111111);
            stop = Vrai;
        }
    }
    random = rand() % (30 - 4) + 4;
    strcpy(enrg->nom, Nom(random));
    strcpy(enrg->prenom, Prenom(random));
    strcpy(enrg->dateDeNaissance, DateDeNaissance());
    enrg->wilayaDeNaissance = rand() % (58 - 1) + 1;
    enrg->groupeSanguin = rand() % (8 - 1) + 1;
    enrg->grade = rand() % (17 - 1) + 1;
    enrg->forceArmee = rand() % (8 - 1) + 1;
    enrg->regionMelitaire = rand() % (6 - 1) + 1;
}

        /*********************************************************************************
                    |Le module permettant de remplir un bloc|
        **********************************************************************************/
void RemplirBloc(Buffer_LnOF *buf, Tenreg_LnOF *enreg, int j)
{
    buf->tab[j].matricule = enreg->matricule;
    strcpy(buf->tab[j].nom, enreg->nom);
    strcpy(buf->tab[j].prenom, enreg->prenom);
    strcpy(buf->tab[j].dateDeNaissance, enreg->dateDeNaissance);
    buf->tab[j].wilayaDeNaissance = enreg->wilayaDeNaissance;
    buf->tab[j].groupeSanguin = enreg->groupeSanguin;
    buf->tab[j].grade = enreg->grade;
    buf->tab[j].forceArmee = enreg->forceArmee;
    buf->tab[j].regionMelitaire = enreg->regionMelitaire;
}

        /*********************************************************************************
                        |Le module permettant de remplir la table d'Index|
        **********************************************************************************/
void RemplirIndex(TableIndex *tabIndex, int k, int ID, int numBloc, int position)
{
    tabIndex->tabIndex[k].Matricule = ID;
    tabIndex->tabIndex[k].NumbBloc = numBloc;
    tabIndex->tabIndex[k].Depl = position;
}

        /*********************************************************************************
                    |La fontion permettant de remplir le fichier|
        *********************************************************************************/

/* une fonction permettant de remplir un fichier */

void CreerFichier(char *nomFichier, int nbSoldats, TableIndex *tabIndex)
{
    Fichier_LnOF *F;
    Tenreg_LnOF *enreg = calloc(1, sizeof(Tenreg_LnOF));
    Buffer_LnOF *buf = calloc(1, sizeof(Buffer_LnOF));
    int n, i, j;
    int k = 0; // compteur d'enreg dans la table d'index
    bool continu = Vrai;

    F = Ouvrir(nomFichier, 'N');
    /* Chargement de blocs compl�tement charg�s */
    n = nbSoldats / Max; // n rep�sente le nombre de blocs compl�tement charg�s
    i = 1;               // i compteur de blocs
    if (n != 0)
    {
        while (continu)
        {
            for (j = 0; j < Max; j++)
            {
                RemplirEnrg(enreg); // Rempplissage de l'enregistrement
                RemplirBloc(buf, enreg, j);
                RemplirIndex(tabIndex, k, enreg->matricule, i, j);
                k++;
            }
            buf->nb = Max;     // tout bloc contient Max enregistrements
            buf->suiv = i + 1; // pointeur vers le prochain bloc ----------------------------------------
            if ((i == n) && (nbSoldats % Max == 0))
                buf->suiv = -1;
            EcrireDir(F, i, *buf);
            i++; // passer au bloc suivant
            if (i > n)
            {
                i--; // ------------------------------------------------------+
                continu = 0;
            } // chargement fini
        }
        Aff_Entete(F, 1, 1);
        Aff_Entete(F, 3, i);
    }
    /* charfement du dernier bloc */
    n = (nbSoldats % Max); // n vaut le nombre d'enregistrements restant
    if (n != 0)
    {
        for (j = 0; j < n; j++)
        {                       // remplissage du dernier bloc - non complet -
            RemplirEnrg(enreg); // Rempplissage de l'enregistrement
            RemplirBloc(buf, enreg, j);
            RemplirIndex(tabIndex, k, enreg->matricule, i + 1, j);
            k++;
        }
        buf->nb = n;
        buf->suiv = -1;
        EcrireDir(F, i + 1, *buf); // -----------------------------------------------------+
        Aff_Entete(F, 1, 1);
        Aff_Entete(F, 3, i + 1);
    }

    Aff_Entete(F, 2, nbSoldats);
    tabIndex->NbE = nbSoldats;
    quickSort(tabIndex, 0, tabIndex->NbE - 1);
    Fermer(F);
}

        /*********************************************************************************
                    |Le module permettant d'afficher un bloc|
        *********************************************************************************/

void AffichageBloc(char *nomFichier, int b)
{
    Fichier_LnOF *F;
    F = Ouvrir(nomFichier, 'A');
    Buffer_LnOF *buf = malloc(sizeof(Buffer_LnOF));
    LireDir(F, b, buf);
    printf("\n\t\t\t\t+------------------------------+");
    printf("\n\t\t\t\t|         Bloc%2d               |", b);
    printf("\n\t\t\t\t+------------------------------+");
    printf("\n\t\t\t+----------------------------------------------+");
    printf("\n\t\t\t|Le nombre du bloc suivant :        %2d         |", buf->suiv);
    printf("\n\t\t\t|Le nombre d'enreg dans le bloc :   %3d        |", buf->nb);
    printf("\n\t\t\t+----------------------------------------------+");
    for (int i = 0; i < buf->nb; i++)
    {
        printf("\n\n\t\t\t\t+------------------------+");
        printf("\n\t\t\t\t|    Soldat numero %-6d|", i+1);
        printf("\n\t\t\t\t+------------------------+");
        printf("\n\t+------------------------+----------------------------------------------------+");
        printf("\n\t|  Matricule             |  %-50d|", buf->tab[i].matricule);
        printf("\n\t|  Nom                   |  %-50s|", buf->tab[i].nom);
        printf("\n\t|  Prenom                |  %-50s|", buf->tab[i].prenom);
        printf("\n\t|  Date de Naissance     |  %-50s|", buf->tab[i].dateDeNaissance);
        Wilaya(buf->tab[i].wilayaDeNaissance);
        GroupeSanguin(buf->tab[i].groupeSanguin);
        ForceArmee(buf->tab[i].forceArmee);
        RegionMelitaire(buf->tab[i].regionMelitaire);
        printf("\n\t+------------------------+----------------------------------------------------+");
    }
    Fermer(F);
}

        /*********************************************************************************
                    |Le module permettant d'afficher l'index|
        *********************************************************************************/

void AffichageIndex(TableIndex *tabIndex)
{
    int k = 0;

    printf("le nombre d'enreg dans table d'index : %d \n ", tabIndex->NbE);
    printf("\n \n ----------------------------------------- \n ");
    printf("\n \n ----------------------------------------- \n ");
    printf("\n \n ----------------------------------------- \n ");

    for (k = 0; k < tabIndex->NbE; k++)
    {
        printf("Matricule [ %d] : %d \n", k, tabIndex->tabIndex[k].Matricule);
        printf("Bloc du Mat  [ %d] : %d \n", k, tabIndex->tabIndex[k].NumbBloc);
        printf("Deplacement du Mat  [ %d] : %d \n ", k, tabIndex->tabIndex[k].Depl);
        printf("\n \n ----------------------------------------- \n ");
    }
}

        /*********************************************************************************
                    |Le module permettant d'afficher l'entête|
        *********************************************************************************/
void AfficherEntete(char *nomFichier)
{
    ClearScrean();
    Fichier_LnOF *F;
    F = Ouvrir(nomFichier, 'A');
    printf("\n\t\t+------------------------------------------------------------------+");
    printf("\n\t\t|             L'entete du fichier LObarF                           |");
    printf("\n\t\t+------------------------------------------------------------------+");
    printf("\n\t+------------------------------------------------------------+--------------------+");
    printf("\n\t|Numero du premier bloc (Tete de la liste)                   |      %5d         |", Entete(F, 1));
    printf("\n\t|Nombre d'enreg dans le fichier                              |      %5d         |", Entete(F, 2));
    printf("\n\t|Numero du bloc queue = Nombre de blocs dans le fichier      |      %5d         |", Entete(F, 3));
    printf("\n\t+------------------------------------------------------------+--------------------+");
    Fermer(F);
}

        /*********************************************************************************
                |Le module permettant de permuter le contenu de deux variables|
        *********************************************************************************/
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(TableIndex *tabIndex, int low, int high)
{
    int pivot = tabIndex->tabIndex[high].Matricule; // pivot
    int i = (low - 1);                              // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (tabIndex->tabIndex[j].Matricule < pivot)
        {
            i++; // increment index of smaller element
            swap(&(tabIndex->tabIndex[i].Matricule), &(tabIndex->tabIndex[j].Matricule));
            swap(&(tabIndex->tabIndex[i].NumbBloc), &(tabIndex->tabIndex[j].NumbBloc));
            swap(&(tabIndex->tabIndex[i].Depl), &(tabIndex->tabIndex[j].Depl));
        }
    }

    swap(&(tabIndex->tabIndex[i + 1].Matricule), &(tabIndex->tabIndex[high].Matricule));
    swap(&(tabIndex->tabIndex[i + 1].NumbBloc), &(tabIndex->tabIndex[high].NumbBloc));
    swap(&(tabIndex->tabIndex[i + 1].Depl), &(tabIndex->tabIndex[high].Depl));
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(TableIndex *tabIndex, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(tabIndex, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(tabIndex, low, pi - 1);
        quickSort(tabIndex, pi + 1, high);
    }
}

        /*********************************************************************************
                |Le module permettant de supprimer un enregistrement|
        *********************************************************************************/

void supprimEnregLnoF(char *nomFichier, int i, int j, int *cout)
{

    Fichier_LnOF *File = malloc(sizeof(Fichier_LnOF));
    Buffer_LnOF buf1;
    Buffer_LnOF buf2;

    File = Ouvrir(nomFichier, 'A');
    LireDir(File, i, &buf1);
    (*cout)++; coutTotal++;
    if (i == Entete(File, 3))
    { // l'enreg se trouve dans le dernier bloc
        if (j == buf1.nb - 1)
        { // l'enreg est le dernier enreg dans le bloc queue
            buf1.nb--;
            EcrireDir(File, i, buf1);                 // pour maj le nb du dernier bloc
            (*cout)++; coutTotal++;
            Aff_Entete(File, 2, Entete(File, 2) - 1); // Maj nbr enreg dans le fichier
            Aff_Entete(File, 3, Entete(File, 3) - 1); // maj du bloc queue. va devenir le bloc li 9bel l'ancien
        }
        else
        {
            buf1.tab[j] = buf1.tab[buf1.nb - 1];
            buf1.nb--;
            EcrireDir(File, i, buf1);
            (*cout++); coutTotal++;
            Aff_Entete(File, 2, Entete(File, 2) - 1); // Maj nbr enreg dans le fichier
        }
    }
    else
    {                                          // le bloc d'enreg a supprime n'est pas le dernier bloc
        LireDir(File, Entete(File, 3), &buf2); // lire bloc queue.  //segem Entete(F,3).
        (*cout)++; coutTotal++;
        if (buf2.nb == 1)
        { // le bloc queue contient un seul enreg
            buf1.tab[j] = buf2.tab[buf2.nb - 1];
            buf2.nb--;
            EcrireDir(File, i, buf1);                 // pour maj le nb du dernier bloc
            (*cout)++; coutTotal++;
            Aff_Entete(File, 2, Entete(File, 2) - 1); // Maj nbr enreg dans le fichier
            Aff_Entete(File, 3, Entete(File, 3) - 1); // maj du bloc queue. va devenir le bloc li 9bel l'ancien
        }
        else
        { // dernier bloc contient plsr enreg.
            buf1.tab[j] = buf2.tab[buf2.nb - 1];
            buf2.nb--;
            EcrireDir(File, i, buf1);                 // Ecrire les modifiactions sur le bloc d'enreg supprime.
            (*cout)++; coutTotal++;
            EcrireDir(File, Entete(File, 3), buf2);   // pour maj le nb du dernier bloc
            (*cout)++; coutTotal++;
            Aff_Entete(File, 2, Entete(File, 2) - 1); // Maj nbr enreg dans le fichier
        }
    }
    Fermer(File);
}

        /*********************************************************************************
                |Le module permettant de faire la recherche dichotomique|
        *********************************************************************************/
void RechDichotomique(TableIndex *tabIndex, int val, bool *trouv, int *pos)
{
    int sup, inf, mil;

    (*trouv) = Faux;
    inf = 0;
    sup = tabIndex->NbE - 1;

    while (!(*trouv) && inf <= sup)
    {
        mil = (inf + sup) / 2;
        if (tabIndex->tabIndex[mil].Matricule == val)
        {
            (*trouv) = Vrai;
        }
        else
        {
            if (val > tabIndex->tabIndex[mil].Matricule)
            {
                inf = mil + 1;
            }
            else
            {
                sup = mil - 1;
            }
        }
    }
    (*pos) = mil;
}

        /*********************************************************************************
                    |Le module permettant de remplir le fichier d'Index|
        *********************************************************************************/

void Sauv_Tab_Index(TableIndex *tabIndex, Fichier_TOF_Index *fich_index)
{

    Ouvrir_TOF_Index(fich_index, "Index_Matricule.bin", 'N');
    int i = 1, j = 0, k = 0;
    Tbloc_TOF_Index Buf;
    Buf.nb = 0;
    while (k < tabIndex->NbE)
    {
        if (j < Max_Tab_Index)
        {
            Buf.tab[j].Matricule = tabIndex->tabIndex[k].Matricule; // on ramene un enreg du tab et on le met dans buf
            Buf.tab[j].NumbBloc = tabIndex->tabIndex[k].NumbBloc;
            Buf.tab[j].Depl = tabIndex->tabIndex[k].Depl;
            j++;
            Buf.nb++;
        }
        else
        {
            EcrireDir_TOF_Index(fich_index, i, Buf);
            i++;
            Buf.tab[0].Matricule = tabIndex->tabIndex[k].Matricule;
            Buf.tab[0].NumbBloc = tabIndex->tabIndex[k].NumbBloc;
            Buf.tab[0].Depl = tabIndex->tabIndex[k].Depl;
            Buf.nb = 1;
            j = 1;
        }
        k++;
    }
    EcrireDir_TOF_Index(fich_index, i, Buf);
    Aff_Entete_TOF_Index(fich_index, 1, i);
    Aff_Entete_TOF_Index(fich_index, 2, tabIndex->NbE);
    Fermer_TOF_Index(fich_index);
}

        /*****************************************************************************************
                |Le module permettant de remplir la table d'Index à partir du fichier Index|
        *****************************************************************************************/
void RemplirIndexFichier(char *nomFichier, TableIndex *tabIndex){
    Fichier_TOF_Index F;
    Tbloc_TOF_Index buf;
    int i, j, k;
    bool stop;

    Ouvrir_TOF_Index(&F, nomFichier, 'A');
    i = 1;
    k = 0;
    stop = Faux;
    LireDir_TOF_Index(F, i, &buf);

    while (!stop){
        for (j = 0 ; j < buf.nb ; j++){
            tabIndex->tabIndex[k].Matricule = buf.tab[j].Matricule;
            tabIndex->tabIndex[k].NumbBloc = buf.tab[j].NumbBloc;
            tabIndex->tabIndex[k].Depl = buf.tab[j].Depl;
            k++;
        }
        i++;
        if (i <= Entete_Index(F, 1)) {
            LireDir_TOF_Index(F, i, &buf);
        }
        else {
            stop = Vrai;
        }
    }
    tabIndex->NbE = k;
    quickSort(tabIndex, 0, tabIndex->NbE - 1);
}


void Affich_fichier_index(char *NomFichierIndex)
{
    Fichier_TOF_Index F;
    Ouvrir_TOF_Index(&F, NomFichierIndex, 'A');
    Tbloc_TOF_Index Buf;
    int i = 1, j;
    printf(" nombre du blocs dans le fichier index : %d \n \n ", Entete_Index(F, 1));
    printf(" nombre d'enreg dans le fichier index :  %d\n \n \n ", Entete_Index(F, 2));
    printf("  Matricule    |Num de bloc|   Deplacement \n");

    while (i <= Entete_Index(F, 1))
    {
        LireDir_TOF_Index(F, i, &Buf);
        j = 0;

        while (j < Buf.nb)
        {
            printf("%15d|%11d|%15d\n", Buf.tab[j].Matricule, Buf.tab[j].NumbBloc, Buf.tab[j].Depl);
            printf("\n-----------------------------------------------------------------\n");
            j++;
        }

        i++;
    }
    Fermer_TOF_Index(&F);
}

void AfficherWilayas(){
    char Wilayas[] = "Adrar-Chlef-Laghouat-OumElBouaghi-Batna-Bejaia-biskra-Bechar-Blida-Bouira-Tamanrasset-Tebessa-Tlemcen-Tiaret-Tizi Ouzou-Alger-Djelfa-Jijel-Setif-Saida-Skikda-Sidi Bel Abbes-Annaba-Guelma-Constantine-Medea-Monstganem-Msila-Mascara-Ouargla-Oran-Bayadh-Illizi-Bordj Bou Arreridj-Boumerdes-Tarf-Tindouf-Tissemsilt-El Oued-Khenchela-Souk Ahras-Tipaza-Mila-Ain Defla-Naama-Ain Temouchent-Ghardaia-Relizane-Timimoun-Bordj Badji Mokhtar-Ouled Djellal-Beni Abbes-In Salah-In Guezzam-Touggourt-Djanet-El Mghair-El Meniaa" ;
    char s[2] = "-", *token;
    int i = 1;

    printf("\n\t\t\t+-------------------------------------+");
    printf("\n\t\t\t|        Affichage des wilayas        |");
    printf("\n\t\t\t+-------------------------------------+");
    token = strtok(Wilayas, s);
    printf("\n\t\t\t| %-2d.%-30s   |", i, token);
    for(i = 2 ; i <= 58 ; i++) {
        token = strtok(NULL, s);
        printf("\n\t\t\t| %-2d.%-30s   |", i, token);
    }
    printf("\n\t\t\t+-------------------------------------+");
}
void AfficherGroupes(){
    char Groupes[] = "O+/A+/B+/O-/A-/AB+/B-/AB-";
    char s[2] = "/";
    char *token;
    int i = 1;

    printf("\n\t\t\t+------------------------------------+");
    printf("\n\t\t\t|   Affichage des groupes sanguins   |");
    printf("\n\t\t\t+------------------------------------+");
    token = strtok(Groupes, s);
    printf("\n\t\t\t|  %2d.%-4s                           |", i, token);
    for(i = 2 ; i <= 8 ; i++) {
        token = strtok(NULL, s);
        printf("\n\t\t\t|  %2d.%-4s                           |", i, token);
    }
    printf("\n\t\t\t+------------------------------------+");

}

            /*********************************************************************************
                        |Le module permettant d'afficher les forces|
            **********************************************************************************/
void AfficherForces(){
    char Forces[] = "Armee de terre/Armee de l'air/Marine nationale/Defense aerienne du territoire/Gendarmerie nationale/Garde republicaine/Departement du renseignement et de la securite/Sante militaire";
    char s[2] = "/";
    char *token;
    int i = 1;

    printf("\n\t\t\t+---------------------------------------------------------------+");
    printf("\n\t\t\t|                     Affichage des forces                      |");
    printf("\n\t\t\t+---------------------------------------------------------------+");
    token = strtok(Forces, s);
    printf("\n\t\t\t|  %-2d.%-55s   |", i, token);
    for(i = 2 ; i <= 8 ; i++) {
        token = strtok(NULL, s);
        printf("\n\t\t\t|  %-2d.%-55s   |", i, token);
    }
    printf("\n\t\t\t+---------------------------------------------------------------+");

}

            /*********************************************************************************
                        |Le module permettant d'afficher les grades|
            **********************************************************************************/
void AfficherGrades(){
    char Grades[] ="General de corps d'armee-General Major-General-Colonel-Lieutenant colonel-Commandant-Capitaine-Lieutenant-Sous lieutenant-Aspirant-Adjudant chef-Adjudant-Sergent chef-Sergent-Caporal chef-Caporal-Djoundi";
    char s[2] = "-";
    char *token;
    int i = 1;

    printf("\n\t\t\t+--------------------------------------------------+");
    printf("\n\t\t\t|              Affichage des grades                |");
    printf("\n\t\t\t+--------------------------------------------------+");
    token = strtok(Grades, s);
    printf("\n\t\t\t|  %-2d.%-45s|", i, token);
    for(i = 2 ; i <= 17 ; i++) {
        token = strtok(NULL, s);
        printf("\n\t\t\t|  %-2d.%-45s|", i, token);
    }
    printf("\n\t\t\t+--------------------------------------------------+");
}

            /*********************************************************************************
                        |Le module permettant d'afficher les régions|
            **********************************************************************************/
void AfficherRegions(){
    char Regions[] = "RM-Blida/RM-Oran/RM-Bechar/RM-Ouargla/RM-Constantine/RM-Tamanrasset";
    char s[2] = "/";
    char *token;
    int i = 1;

    printf("\n\t\t\t+---------------------------------------------------------+");
    printf("\n\t\t\t|           Affichage des regions melitaires              |");
    printf("\n\t\t\t+---------------------------------------------------------+");
    token = strtok(Regions, s);
    printf("\n\t\t\t|  %-2d.%-50s  |", i, token);
    for(i = 2 ; i <= 6 ; i++) {
        token = strtok(NULL, s);
        printf("\n\t\t\t|  %-2d.%-50s  |", i, token);
    }
    printf("\n\t\t\t+---------------------------------------------------------+");
}


            /*********************************************************************************
                |Le module permettant d'insérer un enregistrement dans le fichier|
            *********************************************************************************/
int InsererEnreg(char *nomFichier, TableIndex *tabIndex){
    Fichier_LnOF *F;
    Buffer_LnOF *buf = calloc(1, sizeof(Buffer_LnOF)), enreg;
    int matricule, pos, i, j, k, a, cout;
    char *date = calloc(11, sizeof(char));
    bool trouv, stop;

    F = Ouvrir(nomFichier, 'A');
    stop = Faux;
    trouv = Faux;
    cout = 0;

    i = Entete(F, 3);
    LireDir(F, i, buf);
    cout++; coutTotal++;
    j = buf->nb;
    k = tabIndex->NbE;

    if (j < Max) {
        buf->nb++;
        j = buf->nb-1;
    }
    else{
        buf->suiv = i + 1;
        Aff_Entete(F, 3, Entete(F, 3) + 1);
        EcrireDir(F, i, *buf);
        cout++; coutTotal++;
        buf->nb = 1;
        buf->suiv = -1;
        j = 0;
        i++;
    }

    ClearScrean();
    printf("\n\t\t\t+-----------------------------------------------------------+");
    printf("\n\t\t\t|           Insertion d'un nouvel enregistrement            |");
    printf("\n\t\t\t+-----------------------------------------------------------+\n\t>> ");
    system("PAUSE");
    printf("\n\t>> Veuillez inserer un matricule entre 111111 et 999999: ");
    scanf("%d", &(buf->tab[j].matricule));
    RechDichotomique(tabIndex, buf->tab[j].matricule, &trouv, &pos);
    if (trouv) {
            printf("\n >> Inserttion impossible, le matricule exite deja");
            stop = Vrai;
    }
    if (stop) return 0;
    printf("\t>> Veuillez inserer le nom : ");
    scanf("%s", buf->tab[j].nom);

    printf("\t>> Veuillez inserer le prenom : ");
    scanf("%s",buf->tab[j].prenom);

    printf("\t>> Veuillez inserer la date de naissance entre 1945 et 2003 : ");
    scanf("%s", (buf->tab[j].dateDeNaissance));

    printf("\n\t>> Ci dessous  les wilayas, veuillez choisir le numero de la wilaya correspendante: ");
    AfficherWilayas();
    printf("\n\t>> Le numero de wilaya choisie : ");
    scanf("%d", &(buf->tab[j].wilayaDeNaissance));

    printf("\n\t>> Ci dessous  les groupes sanguins, veuillez choisir le numero du groupe correspendant: ");
    AfficherGroupes();
    printf("\n\t>> Le numero du groupe choisi : ");
    scanf("%d", &(buf->tab[j].groupeSanguin));

    printf("\n\t>> Ci dessous  les grades, veuillez choisir le numero du grade correspendant: ");
    AfficherGrades();
    printf("\n\t>> Le numero du grade choisi : ");
    scanf("%d", &(buf->tab[j].grade));

    printf("\n\t>> Ci dessous  les forces, veuillez choisir le numero de la force correspendante: ");
    AfficherForces();
    printf("\n\t>> Le numero de la force choisie : ");
    scanf("%d", &(buf->tab[j].forceArmee));

    printf("\n\t>> Ci dessous  les regions melitaires, veuillez choisir le numero de la region correspendante: ");
    AfficherRegions();
    printf("\n\t>> Le numero de la region choisie : ");
    scanf("%d", &(buf->tab[j].regionMelitaire));

    EcrireDir(F, i, *buf);
    cout++; coutTotal++;
    Aff_Entete(F, 2, Entete(F, 2) + 1);
    RemplirIndex(tabIndex, k, buf->tab[j].matricule, i, j);
    quickSort(tabIndex, 0, tabIndex->NbE);
    tabIndex->NbE++;
    Fermer(F);
    printf("\n\t>> Si vous voulez afficher le dernier bloc apres l insertion inserez 1, sinon 0 : ");
    scanf("%d", &a);
    if (a == 1) AffichageBloc(nomFichier, i);

    printf("\n\n\t\t+---------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque       |", cout);
    printf("\n\t\t+---------------------------------------------------------+");
}

            /*********************************************************************************
                |Le module permettant de modifier la région mélitaire d'un soldat|
            *********************************************************************************/
void ModifierRegion (char *nomFichier, TableIndex *tabIndex){
    Fichier_LnOF *F;
    Buffer_LnOF *buf = calloc(1, sizeof(Buffer_LnOF));
    int matr, pos, i, j, region, a, cout;
    bool trouv = Faux;

    F = Ouvrir(nomFichier, 'A');
    cout = 0;
    ClearScrean();
    printf("\n\t\t\t+-------------------------------------------------------+");
    printf("\n\t\t\t|         Modification de la region Melitaire           |");
    printf("\n\t\t\t+-------------------------------------------------------+\n\t>> ");
    system("PAUSE");
    printf("\n\t>> Inserer le matricule que vous voulez changer sa region melitaire: ");
    scanf("%d", &matr);
    RechDichotomique(tabIndex, matr, &trouv, &pos);
    if (!trouv) {
        printf("\n\t>> Matricule non trouvee");
    }
    else{
        i = tabIndex->tabIndex[pos].NumbBloc;
        j = tabIndex->tabIndex[pos].Depl;
        LireDir(F, i, buf);
        cout++; coutTotal++;
        printf("\n\t>> Le soldat existe dans le bloc   %d   a la place   %d", i, j+1);
        printf("\n\t>>La region melitaire actuelle ");
        printf("\n\t+------------------------+----------------------------------------------------+");
        RegionMelitaire(buf->tab[j].regionMelitaire);
        printf("\n\t+------------------------+----------------------------------------------------+");
        printf("\n\t>> Veuillez choisir parmi les regions ci-dessous la nouvelle region: ");
        AfficherRegions();
        printf("\n\t>> La region choisie est: ");
        scanf("%d", &region);
        printf("\n\t>> La nouvelle region ");
        printf("\n\t+------------------------+----------------------------------------------------+");
        RegionMelitaire(region);
        printf("\n\t+------------------------+----------------------------------------------------+");
        buf->tab[j].regionMelitaire = region;
        EcrireDir(F, i, *buf);
        cout++; coutTotal++;
    }
    Fermer(F);
    printf("\n\t>> Si vous voulez afficher le bloc du soldat apres la modification inserez 1, sinon 0 : ");
    scanf("%d",&a);
    if (a == 1){
        F = Ouvrir(nomFichier, 'A');
        if (a == 1) AffichageBloc(nomFichier, i);
    }
    printf("\n\n\t\t+-----------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque         |", cout);
    printf("\n\t\t+-----------------------------------------------------------+");
}

            /*********************************************************************************************************
                |Le module permettant d'afficher les enregistrements appartenant à une seule catégorie de grades|
            *********************************************************************************************************/
void AfficherSelonGrades(char *nomFichier){
    ClearScrean();
    Fichier_LnOF *F;
    Buffer_LnOF *buf = calloc(1,sizeof(Buffer_LnOF));
    int grade, i, j, k, cout;

    F = Ouvrir(nomFichier, 'A');
    i = 1;
    k = 1;
    cout = 0;

    printf("\n\t\t\t+-------------------------------------------------------+");
    printf("\n\t\t\t|      Afficher les soldats ayant le meme grade         |");
    printf("\n\t\t\t+-------------------------------------------------------+\n\t>> ");
    system("PAUSE");
    printf("\n\t>> Ci-dessous les grades du corps, veuillez choisir le numero correspendant au grade que vous voulez");
    AfficherGrades();
    printf("\n\t>> Le numero du grade choisi: ");
    scanf("%d", &grade);

    while (i != -1){
        LireDir(F, i, buf);
        cout++; coutTotal++;
        for(j = 0 ; j < buf->nb ; j++){
            if (buf->tab[j].grade == grade){
                printf("\n\n\t\t\t\t+------------------------+");
                printf("\n\t\t\t\t|    Soldat numero %-6d|", k);
                printf("\n\t\t\t\t+------------------------+");
                printf("\n\t+------------------------+----------------------------------------------------+");
                printf("\n\t|  Matricule             |  %-50d|", buf->tab[j].matricule);
                printf("\n\t|  Nom                   |  %-50s|", buf->tab[j].nom);
                printf("\n\t|  Prenom                |  %-50s|", buf->tab[j].prenom);
                printf("\n\t|  Date de Naissance     |  %-50s|", buf->tab[j].dateDeNaissance);
                Wilaya(buf->tab[j].wilayaDeNaissance);
                GroupeSanguin(buf->tab[j].groupeSanguin);
                ForceArmee(buf->tab[j].forceArmee);
                RegionMelitaire(buf->tab[j].regionMelitaire);
                printf("\n\t+------------------------+----------------------------------------------------+");
                k++;
            }
        }
        i = buf->suiv;
    }
    Fermer(F);
    printf("\n\n\t\t+---------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque       |", cout);
    printf("\n\t\t+---------------------------------------------------------+");
}


        /*************************************************************************************************************
            |Le module permettant d'afficher les soldats d'une région ayant un âge compris dans un intervalle donné|
        *************************************************************************************************************/
void AfficherSelonRegionAge(char *nomFichier){
    ClearScrean();
    Fichier_LnOF *F;
    Buffer_LnOF *buf = calloc(1,sizeof(Buffer_LnOF));
    int region, i, j, k, l, inf, sup, taille, annee, cout ;
    char anneStr[5], date[11];

    F = Ouvrir(nomFichier, 'A');
    i = 1;
    k = 1;
    cout = 0;
    printf("\n\t+---------------------------------------------------------------------------------------------+");
    printf("\n\t|      Afficher les soldats d une meme region ayant un age compris dans un intervalle         |");
    printf("\n\t+---------------------------------------------------------------------------------------------+\n\t>>");
    system("PAUSE");
    printf("\n\t>> Ci-dessous les regions melitaires, veuillez choisir le numero correspendant a la region que vous voulez");
    AfficherRegions();
    printf("\n\t>> Le numero du grade choisi: ");
    scanf("%d", &region);
    printf("\n\t>> Les ages des soldats sont compris entre 18 ans et 77 ans, veuillez inserer un intervalle inclus dans celui ci");
    printf("\n\t\t Borne Inferieure  = ");
    scanf("%d", &inf);
    printf("\t\t Borne Superieure = ");
    scanf("%d", &sup);

    inf = 2021 - inf;
    sup = 2021 - sup;

    while (i != -1){
        LireDir(F, i, buf);
        cout++; coutTotal++;
        for(j = 0 ; j < buf->nb ; j++){
            if (buf->tab[j].regionMelitaire == region){
                taille = strlen(buf->tab[j].dateDeNaissance) - 4;
                strcpy(date, buf->tab[j].dateDeNaissance);
                for (l = 0 ; l < 4 ; l++){
                    anneStr[l] = date[taille];
                    taille++;
                }
                anneStr[4] = '\0';
                annee = atoi(anneStr);
                if ((annee < inf) && (annee > sup)){
                    printf("\n\n\t\t\t\t+------------------------+");
                    printf("\n\t\t\t\t|    Soldat numero %-6d|", k);
                    printf("\n\t\t\t\t+------------------------+");
                    printf("\n\t+------------------------+----------------------------------------------------+");
                    printf("\n\t|  Matricule             |  %-50d|", buf->tab[j].matricule);
                    printf("\n\t|  Nom                   |  %-50s|", buf->tab[j].nom);
                    printf("\n\t|  Prenom                |  %-50s|", buf->tab[j].prenom);
                    printf("\n\t|  Date de Naissance     |  %-50s|", buf->tab[j].dateDeNaissance);
                    Wilaya(buf->tab[j].wilayaDeNaissance);
                    GroupeSanguin(buf->tab[j].groupeSanguin);
                    ForceArmee(buf->tab[j].forceArmee);
                    RegionMelitaire(buf->tab[j].regionMelitaire);
                    printf("\n\t+------------------------+----------------------------------------------------+");
                    k++;
                }
            }
        }
        i = buf->suiv;
    }
    Fermer(F);
    printf("\n\n\t\t+------------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque          |", cout);
    printf("\n\t\t+------------------------------------------------------------+");
}

        /************************************************************************************
            |Le module permettant de supprimer un enregistrement donné par son matricule|
        *************************************************************************************/
void SupprimSelonMatricule(TableIndex *tabIndex, char *nomFichier)
{
    ClearScrean();
    Fichier_LnOF *F;
    bool trouv;
    int pos, matricule, a, cout;
    Buffer_LnOF buf;
    F = Ouvrir(nomFichier, 'A');

    printf("\n\t+---------------------------------------------------------------------------------------------+");
    printf("\n\t|                  Suppression d un enregistrement donne par son matricule                    |");
    printf("\n\t+---------------------------------------------------------------------------------------------+\n\t>> ");
    system("PAUSE");
    printf("\n>> Veuillez introduire le matricule du soldat que vous voudrez le supprimer : ");
    scanf("%d", &matricule);
    trouv = Faux;
    cout = 0;
    RechDichotomique(tabIndex, matricule, &trouv, &pos);

    while (!trouv)
    {
        printf("\n\t>> Ce soldat ne figure pas dans notre caserne, \n Veuillez introduire le matricule du soldat que vous voudrez le supprimer : ");
        scanf("%d", &matricule);
        RechDichotomique(tabIndex, matricule, &trouv, &pos);
    }
    printf("\n+-----------------------+--------------------------------+----------------+----------------------------------+");
    printf("\n| Le matricule : %6d | La position dans l index : %3d | Son bloc : %3d | Sa position dans le bloc : %3d   |", tabIndex->tabIndex[pos].Matricule, pos, tabIndex->tabIndex[pos].NumbBloc, tabIndex->tabIndex[pos].Depl);
    printf("\n+-----------------------+--------------------------------+----------------+----------------------------------+");
    printf("\n\t>> Si vous voulez afficher le dernier bloc avant la supression inserez 1, sinon 0 : ");
    scanf("%d", &a);
    if (a == 1) AffichageBloc(nomFichier, Entete(F, 3));
    supprimEnregLnoF(nomFichier, tabIndex->tabIndex[pos].NumbBloc, tabIndex->tabIndex[pos].Depl, &cout);
    if (pos == tabIndex->NbE - 1)
    {
        tabIndex->NbE--;
    }
    else
    {
        // decalage
        int mx = tabIndex->NbE - 1;
        for (int j = pos; j < mx; j++)
        {
            tabIndex->tabIndex[j] = tabIndex->tabIndex[j + 1];
        }
        tabIndex->NbE--;
    }
    printf("\n\t>> Suppression terminee");
    printf("\n\n\t\t+------------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque          |", cout);
    printf("\n\t\t+------------------------------------------------------------+");
    printf("\n\t>> Si vous voulez afficher le dernier bloc apres la supression inserez 1, sinon 0 : ");
    scanf("%d", &a);
    if (a == 1) AffichageBloc(nomFichier, Entete(F, 3));


}

        /************************************************************************************
            |Le module permettant de supprimer des enregistrements donné par leur force|
        *************************************************************************************/
void SupprimSelonForces(char *nomFichier, TableIndex *tabIndex)
{
    ClearScrean();
    Fichier_LnOF *F;
    Buffer_LnOF *buf = calloc(1, sizeof(Buffer_LnOF));
    int forceArmee, i, j, cpt = 0, a, c, pos, b = 0, cout;
    bool trouv;
    printf("\n\t+---------------------------------------------------------------------------------------------+");
    printf("\n\t|               Suppression des enregistrements relatifs a une force armee                    |");
    printf("\n\t+---------------------------------------------------------------------------------------------+\n\t>> ");
    system("PAUSE");
    printf("\n>> Ci-dessous nos forces armees , veuillez choisir le numero correspendant a la force que vous voullez la supprimer :");
    AfficherForces();
    printf("\n\t>> Le numero du grade choisi: ");
    scanf("%d", &forceArmee);
    F = Ouvrir(nomFichier, 'A');
    cout = 0;
    loop:i = 1;
    trouv = Faux;
    while (i != -1)
    {
        LireDir(F, i, buf);
         for (j = 0; j < buf->nb; j++)
        {
            if (buf->tab[j].forceArmee == forceArmee)
            {
                if (b == 0) supprimEnregLnoF(nomFichier, i, j, &cout);
                if (b != 0) supprimEnregLnoF(nomFichier, i, j, &c);
                cpt++;
                RechDichotomique(tabIndex, buf->tab[j].matricule, &trouv, &pos);
                if (pos == tabIndex->NbE - 1)
                {
                    tabIndex->NbE--;
                }
                else
                {
                    // decalage
                    int mx = tabIndex->NbE - 1;
                    for (int k = pos; k < mx; k++)
                    {
                        tabIndex->tabIndex[k] = tabIndex->tabIndex[k + 1];
                    }
                    tabIndex->NbE--;
                }
            }
        }
        i = buf->suiv;
    }
    b++;
    if (b < 2)goto loop;
    printf("\n\t>> Suppression terminee");
    printf("\n\n\t\t+-------------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque          |", cout);
    printf("\n\t\t+-------------------------------------------------------------+");
    //printf("\n\t>> Le nombre des soldats supprimees est : %d", cpt);
    Fermer(F);
    coutTotal = coutTotal - c;
    printf("\n\t>> Si vous voulez afficher le premier bloc inserez 1, sinon 0 : ");
    scanf("%d", &a);
    ClearScrean();
    if(a == 1) AffichageBloc(nomFichier, 1);
}

            /****************************************************************************
                    |Le module permettant de fragementer le fichier binaire|
            *****************************************************************************/
void Fragmentation(char *nomFichier)
{
    ClearScrean();
    Fichier_LnOF *F;
    Fichier_LnOF *F1 = Ouvrir("F1.bin", 'N');
    Fichier_LnOF *F2 = Ouvrir("F2.bin", 'N');
    Fichier_LnOF *F3 = Ouvrir("F3.bin", 'N');
    Fichier_LnOF *F4 = Ouvrir("F4.bin", 'N');
    Fichier_LnOF *F5 = Ouvrir("F5.bin", 'N');
    Fichier_LnOF *F6 = Ouvrir("F6.bin", 'N');
    F = Ouvrir(nomFichier, 'A');
    Buffer_LnOF *Buf = malloc(sizeof(Buffer_LnOF));
    Buffer_LnOF *Buf1 = malloc(sizeof(Buffer_LnOF));
    Buffer_LnOF *Buf2 = malloc(sizeof(Buffer_LnOF));
    Buffer_LnOF *Buf3 = malloc(sizeof(Buffer_LnOF));
    Buffer_LnOF *Buf4 = malloc(sizeof(Buffer_LnOF));
    Buffer_LnOF *Buf5 = malloc(sizeof(Buffer_LnOF));
    Buffer_LnOF *Buf6 = malloc(sizeof(Buffer_LnOF));
    Tenreg_LnOF Enrg;
    int i = 1, X;
    int i1 = 1, i2 = 1, i3 = 1, i4 = 1, i5 = 1, i6 = 1;
    int j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, j6 = 0;
    int cpt1 = 0, cpt2 = 0, cpt3 = 0, cpt4 = 0, cpt5 = 0, cpt6 = 0;
    int a, numFich, cout;

    cout = 0;
    if ((F1 != NULL) && (F2 != NULL) && (F3 != NULL) && (F4 != NULL) && (F5 != NULL) && (F6 != NULL))
    {
        while (i != -1)
        {
            LireDir(F, i, Buf);
            cout++; coutTotal++;
            for (int j = 0; j < Buf->nb; j++)
            {
                X = Buf->tab[j].regionMelitaire;
                Enrg = Buf->tab[j];
                switch (X)
                {
                case 1:
                    Buf1->tab[j1] = Enrg;
                    cpt1++;

                    j1++;
                    if (j1 > Max)
                    {
                        Buf1->nb = Max;
                        Buf1->suiv = i1 + 1;
                        EcrireDir(F1, i1, *Buf1);
                        cout++; coutTotal++;
                        i1++;
                        j1 = 1;
                    }
                    break;
                case 2:
                    Buf2->tab[j2] = Enrg;
                    cpt2++;
                    j2++;
                    if (j2 > Max)
                    {
                        Buf2->nb = Max;
                        Buf2->suiv = i2 + 1;
                        EcrireDir(F2, i2, *Buf2);
                        cout++; coutTotal++;
                        i2++;
                        j2 = 1;
                    }
                    break;
                case 3:
                    Buf3->tab[j3] = Enrg;
                    cpt3++;

                    j3++;
                    if (j3 > Max)
                    {
                        Buf3->nb = Max;
                        Buf3->suiv = i3 + 1;
                        EcrireDir(F3, i3, *Buf3);
                        cout++; coutTotal++;
                        i3++;
                        j3 = 1;
                    }
                    break;
                case 4:
                    Buf4->tab[j4] = Enrg;
                    cpt4++;

                    j4++;
                    if (j4 > Max)
                    {
                        Buf4->nb = Max;
                        Buf4->suiv = i4 + 1;
                        EcrireDir(F4, i4, *Buf4);
                        cout++; coutTotal++;
                        i4++;
                        j4 = 1;
                    }
                    break;
                case 5:
                    Buf5->tab[j5] = Enrg;
                    cpt5++;

                    j5++;
                    if (j5 > Max)
                    {
                        Buf5->nb = Max;
                        Buf5->suiv = i5 + 1;
                        EcrireDir(F5, i5, *Buf5);
                        cout++; coutTotal++;
                        i5++;
                        j5 = 1;
                    }
                    break;
                case 6:
                    Buf6->tab[j6] = Enrg;
                    cpt6++;

                    j6++;
                    if (j6 > Max)
                    {
                        Buf6->nb = Max;
                        Buf6->suiv = i6 + 1;
                        EcrireDir(F6, i6, *Buf6);
                        cout++; coutTotal++;
                        i6++;
                        j6 = 1;
                    }
                    break;

                default:
                    break;
                }
            }

            i = Buf->suiv;
        } // fin while.
        // printf("Hello from outside...");
        Buf1->nb = j1;
        Buf1->suiv = -1;
        EcrireDir(F1, i1, *Buf1);
        cout++; coutTotal++;
        Buf2->nb = j2;
        Buf2->suiv = -1;
        EcrireDir(F2, i2, *Buf2);
        cout++; coutTotal++;
        Buf3->nb = j3;
        Buf3->suiv = -1;
        EcrireDir(F3, i3, *Buf3);
        cout++; coutTotal++;
        Buf4->nb = j4;
        Buf4->suiv = -1;
        EcrireDir(F4, i4, *Buf4);
        cout++; coutTotal++;
        Buf5->nb = j5;
        Buf5->suiv = -1;
        EcrireDir(F5, i5, *Buf5);
        cout++; coutTotal++;
        Buf6->nb = j6;
        Buf6->suiv = -1;
        EcrireDir(F6, i6, *Buf6);
        cout++; coutTotal++;
        Aff_Entete(F1, 1, 1);
        Aff_Entete(F1, 2, cpt1);
        Aff_Entete(F1, 3, i1);
        Aff_Entete(F2, 1, 1);
        Aff_Entete(F2, 2, cpt2);
        Aff_Entete(F2, 3, i2);
        Aff_Entete(F3, 1, 1);
        Aff_Entete(F3, 2, cpt3);
        Aff_Entete(F3, 3, i3);
        Aff_Entete(F4, 1, 1);
        Aff_Entete(F4, 2, cpt4);
        Aff_Entete(F4, 3, i4);
        Aff_Entete(F5, 1, 1);
        Aff_Entete(F5, 2, cpt5);
        Aff_Entete(F5, 3, i5);
        Aff_Entete(F6, 1, 1);
        Aff_Entete(F6, 2, cpt6);
        Aff_Entete(F6, 3, i6);

        Fermer(F1);
        Fermer(F2);
        Fermer(F3);
        Fermer(F4);
        Fermer(F5);
        Fermer(F6);
    }
    Fermer(F);
    printf("\n\t>> Fragmentation terminee");
    printf("\n\n\t\t+---------------------------------------------------------+");
    printf("\n\t\t| Le cout de cette opeartion est : %2d accees disque       |", cout);
    printf("\n\t\t+---------------------------------------------------------+");
    printf("\n\t>> Si vous voulez affficher le premier bloc d un fichier parmi les six inszerez 1, sinon 0 : ");
    scanf("%d", &a);
    printf("\n\t>> Ci-dessous la liste des regions, veuillez choisir un numero correspendant a une region que vous voulez : ");
    AfficherRegions();
    printf("\n\t>> La region choisie : ");
    scanf("%d", &numFich);
    if (a == 1) {
        switch(numFich){
            case 1: F = Ouvrir("F1.bin", 'A'); AfficherEntete("F1.bin"); AffichageBloc("F1.bin", 1);break;
            case 2: F = Ouvrir("F2.bin", 'A'); AfficherEntete("F2.bin"); AffichageBloc("F2.bin", 1);break;
            case 3: F = Ouvrir("F3.bin", 'A'); AfficherEntete("F3.bin"); AffichageBloc("F3.bin", 1);break;
            case 4: F = Ouvrir("F4.bin", 'A'); AfficherEntete("F4.bin"); AffichageBloc("F4.bin", 1);break;
            case 5: F = Ouvrir("F5.bin", 'A'); AfficherEntete("F5.bin"); AffichageBloc("F5.bin", 1);break;
            case 6: F = Ouvrir("F6.bin", 'A'); AfficherEntete("F6.bin"); AffichageBloc("F6.bin", 1);break;
            default: printf("\n\t>> Fichier non existant");
        }
    }
}

        /********************************************************************************
                                    |Initiation|
        *********************************************************************************/
void Initiation (){
    char str1[] = " | # Bienvenue dans le programme 'Armee Nationale Algerienne'. Ce programme est concu afin d'enregistrer    |\n | les informations des soldats algeriens dans un fichier binaire, et les manipuler tout en ajoutant,       |\n | supprimant,   modifiant ... de multiples inforamtions concernant un soldat ou plusieurs soldat           | \n"   ;
    char str2[] = " | # Il contient aussi les differents affichages des noms, prenoms, dates et wilayas de naissances,         |\n | groupes sanguins, grades, regions melitaires, forces armees, tout en affichant les trois premiers bloc   |  ";

  printf("\n\n\n\n\n\n");
  printf("                        **************************************************************\n");
  Sleep(100);
  printf("                        *****************                            *****************\n");
  Sleep(100);
  printf("                        ************                                      ************\n");
  Sleep(100);
  printf("                        ******                                                  ******\n");
  Sleep(100);
  printf("                        ***    Ecole nationale Superieure dInformatique - Alger    ***\n");
  Sleep(100);
  printf("                        ***                   TP Du module SFSD                    ***\n");
  Sleep(100);
  printf("                        ***                        2021-2022                       ***\n");
  Sleep(100);
  printf("                        ***     Realise par : Adjou Amine et Seddiki Abdessamed    ***\n");
  Sleep(100);
  printf("                        ***    Enseignant: Dr. KERMI Adel Maitre de Conference A   ***\n");
  Sleep(100);
  printf("                        ******                                                  ******\n");
  Sleep(100);
  printf("                        ************                                      ************\n");
  Sleep(100);
  printf("                        *****************                            *****************\n");
  Sleep(100);
  printf("                        **************************************************************\n");
  printf("\n");
  printf("\n");

  printf("     \t\t Salutations ! \n");
  printf(" +----------------------------------------------------------------------------------------------------------+\n");
  int longueur = strlen(str1);
  int i = 0;
  while (i != longueur) {
    printf ("%c", str1[i]);
    Sleep(30);
    i++;
  }
  longueur = strlen(str2);
  i = 0;
  while (i != longueur) {
    printf ("%c", str2[i]);
    Sleep(30);
    i++;
  }

  printf("\n +----------------------------------------------------------------------------------------------------------+\n");

  Sleep(2000);

  printf("\n\n \t\tReaslise par : \n\t\t\t - Seddiki Abdessamed \n \t\t\t - Adjou Amine \n \t\t Enseignant: Dr. KERMI Adel Maitre de Conference Classe A \n\n\n");
  system("PAUSE");
  printf("\n");
}



void Cloture ()
{
    printf("\n\n\n                  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n");
    printf("\t\t *                                                                       @@      *         \n");
    printf("\t\t *     @@@@@@@@@@  @@@@@@        @@@@@@      @@@@@@@@@@    @@@@@@      @@@@      *         \n");
    printf("\t\t *       @@    @@@@      @@    @@@@    @@      @@    @@  @@      @@    @@@@      *         \n");
    printf("\t\t *       @@      @@      @@    @@      @@@@    @@        @@              @@      *          \n");
    printf("\t\t *       @@      @@      @@    @@@@@@@@@@@@    @@        @@              @@      *          \n");
    printf("\t\t *       @@      @@      @@    @@              @@        @@              @@      *           \n");
    printf("\t\t *       @@      @@      @@    @@@@      @@    @@        @@      @@      @@@@    *            \n");
    printf("\t\t *     @@@@@@  @@@@@@  @@@@@@    @@@@@@@@    @@@@@@        @@@@@@        @@@@    *           \n");
    printf("                 *                                                                               *  \n");
    printf("                  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n");
    printf("\n\n\n");
    printf("\t\t\t\t\t >> Seddiki Abdessamed \n\t\t\t\t\t >> Adjou Amine \n\t\t\t\t\t >> Ens KERMI Adel");
    printf("\n\n\t\t\t\t\t +-----------------------+");
    printf("\n\t\t\t\t\t |   fin du programme    |");
    printf("\n\t\t\t\t\t +-----------------------+\n\n\n\n");

}

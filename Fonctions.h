#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include "Machine Abstraite.c"
#include "ListeLineaireChainee.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *Nom (int i);
char *Prenom (int i);
char *DateDeNaissance();
int Wilaya(int i);
int GroupeSanguin(int i);
int ForceArmee(int i);
int RegionMelitaire (int i);
void RemplirEnrg(Tenreg_LnOF *enrg);
void RemplirBloc(Buffer_LnOF *buf, Tenreg_LnOF *enreg, int j);
void RemplirIndex(TableIndex *tabIndex, int k, int ID, int numBloc, int position);
void quickSort(TableIndex *tabIndex, int low, int high);
int partition(TableIndex *tabIndex, int low, int high);
void CreerFichier(char *nomFichier, int nbSoldats, TableIndex* tabIndex );
void RechDichotomique(TableIndex *tabIndex, int val, bool *trouv, int *pos);
void supprimEnregLnoF(char *nomFichier, int i, int j, int (*cout));
void RemplirIndexFichier(char *nomFichier, TableIndex *tabIndex);
void Sauv_Tab_Index(TableIndex *tabIndex, Fichier_TOF_Index *fich_index);
void RemplirIndexFichier(char *nomFichier, TableIndex *tabIndex);
void AfficherWilayas();
void AfficherGroupes();
void AfficherForces();
void AfficherGrades();
void AfficherRegions();
int InsererEnreg(char *nomFichier, TableIndex *tabIndex);
void ModifierRegion (char *nomFichier, TableIndex *tabIndex);
void AfficherSelonGrades(char *nomFichier);
void AfficherSelonRegionAge(char *nomFichier);
void SupprimSelonMatricule(TableIndex *tabIndex, char *nomFichier);
void SupprimSelonMatricule(TableIndex *tabIndex, char *nomFichier);
void Fragmentation(char *nomFichier);

#endif // FONCTIONS_H_INCLUDED

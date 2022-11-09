#ifndef EELECTION_H_INCLUDED
#define EELECTION_H_INCLUDED
#include <stdio.h>
typedef struct
{
int jour,mois,annee;
}date;
typedef struct
{
date d_e;
int id_e;
char muni_e[20];
char nbhab_e[20];
int nbcons_e;
int actif;
}election;

int ajouter(char *filename, election e);
int modifier( char *filename, int id_e, election nouv_e );
int supprimer(char *filename, int id_e );
election chercher(char * filename, int id_e);

#endif

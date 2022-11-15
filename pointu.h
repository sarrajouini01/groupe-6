#ifndef Utilisateur_H_INCLUDED
#define Utilisateur_H_INCLUDED

typedef struct
{
     int jours,mois,annee;
} date;
typedef struct
{ 
     int loginu; 
     char MPu[20];
     char  cinu[10];
     char nomu[20]; 
     char prenomu[20];
     char genderu[20];
     date DN;
     int numbv; 
     int voteu;
     char roleu[20];
} Utilisateur;

Utilisateur u,u1;

int ajouter(Utilisateur u, char filename []);
int modifier(int loginu, Utilisateur nouv, char * filename);
int supprimer(int loginu, char * filename);
Utilisateur chercher(int loginu, char * filename);

#endif // Utilisateur_H_INCLUDED

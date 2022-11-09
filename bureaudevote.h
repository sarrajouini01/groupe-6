#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
typedef struct{
    int numbv;
    char identifiantbv[50];
    char idobservateurbv[50];
    char adressebv[100];
    int nbobservateurbv;
    int capacitebv;
    int disponibilitebv;
}bureaudevote;
int ajouter(bureaudevote bv , char  buv[]);
int modifier(char * filename,int numbv, bureaudevote nouvbv);
int supprimer(char * filename,int numbv);
bureaudevote  chercher(int numbv, char * filenames);

#endif

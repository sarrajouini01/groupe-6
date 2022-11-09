#include <stdio.h>
#include <string.h>
#include"eelection.h"
int main()
{
    election e1= {10,12,2018,10030604,"ariana","1000",16,1},e2= {1,2,2020,13050809,"nabeul","700",8,0},e3;
    int x=ajouter("election.txt",e1);



    x=modifier("election.txt",13050809,e2 );

    if(x==1)
        printf("\nModification d'éléction  avec succés");
    else printf("\nechec Modification");
    x=supprimer("election.txt",10030604);
    if(x==1)
        printf("\nSuppression de l'éléction avec succés");
    else printf("\nechec Suppression");
    e3=chercher("election.txt",12345678 );
    if(e3.id_e==-1)
        printf("introuvable");
    return 0;
}


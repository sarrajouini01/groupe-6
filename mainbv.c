#include <stdio.h>
#include <string.h>
#include"bureaudevote.h"

int main()
{
    bureaudevote bv1= {300607,"701584","14772717","bardo2017",2,20,1},bv2= {271229,"676680","00980650","ariana3001",3,10,1},bv3;
    int x=ajouter(bv1,"bureaudevote.txt");
    x=modifier("bureaudevote.txt",233429,bv2);
    if(x==1)
        printf("\nModification de bureau de vote avec succés");
    else
     printf("\nechec Modification");
    x=supprimer("bureaudevote.txt",300607);
    if(x==1)
        printf("\nSuppression de bureau de vote avec succés");
    else printf("\nechec Suppression");
    bv3=chercher("bureaudevote.txt",270105);
    if(bv3.identifiantbv==-1)
        printf("introuvable");
    return 0;
}


#include "pointu.h"
#include<stdio.h>
int main()
{

Utilisateur u1={"monta","20092000","14403904","alaya","montassar","male",5,57,45} ,u2={"52885","456","546","4562","54555","5621",543,563,789} ;

Utilisateur u= chercher(9,"point.txt");
if(u.loginu == NULL)
printf("inexistant");
else
printf("%s %s %s %s %s %s %d %d %d %d %d %s\n",u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,u.DN.jours,u.DN.mois,u.DN.annee,u.numbv,u.voteu,u.roleu);

}

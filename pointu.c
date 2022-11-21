#include"pointu.h"
#include<stdio.h>
int ajouter(Utilisateur u , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s %s %d %d %d %d %d %s\n",u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,u.DN.jours,u.DN.mois,u.DN.annee,u.numbv,u.voteu,u.roleu);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int loginu, Utilisateur nouv, char *filename)
{
Utilisateur u;
int tr=0;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
    {
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %s\n",&u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,&u.DN.jours,&u.DN.mois,&u.DN.annee,&u.numbv,&u.voteu,u.roleu)!=EOF)
{
if(u.loginu!=loginu){
        fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d %s\n",u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,u.DN.jours,u.DN.mois,u.DN.annee,u.numbv,u.voteu,u.roleu);
tr=1;
}
else

  fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d %s\n",u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,u.DN.jours,u.DN.mois,u.DN.annee,u.numbv,u.voteu,u.roleu);

}
}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
return tr; 
}
 

int supprimer(int loginu, char *filename)
{
Utilisateur u;
int tr=0;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
    {
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %s\n",&u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,&u.DN.jours,&u.DN.mois,&u.DN.annee,&u.numbv,&u.voteu,u.roleu)!=EOF)
{
if(u.loginu!=loginu)
tr=1;
else
        fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d %s\n",u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,u.DN.jours,u.DN.mois,u.DN.annee,u.numbv,u.voteu,u.roleu);

}
}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return tr;
    }



Utilisateur chercher(int loginu, char *filename)
{
Utilisateur u; 
int tr;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %s\n",&u.loginu,u.MPu,u.cinu,u.nomu,u.prenomu,u.genderu,&u.DN.jours,&u.DN.mois,&u.DN.annee,&u.numbv,&u.voteu,u.roleu)!=EOF && tr==0)
{if(loginu==u.loginu)
tr=1;
}
}
if(tr==0)
u.loginu==-1;
return u;

}

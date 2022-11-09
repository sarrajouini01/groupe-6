#include "bureaudevote.h"
#include<stdio.h>
int ajouter(bureaudevote bv,char * filename)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %d %d %d\n",&bv.numbv,bv.identifiantbv,bv.idobservateurbv,bv.adressebv,bv.nbobservateurbv,bv.capacitebv,bv.disponibilitebv);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(char * filename, int numbv, bureaudevote nouvbv)
{
    int tr=0;
    bureaudevote bv;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nouvbv.txt", "w");
    if(f==NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %d %d %d\n",&bv.numbv,bv.identifiantbv,bv.idobservateurbv,bv.adressebv,&bv.nbobservateurbv,&bv.capacitebv,&bv.disponibilitebv)!=EOF)
        {
            if(bv.numbv==numbv)
            {
            fprintf(f2,"%d %s %s %s %d %d %d\n",nouvbv.numbv,nouvbv.identifiantbv,nouvbv.idobservateurbv,nouvbv.adressebv,nouvbv.nbobservateurbv,nouvbv.capacitebv,nouvbv.disponibilitebv);
            tr=1;
            }
            else

      fprintf(f2,"%d %s %s %s %d %d %d\n",bv.numbv,bv.identifiantbv,bv.idobservateurbv,bv.adressebv,bv.nbobservateurbv,bv.capacitebv,bv.disponibilitebv);
        }
}
        fclose(f);
        fclose(f2);
remove(filename);
rename("nouvbv.txt", filename);
        return tr;
    }


int supprimer(char * filename, int numbv)
{
int tr=0;
bureaudevote bv;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nouvbv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
while(fscanf(f,"%d %s %s %s %d %d %d\n",&bv.numbv,bv.identifiantbv,bv.idobservateurbv,bv.adressebv,bv.nbobservateurbv,bv.capacitebv,bv.disponibilitebv)!=EOF)
{
    if(bv.numbv==numbv)
    tr=1;
    else
    fprintf(f2,"%d %s %s %s %d %d %d\n",&bv.numbv,bv.identifiantbv,bv.idobservateurbv,bv.adressebv,bv.nbobservateurbv,bv.capacitebv,bv.disponibilitebv);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("nouvbv.txt", filename);
        return tr;
    }
}

bureaudevote chercher(int numbv,char * filename)
{
bureaudevote bv;
int tr;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %s %d %d %d\n",&bv.numbv,bv.identifiantbv,bv.idobservateurbv,bv.adressebv,bv.nbobservateurbv,bv.capacitebv,bv.disponibilitebv)!=EOF && tr==0)
{
if(numbv==bv.numbv)
tr=1;
}
}
fclose(f);
if(tr==0)
bv.numbv==-1;
return bv;
}

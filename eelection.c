#include "eelection.h"

int ajouter(char * filename, election  e )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s %s %d %d \n",e.d_e.jour,e.d_e.mois,e.d_e.annee,e.id_e,e.muni_e,e.nbhab_e,e.nbcons_e,e.actif);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id_e, election nouv_e )
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv_e.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %d %d \n",&e.d_e.jour,&e.d_e.mois,&e.d_e.annee,&e.id_e,e.muni_e,e.nbhab_e,&e.nbcons_e,&e.actif)!=EOF)
        {
            if(e.id_e== id_e)
            {
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",nouv_e.id_e,nouv_e.d_e.jour,nouv_e.d_e.mois,nouv_e.d_e.annee,nouv_e.muni_e,nouv_e.nbhab_e,nouv_e.nbcons_e,nouv_e.actif);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",e.d_e.jour,e.d_e.mois,e.d_e.annee,e.id_e,e.muni_e,e.nbhab_e,e.nbcons_e,e.actif);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv_e.txt", filename);
    return tr;

}
int supprimer(char * filename, int id_e)
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv_e.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %d %d \n",e.d_e.jour,e.d_e.mois,e.d_e.annee,e.id_e,e.muni_e,e.nbhab_e,e.nbcons_e,e.actif)!=EOF)
        {
            if(e.id_e== id_e)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",e.d_e.jour,e.d_e.mois,e.d_e.annee,e.id_e,e.muni_e,e.nbhab_e,e.nbcons_e,e.actif);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv_e.txt", filename);
    return tr;
}
election chercher(char * filename, int id_e)
{
    election e;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %s %s %d %d \n",e.d_e.jour,e.d_e.mois,e.d_e.annee,e.id_e,e.muni_e,e.nbhab_e,e.nbcons_e,e.actif)!=EOF)
        {
            if(e.id_e== id_e)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.id_e=-1;
    return e;

}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rdv.h"
int tableau_date_reserver(ReservationRdv tab[50])
{
int n=0;
FILE*f=fopen("datesdispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %d %d %d %d",&tab[n].staff,&tab[n].dt_res.jour,&tab[n].dt_res.mois,&tab[n].dt_res.annee,&tab[n].hr_resr)!=EOF)
{n++;}
fclose(f);
}
return n;
}
int verifier_reserver(ReservationRdv r)
{
ReservationRdv r;
int v=0;
FILE*f=fopen("dateRdv.txt","r");
if(f!=NULL)
{
while(!v&&fscanf(f,"%s %d %d %d %d",r.staff,&r.dt_res.jour,&r.dt_res.mois,&r.dt_res.annee,&r.hr_resr)!=EOF)
{
if(strcmp(r.staff,rv.staff)==0)
  {if((r.dt_res.jour==rv.dt_res.jour)&&(r.dt_res.mois==rv.dt_res.mois)&&(r.dt_res.annee==rv.dt_res.annee)&&(r.hr_resr==rv.hr_resr))
{v=1;}
}
}
fclose(f);
}
return v;
}
/*int tableau_date_disponible(char staff[20],Date dt_resr,int hr_resr)
{
int i,nS=0;
FILE*f=fopen("rdv.txt","r");
ReservationRdv r;
r.dt_res=dt_resr;
r.hr_resr=hr_resr;
if(f!=NULL)
{
while(fscanf(f,"%s",r.staff)!=EOF)
 {
   if(!verifier_reserver(r))
     {
      strcpy(staff[nS],r.*/
void reserver_date(ReservationRdv r)
{
FILE*f=fopen("rdv.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %d %d %d %d\n",r.staff,r.dt_res.jour,r.dt_res.mois,r.dt_res.annee,r.hr_resr);
fclose(f);
}
}

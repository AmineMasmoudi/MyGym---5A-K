#include <gtk/gtk.h>
#ifndef reservation_H_INCLUDED	
#define reservation_H_INCLUDED
#include "coach.h"
typedef struct
{
int jour;
int mois;
int annee;
int heure;
}Date;
typedef struct
{
char id[30];
char nom[50];	
int cap;
Date dt_res;

}Reservationseance;

int tableau_seance_Reserver(Reservationseance tab[50]);
void reserver_seance(Reservationseance s);
void afficher_seance(GtkWidget *liste);
void modifier_seance(char ide[],Reservationseance n );
void supprimer_seance(char ide1[10]);
#endif

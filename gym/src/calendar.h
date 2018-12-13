#ifndef reservation_H_INCLUDED	
#define reservation_H_INCLUDED
#include "calendar.h"
#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct
{
char num[100];
Date dt_res;
int hr_resr;
int hr_resrf;
}calendar;

int tableau_calendar(calendar tab[50]);
void reserver(calendar s);
void afficher_event(GtkWidget *liste);
gchar *get_event1(GtkWidget *liste) ;
gchar *get_event2(GtkWidget *liste) ;
gchar *get_event3(GtkWidget *liste) ;
gchar *get_event4(GtkWidget *liste) ;
gchar *get_event5(GtkWidget *liste) ;
gchar *get_event6(GtkWidget *liste) ;
void supprimer_calendar(int day,int month,int year,int hd,int hf);
#endif


#include<gtk/gtk.h>
typedef struct
{ 
        char numero[30];
	int jour ;
	int mois;
        int annee;
        int heure;
        char avec_qui[30];   
	char sujet[30];
}Reservationseance_ad ;

void reserver_ad_seance(Reservationseance_ad sa);
void afficher_seance_ad(GtkWidget *liste);
void modifier_seance_ad(char ide[30],Reservationseance_ad na );
void supprimer_seance_ad(char ide1[10]);

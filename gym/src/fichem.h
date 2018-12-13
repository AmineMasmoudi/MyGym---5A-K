#include <gtk/gtk.h>
#include "calendar.h"
typedef struct
{	
	char nom[30];
	char prenom[30];
	Date naissance;
	int poids;
	int taille;
	int imc;
	char maladies[30];
	char remarques[30];

}fiche;
void createfichem(fiche s);
void afficher_fichem(GtkWidget *liste);
gchar *get_fichemr(GtkWidget *liste) ;
gchar *get_fichemr1(GtkWidget *liste) ;
gchar *get_fichemr2(GtkWidget *liste) ;
gchar *get_fichemr3(GtkWidget *liste) ;
gchar *get_fichemr4(GtkWidget *liste) ;
gchar *get_fichemr5(GtkWidget *liste) ;
gchar *get_fichemr6(GtkWidget *liste) ;
gchar *get_fichemr7(GtkWidget *liste) ;
gchar *get_fichemr8(GtkWidget *liste) ;
gchar *get_fichemr9(GtkWidget *liste) ;
void supprimer_fichemr(int p);


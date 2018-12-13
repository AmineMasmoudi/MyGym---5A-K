#include <gtk/gtk.h>

typedef struct
{	
	char nom[30];
	char prenom[30];
	int jour;
	int mois;
	int annee;
	char poids[30];
	char taille[30];
	char imc[30];
	char regime_alimentaire[50];
	char remarques[50];
	char id[30];
	
	


}fiche;

void ajouter_fiche1(fiche fi1);
void afficher_fiche1(GtkWidget *liste);
void supprimer_fiche1(char id1[30]);
void modifier_fiche1(char ide[30],fiche f1);

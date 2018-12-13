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
	char regime_alimentaire[30];
	char remarques[30];
	char id[30];
	
	


}Fiche;

void ajouter_fiche(Fiche fi);
void afficher_fiche(GtkWidget *liste);
void supprimer_fiche(char id1[30]);
void modifier_fiche(char ide[30],Fiche f);

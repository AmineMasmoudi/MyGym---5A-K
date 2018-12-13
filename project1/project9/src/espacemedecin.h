#include <gtk/gtk.h>


typedef struct 

{	char identifiant[20];
	char nom [20];
        char prenom[20];
        int jour;
        int mois;
        int annee;
        char adresse[20];
        char taille[20];
        char poids[20];
        char imc[20];
        char groupe_sanguin[20];
        char maladies[20];
        char traitement[20];
        
}Fiche  ;

void ajouter_fiche(Fiche fi);
void afficher_fiche(GtkWidget *liste);
void modifier_fiche(char ide[30],Fiche f);
void suupprimer_fiche(char ide1[30]);

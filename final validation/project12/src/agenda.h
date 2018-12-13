#include <gtk/gtk.h>

typedef struct 
{
char date[30];
char taches[30];
char heure[30];
} agenda;
void ajouter_agenda(agenda ag);
void afficher_agenda(GtkWidget *liste);

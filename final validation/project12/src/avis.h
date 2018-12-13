#include<gtk/gtk.h>
typedef struct
{ 
        char choix[30];
	int note ;
	char remarque[30];
}avis_ad;
void reserver_ad_avis(avis_ad av);
void afficher_avis_ad(GtkWidget *liste);

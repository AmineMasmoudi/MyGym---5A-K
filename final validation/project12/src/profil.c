#ifdef HAVE_CONFIG_H
#include<config.h>
#endif
#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"profil.h"

enum 

{ 
   ID,
   NOM,
   PRENOM,
   SEXE,
   TELEPHONE,
   EMAIL,
   TAILLE,
   POIDS,
   JOUR,
   MOIS,
   ANNEE,
   ABONNEMENT,
   COLUMNS
};


void afficher_profil_ad(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        
        char id[30];
	char nom [30];
	char prenom[30];
        char sexe[30];
        char telephone[30];
        char email[30];  
        char taille[30];  
        char poids[30];  
        char jour[30];  
        char mois[30];   
	char annee[30];
        char abonnement[30];

        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

              
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
     
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" sexe", renderer, "text",SEXE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" telephone", renderer, "text",TELEPHONE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" email", renderer, "text",EMAIL, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" taille", renderer, "text",TAILLE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                
	        renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
              


                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
	        renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  abonnement", renderer, "text",ABONNEMENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
              
               
		
	}



	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/amine123/Downloads/project12/src/profil.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f=fopen("/home/amine123/Downloads/project12/src/profil.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s",id,nom,prenom,sexe,telephone,email,taille,poids,jour,mois,annee,abonnement)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ID,id,NOM,nom,PRENOM,prenom,SEXE,sexe,TELEPHONE,telephone,EMAIL,email,TAILLE,taille,POIDS,poids,JOUR,jour,MOIS,mois,ANNEE,annee,ABONNEMENT,abonnement,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

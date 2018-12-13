#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "agenda.h"

enum
{	
	DATE,
	TACHES,
	HEURE,
	COLUMNS,
	
};

void ajouter_agenda(agenda ag)
{
 FILE *f;
 f=fopen("/home/ameni/Projects/project3/src/agenda.txt","a+");
 if(f!=NULL)
{
fprintf(f,"%s %s %s  \n",ag.date,ag.taches,ag.heure);
fclose(f);
}

}
void afficher_agenda(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char date[30];
	char taches[30];
	char heure[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
renderer=gtk_cell_renderer_text_new();		      		column=gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);				  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
renderer=gtk_cell_renderer_text_new(); column=gtk_tree_view_column_new_with_attributes(" taches", renderer,
 "text",TACHES, NULL);				  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" heure", renderer, "text",HEURE, NULL);				  			gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column); 
}
			  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f= fopen("/home/ameni/Projects/project3/src/agenda.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{
		f=fopen("/home/ameni/Projects/project3/src/agenda.txt", "a+");
		while(fscanf(f,"%s %s %s \n",date,taches,heure)!=EOF)
		  {
		gtk_list_store_append (store, &iter);
		  gtk_list_store_set(store, &iter,DATE,date,TACHES,taches,HEURE,heure, -1);
		  }
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
}






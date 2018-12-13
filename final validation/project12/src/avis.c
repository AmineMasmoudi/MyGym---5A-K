#ifdef HAVE_CONFIG_H
#include<config.h>
#endif
#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"avis.h"

enum 

{  CHOIX,
   NOTE,
   REMARQUE,
   
   COLUMNS
};
void reserver_ad_avis(avis_ad av)
{
	FILE *f; 
         f=fopen("/home/amine123/Downloads/project12/src/avis.txt","a+");


	if(f!=NULL)
	{
	fprintf(f,"%s %d %s\n",av.choix,av.note,av.remarque);
        fclose(f);
	}
}
/*********************************/
void afficher_avis_ad(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        char choix[30];
	char note [30];
	char remarque[30];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

              
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" chiox", renderer, "text",CHOIX, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" note", renderer, "text",NOTE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" remarque", renderer, "text",REMARQUE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}



	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/amine123/Downloads/project12/src/avis.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f=fopen("/home/amine123/Downloads/project12/src/avis.txt","a+");
    while(fscanf(f,"%s %s %s ",choix,note,remarque)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,CHOIX,choix,NOTE,note,REMARQUE,remarque,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include "fichem.h"
#include "calendar.h"
#include <gtk/gtk.h>


void createfichem(fiche s)
{
	FILE* f=fopen("fichem.txt","a");


	if(f!=NULL)
	{
	fprintf(f,"%s %s %d %d %d %d %d %d %s %s\n",s.nom,s.prenom,s.naissance.jour,s.naissance.mois,s.naissance.annee,s.poids,s.taille,s.imc,s.maladies,s.remarques);
	fclose(f);
	}
}

enum   
{       
        NOM,
        PRENOM,
	JOUR,
        MOIS,
        ANNEE,
	POIDS,
        TAILLE,
	IMC,
	MALADIES,
	REMARQUES,
	COLUMNS
};

void afficher_fichem(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char prenom [30];
	char jour [30];
	char mois [30];
        char annee[30];
        char poids[30];
	char taille[30];
	char imc[30];
	char maladies[30];
	char remarques[30];
        store=NULL;

       FILE *f;
	
	store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);  

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);	
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
		column = gtk_tree_view_column_new_with_attributes("  poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  imc", renderer, "text",IMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  maladies", renderer, "text",MALADIES, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  remarques", renderer, "text",REMARQUES, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

      	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("fichem.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("fichem.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,jour,mois,annee,poids,taille,imc,maladies,remarques)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, JOUR, jour, MOIS, mois,ANNEE,annee,POIDS,poids,TAILLE,taille,IMC,imc,MALADIES,maladies,REMARQUES,remarques, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}

}

gchar *get_fichemr(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,REMARQUES, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr1(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,NOM, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr2(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,PRENOM, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr3(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,JOUR, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr4(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,MOIS, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr5(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,ANNEE, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr6(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,POIDS, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr7(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,TAILLE, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr8(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,IMC, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_fichemr9(GtkWidget *liste) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  GtkTreeSelection *selection; 
  gchar *strin;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return 0;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
gtk_tree_model_get (model, &iter,MALADIES, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
void supprimer_fichemr(int p)
{	
	FILE*r, *tmp;
        fiche s;
    	r=fopen("fichem.txt","a+");
	tmp=fopen("suppression.txt","a+");
	
	if(r!=NULL) 

	{
		
	while(fscanf(r,"%s %s %d %d %d %d %d %d %s %s\n",s.nom,s.prenom,&s.naissance.jour,&s.naissance.mois,&s.naissance.annee,&s.poids,&s.taille,&s.imc,s.maladies,s.remarques)!=EOF)
	{
    		if(!(s.poids==p))
    		{	
			fprintf(tmp,"%s %s %d %d %d %d %d %d %s %s\n",s.nom,s.prenom,s.naissance.jour,s.naissance.mois,s.naissance.annee,s.poids,s.taille,s.imc,s.maladies,s.remarques);

    		}
    				
	}
	fclose(r);
	fclose(tmp);
remove("fichem.txt");
rename("suppression.txt","fichem.txt");

	}
}








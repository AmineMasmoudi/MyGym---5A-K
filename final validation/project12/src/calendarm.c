#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include "calendarm.h"
#include <gtk/gtk.h>

int tableau_calendar(calendar tab[50])
{
int n=0;
FILE* f=fopen("tempReserve.txt","r");
if(f!=NULL)
{
  while(fscanf(f,"%s %d %d %d %d %d",tab[n].num,&tab[n].dt_res.jour,&tab[n].dt_res.mois,&tab[n].dt_res.annee,&tab[n].hr_resr,&tab[n].hr_resrf)!=EOF)
{
n++;
}
fclose(f);

}

return n;
}

void reserver(calendar s)
{
	FILE* f=fopen("tempReserve.txt","a");


	if(f!=NULL)
	{
	fprintf(f,"%s %d %d %d %d %d\n",s.num,s.dt_res.jour,s.dt_res.mois,s.dt_res.annee,s.hr_resr,s.hr_resrf);
	fclose(f);
	}
}

enum   
{       
        EVENT,
        JOUR,
	MOIS,
        ANNEE,
        HEURED,
	HEUREF,
        COLUMNS
};

void afficher_event(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char event [30];
	char jour [30];
	char mois [30];
	char annee [30];
        char heure_debut[30];
        char heure_fin[30];
        store=NULL;

       FILE *f;
	
	store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  event                                                                                              ", renderer, "text",EVENT,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);  

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure_debut", renderer, "text",HEURED, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure_fin", renderer, "text",HEUREF, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

      	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("tempReserve.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("tempReserve.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s \n",event,jour,mois,annee,heure_debut,heure_fin)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EVENT, event, JOUR, jour, MOIS, mois,ANNEE,annee,HEURED,heure_debut,HEUREF,heure_fin, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}

}






gchar *get_event1(GtkWidget *liste) {
    
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
gtk_tree_model_get (model, &iter,EVENT, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_event2(GtkWidget *liste) {
    
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
gchar *get_event3(GtkWidget *liste) {
    
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
gchar *get_event4(GtkWidget *liste) {
    
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
gchar *get_event5(GtkWidget *liste) {
    
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
gtk_tree_model_get (model, &iter,HEURED, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}
gchar *get_event6(GtkWidget *liste) {
    
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
gtk_tree_model_get (model, &iter,HEUREF, &strin, -1);
/*    gtk_list_store_remove(store, &iter);*/
  }
return strin;
}



void supprimer_calendar(int day,int month,int year,int hd,int hf)
{	
	FILE*r, *tmp;
        calendar s;
    	r=fopen("tempReserve.txt","a+");
	tmp=fopen("suppression.txt","a+");
	
	if(r!=NULL) 

	{
		
	while(fscanf(r,"%s %d %d %d %d %d\n",s.num,&s.dt_res.jour,&s.dt_res.mois,&s.dt_res.annee,&s.hr_resr,&s.hr_resrf)!=EOF)
	{
    		if(!((s.dt_res.annee==year)&&(s.dt_res.jour==day)&&(s.dt_res.mois==month)&&(s.hr_resr==hd)&&(s.hr_resrf==hf)))
    		{	
			fprintf(tmp,"%s %d %d %d %d %d\n",s.num,s.dt_res.jour,s.dt_res.mois,s.dt_res.annee,s.hr_resr,s.hr_resrf);

    		}
    				
	}
	fclose(r);
	fclose(tmp);
remove("tempReserve.txt");
rename("suppression.txt","tempReserve.txt");

	}
}



	

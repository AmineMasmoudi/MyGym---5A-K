#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fiche.h"

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
	REGIME_ALIMENTAIRE,
	REMARQUES,
	ID,
	COLUMNS
	
};

void ajouter_fiche(Fiche fi)
{
 FILE *f;
 f=fopen("fiche.txt", "a+");
 if(f!=NULL)
{
fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s \n",fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.poids,fi.taille,fi.imc,fi.regime_alimentaire,fi.remarques,fi.id);
fclose(f);
}

}
void afficher_fiche(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char nom[30];
	char prenom[30];
	char jour[30];
	char mois[30];
	char annee[30];
	char poids[30];
	char taille[30];
	char imc[30];
	char regime_alimentaire[30];
	char remarques[30];
	
	char id[30];
	
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();		      		
	column=gtk_tree_view_column_new_with_attributes(" nom", renderer,"text",NOM, NULL);				  		  	  gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		
	renderer=gtk_cell_renderer_text_new();
 	column=gtk_tree_view_column_new_with_attributes(" prenom", renderer,
	 "text",PRENOM, NULL);				  		
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",JOUR, NULL);
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
	column = gtk_tree_view_column_new_with_attributes("  regime_alimentaire", renderer, "text",REGIME_ALIMENTAIRE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" remarques", renderer, "text",REMARQUES, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);


	}	
		


			  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING );
		f= fopen("fiche.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{
		f=fopen("fiche.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",nom,prenom,jour,mois,annee,poids,taille,imc,regime_alimentaire,remarques,id)!=EOF)
		  {
		gtk_list_store_append (store, &iter);
		  gtk_list_store_set(store, &iter,NOM,nom,PRENOM,prenom,JOUR,jour,MOIS,mois,ANNEE,annee,POIDS,poids,
TAILLE,taille,IMC,imc,REGIME_ALIMENTAIRE,regime_alimentaire,REMARQUES,remarques,ID,id, -1);
		  }
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
}
/* Modifier Fiche */
void modifier_fiche(char ide[30],Fiche f)
{	
	FILE *r ,*s;
        Fiche fi;
    	r=fopen("fiche.txt","r+");
	s=fopen("fiche.tmp.txt","w+");
	if(r!=NULL) 
	{
			
    			

	while(fscanf(r,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi.nom,fi.prenom,&fi.jour,&fi.mois,&fi.annee,fi.poids,fi.taille,fi.imc,fi.regime_alimentaire,fi.remarques,fi.id)!=EOF)
			{
    				if(strcmp(fi.id,ide)!=0)
    				{	
						fprintf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.poids,fi.taille,fi.imc,fi.regime_alimentaire,fi.remarques,fi.id);

    				}
    				else{
					

    					fprintf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",f.nom,f.prenom,f.jour,f.mois,f.annee,f.poids,f.taille,f.imc,f.regime_alimentaire,f.remarques,f.id);
    				}
			}
			fclose(r);
			fclose(s);
}

	r=fopen("fiche.txt","w+");
	s=fopen("fiche.tmp.txt","r+");


		while(fscanf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",f.nom,f.prenom,&f.jour,&f.mois,&f.annee,f.poids,f.taille,f.imc,f.regime_alimentaire,f.remarques,f.id)!=EOF)

	fprintf(r,"%s %s %d %d %d %s %s %s %s %s %s  \n",f.nom,f.prenom,f.jour,f.mois,f.annee,f.poids,f.taille,f.imc,f.regime_alimentaire,f.remarques,f.id);
		
			fclose(r);
			fclose(s);

			remove("fiche.tmp.txt");
			

	}


/* Supprimer Fiche */
void supprimer_fiche(char id1[30])
{	
	FILE*r, *s;
        Fiche fi;
    	r=fopen("fiche.txt","a+");
	s=fopen("suppression.txt","a+");
	
	if(r!=NULL) 

	{
		
	while(fscanf(r,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi.nom,fi.prenom,&fi.jour,&fi.mois,&fi.annee,fi.taille,fi.poids,fi.imc,fi.regime_alimentaire,fi.remarques,fi.id)!=EOF)
	{
    		if(strcmp(fi.id,id1)!=0)
    		{	
			fprintf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.taille,fi.poids,fi.imc,fi.regime_alimentaire,fi.remarques,fi.id);

    		}
    				
	}
	fclose(r);
	fclose(s);
remove("fiche.txt");
rename("suppression.txt","fiche.txt");

	}
}

			








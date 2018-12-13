#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "nutritionniste.h"

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

void ajouter_fiche1(fiche fi1)
{
 FILE *f;
 f=fopen("/home/amine123/Downloads/project12/src/ameni.txt", "a+");
 if(f!=NULL)
{
fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s \n",fi1.nom,fi1.prenom,fi1.jour,fi1.mois,fi1.annee,fi1.poids,fi1.taille,fi1.imc,fi1.regime_alimentaire,fi1.remarques,fi1.id);
fclose(f);
}

}
void afficher_fiche1(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char nom[30];
	char prenom[30];
	char poids[30];
	char taille[30];
	char imc[30];
	char regime_alimentaire[50];
	char remarques[50];
	char jour[30];
	char mois[30];
	char annee[30];
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
		f= fopen("/home/amine123/Downloads/project12/src/ameni.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{
		f=fopen("/home/amine123/Downloads/project12/src/ameni.txt", "a+");
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
void modifier_fiche1(char ide[30],fiche f1)
{	
	FILE *r ,*s;
        fiche fi1;
    	r=fopen("/home/amine123/Downloads/project12/src/ameni.txt","r+");
	s=fopen("/home/amine123/Downloads/project12/src/fiche.tmp.txt","w+");
	if(r!=NULL) 
	{
			
    			

	while(fscanf(r,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi1.nom,fi1.prenom,&fi1.jour,&fi1.mois,&fi1.annee,fi1.poids,fi1.taille,fi1.imc,fi1.regime_alimentaire,fi1.remarques,fi1.id)!=EOF)
			{
    				if(strcmp(fi1.id,ide)!=0)
    				{	
						fprintf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi1.nom,fi1.prenom,fi1.jour,fi1.mois,fi1.annee,fi1.poids,fi1.taille,fi1.imc,fi1.regime_alimentaire,fi1.remarques,fi1.id);

    				}
    				else{
					

    					fprintf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",f1.nom,f1.prenom,f1.jour,f1.mois,f1.annee,f1.poids,f1.taille,f1.imc,f1.regime_alimentaire,f1.remarques,f1.id);
    				}
			}
			fclose(r);
			fclose(s);
}

	r=fopen("/home/amine123/Downloads/project12/src/ameni.txt","w+");
	s=fopen("/home/amine123/Downloads/project12/src/fiche.tmp.txt","r+");


		while(fscanf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",f1.nom,f1.prenom,&f1.jour,&f1.mois,&f1.annee,f1.poids,f1.taille,f1.imc,f1.regime_alimentaire,f1.remarques,f1.id)!=EOF)

	fprintf(r,"%s %s %d %d %d %s %s %s %s %s %s  \n",f1.nom,f1.prenom,f1.jour,f1.mois,f1.annee,f1.poids,f1.taille,f1.imc,f1.regime_alimentaire,f1.remarques,f1.id);
		
			fclose(r);
			fclose(s);

			remove("/home/amine123/Downloads/project12/src/fiche.tmp.txt");
			

	}


/* Supprimer Fiche */
void supprimer_fiche1(char id1[30])
{	
	FILE*r, *s;
        fiche fi1;
    	r=fopen("/home/amine123/Downloads/project12/src/ameni.txt","a+");
	s=fopen("/home/amine123/Downloads/project12/src/suppression.txt","a+");
	
	if(r!=NULL) 

	{
		
	while(fscanf(r,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi1.nom,fi1.prenom,&fi1.jour,&fi1.mois,&fi1.annee,fi1.taille,fi1.poids,fi1.imc,fi1.regime_alimentaire,fi1.remarques,fi1.id)!=EOF)
	{
    		if(strcmp(fi1.id,id1)!=0)
    		{	
			fprintf(s,"%s %s %d %d %d %s %s %s %s %s %s  \n",fi1.nom,fi1.prenom,fi1.jour,fi1.mois,fi1.annee,fi1.taille,fi1.poids,fi1.imc,fi1.regime_alimentaire,fi1.remarques,fi1.id);

    		}
    				
	}
	fclose(r);
	fclose(s);
remove("/home/amine123/Downloads/project12/src/ameni.txt");
rename("/home/amine123/Downloads/project12/src/suppression.txt","/home/amine123/Downloads/project12/src/ameni.txt");

	}
}

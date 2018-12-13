#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include<stdlib.h>

#include <stdio.h>
#include <string.h>
#include "espacemedecin.h"


enum   
{       IDENTIFIANT,
        NOM,
	PRENOM,
        JOUR,
        MOIS,
        ANNEE,
        ADRESSE,
        TAILLE,
        POIDS,
        IMC,
        GROUPE_SANGUIN,
        MALADIES,
        TRAITEMENT,
        COLUMNS
};

//Ajouter 
void ajouter_fiche(Fiche fi)
{

 FILE*f;
  f=fopen("/home/khaoula/Projects/project1/project9/src/fiches.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement);
  fclose(f);

}

}




void afficher_fiche(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        char identifiant[20];
	char nom [20];
        char prenom[20];
	char jour[20];
        char mois[20];
        char annee[20];
        char adresse[20];
        char taille[20];
        char poids[20];
        char imc[20];
        char groupe_sanguin[20];
        char maladies[20];
        char traitement[20];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",IDENTIFIANT, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
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
		column = gtk_tree_view_column_new_with_attributes("  adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



        renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" taille", 
renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

             renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


             renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  imc", renderer, "text",IMC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
              
             renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  groupe_sanguin", renderer, "text",GROUPE_SANGUIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


           

           renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  maladies", renderer, "text",MALADIES, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

         renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  traitement", renderer, "text",TRAITEMENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	}



	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("/home/khaoula/Projects/project1/project9/src/fiches.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/khaoula/Projects/project1/project9/src/fiches.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s",identifiant,nom,prenom,jour,mois,annee,adresse,taille, poids,imc,groupe_sanguin,maladies,traitement)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,IDENTIFIANT,identifiant,  NOM, nom,PRENOM,prenom, JOUR, jour,MOIS,mois,ANNEE,annee,ADRESSE,adresse,TAILLE,taille,POIDS,poids,IMC,imc,GROUPE_SANGUIN,groupe_sanguin,MALADIES,maladies,TRAITEMENT,traitement, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
/**********************************************************************************************/
void modifier_fiche(char ide[30],Fiche f)
{	
	FILE*r ,*s;
        Fiche fi;
    	r=fopen("/home/khaoula/Projects/project1/project9/src/fiches.txt","r+");
	    s=fopen("/home/khaoula/Projects/project1/project9/src/fiches.tmp.txt","w+");
	if(r!=NULL) 
	{
			
    			

			while(fscanf(r,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,&fi.jour,&fi.mois,&fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement)!=EOF)
			{
    				if(strcmp(fi.identifiant,ide)!=0)
    				{	
						fprintf(s,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement);

    				}
    				else{
					

    					fprintf(s,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",f.identifiant,f.nom,f.prenom,f.jour,f.mois,f.annee,f.adresse,f.taille,f.poids,f.imc,f.groupe_sanguin,f.maladies,f.traitement);
    				}
			}
			fclose(r);
			fclose(s);
}

	r=fopen("/home/khaoula/Projects/project1/project9/src/fiches.txt","w+");
	    s=fopen("/home/khaoula/Projects/project1/project9/src/fiches.tmp.txt","r+");


		while(fscanf(s,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",f.identifiant,f.nom,f.prenom,&f.jour,&f.mois,&f.annee,f.adresse,f.taille,f.poids,f.imc,f.groupe_sanguin,f.maladies,f.traitement)!=EOF)

	fprintf(r,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",f.identifiant,f.nom,f.prenom,f.jour,f.mois,f.annee,f.adresse,f.taille,f.poids,f.imc,f.groupe_sanguin,f.maladies,f.traitement);
		
			fclose(r);
			fclose(s);

			remove("/home/khaoula/Projects/project1/project9/src/fiches.tmp.txt");
			

	}




void suupprimer_fiche(char ide1[30])
{	
	FILE*r ,*s;
        Fiche fi;
    	r=fopen("/home/khaoula/Projects/project1/project9/src/fiches.txt","a+");
	    s=fopen("/home/khaoula/Projects/project1/project9/src/supprimer.txt","a+");
	if(r!=NULL) 
	{
		
			while(fscanf(r,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,&fi.jour,&fi.mois,&fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement)!=EOF)
			{
    				if(strcmp(fi.identifiant,ide1)!=0)
    				{	
						fprintf(s,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement);

    				}
    				
			}
			fclose(r);
			fclose(s);
remove("/home/khaoula/Projects/project1/project9/src/fiches.txt");
rename("/home/khaoula/Projects/project1/project9/src/supprimer.txt","/home/khaoula/Projects/project1/project9/src/fiches.txt");
}
}
			


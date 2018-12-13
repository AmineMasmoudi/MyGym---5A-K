#ifdef HAVE_CONFIG_H
#include<config.h>
#endif
#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"adherant.h"

enum 

{ 
   NUMERO,
   JOUR,
   MOIS,
   ANNEE,
   HEURE,
   AVEC_QUI,
   SUJET,
   COLUMNS
};




void reserver_ad_seance(Reservationseance_ad sa)
{
	FILE *f; 
         f=fopen("/home/amine123/Downloads/project12/src/reserve.txt","a+");


	if(f!=NULL)
	{
	fprintf(f,"%s %d %d %d %d %s %s\n",sa.numero,sa.jour,sa.mois,sa.annee,sa.heure,sa.avec_qui,sa.sujet);
        fclose(f);
	}
}

/*******************************/





void afficher_seance_ad(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        
        char numero[30];
	char jour [30];
	char mois[30];
        char annee[30];
        char heure[30];
        char avec_qui[30];   
	char sujet[30];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

              
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" numero", renderer, "text",NUMERO, NULL);	
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
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
              
               
	       
	       
	        
	        renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" avec_qui", renderer, "text",AVEC_QUI, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  sujet", 
renderer, "text",SUJET, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	}



	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/amine123/Downloads/project12/src/reserve.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f=fopen("/home/amine123/Downloads/project12/src/reserve.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s %s",numero,jour,mois,annee,heure,avec_qui,sujet)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NUMERO,numero,JOUR,jour,MOIS,mois,ANNEE,annee,HEURE,heure,avec_qui,AVEC_QUI,SUJET,sujet,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
/*****************************/

void modifier_seance_ad(char ide[30],Reservationseance_ad na )
{	

	FILE*f;
        FILE*r;
    	Reservationseance_ad sa ;

    	f=fopen("/home/amine123/Downloads/project12/src/reserve.txt","r+");
	    r=fopen("/home/amine123/Downloads/project12/src/seances.txt","w+");
	if(f!=NULL) 
	{
			
    			

	while(fscanf(f,"%s %d %d %d %d %s %s\n",sa.numero,&sa.jour,&sa.mois,&sa.annee,&sa.heure,sa.avec_qui,sa.sujet)!=EOF)
			{
    				if(strcmp(sa.numero,ide)!=0)
    				{	     
						fprintf(r,"%s %d %d %d %d %s %s\n",sa.numero,sa.jour,sa.mois,sa.annee,sa.heure,sa.avec_qui,sa.sujet);

    				}
    				else{					


    					fprintf(r,"%s %d %d %d %d %s %s\n",na.numero,na.jour,na.mois,na.annee,na.heure,na.avec_qui,na.sujet);
    				}
			}
			fclose(f);
			fclose(r);

			
}	
f=fopen("/home/amine123/Downloads/project12/src/reserve.txt","w+"); r=fopen("/home/amine123/Downloads/project12/src/seances.txt","r+");
 while(fscanf(r,"%s %d %d %d %d %s %s\n",na.numero,&na.jour,&na.mois,&na.annee,&na.heure,na.avec_qui,na.sujet)!=EOF)

    					fprintf(f,"%s %d %d %d %d %s %s\n",na.numero,na.jour,na.mois,na.annee,na.heure,na.avec_qui,na.sujet);

fclose(f);
fclose(r);
remove("/home/amine123/Downloads/project12/src/seances.txt");

}

/************************/

void supprimer_seance_ad(char ide1[10])
{ 	
	FILE*f ,*r;
    	Reservationseance_ad sa;

    	f=fopen("/home/amine123/Downloads/project12/src/reserve.txt","a+");
	r=fopen("/home/amine123/Downloads/project12/src/suprimers.txt","a+");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %d %d %d %d %s %s\n",sa.numero,&sa.jour,&sa.mois,&sa.annee,&sa.heure,sa.avec_qui,sa.sujet)!=EOF)
			{
    				if(strcmp(sa.numero,ide1)!=0)
    				{	
						fprintf(r,"%s %d %d %d %d %s %s\n",sa.numero,sa.jour,sa.mois,sa.annee,sa.heure,sa.avec_qui,sa.sujet);

    				}
			}
			fclose(f);
			fclose(r);

remove("/home/amine123/Downloads/project12/src/reserve.txt");
rename("/home/amine123/Downloads/project12/src/suprimers.txt","/home/amine123/Downloads/project12/src/reserve.txt");


	}
}

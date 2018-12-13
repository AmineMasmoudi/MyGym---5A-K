#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "coach.h"

enum 

{ 
   NOM,
   JOUR,
   MOIS,
   ANNEE,
   HEURE,
   CAP,
   ID,
   COLUMNS
};




void reserver_seance(Reservationseance s)
{
	FILE *f; 
         f=fopen("/home/amine123/Downloads/project12/src/seanceReserve.txt","a+");


	if(f!=NULL)
	{
	fprintf(f,"%s %s %d %d %d %d %d\n",s.id,s.nom,s.dt_res.jour,s.dt_res.mois,s.dt_res.annee,s.dt_res.heure,s.cap);
	fclose(f);
	}
}





int tableau_seance_Reserver(Reservationseance tab[50])
{
int n=0;
FILE* f=fopen("/home/amine123/Projects/proje/src","r");
if(f!=NULL)
{
  while(fscanf(f,"%s %d %d %d %d %d",tab[n].nom,&tab[n].dt_res.jour,&tab[n].dt_res.mois,&tab[n].dt_res.annee,&tab[n].dt_res.heure
,&tab[n].cap)!=EOF)
{
n++;
}
fclose(f);

}

return n;
}







void afficher_seance(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        
        char id[30];
	char nom [30];
	char jour[30];
        char mois[30];
        char annee[30];
        char heure[30];   
	char cap[30];
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
		column = gtk_tree_view_column_new_with_attributes("  cap", 
renderer, "text",CAP, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	}



	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/amine123/Downloads/project12/src/seanceReserve.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f=fopen("/home/amine123/Downloads/project12/src/seanceReserve.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s %s",id,nom,jour,mois,annee,heure,cap)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ID, id,  NOM, nom, JOUR, jour,MOIS,mois,ANNEE,annee,HEURE,heure,CAP,cap, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


void modifier_seance(char ide[],Reservationseance n  )
{	

	FILE*f;
        FILE*r;
    	Reservationseance s ;

    	f=fopen("/home/amine123/Downloads/project12/src/seanceReserve.txt","r+");
	    r=fopen("/home/amine123/Downloads/project12/src/seances.txt","w+");
	if(f!=NULL) 
	{
			
    			

	while(fscanf(f,"%s %s %d %d  %d %d %d \n",s.id,s.nom,&s.dt_res.jour,&s.dt_res.mois,&s.dt_res.annee,&s.dt_res.heure,&s.cap)!=EOF)
			{
    				if(strcmp(s.id,ide)!=0)
    				{	     
						fprintf(r,"%s %s %d %d  %d %d %d \n",s.id,s.nom,s.dt_res.jour,s.dt_res.mois,s.dt_res.annee,s.dt_res.heure,s.cap);

    				}
    				else{					


    					fprintf(r,"%s %s %d %d  %d %d %d \n",n.id,n.nom,n.dt_res.jour,n.dt_res.mois,n.dt_res.annee,n.dt_res.heure,n.cap);
    				}
			}
			fclose(f);
			fclose(r);

			
}	
f=fopen("/home/amine123/Downloads/project12/src/seanceReserve.txt","w+"); r=fopen("/home/amine123/Downloads/project12/src/seances.txt","r+");
 while(fscanf(r,"%s %s %d %d  %d %d %d \n", n.id,n.nom,&n.dt_res.jour,&n.dt_res.mois,&n.dt_res.annee,&n.dt_res.heure,&n.cap)!=EOF)

    					fprintf(f,"%s %s %d %d  %d %d %d \n",n.id,n.nom,n.dt_res.jour,n.dt_res.mois,n.dt_res.annee,n.dt_res.heure,n.cap);

fclose(f);
fclose(r);
remove("/home/amine123/Downloads/project12/src/seances.txt");

}



void supprimer_seance(char ide1[10])
{ 	
	FILE*f ,*r;
    	Reservationseance s;

    	f=fopen("/home/amine123/Downloads/project12/src/seanceReserve.txt","a+");
	r=fopen("/home/amine123/Downloads/project12/src/suprimer.txt","a+");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %s %d %d  %d %d %d \n",s.id,s.nom,&s.dt_res.jour,&s.dt_res.mois,&s.dt_res.annee,&s.dt_res.heure,&s.cap)!=EOF)
			{
    				if(strcmp(s.id,ide1)!=0)
    				{	
						fprintf(r,"%s %s %d %d  %d %d %d \n",s.id,s.nom,s.dt_res.jour,s.dt_res.mois,s.dt_res.annee,s.dt_res.heure,s.cap);

    				}
			}
			fclose(f);
			fclose(r);

remove("/home/amine123/Downloads/project12/src/seanceReserve.txt");
rename("/home/amine123/Downloads/project12/src/suprimer.txt","/home/amine123/Downloads/project12/src/seanceReserve.txt");


	}
}

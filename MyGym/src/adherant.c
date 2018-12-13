#include<string.h>
#include<stdio.h>
#include"adherant.h"
#include<stdlib.h>
#include<gtk/gtk.h>


detail getinfo(char nom[])
{
	detail utilisateur;
	FILE *f;
	f=fopen("src/data/users.txt","r");
	while(fscanf(f,"%s %s %s %d %s %s %d %s %s %s %d %d",utilisateur.cin,utilisateur.user,utilisateur.pass,&utilisateur.role,utilisateur.nom,utilisateur.prenom,&utilisateur.age,utilisateur.sexe,utilisateur.email,utilisateur.tel,&utilisateur.poid,&utilisateur.taill)!=EOF){
		if(!strcmp(utilisateur.user,nom)){
			return utilisateur;
			}
		}
}
void modifier_profil(detail new)
{
	detail profil;
	FILE *f,*tmp;
		f=fopen("src/data/users.txt","r");
	tmp=fopen("src/data/users.tmp","a+");
	while(fscanf(f,"%s %s %s %d %s %s %d %s %s %s %d %d",profil.cin,profil.user,profil.pass,&profil.role,profil.nom,profil.prenom,&profil.age,profil.sexe,profil.email,profil.tel,&profil.poid,&profil.taill)!=EOF){
	if(!strcmp(profil.cin,new.cin)){
		fprintf(tmp,"%s %s %s %d %s %s %d %s %s %s %d %d\n",new.cin,new.user,new.pass,new.role,new.nom,new.prenom,new.age,new.sexe,new.email,new.tel,new.tel,new.poid,new.taill);
}else
fprintf(tmp,"%s %s %s %d %s %s %d %s %s %s %d %d\n",profil.cin,profil.user,profil.pass,profil.role,profil.nom,profil.prenom,profil.age,profil.sexe,profil.email,profil.tel,profil.poid,profil.taill);
}
fclose(f);
fclose(tmp);
rename("src/data/users.tmp","src/data/users.txt");
}

 void afficher1 (GtkWidget *plistview){
	
enum { COL_DATE_DEBUT,
       COL_DATE_FIN,
       COL_TITRE,
       COL_DETAIL,
       NUM_COLS
      };
char titre[50],detail[50],date_debut[50],date_fin[50];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("src/even.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s %s",date_debut,date_fin,titre,detail)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_DATE_DEBUT, date_debut,
                          COL_DATE_FIN, date_fin,
		          COL_TITRE, titre,
			  COL_DETAIL,detail,
		          
		          		         
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("date_debut",celrender,"text",COL_DATE_DEBUT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("date_fin",celrender,"text",COL_DATE_FIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("titre",celrender,"text",COL_TITRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("detail",celrender,"text",COL_DETAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);

}
void afficher_rdv (GtkWidget *plistview){
	
enum { COL_JOUR,
       COL_MOIS,
       COL_ANNEE,
       COL_HEURE,
       COL_STAFF,
       COL_DETAIL,
       NUM_COLS,
      };
char heure[20],staff[50],detail[50];
int jour,mois,annee;
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("src/rdv.txt","r");
if(f!=NULL){
       while(fscanf(f,"%d %d %d %s %s %s",&jour,&mois,&annee,heure,staff,detail)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_JOUR, jour,
                          COL_MOIS, mois,
			  COL_ANNEE, annee,
		          COL_HEURE, heure,
		          COL_STAFF, staff,
			  COL_DETAIL,detail,
		          
		          		         
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour",celrender,"text",COL_JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois",celrender,"text",COL_MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("annee",celrender,"text",COL_ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("heure",celrender,"text",COL_HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("staff",celrender,"text",COL_STAFF,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("detail",celrender,"text",COL_DETAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);

}
void ajout_rdv1(rdv r)
{
FILE *f;

f=fopen("src/rdv.txt","a");

		
	
	
	fprintf(f,"%d %d %d %s %s %s \n",r.dt_rdv.jour,r.dt_rdv.mois,r.dt_rdv.annee,r.hr_rdv,r.staff_rdv,r.detail_rdv);
	
fclose(f);
}

void ajout_rdv2(rdv1 r)
{
FILE *f;

f=fopen("src/rdv1.txt","a");

		
	
	
	fprintf(f,"%s %s %s %d %d %d \n",r.staff_rdv1,r.hr_rdv1,&r.dt_rdv1.jour,&r.dt_rdv1.mois,&r.dt_rdv1.annee);
	
fclose(f);
}

/*void afficher_tableau_event(GtkWidget *plistview)
{ 
enum { COL_COACH,
       COL_TYPE,
       COL_HEURE,
       COL_JOUR,
       COL_MOIS,
       COL_ANNEE,
       NUM_COLS
      };
char coach[20],type[20],heure[20],jour[20],mois[20],annee[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("/home/sahar/Projets/projet1/src/seance.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s %s %s %s",coach,type,heure,jour,mois,annee)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_COACH, coach,
                          COL_TYPE, type,
			  COL_HEURE, heure,
		          COL_JOUR, jour,
		          COL_MOIS, mois,
		          COL_ANNEE, annee,
		          		         
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("coach",celrender,"text",COL_COACH,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("type",celrender,"text",COL_TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("heure",celrender,"text",COL_HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour",celrender,"text",COL_JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois",celrender,"text",COL_MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("annee",celrender,"text",COL_ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}*/

void afficher_tableau_event2(GtkWidget *plistview1)
{ 
enum { COL_STAFF,
       COL_HEURE,
       COL_JOUR,
       COL_MOIS,
       COL_ANNEE,
       NUM_COLS
      };
char staff[20],heure[20],jour[20],mois[20],annee[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("/home/gazgouz/Desktop/copie/MyGym/src/rdv1.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s %s %s",staff,heure,jour,mois,annee)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_STAFF, staff,
		          COL_HEURE, heure,
		          COL_JOUR, jour,
		          COL_MOIS, mois,
		          COL_ANNEE, annee,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("staff",celrender,"text",COL_STAFF,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview1),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("heure",celrender,"text",COL_HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview1),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour",celrender,"text",COL_JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview1),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois",celrender,"text",COL_MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview1),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("annee",celrender,"text",COL_ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview1),col);



	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview1), GTK_TREE_MODEL (liststore));

}
fclose(f);
}


void modifier1(char cin[],char prenom[],char nom[],char poids[],char login[],char sexe[],char mdps[],char age[],char taille[],int tel )
{    
char cin1[20];char prenom1[20];char nom1[20];char poids1[20];char login1[20];char sexe1[20];char mdps1[20];char age1[20];char taille1[20];
int tel1;
    FILE *f , *tmp;
    f=fopen("/home/gazgouz/Desktop/copie/MyGym/src/profil.txt","r");
    tmp=fopen("/home/gazgouz/Desktop/copie/MyGym/src/tmp.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d ",cin1,nom1,prenom1,poids1,login1,sexe1,mdps1,age1,taille1,&tel1)!=EOF){
        if(!strcmp(cin,cin1)){fprintf(tmp,"%s %s %s %s %s %s %s %s %s %d\n",cin1,nom1,prenom1,poids1,login1,sexe1,mdps1,age1,taille1,tel1);}
else fprintf(tmp,"%s %s %s %s %s %s %s %s %s %d \n",cin1,nom1,prenom1,poids1,login1,sexe1,mdps1,age1,taille1,tel1);
}
fclose(f);
fclose(tmp);
rename("/home/gazgouz/Desktop/copie/MyGym/src/tmp.txt","/home/gazgouz/Desktop/copie/MyGym/src/profil.txt");
}                 

void a_modifier1(char staff[],char heure[],int jour,int mois,int annee)
{    
char staff1[20]; char heure1[20];
int jour1, mois1,annee1;
    FILE *f , *tmp1;
    f=fopen("/home/gazgouz/Desktop/copie/MyGym/src/profil1.txt","r");
    tmp1=fopen("/home/gazgouz/Desktop/copie/MyGym/src/tmp1.txt","a+");
    while(fscanf(f,"%s %s %d %d %d ",staff1,heure1,&jour1,&mois1,&annee1)!=EOF){
        if(!strcmp(staff,staff1)){fprintf(tmp1,"%s %s %d %d %d\n",staff,heure,jour,mois,annee);}
else fprintf(tmp1,"%s %s %d %d %d \n",staff1,heure1,jour1,mois1,annee1);
}
fclose(f);
fclose(tmp1);
rename("src/tmp1.txt","src/profil.txt");
}             


 void supprimer1(int jour,int mois,int annee,char heure[],char staff[],char detail[])
{    
   char heure1[20]; char staff1[20]; char detail1[20];
   int jour1 ; int mois1 ; int annee1; 
    FILE *f , *tmp;
    f=fopen("src/rdv.txt","r");
    tmp=fopen("src/tmp.txt","a+");
    while(fscanf(f,"%d %d %d %s %s %s ",&jour1,&mois1,&annee1,heure1,staff1,detail1)!=EOF){
        if(!strcmp(jour,jour1)) {continue;}
else fprintf(tmp,"%d %d %d %s %s %s \n",jour1,mois1,annee1,heure1,staff1,detail1);
}
fclose(f);
fclose(tmp);
rename("src/tmp.txt","src/rdv.txt");
}           

/*void a_supprimer1(char staff[],char type[],char heure[],char jour[],char mois[],char annee[])
{    
   char staff1[20];char type1[20];char heure1[20];char jour1[20];char mois1[20];char annee1[20];
    FILE *f , *tmp1;
    f=fopen("/home/sahar/Projets/projet1/src/seance1.txt","r");
    tmp1=fopen("/home/sahar/Projets/projet1/src/tmp1.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s ",staff1,type1,heure1,jour1,mois1,annee1)!=EOF){
        if(!strcmp(staff,staff1)) {continue;}
else fprintf(tmp1,"%s %s %s %s %s %s \n",staff1,type1,heure1,jour1,mois1,annee1);
}
fclose(f);
fclose(tmp1);
rename("/home/sahar/Projets/projet1/src/tmp1.txt","/home/sahar/Projets/projet1/src/seance1.txt");
}*/                  



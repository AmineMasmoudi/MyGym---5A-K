#ifndef reservation_H_INCLUDED	
#define reservation_H_INCLUDED
#include "adherant.h"
#include <gtk/gtk.h>

typedef struct
{
int jour;
int mois;
int annee;

}Date;
typedef struct
{
char hr_rdv[50];
char staff_rdv[50];
char detail_rdv[50];
Date dt_rdv;

}rdv;

typedef struct
{
char hr_rdv1[50];
char staff_rdv1[50];
char detail_rdv1[50];
Date dt_rdv1;

}rdv1;
typedef struct
{
char cin[20];
char user[20];
char login[20];
char pass[20];
char nom[100];
char prenom[100];
char sexe[100];
char email[100];
char tel[100];
int role;
int taill;
int poid;
int age;
}detail;

void modifier_profil(detail new);
detail getinfo(char nom[]);
void afficher_rdv (GtkWidget *plistview);
void afficher1(GtkWidget *plistview);
void a_ajouter(char login[],char password[],int role);


int a_verification(char log[],char password[], char hello[]);


/*void a_affiche();*/

/*void afficher2(char nom[],char prenom[],char date[],char email[],char cin[],char adresse[],char poids[],char objectif[]);*/

void ajout_rdv1(rdv r);

void a_ajout_rdv2(rdv1 s);

void a_afficher_tableau_event(GtkWidget *plistview);

void a_afficher_tableau_event2(GtkWidget *plistview1);


void a_modifier(char staff[],char heure[],int jour,int mois,int annee);

void a_modifier1(char staff[],char heure[],int jour,int mois,int annee);

void a_supprimer1(int jour,int mois,int annee, char heure[], char staff [] , char detail[]);

/*void a_supprimer1(char staff[],char heure[],char jour[],char mois[],char annee[]);*/
#endif


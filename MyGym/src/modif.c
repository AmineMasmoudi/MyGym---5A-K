#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"modif.h"
#include<gtk/gtk.h>

//profil
void modifier_profil_adherant(char cin[],char nom[],char prenom[],char email[],char telephone[],char sexe[],int age[], int poids[],int taille[])
{
	char cina[20];char noma[20];char prenoma[20];char emaila[20];char telephonea[20];char sexea[20];
int agea,poidsa,taillea;
	FILE*f , *tmp;
	f=fopen("src/modif.txt","r");
	tmp=fopen("src/tmp.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %d %d %d",cina,noma,prenoma,emaila,telephonea,sexea,&agea,&poidsa,&taillea)!=EOF){
		if(!strcmp(cin,cina)){
			fprintf(tmp,"%s %s %s %s %s %s %d %d %d\n",cin,nom,prenom,email,telephone,sexe,age,poids,taille);
		}else
		fprintf(tmp,"%s %s %s %s %s %s %d %d %d\n",cina,noma,prenoma,emaila,telephonea,sexea,agea,poidsa,taillea);
	}
	fclose(f);
	fclose(tmp);
	rename("src/tmp.txt","src/modif.txt");
	}

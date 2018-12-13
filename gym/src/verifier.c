#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include "verifier.h"


int verifier (char log[], char pass[]){
FILE *f;
char Username[30]; char Password[30];int role;
f=fopen("users.txt","r");
rewind(f);
if(f!=NULL)
	{
 	 while((fscanf(f,"%s\n%s\n%d\n",Username,Password,&role)!=EOF))
	 	 if((strcmp(Username,log)==0)&&(strcmp(Password,pass)==0))return(role);
	 fclose(f);
	}
 else return(-1); 
}

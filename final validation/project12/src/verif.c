#include <stdio.h>
#include "verif.h"
#include <string.h>
int verifier (char login[],char password[])
 {
         FILE *h;
         char identifiant[20]; char mdp[20]; int role;
         h=fopen("/home/amine123/Downloads/project12/src/users.txt","r");
        if (h!=NULL)
     {
             while(fscanf(h,"%s %s %d \n",identifiant,mdp,&role)!=EOF)   
         {
           if ((strcmp(login,identifiant)==0)&&(strcmp(password,mdp)==0))
            {
            	return (role);
	    }
	}
     }   
	fclose(h);    
         
 	return(-1);
     
 }
 

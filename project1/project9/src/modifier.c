void supprimer_medicament(char desmd[10])
{ 	
	FILE*f ,*s;
    	medicament md;

    	f=fopen("medicament.txt","a+");
	    s=fopen("medicament.tmp.txt","a+");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement)!=EOF)
			{
    				if(strcmp(md.desmd1,desmd)!=0)
    				{	
						fprintf(s,"%s %s %s  %s \n",md.nommd1 ,md.desmd1,md.expmd1,md.typemed);

    				}
			}
			fclose(f);
			fclose(s);

			remove("medicament.txt");
			rename("medicament.tmp.txt","medicament.txt");


	}
}

/**********************************************************************************************/
void modifier_fiche(char designation[],Fiche fi)
{	
	FILE*f ,*s;

    	f=fopen("fiches.txt","a+");
	    s=fopen("fiches.tmp.txt","a+");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement)!=EOF)
			{
    				if(strcmp(fi.identifiant,designation)!=0)
    				{	
						fprintf(s,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement);

    				}
    				else{
					

    					fprintf(s,"%s %s %s %d %d %d %s %s %s %s %s %s  %s\n",fi.identifiant,fi.nom,fi.prenom,fi.jour,fi.mois,fi.annee,fi.adresse,fi.taille,fi.poids,fi.imc,fi.groupe_sanguin,fi.maladies,fi.traitement);
    				}
			}
			fclose(f);
			fclose(s);

			remove("fiches.txt");
			rename("fiches.tmp.txt","fiches.txt");

	}
}

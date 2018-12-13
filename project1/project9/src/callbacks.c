#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"espacemedecin.h"


void
on_button1_clicked(GtkWidget *objet_graphique, gpointer    user_data)
{
Fiche fi;
GtkWidget *treeview1;
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
GtkWidget *jour; //spinbuttun pour le choix du jour
GtkWidget *mois; //spinbuttun pour le choix du mois
GtkWidget *annee; //spinbuttun pour le choix de l’année
GtkWidget *combobox1;
GtkWidget *label34;
GtkWidget *espacemedecin;


espacemedecin=lookup_widget(objet_graphique,"espacemedecin");
combobox1=lookup_widget(objet_graphique,"combobox1");
input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
input3=lookup_widget(objet_graphique,"entry3");
input4=lookup_widget(objet_graphique,"entry4");
input5=lookup_widget(objet_graphique,"entry5");
input6=lookup_widget(objet_graphique,"entry6");
input7=lookup_widget(objet_graphique,"entry7");
input8=lookup_widget(objet_graphique,"entry8");
input9=lookup_widget(objet_graphique,"entry9");
label34=lookup_widget(objet_graphique,"label34");

strcpy(fi.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(fi.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(fi.poids,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(fi.imc,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(fi.maladies,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(fi.traitement,gtk_entry_get_text(GTK_ENTRY(input9)));

jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinbutton3");


fi.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
fi.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
fi.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

strcpy(fi.groupe_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

ajouter_fiche(fi);

gtk_label_set_text(GTK_LABEL(label34),"ajout réussit");

treeview1=lookup_widget(espacemedecin,"treeview1");
afficher_fiche(treeview1);
}



void
on_Modifier_clicked                    (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview1;
GtkWidget *entry10;
GtkWidget *entry11;
GtkWidget *entry12;
GtkWidget *entry14;
GtkWidget *entry15;
GtkWidget *entry16;
GtkWidget *entry17;
GtkWidget *entry19;
GtkWidget *entry20;
GtkWidget *entry22;
GtkWidget *label35;
GtkWidget *jour1; //spinbuttun pour le choix du jour
GtkWidget *mois1; //spinbuttun pour le choix du mois
GtkWidget *annee1; //spinbuttun pour le choix de l’
GtkWidget *combobox2;
Fiche f;
char ide[30];
combobox2=lookup_widget(objet_graphique,"combobox2");
label35=lookup_widget( objet_graphique, "label35");
entry22=lookup_widget(objet_graphique, "entry22");
entry10=lookup_widget(objet_graphique, "entry10");
entry11=lookup_widget(objet_graphique, "entry11");
entry12=lookup_widget(objet_graphique, "entry12");
entry14=lookup_widget(objet_graphique, "entry14");
entry15=lookup_widget(objet_graphique, "entry15");
entry16=lookup_widget(objet_graphique, "entry16");
entry17=lookup_widget(objet_graphique, "entry17");
entry19=lookup_widget(objet_graphique, "entry19");
entry20=lookup_widget(objet_graphique, "entry20");
strcpy(f.identifiant,gtk_entry_get_text(GTK_ENTRY(entry10)));
strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(entry11)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(entry12)));
strcpy(f.adresse,gtk_entry_get_text(GTK_ENTRY(entry14)));
strcpy(f.taille,gtk_entry_get_text(GTK_ENTRY(entry15)));
strcpy(f.poids,gtk_entry_get_text(GTK_ENTRY(entry16)));
strcpy(f.imc,gtk_entry_get_text(GTK_ENTRY(entry17)));
strcpy(f.maladies,gtk_entry_get_text(GTK_ENTRY(entry19)));
strcpy(f.traitement,gtk_entry_get_text(GTK_ENTRY(entry20)));
strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry22)));

jour1=lookup_widget(objet_graphique, "spinbutton4");
mois1=lookup_widget(objet_graphique, "spinbutton5");
annee1=lookup_widget(objet_graphique, "spinbutton6");


f.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
f.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
f.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));

strcpy(f.groupe_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

modifier_fiche(ide,f);
gtk_label_set_text(GTK_LABEL(label35),"fiche modifier");
treeview1=lookup_widget(objet_graphique,"treeview1");
afficher_fiche(treeview1);
}


void
on_Supprimer_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry21;
GtkWidget *treeview1;
char ide1[20];
Fiche fi;

entry21=lookup_widget(objet_graphique,"entry21");


strcpy(ide1,gtk_entry_get_text(GTK_ENTRY(entry21)));
suupprimer_fiche(ide1);

treeview1=lookup_widget(objet_graphique,"treeview1");
afficher_fiche(treeview1);

}


void
on_refresh_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *espacemedecin;
treeview1=lookup_widget(objet_graphique,"treeview1");
afficher_fiche(treeview1);
}


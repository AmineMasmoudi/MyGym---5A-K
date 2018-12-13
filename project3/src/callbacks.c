#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agenda.h"
#include "fiche.h"





void
on_button155_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window3;
window1=lookup_widget(objet_graphique,"window1");
	window3=create_window3();
	gtk_widget_show (window3);
        gtk_widget_hide(window1);
}


void
on_button355_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window5;

window1=lookup_widget(objet_graphique,"window1");
	window5=create_window5();
	gtk_widget_show (window5);
	gtk_widget_hide(window1);
}


void
on_button855_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window2;
window2=lookup_widget(objet_graphique,"window2");
	window5=create_window5();
	gtk_widget_show(window5);
	gtk_widget_hide(window2);
}


void
on_button1555_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Fiche fi;
GtkWidget  *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11;
GtkWidget *window3;
GtkWidget *jour; //spinbuttun pour le choix du jour
GtkWidget *mois; //spinbuttun pour le choix du mois
GtkWidget *annee; //spinbuttun pour le choix de l’année


window3=lookup_widget(objet_graphique,"window3");


input4=lookup_widget(objet_graphique,"entry155");
input5=lookup_widget(objet_graphique,"entry255");
input6=lookup_widget(objet_graphique,"entry455");
input7=lookup_widget(objet_graphique,"entry555");
input8=lookup_widget(objet_graphique,"entry655");
input9=lookup_widget(objet_graphique,"entry755");
input10=lookup_widget(objet_graphique,"entry1255");
input11=lookup_widget(objet_graphique,"entry1355");




strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(fi.poids,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(fi.taille,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(fi.imc,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(fi.regime_alimentaire,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(fi.remarques,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(fi.id,gtk_entry_get_text(GTK_ENTRY(input11)));


jour=lookup_widget(objet_graphique, "spinbutton155");
mois=lookup_widget(objet_graphique, "spinbutton255");
annee=lookup_widget(objet_graphique, "spinbutton355");

fi.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
fi.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
fi.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));

ajouter_fiche(fi);
}


void
on_button1655_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window4;
GtkWidget *treeview255;

window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
window4=lookup_widget(objet_graphique,"window4");
window4=create_window4();
	gtk_widget_show(window4);

treeview255=lookup_widget(window4,"treeview255");
afficher_fiche(treeview255);
}


void
on_button1255_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
GtkWidget *window3;
window4=lookup_widget(objet_graphique,"window4");
	window3=create_window3();
	gtk_widget_show (window3);
        gtk_widget_hide(window4);
}


void
on_button2155_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
GtkWidget *window7;
window4=lookup_widget(objet_graphique,"window4");
	window7=create_window7();
	gtk_widget_show (window7);
        gtk_widget_hide(window4);
}



void
on_button1855_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
GtkWidget *window6;
window4=lookup_widget(objet_graphique,"window4");
	window6=create_window6();
	gtk_widget_show (window6);
        gtk_widget_hide(window4);
}


void
on_button1355_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
agenda ag;
GtkWidget *input1, *input2, *input3;
GtkWidget *window5;

window5=lookup_widget(objet_graphique,"window5");
input1=lookup_widget(objet_graphique,"entry1155");
strcpy(ag.date,gtk_entry_get_text(GTK_ENTRY (input1)));
input2=lookup_widget(objet_graphique,"entry955");
strcpy(ag.taches,gtk_entry_get_text(GTK_ENTRY (input2)));
input3=lookup_widget(objet_graphique,"entry1055");
strcpy(ag.heure,gtk_entry_get_text(GTK_ENTRY (input3)));

ajouter_agenda(ag);
	
}


void
on_button1455_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window2;
GtkWidget *treeview155;


window5=lookup_widget(objet_graphique,"window5");
	gtk_widget_hide(window5);
window2=lookup_widget(objet_graphique,"window2");
window2=create_window2();
	gtk_widget_show(window2);
treeview155=lookup_widget(window2,"treeview155");
afficher_agenda(treeview155);
	
}


void
on_button1755_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry1455;
GtkWidget *label3956;

Fiche fi;
char id1[30];
label3956=lookup_widget( objet_graphique, "label3956");
entry1455=lookup_widget(objet_graphique,"entry1455");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry1455)));

supprimer_fiche(id1);
gtk_label_set_text(GTK_LABEL(label3956),"fiche supprimée");
}


void
on_button2055_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
GtkWidget *window7;
GtkWidget *treeview255;

window7=lookup_widget(objet_graphique,"window7");
	gtk_widget_hide(window7);
window4=lookup_widget(objet_graphique,"window4");
window4=create_window4();
	gtk_widget_show(window4);

treeview255=lookup_widget(window4,"treeview255");
afficher_fiche(treeview255);
}


void
on_button1955_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *entry1655;
GtkWidget *entry1755;
GtkWidget *entry1855;
GtkWidget *entry1955;
GtkWidget *entry2055;
GtkWidget *entry2155;
GtkWidget *entry1555;
GtkWidget *entry2355;
GtkWidget *entry2255;
GtkWidget *label3955;
GtkWidget *jour1; //spinbuttun pour le choix du jour
GtkWidget *mois1; //spinbuttun pour le choix du mois
GtkWidget *annee1; //spinbuttun pour le choix de l’

Fiche f;
char ide[30];
label3955=lookup_widget( objet_graphique, "label3955");
entry1555=lookup_widget(objet_graphique, "entry1555");
entry1655=lookup_widget(objet_graphique, "entry1655");
entry1755=lookup_widget(objet_graphique, "entry1755");
entry1855=lookup_widget(objet_graphique, "entry1855");
entry1955=lookup_widget(objet_graphique, "entry1955");
entry2055=lookup_widget(objet_graphique, "entry2055");
entry2155=lookup_widget(objet_graphique, "entry2155");
entry2355=lookup_widget(objet_graphique, "entry2355");
entry2255=lookup_widget(objet_graphique, "entry2255");

strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(entry1655)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(entry1755)));
strcpy(f.poids,gtk_entry_get_text(GTK_ENTRY(entry1855)));
strcpy(f.taille,gtk_entry_get_text(GTK_ENTRY(entry1955)));
strcpy(f.imc,gtk_entry_get_text(GTK_ENTRY(entry2055)));
strcpy(f.regime_alimentaire,gtk_entry_get_text(GTK_ENTRY(entry2155)));
strcpy(f.remarques,gtk_entry_get_text(GTK_ENTRY(entry2255)));
strcpy(f.id,gtk_entry_get_text(GTK_ENTRY(entry2355)));
strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry1555)));


jour1=lookup_widget(objet_graphique, "spinbutton455");
mois1=lookup_widget(objet_graphique, "spinbutton555");
annee1=lookup_widget(objet_graphique, "spinbutton655");


f.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
f.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
f.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));


modifier_fiche(ide,f);
gtk_label_set_text(GTK_LABEL(label3955),"fiche modifiée");
}


void
on_button2156_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window6;
GtkWidget *window4;
GtkWidget *treeview255;

window6=lookup_widget(objet_graphique,"window6");
	gtk_widget_hide(window6);
window4=lookup_widget(objet_graphique,"window4");
	window4=create_window4();
	gtk_widget_show(window4);

treeview255=lookup_widget(window4,"treeview255");
afficher_fiche(treeview255);
}


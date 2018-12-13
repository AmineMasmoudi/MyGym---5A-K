#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "coach.h"
#include "verif.h"
#include "medecin.h"
#include "nutritionniste.h"
#include "agenda.h"
#include "adherant.h" 
#include "avis.h"
#include "profil.h"
#include "interfacem.h"
#include "verifierm.h"
#include "Ajoutadherent.h"
#include "Coach.h"
#include "Medical.h"
#include "Site.h"

void
on_button877_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *coach;
GtkWidget *treeview177;
GtkWidget *entry377;
GtkWidget *combobox177;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *heure;
GtkWidget *cap;
GtkWidget *label4277;

Date dt_resr;
int i,n;

Reservationseance s;

// associÃ© les objets avec des variables
entry377=lookup_widget( objet_graphique, "entry377");
combobox177=lookup_widget( objet_graphique, "combobox177");
jour=lookup_widget( objet_graphique, "spinbutton177");
mois=lookup_widget( objet_graphique, "spinbutton277");
annee=lookup_widget(objet_graphique, "spinbutton377");
heure=lookup_widget ( objet_graphique, "spinbutton477");
cap=lookup_widget( objet_graphique, "spinbutton577");
label4277=lookup_widget( objet_graphique, "label4277");
// rÃ©cuperer les valeurs 

s.dt_res.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.dt_res.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.dt_res.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
s.dt_res.heure=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (heure));
s.cap=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (cap));
strcpy(s.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox177)));
strcpy(s.id,gtk_entry_get_text(GTK_ENTRY(entry377)));
reserver_seance(s);
 
gtk_label_set_text(GTK_LABEL(label4277),"seance ajouter.");
treeview177=lookup_widget(objet_graphique,"treeview177");
afficher_seance(treeview177);
}


void
on_button1077_clicked                 (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *coach;
GtkWidget *treeview177;
GtkWidget *combobox277;
GtkWidget *entry577;
GtkWidget *entry477;

GtkWidget *jour2;
GtkWidget *mois2;
GtkWidget *annee2;
GtkWidget *heure2;
GtkWidget *cap2;
GtkWidget *label2677;

Date dt_resr;
char ide[30];

Reservationseance n;

// associÃ© les objets avec des variab
combobox277=lookup_widget( objet_graphique, "combobox277");
jour2=lookup_widget( objet_graphique, "spinbutton677");
mois2=lookup_widget( objet_graphique, "spinbutton777");
annee2=lookup_widget(objet_graphique, "spinbutton877");
heure2=lookup_widget ( objet_graphique, "spinbutton977");
cap2=lookup_widget( objet_graphique, "spinbutton1077");
entry477=lookup_widget( objet_graphique, "entry477");
entry577=lookup_widget( objet_graphique, "entry577");
label2677=lookup_widget( objet_graphique, "label2677");
// rÃ©cuperer les valeurs 

n.dt_res.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour2));
n.dt_res.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois2));
n.dt_res.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee2));
n.dt_res.heure=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (heure2));
n.cap=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (cap2));
strcpy(n.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox277)));
strcpy(n.id,gtk_entry_get_text(GTK_ENTRY(entry577)));
strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry477)));
modifier_seance(ide,n);

gtk_label_set_text(GTK_LABEL(label2677),"seance modifier");
treeview177=lookup_widget(objet_graphique,"treeview177");
afficher_seance(treeview177);
}


void
on_button1277_clicked                  (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *coach;
GtkWidget *treeview177;
GtkWidget *entry677;
GtkWidget *label4877;
char ide1[20];
Reservationseance s;

entry677=lookup_widget(objet_graphique,"entry677");
label4877=lookup_widget( objet_graphique, "label4877");

strcpy(ide1,gtk_entry_get_text(GTK_ENTRY(entry677)));

supprimer_seance(ide1);
gtk_label_set_text(GTK_LABEL(label4877),"seance supprimer");
treeview177=lookup_widget(objet_graphique,"treeview177");
afficher_seance(treeview177);
}


void
on_Login_clicked                       (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *label34;
GtkWidget *window1;
GtkWidget *medecin;
GtkWidget *coach;
GtkWidget *Admin;
GtkWidget *adherant;
GtkWidget *nutritionniste;
GtkWidget *bienvenue;
char Username[20];
char Password[20];

input1=lookup_widget(objet_graphique,"entry1");
strcpy(Username,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"entry2");
strcpy(Password,gtk_entry_get_text(GTK_ENTRY(input2)));
label34=lookup_widget( objet_graphique, "label34");

 if (verifierm(Username, Password)==1)
{		
	window1=lookup_widget(objet_graphique,"window1");
	 coach=create_coach();
	 gtk_widget_show(coach);
	 gtk_widget_hide(window1);
}

else
if (verifierm(Username, Password)==2)
{		
	window1=lookup_widget(objet_graphique,"window1");
	 medecin=create_medecin();
	 gtk_widget_show(medecin);
	 gtk_widget_hide(window1);
}


else
if (verifierm(Username, Password)==3)
{		
	window1=lookup_widget(objet_graphique,"window1");
	 nutritionniste=create_nutritionniste();
	 gtk_widget_show(nutritionniste);
	 gtk_widget_hide(window1);
}

else
if (verifierm(Username, Password)==4)
{		
	window1=lookup_widget(objet_graphique,"window1");
	 adherant=create_adherant();
	 gtk_widget_show(adherant);
	 gtk_widget_hide(window1);


}
else
if (verifierm(Username, Password)==5)
{		
	window1=lookup_widget(objet_graphique,"window1");
	 bienvenue=create_bienvenue();
	 gtk_widget_show(bienvenue);
	 gtk_widget_hide(window1);
}

else
if (verifierm(Username, Password)==6)
{		
	window1=lookup_widget(objet_graphique,"window1");
	 Admin=create_Admin();
	 gtk_widget_show(Admin);
	 gtk_widget_hide(window1);


}

else
	gtk_label_set_text(GTK_LABEL (label34), "Error");





}


void
on_button266_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
Fiche fi;
GtkWidget *treeview166;
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
GtkWidget *jour; //spinbuttun pour le choix du jour
GtkWidget *mois; //spinbuttun pour le choix du mois
GtkWidget *annee; //spinbuttun pour le choix de l’année
GtkWidget *combobox166;
GtkWidget *label2466;
GtkWidget *medecin;


medecin=lookup_widget(objet_graphique,"medecin");
combobox166=lookup_widget(objet_graphique,"combobox166");
input1=lookup_widget(objet_graphique,"entry366");
input2=lookup_widget(objet_graphique,"entry466");
input3=lookup_widget(objet_graphique,"entry566");
input4=lookup_widget(objet_graphique,"entry666");
input5=lookup_widget(objet_graphique,"entry766");
input6=lookup_widget(objet_graphique,"entry866");
input7=lookup_widget(objet_graphique,"entry966");
input8=lookup_widget(objet_graphique,"entry1066");
input9=lookup_widget(objet_graphique,"entry1166");
label2466=lookup_widget(objet_graphique,"label2466");

strcpy(fi.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(fi.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(fi.poids,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(fi.imc,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(fi.maladies,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(fi.traitement,gtk_entry_get_text(GTK_ENTRY(input9)));

jour=lookup_widget(objet_graphique, "spinbutton166");
mois=lookup_widget(objet_graphique, "spinbutton266");
annee=lookup_widget(objet_graphique, "spinbutton366");


fi.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
fi.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
fi.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

strcpy(fi.groupe_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox166)));

ajouter_fiche(fi);

gtk_label_set_text(GTK_LABEL(label2466),"ajout réussit");

treeview166=lookup_widget(objet_graphique,"treeview166");
afficher_fiche(treeview166);
}


void
on_button566_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *medecin;
GtkWidget *treeview166;
GtkWidget *entry3066;
GtkWidget *label6366;
char ide1[20];
Fiche fi;

entry3066=lookup_widget(objet_graphique,"entry3066");
label6366=lookup_widget( objet_graphique, "label6366");

strcpy(ide1,gtk_entry_get_text(GTK_ENTRY(entry3066)));

suupprimer_fiche(ide1);
gtk_label_set_text(GTK_LABEL(label6366),"seance supprimer");
treeview166=lookup_widget(objet_graphique,"treeview166");
afficher_fiche(treeview166);
}


void
on_button466_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview166;
GtkWidget *medecin;
GtkWidget *entry2166;
GtkWidget *entry3166;
GtkWidget *entry2266;
GtkWidget *entry2366;
GtkWidget *entry2466;
GtkWidget *entry2566;
GtkWidget *entry2666;
GtkWidget *entry2766;
GtkWidget *entry2866;
GtkWidget *entry2966;
GtkWidget *label6066;
GtkWidget *jour1; //spinbuttun pour le choix du jour
GtkWidget *mois1; //spinbuttun pour le choix du mois
GtkWidget *annee1; //spinbuttun pour le choix de l’
GtkWidget *combobox366;
Fiche f;
char ide[30];
combobox366=lookup_widget(objet_graphique,"combobox366");
label6066=lookup_widget( objet_graphique, "label6066");
entry2166=lookup_widget(objet_graphique, "entry2166");
entry3166=lookup_widget(objet_graphique, "entry3166");
entry2266=lookup_widget(objet_graphique, "entry2266");
entry2366=lookup_widget(objet_graphique, "entry2366");
entry2466=lookup_widget(objet_graphique, "entry2466");
entry2566=lookup_widget(objet_graphique, "entry2566");
entry2666=lookup_widget(objet_graphique, "entry2666");
entry2766=lookup_widget(objet_graphique, "entry2766");
entry2866=lookup_widget(objet_graphique, "entry2866");
entry2966=lookup_widget(objet_graphique, "entry2966");
strcpy(f.identifiant,gtk_entry_get_text(GTK_ENTRY(entry3166)));
strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(entry2266)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(entry2366)));
strcpy(f.adresse,gtk_entry_get_text(GTK_ENTRY(entry2466)));
strcpy(f.taille,gtk_entry_get_text(GTK_ENTRY(entry2566)));
strcpy(f.poids,gtk_entry_get_text(GTK_ENTRY(entry2666)));
strcpy(f.imc,gtk_entry_get_text(GTK_ENTRY(entry2766)));
strcpy(f.maladies,gtk_entry_get_text(GTK_ENTRY(entry2866)));
strcpy(f.traitement,gtk_entry_get_text(GTK_ENTRY(entry2966)));
strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry2166)));

jour1=lookup_widget(objet_graphique, "spinbutton766");
mois1=lookup_widget(objet_graphique, "spinbutton866");
annee1=lookup_widget(objet_graphique, "spinbutton966");


f.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
f.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
f.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));

strcpy(f.groupe_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox366)));

modifier_fiche(ide,f);
gtk_label_set_text(GTK_LABEL(label6066),"fiche modifier");
treeview166=lookup_widget(objet_graphique,"treeview166");
afficher_fiche(treeview166);
}


void
on_button1278_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview166;
GtkWidget *medecin;
treeview166=lookup_widget(objet_graphique,"treeview166");
afficher_fiche(treeview166);
}


void
on_button1279_clicked                  (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview177;
GtkWidget *coach;
treeview177=lookup_widget(objet_graphique,"treeview177");
afficher_seance(treeview177);
}


void
on_button155_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
agenda ag;
GtkWidget *input1, *input2, *input3;
GtkWidget *nutritionniste;
GtkWidget *label6415;
GtkWidget *treeview155;

nutritionniste=lookup_widget(objet_graphique,"nutritionniste");
input1=lookup_widget(objet_graphique,"entry955");
strcpy(ag.date,gtk_entry_get_text(GTK_ENTRY (input1)));
input2=lookup_widget(objet_graphique,"entry1055");
strcpy(ag.taches,gtk_entry_get_text(GTK_ENTRY (input2)));
input3=lookup_widget(objet_graphique,"entry1155");
strcpy(ag.heure,gtk_entry_get_text(GTK_ENTRY (input3)));
label6415=lookup_widget(objet_graphique,"label6415");
treeview155=lookup_widget(objet_graphique,"treeview155");
ajouter_agenda(ag);
afficher_agenda(treeview155);
gtk_label_set_text(GTK_LABEL(label6415),"ajout réussit");
}


void
on_button455_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
fiche fi1;
GtkWidget  *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11;
GtkWidget *nutritionniste;
GtkWidget *jour; //spinbuttun pour le choix du jour
GtkWidget *mois; //spinbuttun pour le choix du mois
GtkWidget *annee; //spinbuttun pour le choix de l’année
GtkWidget *label3855;
GtkWidget *treeview144;
nutritionniste=lookup_widget(objet_graphique,"nutritionniste");
label3855=lookup_widget( objet_graphique, "label3855");
input11=lookup_widget(objet_graphique,"entry155");
input4=lookup_widget(objet_graphique,"entry355");
input5=lookup_widget(objet_graphique,"entry255");
input6=lookup_widget(objet_graphique,"entry455");
input7=lookup_widget(objet_graphique,"entry555");
input8=lookup_widget(objet_graphique,"entry655");
input9=lookup_widget(objet_graphique,"entry755");
input10=lookup_widget(objet_graphique,"entry855");


strcpy(fi1.id,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(fi1.nom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(fi1.prenom,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(fi1.poids,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(fi1.taille,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(fi1.imc,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(fi1.regime_alimentaire,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(fi1.remarques,gtk_entry_get_text(GTK_ENTRY(input10)));



jour=lookup_widget(objet_graphique, "spinbutton155");
mois=lookup_widget(objet_graphique, "spinbutton255");
annee=lookup_widget(objet_graphique, "spinbutton355");

fi1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
fi1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
fi1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));

ajouter_fiche1(fi1);
gtk_label_set_text(GTK_LABEL(label3855),"fiche ajoutée");
treeview144=lookup_widget(objet_graphique,"treeview144");
afficher_fiche1(treeview144);
}


void
on_button255_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *entry1255;
GtkWidget *entry1355;
GtkWidget *entry1455;
GtkWidget *entry1555;
GtkWidget *entry1655;
GtkWidget *entry1755;
GtkWidget *entry1855;
GtkWidget *entry1955;
GtkWidget *entry2055;
GtkWidget *treeview144;
GtkWidget *label3955;
GtkWidget *jour1; //spinbuttun pour le choix du jour
GtkWidget *mois1; //spinbuttun pour le choix du mois
GtkWidget *annee1; //spinbuttun pour le choix de l’

fiche f1;
char ide[30];
label3955=lookup_widget( objet_graphique, "label3955");
entry1455=lookup_widget(objet_graphique, "entry1455");
entry1555=lookup_widget(objet_graphique, "entry1555");
entry1655=lookup_widget(objet_graphique, "entry1655");
entry1755=lookup_widget(objet_graphique, "entry1755");
entry1855=lookup_widget(objet_graphique, "entry1855");
entry1955=lookup_widget(objet_graphique, "entry1955");
entry2055=lookup_widget(objet_graphique, "entry2055");
entry1255=lookup_widget(objet_graphique, "entry1255");
entry1355=lookup_widget(objet_graphique, "entry1355");

strcpy(f1.nom,gtk_entry_get_text(GTK_ENTRY(entry1455)));
strcpy(f1.prenom,gtk_entry_get_text(GTK_ENTRY(entry1555)));
strcpy(f1.poids,gtk_entry_get_text(GTK_ENTRY(entry1655)));
strcpy(f1.taille,gtk_entry_get_text(GTK_ENTRY(entry1755)));
strcpy(f1.imc,gtk_entry_get_text(GTK_ENTRY(entry1855)));
strcpy(f1.regime_alimentaire,gtk_entry_get_text(GTK_ENTRY(entry1955)));
strcpy(f1.remarques,gtk_entry_get_text(GTK_ENTRY(entry2055)));
strcpy(f1.id,gtk_entry_get_text(GTK_ENTRY(entry1255)));
strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry1355)));


jour1=lookup_widget(objet_graphique, "spinbutton455");
mois1=lookup_widget(objet_graphique, "spinbutton555");
annee1=lookup_widget(objet_graphique, "spinbutton655");


f1.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
f1.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
f1.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));


modifier_fiche1(ide,f1);
gtk_label_set_text(GTK_LABEL(label3955),"fiche modifiée");
treeview144=lookup_widget( objet_graphique, "treeview144");
afficher_fiche1(treeview144);
}


void
on_button355_clicked                   (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *entry2155;
GtkWidget *treeview144;
GtkWidget *label6418;

fiche fi1;
char id1[30];
label6418=lookup_widget( objet_graphique, "label6418");
entry2155=lookup_widget(objet_graphique,"entry2155");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry2155)));

supprimer_fiche1(id1);
gtk_label_set_text(GTK_LABEL(label6418),"fiche supprimée");
treeview144=lookup_widget(objet_graphique,"treeview144");
afficher_fiche1(treeview144);
}


void
on_button133_clicked                   (GtkWidget       *object_graphique, gpointer user_data)
{
GtkWidget *treeview133;
GtkWidget *adherant;
GtkWidget *entry133;
GtkWidget *label1833;
GtkWidget *combobox133;
GtkWidget *entry333;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *heure;


Reservationseance_ad sa;

// associÃ© les objets avec des variables
adherant=lookup_widget( object_graphique, "adherant");
entry133=lookup_widget( object_graphique, "entry133");
entry333=lookup_widget( object_graphique, "entry333");
combobox133=lookup_widget( object_graphique, "combobox133");
jour=lookup_widget( object_graphique, "spinbutton233");
mois=lookup_widget( object_graphique, "spinbutton333");
annee=lookup_widget(object_graphique, "spinbutton433");
heure=lookup_widget( object_graphique, "spinbutton133");
label1833=lookup_widget(object_graphique, "label1833");


// rÃ©cuperer les valeurs 
strcpy(sa.numero,gtk_entry_get_text(GTK_ENTRY(entry133)));
strcpy(sa.sujet,gtk_entry_get_text(GTK_ENTRY(entry333)));


sa.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
sa.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
sa.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
sa.heure=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (heure));
strcpy(sa.avec_qui,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox133)));

reserver_ad_seance(sa);
 
gtk_label_set_text(GTK_LABEL(label1833),"rendez_vous ajouter");
treeview133=lookup_widget(object_graphique,"treeview133");
afficher_seance_ad(treeview133);
}


void
on_button233_clicked                   (GtkWidget       *object_graphique, gpointer user_data)
{
GtkWidget *treeview133;
GtkWidget *adherant;
GtkWidget *entry433;
GtkWidget *label3033;
GtkWidget *combobox233;
GtkWidget *entry633;
GtkWidget *entry533;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *heure1;
char ide[30];
Reservationseance_ad na;



adherant=lookup_widget( object_graphique, "adherant");
entry433=lookup_widget( object_graphique, "entry433");
entry533=lookup_widget( object_graphique, "entry533");
entry633=lookup_widget( object_graphique, "entry633");
combobox233=lookup_widget( object_graphique, "combobox233");
jour1=lookup_widget( object_graphique, "spinbutton533");
mois1=lookup_widget( object_graphique, "spinbutton633");
annee1=lookup_widget(object_graphique, "spinbutton733");
heure1=lookup_widget( object_graphique, "spinbutton833");
label3033=lookup_widget(object_graphique, "label3033");

strcpy(na.numero,gtk_entry_get_text(GTK_ENTRY(entry533)));
strcpy(na.sujet,gtk_entry_get_text(GTK_ENTRY(entry633)));
strcpy(ide,gtk_entry_get_text(GTK_ENTRY(entry433)));


na.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
na.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
na.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));
na.heure=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (heure1));
strcpy(na.avec_qui,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox233)));

modifier_seance_ad(ide,na);
gtk_label_set_text(GTK_LABEL(label3033),"rendez_vous modifier");
treeview133=lookup_widget(object_graphique,"treeview133");
afficher_seance_ad(treeview133);
}


void
on_button333_clicked                   (GtkWidget       *object_graphique, gpointer user_data)
{
GtkWidget *treeview133;
GtkWidget *adherant;
GtkWidget *entry733;
GtkWidget *label8533;
char ide1[10];
Reservationseance_ad sa;
label8533=lookup_widget(object_graphique, "label8533");
entry733=lookup_widget(object_graphique,"entry733");


strcpy(ide1,gtk_entry_get_text(GTK_ENTRY(entry733)));
supprimer_seance_ad(ide1);
gtk_label_set_text(GTK_LABEL(label8533),"rendez_vous supprimer");
treeview133=lookup_widget(object_graphique,"treeview133");
afficher_seance_ad(treeview133);
}


void
on_button33433_clicked                 (GtkWidget       *object_graphique, gpointer user_data)
{
GtkWidget *treeview13433;
GtkWidget *adherant;
GtkWidget *entry73433;
GtkWidget *label86533;
GtkWidget *combobox23433;
GtkWidget *note;


avis_ad av;

adherant=lookup_widget( object_graphique, "adherant");
entry73433=lookup_widget( object_graphique, "entry73433");
combobox23433=lookup_widget( object_graphique, "combobox23433");
note=lookup_widget( object_graphique, "spinbutton83433");
label86533=lookup_widget(object_graphique, "label86533");

strcpy(av.remarque,gtk_entry_get_text(GTK_ENTRY(entry73433)));
strcpy(av.choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox23433)));
av.note=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (note));

reserver_ad_avis(av);

gtk_label_set_text(GTK_LABEL(label86533),"avis ajouter");
treeview13433=lookup_widget(object_graphique,"treeview13433");
afficher_avis_ad(treeview13433);
}


void
on_button33434_clicked                  (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview133;
GtkWidget *adherant;
treeview133=lookup_widget(objet_graphique,"treeview133");
afficher_seance_ad(treeview133);
}


void
on_button33435_clicked                 (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview13433;
GtkWidget *adherant;
treeview13433=lookup_widget(objet_graphique,"treeview13433");
afficher_seance_ad(treeview13433);
}


void
on_button33533_clicked                 (GtkWidget       *objet_graphique, gpointer user_data)
{
GtkWidget *treeview13533;
GtkWidget *adherant;
treeview13533=lookup_widget(objet_graphique,"treeview13533");
afficher_profil_ad(treeview13533);
}


void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_Adherents;
GtkWidget *Admin;
GtkWidget *treeview1;

Admin=lookup_widget(objet,"Admin");

treeview1=lookup_widget(Admin,"treeview1");

afficher_adherent(treeview1); 
}


void
on_button14_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview2;

Admin=lookup_widget(button,"Admin");

treeview2=lookup_widget(Admin,"treeview2");

afficher_coach(treeview2); 
}

void
on_button18_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview3;

Admin=lookup_widget(button,"Admin");

treeview3=lookup_widget(Admin,"treeview3");

afficher_med(treeview3); 
}


void
on_button20_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *output;
	char ID[50];

	input1=lookup_widget(button,"entry27");
	output=lookup_widget(button,"erreur1");

	strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(Verifier_Med(ID)==1)
	{
	Supprimer_Med(ID);	
	gtk_label_set_text(GTK_LABEL(output),"Staff Médical Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"ID n'existe pas");
	}
}


void
on_button19_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *combobox2;    
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *output;
	Medical M;


combobox1=lookup_widget(button, "combobox5");
combobox2=lookup_widget(button, "combobox6");


input1=lookup_widget(button,"entry27");
input2=lookup_widget(button,"entry23");
input3=lookup_widget(button,"entry24");
input4=lookup_widget(button,"entry26");
input5=lookup_widget(button,"entry25");

output=lookup_widget(button,"erreur1");



strcpy(M.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(M.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(M.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(M.num,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(M.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));




if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(M.sexe,"Homme");
else
strcpy(M.sexe,"Femme");

if(strcmp("Kinésithérapeute",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(M.role,"Kinésithérapeute");

else if(strcmp("Diéticien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(M.role,"Diéticien");

else
strcpy(M.role,"Médecin_Nutritioniste");

	if(Verifier_Med(M.ID)==0)
	{
	Ajouter_Med(M);
	gtk_label_set_text(GTK_LABEL(output),"Staff Médical Ajouté");
	}
	else
	{
	Supprimer_Med(M.ID);
	Ajouter_Med(M);
	gtk_label_set_text(GTK_LABEL(output),"Staff Médical Modifié");
	}
}

void
on_button21_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview4;

Admin=lookup_widget(button,"Admin");

treeview4=lookup_widget(Admin,"treeview4");

afficher_ev(treeview4); 

}


void
on_button23_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *output;
	char ID[50];

	input1=lookup_widget(button,"entry34");
	output=lookup_widget(button,"erreur2");

	strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(Verifier_Ev(ID)==1)
	{
	Supprimer_Ev(ID);	
	gtk_label_set_text(GTK_LABEL(output),"Evenement Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"Evenement n'existe pas");
	}
}


void
on_button24_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *output5;
	int A,AF,AH,C,M;
	char NbA[75];
	char NbAF[75];
	char NbAH[75];
	char NbC[75];
	char NbM[75];

A=Nbr_Adherent();

AF=Nbr_Adherent_F();

AH=Nbr_Adherent_H();

C=Nbr_Coach();

M=Nbr_Med();

snprintf( NbA, 75, "Nombre d'adhérents : %d", A );

snprintf( NbAF, 75, "Nombre de femmes : %d", AF );

snprintf( NbAH, 75, "Nombre d'hommes : %d", AH );

snprintf( NbC, 75, "Nombre de coaches : %d", C );

snprintf( NbM, 75, "Effectif Médical : %d", M );

output1=lookup_widget(button,"NB_A");
output2=lookup_widget(button,"NB_A_F");
output3=lookup_widget(button,"NB_A_H");
output4=lookup_widget(button,"NB_C");
output5=lookup_widget(button,"NB_M");

gtk_label_set_text(GTK_LABEL(output1),NbA);
gtk_label_set_text(GTK_LABEL(output2),NbAF);
gtk_label_set_text(GTK_LABEL(output3),NbAH);
gtk_label_set_text(GTK_LABEL(output4),NbC);
gtk_label_set_text(GTK_LABEL(output5),NbM);
}

void
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 
	GtkWidget *input7;

	GtkWidget *output2;

	Adherent A;
	char ID[50];



input7=lookup_widget(objet_graphique,"entry15");


output2=lookup_widget(objet_graphique,"erreur");




strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input7)));


	if(Verifier_Adherent(ID)==1)
	{
	Supprimer_Adherent(ID);	
	gtk_label_set_text(GTK_LABEL(output2),"Adhérent Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output2),"Adhérent n'existe pas");
	}


}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *combobox2;  
	GtkWidget *jour; 
	GtkWidget *mois; 
	GtkWidget *annee;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *output1;
	Adherent A;


combobox1=lookup_widget(objet_graphique, "combobox1");
combobox2=lookup_widget(objet_graphique, "combobox2");
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinbutton3");

input1=lookup_widget(objet_graphique,"entry3");
input2=lookup_widget(objet_graphique,"entry4");
input3=lookup_widget(objet_graphique,"entry5");
input4=lookup_widget(objet_graphique,"entry6");
input5=lookup_widget(objet_graphique,"entry7");
input6=lookup_widget(objet_graphique,"entry8");
input7=lookup_widget(objet_graphique,"entry15");

output1=lookup_widget(objet_graphique,"erreur");

A.datenaissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
A.datenaissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
A.datenaissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


strcpy(A.ID,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(A.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(A.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(A.num,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(A.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(A.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(A.poids,gtk_entry_get_text(GTK_ENTRY(input6)));




if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(A.sexe,"Homme");
else
strcpy(A.sexe,"Femme");

if(strcmp("3 Mois",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(A.abonnement,"3_mois");
else if(strcmp("6 Mois",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(A.abonnement,"6_mois");
else
strcpy(A.abonnement,"1_année");


if(atoi(A.taille)<50 || atoi(A.taille)>999)
	gtk_label_set_text(GTK_LABEL(output1),"Valeur Incorrecte");

else if(atoi(A.poids)<10 || atoi(A.poids)>999)
	gtk_label_set_text(GTK_LABEL(output1),"Valeur Incorrecte");

else {
	if(Verifier_Adherent(A.ID)==0)
	{
	Ajouter_Adherent(A);
	gtk_label_set_text(GTK_LABEL(output1),"Adhérent Ajouté");
	}
	else
	{
	Supprimer_Adherent(A.ID);
	Ajouter_Adherent(A);
	gtk_label_set_text(GTK_LABEL(output1),"Adhérent Modifié");
	}
     }
}



void
on_button17_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{ 
	GtkWidget *input1;
	GtkWidget *output;
	char ID[50];

	input1=lookup_widget(button,"entry22");
	output=lookup_widget(button,"erreur3");

	strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(Verifier_Coach(ID)==1)
	{
	Supprimer_Coach(ID);	
	gtk_label_set_text(GTK_LABEL(output),"Coach Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"Coach n'existe pas");
	}

}
void
on_button16_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;  
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *output;
	Coach C;


combobox1=lookup_widget(button, "combobox4");


input1=lookup_widget(button,"entry22");
input2=lookup_widget(button,"entry16");
input3=lookup_widget(button,"entry17");
input4=lookup_widget(button,"entry19");
input5=lookup_widget(button,"entry18");

output=lookup_widget(button,"erreur3");



strcpy(C.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(C.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(C.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(C.num,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(C.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));




if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(C.sexe,"Homme");
else
strcpy(C.sexe,"Femme");

	if(Verifier_Coach(C.ID)==0)
	{
	Ajouter_Coach(C);
	gtk_label_set_text(GTK_LABEL(output),"Coach Ajouté");
	}
	else
	{
	Supprimer_Coach(C.ID);
	Ajouter_Coach(C);
	gtk_label_set_text(GTK_LABEL(output),"Coach Modifié");
	}

}


void
on_button22_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *combobox;
	GtkWidget *output;
	GtkWidget *jour; 
	GtkWidget *mois; 
	GtkWidget *annee;
	Evenement E;

combobox=lookup_widget(button, "combobox8");

jour=lookup_widget(button, "spinbutton4");
mois=lookup_widget(button, "spinbutton5");
annee=lookup_widget(button, "spinbutton6");

input1=lookup_widget(button,"entry34");
input2=lookup_widget(button,"entry28");

output=lookup_widget(button,"erreur2");

strcpy(E.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(input2)));

E.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
E.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
E.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(strcmp("Offre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
strcpy(E.type,"Offre");

else if(strcmp("Cours_Spécial",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
strcpy(E.type,"Cours_Spécial");

else
strcpy(E.type,"Autre");

	if(Verifier_Ev(E.ID)==0)
	{
	Ajouter_Ev(E);
	gtk_label_set_text(GTK_LABEL(output),"Evenement Ajouté");
	}
	else
	{
	Supprimer_Ev(E.ID);
	Ajouter_Ev(E);
	gtk_label_set_text(GTK_LABEL(output),"Evenement Modifié");
	}
}


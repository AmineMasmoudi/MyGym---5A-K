#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "verifier.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "calendar.h"
#include "fichem.h"



void
on_button1_clicked                     (GtkWidget       *data,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *dialog;
GtkWidget *admin1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *login;
GtkWidget *bienvenue;
char Username[20];
char Password[20];

input1=lookup_widget(data,"entry1");
strcpy(Username,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(data,"entry2");
strcpy(Password,gtk_entry_get_text(GTK_ENTRY(input2)));
if (verifier(Username, Password)==1)
{		
	login=lookup_widget(data,"login");
	bienvenue=create_bienvenue();
	gtk_widget_show (bienvenue);
        gtk_widget_hide(login);
}
else if (verifier(Username, Password)==2)
{		
	login=lookup_widget(data,"login");
	admin1=create_admin1();
	gtk_widget_show (admin1);
        gtk_widget_hide(login);
}
else
{

  dialog = gtk_message_dialog_new(GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Error le mot de passe est incorrect ");
  gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);

}
}

void
on_calendar1_day_selected_double_click (GtkWidget     *calendar,
                                        gpointer         user_data)
{
  GtkWidget *bienvenue;
  GtkWidget *window2;
  GtkWidget *calendar1;
  int year,month,day;
  GtkWidget *jour;
  GtkWidget *mois;
  GtkWidget *annee;
bienvenue=lookup_widget(calendar,"bienvenue");
gtk_widget_hide(bienvenue);
calendar1=lookup_widget(calendar,"calendar1");
gtk_calendar_get_date(GTK_CALENDAR (calendar1),&year,&month,&day);
window2=create_window2();
jour=lookup_widget(window2, "spinbutton4");
mois=lookup_widget(window2, "spinbutton5");
annee=lookup_widget(window2, "spinbutton6");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),day);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),month);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),year);
gtk_widget_show_all(window2);
}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox3;
GtkWidget *combobox5;
GtkWidget *label28;
GtkWidget *combobox8;
calendar s;

combobox3=lookup_widget(objet_graphique, "combobox3");
label28=lookup_widget(objet_graphique, "label28");
jour=lookup_widget(objet_graphique, "spinbutton4");
mois=lookup_widget(objet_graphique, "spinbutton5");
annee=lookup_widget(objet_graphique, "spinbutton6");
combobox8=lookup_widget(objet_graphique, "combobox8");
combobox5=lookup_widget(objet_graphique, "combobox5");

s.dt_res.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.dt_res.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.dt_res.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(strcmp("8",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=8;
if(strcmp("9",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=9;
if(strcmp("10",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=10;
if(strcmp("11",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=11;
if(strcmp("12",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=12;
if(strcmp("13",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=13;
if(strcmp("14",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=14;
if(strcmp("15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=15;
if(strcmp("16",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=16;
if(strcmp("17",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=17;
if(strcmp("18",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
s.hr_resr=18;

if(strcmp("8",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=8;
if(strcmp("9",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=9;
if(strcmp("10",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=10;
if(strcmp("11",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=11;
if(strcmp("12",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=12;
if(strcmp("13",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=13;
if(strcmp("14",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=14;
if(strcmp("15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=15;
if(strcmp("16",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=16;
if(strcmp("17",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=17;
if(strcmp("18",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)))==0) 
s.hr_resrf=18;



strcpy(s.num,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)));

reserver(s);


gtk_label_set_text(GTK_LABEL(label28),"Événement ajouter.");
}

/*add in interface
	g_signal_connect(window2, "destroy",
	G_CALLBACK(gtk_back_bienvenue), NULL); 
*/
void
gtk_back_bienvenue                     (GtkWidget       *back,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *bienvenue;


	bienvenue=create_bienvenue();
	gtk_widget_show (bienvenue);
        
}
void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *treeview1;
GtkWidget *bienvenue;
GtkWidget *notebook1;

window2=lookup_widget(objet,"window2");
gtk_widget_hide(window2);
bienvenue=create_bienvenue();
gtk_widget_show (bienvenue);
notebook1=lookup_widget(bienvenue,"notebook1");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1),2);
treeview1=lookup_widget(bienvenue,"treeview1");
afficher_event(treeview1); 
}


void on_combobox3_changed                   (GtkWidget     *combobox,
                                        gpointer         user_data)
{
GtkWidget *combobox3;
GtkWidget *combobox5;
int i;
combobox3=lookup_widget(combobox,"combobox3");
combobox5=lookup_widget(combobox,"combobox5");
if(strcmp("9",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("10",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0)
for(i=0;i<=1;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("11",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=2;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("12",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=3;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("13",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=4;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("14",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=5;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=6;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("16",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=7;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
if(strcmp("17",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0) 
for(i=0;i<=8;i++)
gtk_combo_box_remove_text(GTK_COMBO_BOX(combobox5),0);
}




void on_button8_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *notebook1;
  GtkWidget *bienvenue;
  GtkWidget *treeview1;
bienvenue=lookup_widget(button,"bienvenue");
treeview1=lookup_widget(button,"treeview1");
gchar *day=get_event2(treeview1);
gchar *month=get_event3(treeview1);
gchar *year=get_event4(treeview1);
gchar *deb=get_event5(treeview1);
gchar *fin=get_event6(treeview1);
gchar *even=get_event1(treeview1);
supprimer_calendar(atoi(day),atoi(month),atoi(year),atoi(deb),atoi(fin));
gtk_widget_hide(bienvenue);
bienvenue=create_bienvenue();
notebook1=lookup_widget(bienvenue,"notebook1");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1),2);
treeview1=lookup_widget(bienvenue,"treeview1");
afficher_event(treeview1);
gtk_widget_show(bienvenue);
}


/*ajouter*/
void on_button7_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *bienvenue;
  GtkWidget *window2;
bienvenue=lookup_widget(button,"bienvenue");
gtk_widget_hide(bienvenue);
window2=create_window2();
gtk_widget_show_all(window2);
}


void on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *combobox5;
  GtkWidget *combobox8;
  GtkWidget *combobox3;
  GtkWidget *bienvenue;
  GtkWidget *window2;
  GtkWidget *treeview1;
  GtkWidget *jour;
  GtkWidget *mois;
  GtkWidget *annee;
bienvenue=lookup_widget(button,"bienvenue");
treeview1=lookup_widget(button,"treeview1");
window2=create_window2();
jour=lookup_widget(window2, "spinbutton4");
mois=lookup_widget(window2, "spinbutton5");
annee=lookup_widget(window2, "spinbutton6");
combobox5=lookup_widget(window2, "combobox5");
combobox8=lookup_widget(window2, "combobox8");
combobox3=lookup_widget(window2, "combobox3");
gtk_widget_show_all(window2);
gchar *day=get_event2(treeview1);
gchar *month=get_event3(treeview1);
gchar *year=get_event4(treeview1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),atof(day));
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),atof(month));
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),atof(year));
gchar *deb=get_event5(treeview1);
gchar *fin=get_event6(treeview1);
gchar *even=get_event1(treeview1);
int x,y;
y=atoi(fin)-atoi(deb)-1;
x=atoi(deb)-8;
gtk_combo_box_set_active (GTK_COMBO_BOX(combobox3),x);
gtk_combo_box_set_active (GTK_COMBO_BOX(combobox5),y);
gtk_widget_hide(bienvenue);
supprimer_calendar(atoi(day),atoi(month),atoi(year),atoi(deb),atoi(fin));
}


void
on_ajoutad_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *admin1;
  GtkWidget *window3;
admin1=lookup_widget(button,"admin1");
gtk_widget_hide(admin1);
window3=create_window3();
gtk_widget_show(window3);
}



void
on_button17_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *treeview1;
GtkWidget *bienvenue;
GtkWidget *notebook1;

bienvenue=lookup_widget(button,"bienvenue");
gtk_widget_hide(bienvenue);
bienvenue=create_bienvenue();
gtk_widget_show (bienvenue);
notebook1=lookup_widget(bienvenue,"notebook1");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1),2);
treeview1=lookup_widget(bienvenue,"treeview1");
afficher_event(treeview1); 
}


void
on_button18m_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *login;
GtkWidget *bienvenue;	
	bienvenue=lookup_widget(button,"bienvenue");
	login=create_login();
	gtk_widget_show (login);
        gtk_widget_hide(bienvenue);
}





void
on_button19ms_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *bienvenue;
  GtkWidget *window4m;
  GtkWidget *treeview4m;
  GtkWidget *entry12mm;
  GtkWidget *jj1,*jj2,*jj3,*jj4,*jj5,*jj6,*jj7,*jj8,*jj9;	
bienvenue=lookup_widget(button,"bienvenue");
treeview4m=lookup_widget(button,"treeview4m");
window4m=create_window4m();
entry12mm=lookup_widget(window4m, "entry12mm");
jj1=lookup_widget(window4m, "jj1");
jj2=lookup_widget(window4m, "jj2");
jj3=lookup_widget(window4m, "jj3");
jj4=lookup_widget(window4m, "jj4");
jj5=lookup_widget(window4m, "jj5");
jj6=lookup_widget(window4m, "jj6");
jj7=lookup_widget(window4m, "jj7");
jj8=lookup_widget(window4m, "jj8");
jj9=lookup_widget(window4m, "jj9");
gtk_widget_show_all(window4m);
gchar *str=get_fichemr(treeview4m);
gchar *nom=get_fichemr1(treeview4m);
gchar *prenom=get_fichemr2(treeview4m);
gchar *jour=get_fichemr3(treeview4m);
gchar *mois=get_fichemr4(treeview4m);
gchar *annee=get_fichemr5(treeview4m);
gchar *poids=get_fichemr6(treeview4m);
gchar *taille=get_fichemr7(treeview4m);
gchar *imc=get_fichemr8(treeview4m);
gchar *maladies=get_fichemr9(treeview4m);
gtk_entry_set_text (GTK_ENTRY(entry12mm),str);
gtk_label_set_text(GTK_LABEL(jj1), nom);
gtk_label_set_text(GTK_LABEL(jj2), prenom);
gtk_label_set_text(GTK_LABEL(jj3), jour);
gtk_label_set_text(GTK_LABEL(jj4), mois);
gtk_label_set_text(GTK_LABEL(jj5), annee);
gtk_label_set_text(GTK_LABEL(jj6), poids);
gtk_label_set_text(GTK_LABEL(jj7), taille);
gtk_label_set_text(GTK_LABEL(jj8), imc);
gtk_label_set_text(GTK_LABEL(jj9), maladies);
gtk_widget_hide(bienvenue);
}


void
on_button18ms_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview4m;
GtkWidget *bienvenue;
GtkWidget *notebook1;

bienvenue=lookup_widget(button,"bienvenue");
gtk_widget_hide(bienvenue);
bienvenue=create_bienvenue();
gtk_widget_show (bienvenue);
notebook1=lookup_widget(bienvenue,"notebook1");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1),3);
treeview4m=lookup_widget(bienvenue,"treeview4m");
afficher_fichem(treeview4m); 
}


void
on_button18nb_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *notebook1;
  GtkWidget *bienvenue;
  GtkWidget *window4m;
  GtkWidget *treeview4m;
  GtkWidget *entry12mm;
  GtkWidget *jj1,*jj2,*jj3,*jj4,*jj5,*jj6,*jj7,*jj8,*jj9;
  fiche s;	
window4m=lookup_widget(button,"window4m");
entry12mm=lookup_widget(window4m, "entry12mm");
jj1=lookup_widget(window4m, "jj1");
jj2=lookup_widget(window4m, "jj2");
jj3=lookup_widget(window4m, "jj3");
jj4=lookup_widget(window4m, "jj4");
jj5=lookup_widget(window4m, "jj5");
jj6=lookup_widget(window4m, "jj6");
jj7=lookup_widget(window4m, "jj7");
jj8=lookup_widget(window4m, "jj8");
jj9=lookup_widget(window4m, "jj9");
strcpy(s.nom,gtk_label_get_text(GTK_LABEL(jj1)));
strcpy(s.prenom,gtk_label_get_text(GTK_LABEL(jj2)));
s.naissance.jour=atoi(gtk_label_get_text(GTK_LABEL(jj3)));
s.naissance.mois=atoi(gtk_label_get_text(GTK_LABEL(jj4)));
s.naissance.annee=atoi(gtk_label_get_text(GTK_LABEL(jj5)));
s.poids=atoi(gtk_label_get_text(GTK_LABEL(jj6)));
s.taille=atoi(gtk_label_get_text(GTK_LABEL(jj7)));
s.imc=atoi(gtk_label_get_text(GTK_LABEL(jj8)));
strcpy(s.maladies,gtk_label_get_text(GTK_LABEL(jj9)));
strcpy(s.remarques,gtk_entry_get_text (GTK_ENTRY(entry12mm)));
supprimer_fichemr(s.poids);
createfichem(s);
bienvenue=create_bienvenue();
gtk_widget_show (bienvenue);
notebook1=lookup_widget(bienvenue,"notebook1");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1),3);
treeview4m=lookup_widget(bienvenue,"treeview4m");
afficher_fichem(treeview4m);

}


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include"adherant.h"



void
on_login_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data)
{
        GtkWidget *user_d;
        GtkWidget *pass_d;
        GtkWidget *status_d;
        GtkWidget *text_lbl;
        GtkWidget *admin;
        GtkWidget *kine;
        GtkWidget *coach;
        GtkWidget *adherant;
        GtkWidget *medecin;
        GtkWidget *diet;
        GtkWidget *current;
GtkWidget *a1;
GtkWidget *b1;
GtkWidget *c1;
GtkWidget *d1;
GtkWidget *e1;
GtkWidget *f1;
GtkWidget *g1;

        char user[20],pass[20],status[20];
        int role;
        current = lookup_widget(graphic,"authentification");
        user_d = lookup_widget(graphic,"login_auth");
        pass_d = lookup_widget(graphic,"pass_auth");
        status_d = lookup_widget(graphic,"status");
        strcpy(user,gtk_entry_get_text(GTK_ENTRY(user_d)));
        strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pass_d)));
        role = verifier(user,pass,status);
        switch (role){
                case 0 :
                        gtk_label_set_text(GTK_LABEL(status_d),status);
                        break;
                case 1 :
                        admin = create_admin();
                        gtk_widget_show(admin);
                        gtk_widget_hide(current);
                        break;
                case 2 ://profil


                        adherant = create_adherant();
                        gtk_widget_show(adherant);
                        gtk_widget_hide(current);
FILE *fic;
a1=lookup_widget(adherant, "entry_cin_adherant");
b1=lookup_widget(adherant, "entry_nom_adherant");
c1=lookup_widget(adherant, "entry_prenom_adherant");
d1=lookup_widget(adherant, "entry_telephone_adherant");
e1=lookup_widget(adherant, "entry_poids_adherant");
f1=lookup_widget(adherant, "entry_adherant_mdps");
g1=lookup_widget(adherant, "entry_adherant_login");
char cin1[20];
char nom1[20];
char prenom1[20];
char telephone1[20];
char poids1[20];
char mdps1[20];
char login1[20];
fic=fopen("/home/gazgouz/Desktop/copie/MyGym/src/profil.txt","r");
fscanf(fic,"%s %s %s %s %s %s %s\n",cin1,nom1,prenom1,telephone1,poids1,mdps1,login1);
{	
fclose(fic);
gtk_entry_set_text(GTK_ENTRY(a1),cin1);
gtk_entry_set_text(GTK_ENTRY(b1),nom1);
gtk_entry_set_text(GTK_ENTRY(c1),prenom1);
gtk_entry_set_text(GTK_ENTRY(d1),telephone1);
gtk_entry_set_text(GTK_ENTRY(e1),poids1);
gtk_entry_set_text(GTK_ENTRY(f1),mdps1);
gtk_entry_set_text(GTK_ENTRY(g1),login1);}
			break;






                case 3 :
                        coach = create_bienvenue_coach();
                        gtk_widget_show(coach);
                        gtk_widget_hide(current);
                        break;
                case 4 :
                        diet = create_diet();
                        gtk_widget_show(diet);
                        gtk_widget_hide(current);
                        break;
                case 5 :
                        kine = create_bienvenue_kine();
                        gtk_widget_show(kine);
                        gtk_widget_hide(current);
                        break;
                case 6 :
                        medecin = create_bienvenue_medecin();
                        gtk_widget_show(medecin);
                        gtk_widget_hide(current);
                        break;
                default :
                        gtk_label_set_text(GTK_LABEL(status_d),status);
                        break;
        }
}



void
on_quitter_clicked                     (GtkWidget *graphic,
                                        gpointer         user_data)
{
        gtk_main_quit();
}


void
on_users_clicked                       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_staff_clicked                       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_events_clicked                      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_logout_admin_clicked                (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_users_list_row_activated            (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retour_userlist_admin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_supprimer_users_admin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modifier_users_admin_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_ajouter_users_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_annuler_users_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_annuler_users_del_clicked           (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_confirmer_users_del_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_filtre_staff_admin_changed          (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_biebutt_profil_coach_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbut_sean_coach_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbut_fich_coach_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbut_listedesadhe_coach_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbutt_retour_coach_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modif_prof_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_profil_coach_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_sean_coach_row_activated   (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_annul_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_ajout_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modif_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_suppr_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_sean_coach_clicked           (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_espace_kine_profile_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_dispo_espace_kine_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_seance_espace_kine_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour__espace_kine_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fiche_med_kine_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_profil_kine_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modifier_profil_kine_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_dispo_kine_row_activated   (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_annuler_rdv_kine_clicked     (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_rdv_kine_clicked     (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_modifier_rdv_kine_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_supprimer_rdv_kine_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_rdv_kine_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_fiche_med_kine_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_seance_kine_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bretour_listead_coach_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fiche_medicale_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_dispo_medecin_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_profil_medecin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_rendez_vous_medecin_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_profil_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_modifier_profil_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_dispo_medecin_row_activated
                                        (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_supp_dispo_medecin_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_modi_dispo_medecin_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_dispo_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_annuler_dispo_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_dispo_medecin_clicked (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_fiche_medecin_clicked (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_profil_espace_diet_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_dispo_espace_diet_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fm_espace_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_rdv_espace_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_espace_diet_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_supp_dispo_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ann_dispo_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_mod_dispo_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ajou_dispo_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_dispo_diet_row_activated   (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_retour_dispo_diet_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_rdv_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_fal_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_profil_diet_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_buttonmod_profil_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_modifier_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{
GtkWidget *adherant , *modification_profil_adherant;
      modification_profil_adherant=create_modification_profil_adherant();
      gtk_widget_show(modification_profil_adherant);
      adherant=lookup_widget(graphic,"adherant");
      gtk_widget_hide(adherant);
}


void
on_button_adherant_rendezvous_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{
GtkWidget *espace_medicale , *ajout_rdv,*List_View;
      ajout_rdv=create_ajout_rdv();
      gtk_widget_show(ajout_rdv);
      espace_medicale=lookup_widget(graphic,"espace_medicale");
      List_View=lookup_widget(ajout_rdv,"treeview_adherant_ajoutrdv");
      gtk_widget_hide(espace_medicale);
      afficher_rdv(List_View);
      gtk_widget_show(ajout_rdv);
      
}


void
on_combobox_choix_staff_changed        (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_combobox7_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_button_adherant_retour_clicked      (GtkWidget    *graphic,
                                        gpointer         user_data)
{
GtkWidget *espace_medicale , *adherant;
      adherant=create_adherant();
      gtk_widget_show(adherant);
      espace_medicale=lookup_widget(graphic,"espace_medicale");
      gtk_widget_hide(espace_medicale);
}


void
on_button_adherant_valider_clicked     (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *staff;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *heure;
GtkWidget *detail;
GtkWidget *rendez_vous;
GtkWidget *ajout_rdv;
GtkWidget *List_view;
rdv r;


jour=lookup_widget(objet_graphique, "spinbutton_date_rdv_adherant_jour");
mois=lookup_widget(objet_graphique, "spinbutton_date_rdv_adherant_mois");
annee=lookup_widget(objet_graphique, "spinbutton_date_rdv_adherant_annee");

heure=lookup_widget(objet_graphique, "combobox_heure_rdv_adherant");
staff=lookup_widget(objet_graphique, "combobox_rdv_adherant_avec");
detail=lookup_widget(objet_graphique,"entry_adherant_detail");

r.dt_rdv.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
r.dt_rdv.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
r.dt_rdv.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


strcpy(r.hr_rdv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)));

strcpy(r.staff_rdv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(staff)));
strcpy(r.detail_rdv,gtk_entry_get_text(GTK_ENTRY(detail)));


ajout_rdv1( r);

rendez_vous= lookup_widget(objet_graphique,"rendez_vous");
ajout_rdv=create_ajout_rdv();
gtk_widget_hide(rendez_vous);
List_view=lookup_widget(ajout_rdv,"treeview_adherant_ajoutrdv");
afficher_rdv(List_view);
gtk_widget_show(ajout_rdv);

}
void
on_treeview_adherant_evennement_row_activated
                                        (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*GtkWidget *joura,*moisa,*annea,*heurea,*ntel,*adherant,*evennements,*List_View;
int *jour,*mois,*annee,*heure,*ntel;
List_View=lookup_widget(objet_graphique,"treeview_adherant_evennement");
adherant=lookup_widget(objet_graphique,"adherant");
evennements=create_evennements();
joura=*/
}


void
on_button_adherant_evennement_retour_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{
GtkWidget *evennements , *adherant;
      adherant=create_adherant();
      gtk_widget_show(adherant);
      evennements=lookup_widget(graphic,"evennements");
      gtk_widget_hide(evennements);
}


void
on_button_adherant_les_evennement_retour_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{
GtkWidget *affichage_evennement , *evennements;
      evennements=create_evennements();
      gtk_widget_show(evennements);
      affichage_evennement=lookup_widget(graphic,"affichage_evennement");
      gtk_widget_hide(affichage_evennement);
}


void
on_retour_fich_coach_clicked           (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fa_espace_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_staff_list_row_activated            (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_supprimer_staff_admin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modifier_staff_admin_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_ajouter_staff_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_annuler_staff_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_stafflist_admin_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_supp_rdv_clicked    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *staff;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *heure;
GtkWidget *detail;
GtkWidget *rendez_vous;
GtkWidget *ajout_rdv;
GtkWidget *List_view;
rdv1 r;
char heure1[20]=""; char staff1[20]; char detail1[20];
int jour1 , mois1 , annee1;
    heure=lookup_widget(objet_graphique,"combobox_heure_rdv_adherant");
    staff=lookup_widget(objet_graphique,"combobox_rdv_adherant_avec");
    detail=lookup_widget(objet_graphique,"entry_adherant_detail");
    jour=lookup_widget(objet_graphique,"spinbutton_date_rdv_adherant_jour");
    mois=lookup_widget(objet_graphique,"spinbutton_date_rdv_adherant_mois");
    annee1=lookup_widget(objet_graphique,"spinbutton_date_rdv_adherant_annee");
strcpy(r.staff_rdv1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(staff)));
r.dt_rdv1.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
r.dt_rdv1.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
r.dt_rdv1.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(r.hr_rdv1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)));
strcpy(r.detail_rdv1,gtk_entry_get_text(GTK_ENTRY(detail)));
supprimer1(r.dt_rdv1.jour,r.dt_rdv1.mois,r.dt_rdv1.annee,r.hr_rdv1,r.staff_rdv1,r.detail_rdv1);
rendez_vous= lookup_widget(objet_graphique,"rendez_vous");
ajout_rdv=create_ajout_rdv();
gtk_widget_hide(rendez_vous);
List_view=lookup_widget(ajout_rdv,"treeview_adherant_ajoutrdv");
afficher_rdv(List_view);
gtk_widget_show(ajout_rdv);
}


void
on_button_adherant_afficher_evennement_clicked
                                        (GtkWidget      *graphic,
                                        gpointer         user_data)
{
GtkWidget *adherant , *evennements, *List_View;
      evennements=create_evennements();
      gtk_widget_show(evennements);
      adherant=lookup_widget(graphic,"adherant");
	List_View=lookup_widget(evennements,"treeview_adherant_evennement");
      gtk_widget_hide(adherant);
      afficher1(List_View);
	gtk_widget_show(evennements);

}


void
on_button_adherant_suivre_fiche_clicked
                                        (GtkWidget       *graphic,
                                        gpointer         user_data)
{
GtkWidget *adherant , *espace_medicale;
      espace_medicale=create_espace_medicale();
      gtk_widget_show(espace_medicale);
      adherant=lookup_widget(graphic,"adherant");
      gtk_widget_hide(adherant);
}






void
on_button_adherant_quitter_clicked     (GtkWidget       *graphic,
                                        gpointer         user_data)
{
GtkWidget *adherant , *current,*adherant_lbl,*nom;
char user[20];
      current=lookup_widget(graphic,"adherant");
      adherant=create_adherant();
      adherant_lbl=lookup_widget(adherant,"label_bienv_adherant");
      nom=lookup_widget(current,"entry_adherant_login");
      gtk_label_set_text(GTK_LABEL(adherant_lbl),gtk_entry_get_text(GTK_ENTRY(nom)));	
      gtk_widget_show(adherant);
      gtk_widget_hide(current);
}


void
on_button_adherant_retour1_clicked      (GtkWidget      *graphic,
                                        gpointer         user_data)
{
GtkWidget *rendez_vous , *espace_medicale;
      espace_medicale=create_espace_medicale();
      gtk_widget_show(espace_medicale);
      rendez_vous=lookup_widget(graphic,"rendez_vous");
      gtk_widget_hide(rendez_vous);
}


void
on_button8_clicked                     (GtkWidget      *graphic,
                                        gpointer         user_data)
{
/*GtkWidget *ajout_rendez_vous , *rendez_vous,*List_View;
      rendez_vous=create_rendez_vous();
      gtk_widget_show(rendez_vous);
      ajout_rendez_vous=lookup_widget(graphic,"ajout_rendez_vous");
      gtk_widget_hide(ajout_rendez_vous);*/

}


void
on_button7_clicked                     (GtkWidget      *graphic,
                                        gpointer         user_data)
{
/*GtkWidget *ajout_rendez_vous , *espace_medicale;
      espace_medicale=create_espace_medicale();
      gtk_widget_show(espace_medicale);
      ajout_rendez_vous=lookup_widget(graphic,"ajout_rendez_vous");
      gtk_widget_destroy(ajout_rendez_vous);*/
}


void
on_button_adherant_retour2_clicked     (GtkWidget       *graphic,
                                        gpointer         user_data)
{
GtkWidget *ajout_rdv , *espace_medicale;
espace_medicale=create_espace_medicale();
      gtk_widget_show(espace_medicale);
      ajout_rdv=lookup_widget(graphic,"ajout_rdv");
      gtk_widget_hide(ajout_rdv);
}


void
on_button_adherant_ajout1_clicked      (GtkWidget       *graphic,
                                        gpointer         user_data)
{
GtkWidget *ajout_rdv , *rendez_vous,*List_View;
      rendez_vous=create_rendez_vous();
      gtk_widget_show(rendez_vous);
      ajout_rdv=lookup_widget(graphic,"ajout_rdv");
      gtk_widget_hide(ajout_rdv);
}


void
on_treeview_adherant_ajoutrdv_row_activated
                                        (GtkWidget     *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *jour1,*mois1,*annee1,*heure1,*staff1,*detail1,*ajout_rdv,*rendez_vous,*List_View,*treeview_adherant_ajoutrdv;
    char staff[20],detail[20],heure[20];
    int jour,mois,annee;
    rendez_vous=create_rendez_vous();
    List_View=lookup_widget(graphic,"treeview_adherant_ajoutrdv");
    /*ajout_rdv=lookup_widget(objet_graphique,"ajout_rdv");*/
    staff1=lookup_widget(rendez_vous,"combobox_rdv_adherant_avec");
    detail1=lookup_widget(rendez_vous,"entry_adherant_detail");
    heure1=lookup_widget(rendez_vous,"combobox_heure_rdv_adherant");
    jour1=lookup_widget(rendez_vous,"spinbutton_date_rdv_adherant_jour");
    mois1=lookup_widget(rendez_vous,"spinbutton_date_rdv_adherant_mois");
    annee1=lookup_widget(rendez_vous,"spinbutton_date_rdv_adherant_annee");
    treeview_adherant_ajoutrdv=lookup_widget(graphic,"treeview_adherant_ajoutrdv");
    GtkTreeIter iter;
    GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(graphic,"treeview_adherant_ajoutrdv")));
    gtk_tree_model_get_iter(model,&iter,path);
    gtk_tree_model_get (model,&iter,0,&staff,1,&detail,2,&heure,3,&jour,4,&mois,5,&annee,-1);
    printf("%s %s %s %d %d %d\n",staff,detail,heure,jour,mois,annee);
    gtk_entry_set_text(GTK_ENTRY (staff1),_(staff));
    if(!strcmp(staff,"coach"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(staff1),0);
    if(!strcmp(staff,"kine"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(staff1),1);
    if(!strcmp(staff,"médecin"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(staff1),2);
    if(!strcmp(staff,"dieteticien"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(staff1),3);
    gtk_entry_set_text(GTK_ENTRY (detail1),_(detail));
    gtk_entry_set_text(GTK_ENTRY (heure1),_(heure));
    if(!strcmp(heure,"9h==>10h"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(heure1),4);
    if(!strcmp(heure,"10h==>11h"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(heure1),5);
    if(!strcmp(heure,"13h==>14h"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(heure1),6);
    if(!strcmp(heure,"14h==>15h"))
	gtk_combo_box_set_active(GTK_COMBO_BOX(heure1),7);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour1),(jour));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois1),(mois));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee1),(annee));
  
    gtk_widget_hide(ajout_rdv);
    gtk_widget_show(rendez_vous);
}


void
on_button_adherant_annuler_modif_clicked
                                        (GtkWidget      *graphic,
                                        gpointer         user_data)
{
GtkWidget *modification_profil_adherant , *adherant;
      adherant=create_adherant();
      gtk_widget_show(adherant);
      modification_profil_adherant=lookup_widget(graphic,"modification_profil_adherant");
      gtk_widget_hide(modification_profil_adherant);
}


void
on_button_adherant_appliquer_modif_clicked
                                        (GtkWidget       *graphic,
                                        gpointer         user_data)
{
GtkWidget *adherant,*modification_profil_adherant;
GtkWidget *cin,*nom,*prenom,*login,*pass,*email,*tel,*sexe,*sexeh,*age,*poid,*taille;
char logina[20];
GSList *radio;
detail profile;
cin=lookup_widget(graphic,"entry_adherant_modif_cin");
nom=lookup_widget(graphic,"entry_adherant_modif_nom");
prenom=lookup_widget(graphic,"entry_adherant_modif_prenom");
login=lookup_widget(graphic,"entry_adherant_modif_login");
pass=lookup_widget(graphic,"entry_adherant_modif_mdps");
email=lookup_widget(graphic,"entry_adherant_modif_mail");
tel=lookup_widget(graphic,"entry_adherant_modif_telephone");
sexe=lookup_widget(graphic,"radiobutton_homme_adherant");
sexeh=lookup_widget(graphic,"radiobutton_femme_adherant");
age=lookup_widget(graphic,"spinbutton_adherant_modif_age");
poid=lookup_widget(graphic,"entry_adherant_modif_poids");
taille=lookup_widget(graphic,"spinbutton_adherant_modif_taille");

strcpy(profile.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(profile.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(profile.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(profile.login,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(profile.pass,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(profile.email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(profile.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(profile.poid,gtk_entry_get_text(GTK_ENTRY(poid)));
profile.role=2;
profile.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));
profile.taill=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(taille));
radio=gtk_radio_button_get_group(GTK_RADIO_BUTTON(sexe));
g_print("%s\n",profile.sexe);
if(gtk_toggle_button_get_active(radio ->data))
	strcpy(profile.sexe,"homme");
else
	strcpy(profile.sexe,"femme");
modifier_profil(profile);
gtk_widget_show(adherant);
gtk_widget_hide(modification_profil_adherant);
}






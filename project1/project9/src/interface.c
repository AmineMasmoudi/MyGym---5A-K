/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_espacemedecin (void)
{
  GtkWidget *espacemedecin;
  GtkWidget *fixed1;
  GtkWidget *notebook1;
  GtkWidget *fixed2;
  GtkWidget *label7;
  GtkWidget *label8;
  GtkWidget *label9;
  GtkWidget *label10;
  GtkWidget *label16;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *entry5;
  GtkObject *spinbutton1_adj;
  GtkWidget *spinbutton1;
  GtkObject *spinbutton2_adj;
  GtkWidget *spinbutton2;
  GtkObject *spinbutton3_adj;
  GtkWidget *spinbutton3;
  GtkWidget *label15;
  GtkWidget *entry6;
  GtkWidget *entry7;
  GtkWidget *entry8;
  GtkWidget *label14;
  GtkWidget *label12;
  GtkWidget *label13;
  GtkWidget *entry9;
  GtkWidget *label18;
  GtkWidget *label17;
  GtkWidget *label11;
  GtkWidget *label6;
  GtkWidget *button1;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label19;
  GtkWidget *label34;
  GtkWidget *combobox1;
  GtkWidget *label5;
  GtkWidget *label1;
  GtkWidget *fixed3;
  GtkWidget *treeview1;
  GtkWidget *label20;
  GtkWidget *calendar1;
  GtkWidget *refresh;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label40;
  GtkWidget *label2;
  GtkWidget *fixed4;
  GtkWidget *entry10;
  GtkWidget *entry11;
  GtkWidget *entry12;
  GtkWidget *entry14;
  GtkWidget *entry15;
  GtkWidget *entry16;
  GtkWidget *entry17;
  GtkWidget *entry19;
  GtkWidget *entry20;
  GtkWidget *Modifier;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label32;
  GtkWidget *label35;
  GtkObject *spinbutton4_adj;
  GtkWidget *spinbutton4;
  GtkObject *spinbutton5_adj;
  GtkWidget *spinbutton5;
  GtkObject *spinbutton6_adj;
  GtkWidget *spinbutton6;
  GtkWidget *label27;
  GtkWidget *label26;
  GtkWidget *label29;
  GtkWidget *combobox2;
  GtkWidget *label25;
  GtkWidget *label28;
  GtkWidget *label24;
  GtkWidget *label22;
  GtkWidget *label21;
  GtkWidget *entry22;
  GtkWidget *label39;
  GtkWidget *label23;
  GtkWidget *label36;
  GtkWidget *label37;
  GtkWidget *label38;
  GtkWidget *label30;
  GtkWidget *label31;
  GtkWidget *label3;
  GtkWidget *fixed5;
  GtkWidget *label33;
  GtkWidget *entry21;
  GtkWidget *Supprimer;
  GtkWidget *label4;

  espacemedecin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (espacemedecin), _("espacemedecin"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (espacemedecin), fixed1);

  notebook1 = gtk_notebook_new ();
  gtk_widget_show (notebook1);
  gtk_fixed_put (GTK_FIXED (fixed1), notebook1, 0, 0);
  gtk_widget_set_size_request (notebook1, 832, 448);

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed2);

  label7 = gtk_label_new (_("Prenom"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed2), label7, 0, 104);
  gtk_widget_set_size_request (label7, 160, 40);

  label8 = gtk_label_new (_("Date de naissance"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed2), label8, 8, 160);
  gtk_widget_set_size_request (label8, 160, 40);

  label9 = gtk_label_new (_("Adresse"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixed2), label9, 8, 216);
  gtk_widget_set_size_request (label9, 160, 40);

  label10 = gtk_label_new (_("Taille:"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed2), label10, 8, 280);
  gtk_widget_set_size_request (label10, 160, 40);

  label16 = gtk_label_new (_("Mois:"));
  gtk_widget_show (label16);
  gtk_fixed_put (GTK_FIXED (fixed2), label16, 264, 168);
  gtk_widget_set_size_request (label16, 49, 17);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed2), entry1, 144, 0);
  gtk_widget_set_size_request (entry1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed2), entry2, 144, 56);
  gtk_widget_set_size_request (entry2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed2), entry3, 144, 112);
  gtk_widget_set_size_request (entry3, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_fixed_put (GTK_FIXED (fixed2), entry4, 144, 216);
  gtk_widget_set_size_request (entry4, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry4), 8226);

  entry5 = gtk_entry_new ();
  gtk_widget_show (entry5);
  gtk_fixed_put (GTK_FIXED (fixed2), entry5, 144, 280);
  gtk_widget_set_size_request (entry5, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry5), 8226);

  spinbutton1_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton1 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton1_adj), 1, 0);
  gtk_widget_show (spinbutton1);
  gtk_fixed_put (GTK_FIXED (fixed2), spinbutton1, 208, 168);
  gtk_widget_set_size_request (spinbutton1, 60, 27);

  spinbutton2_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton2 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton2_adj), 1, 0);
  gtk_widget_show (spinbutton2);
  gtk_fixed_put (GTK_FIXED (fixed2), spinbutton2, 312, 168);
  gtk_widget_set_size_request (spinbutton2, 60, 27);

  spinbutton3_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton3 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton3_adj), 1, 0);
  gtk_widget_show (spinbutton3);
  gtk_fixed_put (GTK_FIXED (fixed2), spinbutton3, 424, 168);
  gtk_widget_set_size_request (spinbutton3, 60, 27);

  label15 = gtk_label_new (_("Jour:"));
  gtk_widget_show (label15);
  gtk_fixed_put (GTK_FIXED (fixed2), label15, 160, 168);
  gtk_widget_set_size_request (label15, 49, 17);
  GTK_WIDGET_SET_FLAGS (label15, GTK_CAN_FOCUS);
  gtk_label_set_selectable (GTK_LABEL (label15), TRUE);

  entry6 = gtk_entry_new ();
  gtk_widget_show (entry6);
  gtk_fixed_put (GTK_FIXED (fixed2), entry6, 600, 8);
  gtk_widget_set_size_request (entry6, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry6), 8226);

  entry7 = gtk_entry_new ();
  gtk_widget_show (entry7);
  gtk_fixed_put (GTK_FIXED (fixed2), entry7, 600, 64);
  gtk_widget_set_size_request (entry7, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry7), 8226);

  entry8 = gtk_entry_new ();
  gtk_widget_show (entry8);
  gtk_fixed_put (GTK_FIXED (fixed2), entry8, 600, 168);
  gtk_widget_set_size_request (entry8, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry8), 8226);

  label14 = gtk_label_new (_("Maladies:"));
  gtk_widget_show (label14);
  gtk_fixed_put (GTK_FIXED (fixed2), label14, 464, 160);
  gtk_widget_set_size_request (label14, 160, 40);

  label12 = gtk_label_new (_("IMC"));
  gtk_widget_show (label12);
  gtk_fixed_put (GTK_FIXED (fixed2), label12, 456, 56);
  gtk_widget_set_size_request (label12, 160, 40);

  label13 = gtk_label_new (_("Groupe_sanguin:"));
  gtk_widget_show (label13);
  gtk_fixed_put (GTK_FIXED (fixed2), label13, 456, 112);
  gtk_widget_set_size_request (label13, 160, 40);
  GTK_WIDGET_SET_FLAGS (label13, GTK_CAN_FOCUS);
  gtk_label_set_selectable (GTK_LABEL (label13), TRUE);

  entry9 = gtk_entry_new ();
  gtk_widget_show (entry9);
  gtk_fixed_put (GTK_FIXED (fixed2), entry9, 600, 224);
  gtk_widget_set_size_request (entry9, 160, 120);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry9), 8226);

  label18 = gtk_label_new (_("Traitement:"));
  gtk_widget_show (label18);
  gtk_fixed_put (GTK_FIXED (fixed2), label18, 456, 216);
  gtk_widget_set_size_request (label18, 160, 40);

  label17 = gtk_label_new (_("Annee:"));
  gtk_widget_show (label17);
  gtk_fixed_put (GTK_FIXED (fixed2), label17, 376, 168);
  gtk_widget_set_size_request (label17, 49, 17);
  GTK_WIDGET_SET_FLAGS (label17, GTK_CAN_FOCUS);
  gtk_label_set_selectable (GTK_LABEL (label17), TRUE);

  label11 = gtk_label_new (_("Poids"));
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixed2), label11, 456, 0);
  gtk_widget_set_size_request (label11, 160, 40);

  label6 = gtk_label_new (_("Nom:"));
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixed2), label6, 0, 48);
  gtk_widget_set_size_request (label6, 160, 40);

  button1 = gtk_button_new ();
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed2), button1, 392, 312);
  gtk_widget_set_size_request (button1, 96, 32);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (button1), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label19 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label19);
  gtk_box_pack_start (GTK_BOX (hbox1), label19, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label19, 60, 78);
  GTK_WIDGET_SET_FLAGS (label19, GTK_CAN_FOCUS);
  gtk_label_set_selectable (GTK_LABEL (label19), TRUE);

  label34 = gtk_label_new ("");
  gtk_widget_show (label34);
  gtk_fixed_put (GTK_FIXED (fixed2), label34, 408, 352);
  gtk_widget_set_size_request (label34, 161, 32);

  combobox1 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox1);
  gtk_fixed_put (GTK_FIXED (fixed2), combobox1, 600, 112);
  gtk_widget_set_size_request (combobox1, 160, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("A+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("A-"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("B+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("B-"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("AB+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("AB-"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("O+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("O-"));

  label5 = gtk_label_new (_("Identifiant"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixed2), label5, 0, 0);
  gtk_widget_set_size_request (label5, 160, 40);

  label1 = gtk_label_new (_("Ajouter fiche medical"));
  gtk_widget_show (label1);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 0), label1);
  gtk_label_set_use_markup (GTK_LABEL (label1), TRUE);

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed3);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed3), treeview1, 0, 64);
  gtk_widget_set_size_request (treeview1, 520, 248);

  label20 = gtk_label_new (_("La fiche medical:"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed3), label20, 312, 0);
  gtk_widget_set_size_request (label20, 180, 70);

  calendar1 = gtk_calendar_new ();
  gtk_widget_show (calendar1);
  gtk_fixed_put (GTK_FIXED (fixed3), calendar1, 544, 104);
  gtk_widget_set_size_request (calendar1, 260, 184);
  gtk_calendar_display_options (GTK_CALENDAR (calendar1),
                                GTK_CALENDAR_SHOW_HEADING
                                | GTK_CALENDAR_SHOW_DAY_NAMES);

  refresh = gtk_button_new ();
  gtk_widget_show (refresh);
  gtk_fixed_put (GTK_FIXED (fixed3), refresh, 512, 368);
  gtk_widget_set_size_request (refresh, 112, 40);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (refresh), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label40 = gtk_label_new_with_mnemonic (_("refresh"));
  gtk_widget_show (label40);
  gtk_box_pack_start (GTK_BOX (hbox3), label40, FALSE, FALSE, 0);

  label2 = gtk_label_new (_("Afficher fiche medical"));
  gtk_widget_show (label2);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 1), label2);

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed4);

  entry10 = gtk_entry_new ();
  gtk_widget_show (entry10);
  gtk_fixed_put (GTK_FIXED (fixed4), entry10, 168, 40);
  gtk_widget_set_size_request (entry10, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry10), 8226);

  entry11 = gtk_entry_new ();
  gtk_widget_show (entry11);
  gtk_fixed_put (GTK_FIXED (fixed4), entry11, 168, 80);
  gtk_widget_set_size_request (entry11, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry11), 8226);

  entry12 = gtk_entry_new ();
  gtk_widget_show (entry12);
  gtk_fixed_put (GTK_FIXED (fixed4), entry12, 168, 120);
  gtk_widget_set_size_request (entry12, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry12), 8226);

  entry14 = gtk_entry_new ();
  gtk_widget_show (entry14);
  gtk_fixed_put (GTK_FIXED (fixed4), entry14, 168, 232);
  gtk_widget_set_size_request (entry14, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry14), 8226);

  entry15 = gtk_entry_new ();
  gtk_widget_show (entry15);
  gtk_fixed_put (GTK_FIXED (fixed4), entry15, 168, 288);
  gtk_widget_set_size_request (entry15, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry15), 8226);

  entry16 = gtk_entry_new ();
  gtk_widget_show (entry16);
  gtk_fixed_put (GTK_FIXED (fixed4), entry16, 632, 8);
  gtk_widget_set_size_request (entry16, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry16), 8226);

  entry17 = gtk_entry_new ();
  gtk_widget_show (entry17);
  gtk_fixed_put (GTK_FIXED (fixed4), entry17, 632, 56);
  gtk_widget_set_size_request (entry17, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry17), 8226);

  entry19 = gtk_entry_new ();
  gtk_widget_show (entry19);
  gtk_fixed_put (GTK_FIXED (fixed4), entry19, 632, 176);
  gtk_widget_set_size_request (entry19, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry19), 8226);

  entry20 = gtk_entry_new ();
  gtk_widget_show (entry20);
  gtk_fixed_put (GTK_FIXED (fixed4), entry20, 632, 232);
  gtk_widget_set_size_request (entry20, 176, 144);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry20), 8226);

  Modifier = gtk_button_new ();
  gtk_widget_show (Modifier);
  gtk_fixed_put (GTK_FIXED (fixed4), Modifier, 352, 320);
  gtk_widget_set_size_request (Modifier, 104, 32);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (Modifier), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-ok", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label32 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label32);
  gtk_box_pack_start (GTK_BOX (hbox2), label32, FALSE, FALSE, 0);

  label35 = gtk_label_new ("");
  gtk_widget_show (label35);
  gtk_fixed_put (GTK_FIXED (fixed4), label35, 512, 360);
  gtk_widget_set_size_request (label35, 160, 40);

  spinbutton4_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton4 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton4_adj), 1, 0);
  gtk_widget_show (spinbutton4);
  gtk_fixed_put (GTK_FIXED (fixed4), spinbutton4, 184, 176);
  gtk_widget_set_size_request (spinbutton4, 60, 27);

  spinbutton5_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton5 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton5_adj), 1, 0);
  gtk_widget_show (spinbutton5);
  gtk_fixed_put (GTK_FIXED (fixed4), spinbutton5, 288, 176);
  gtk_widget_set_size_request (spinbutton5, 60, 27);

  spinbutton6_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton6 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton6_adj), 1, 0);
  gtk_widget_show (spinbutton6);
  gtk_fixed_put (GTK_FIXED (fixed4), spinbutton6, 408, 176);
  gtk_widget_set_size_request (spinbutton6, 60, 27);

  label27 = gtk_label_new (_("IMC:"));
  gtk_widget_show (label27);
  gtk_fixed_put (GTK_FIXED (fixed4), label27, 456, 48);
  gtk_widget_set_size_request (label27, 160, 40);
  gtk_label_set_use_markup (GTK_LABEL (label27), TRUE);

  label26 = gtk_label_new (_("Poids:"));
  gtk_widget_show (label26);
  gtk_fixed_put (GTK_FIXED (fixed4), label26, 464, 0);
  gtk_widget_set_size_request (label26, 160, 40);

  label29 = gtk_label_new (_("Groupe_sanguin:"));
  gtk_widget_show (label29);
  gtk_fixed_put (GTK_FIXED (fixed4), label29, 472, 96);
  gtk_widget_set_size_request (label29, 160, 40);

  combobox2 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox2);
  gtk_fixed_put (GTK_FIXED (fixed4), combobox2, 632, 96);
  gtk_widget_set_size_request (combobox2, 160, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("A+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("A-"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("AB+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("AB-"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("O+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("O-"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("B+"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("B-"));

  label25 = gtk_label_new (_("Taille:"));
  gtk_widget_show (label25);
  gtk_fixed_put (GTK_FIXED (fixed4), label25, 0, 288);
  gtk_widget_set_size_request (label25, 160, 40);

  label28 = gtk_label_new (_("Adresse:"));
  gtk_widget_show (label28);
  gtk_fixed_put (GTK_FIXED (fixed4), label28, 0, 224);
  gtk_widget_set_size_request (label28, 160, 40);

  label24 = gtk_label_new (_("Date de naissance:"));
  gtk_widget_show (label24);
  gtk_fixed_put (GTK_FIXED (fixed4), label24, 0, 176);
  gtk_widget_set_size_request (label24, 160, 40);

  label22 = gtk_label_new (_("Nom:"));
  gtk_widget_show (label22);
  gtk_fixed_put (GTK_FIXED (fixed4), label22, 0, 72);
  gtk_widget_set_size_request (label22, 160, 40);

  label21 = gtk_label_new (_("Identifiant:"));
  gtk_widget_show (label21);
  gtk_fixed_put (GTK_FIXED (fixed4), label21, 0, 32);
  gtk_widget_set_size_request (label21, 160, 40);

  entry22 = gtk_entry_new ();
  gtk_widget_show (entry22);
  gtk_fixed_put (GTK_FIXED (fixed4), entry22, 168, 0);
  gtk_widget_set_size_request (entry22, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry22), 8226);

  label39 = gtk_label_new (_("ide:"));
  gtk_widget_show (label39);
  gtk_fixed_put (GTK_FIXED (fixed4), label39, 48, 0);
  gtk_widget_set_size_request (label39, 60, 24);

  label23 = gtk_label_new (_("Prenom:"));
  gtk_widget_show (label23);
  gtk_fixed_put (GTK_FIXED (fixed4), label23, 0, 120);
  gtk_widget_set_size_request (label23, 160, 40);

  label36 = gtk_label_new (_("jour:"));
  gtk_widget_show (label36);
  gtk_fixed_put (GTK_FIXED (fixed4), label36, 144, 184);
  gtk_widget_set_size_request (label36, 49, 17);

  label37 = gtk_label_new (_("mois:"));
  gtk_widget_show (label37);
  gtk_fixed_put (GTK_FIXED (fixed4), label37, 240, 184);
  gtk_widget_set_size_request (label37, 49, 17);

  label38 = gtk_label_new (_("annee:"));
  gtk_widget_show (label38);
  gtk_fixed_put (GTK_FIXED (fixed4), label38, 352, 184);
  gtk_widget_set_size_request (label38, 49, 17);

  label30 = gtk_label_new (_("Maladies:"));
  gtk_widget_show (label30);
  gtk_fixed_put (GTK_FIXED (fixed4), label30, 464, 168);
  gtk_widget_set_size_request (label30, 160, 40);

  label31 = gtk_label_new_with_mnemonic (_("Traitement:"));
  gtk_widget_show (label31);
  gtk_fixed_put (GTK_FIXED (fixed4), label31, 472, 232);
  gtk_widget_set_size_request (label31, 160, 40);

  label3 = gtk_label_new (_("Modifier fiche medical"));
  gtk_widget_show (label3);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 2), label3);
  gtk_label_set_use_markup (GTK_LABEL (label3), TRUE);

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed5);

  label33 = gtk_label_new (_("Identifiant:"));
  gtk_widget_show (label33);
  gtk_fixed_put (GTK_FIXED (fixed5), label33, 80, 128);
  gtk_widget_set_size_request (label33, 200, 50);

  entry21 = gtk_entry_new ();
  gtk_widget_show (entry21);
  gtk_fixed_put (GTK_FIXED (fixed5), entry21, 304, 136);
  gtk_widget_set_size_request (entry21, 220, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry21), 8226);

  Supprimer = gtk_button_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (Supprimer);
  gtk_fixed_put (GTK_FIXED (fixed5), Supprimer, 336, 264);
  gtk_widget_set_size_request (Supprimer, 120, 40);

  label4 = gtk_label_new (_("Supprimer fiche medical"));
  gtk_widget_show (label4);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 3), label4);

  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) refresh, "clicked",
                    G_CALLBACK (on_refresh_clicked),
                    NULL);
  g_signal_connect ((gpointer) Modifier, "clicked",
                    G_CALLBACK (on_Modifier_clicked),
                    NULL);
  g_signal_connect ((gpointer) Supprimer, "clicked",
                    G_CALLBACK (on_Supprimer_clicked),
                    NULL);

  gtk_label_set_mnemonic_widget (GTK_LABEL (label31), entry20);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (espacemedecin, espacemedecin, "espacemedecin");
  GLADE_HOOKUP_OBJECT (espacemedecin, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (espacemedecin, notebook1, "notebook1");
  GLADE_HOOKUP_OBJECT (espacemedecin, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (espacemedecin, label7, "label7");
  GLADE_HOOKUP_OBJECT (espacemedecin, label8, "label8");
  GLADE_HOOKUP_OBJECT (espacemedecin, label9, "label9");
  GLADE_HOOKUP_OBJECT (espacemedecin, label10, "label10");
  GLADE_HOOKUP_OBJECT (espacemedecin, label16, "label16");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry5, "entry5");
  GLADE_HOOKUP_OBJECT (espacemedecin, spinbutton1, "spinbutton1");
  GLADE_HOOKUP_OBJECT (espacemedecin, spinbutton2, "spinbutton2");
  GLADE_HOOKUP_OBJECT (espacemedecin, spinbutton3, "spinbutton3");
  GLADE_HOOKUP_OBJECT (espacemedecin, label15, "label15");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry6, "entry6");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry7, "entry7");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry8, "entry8");
  GLADE_HOOKUP_OBJECT (espacemedecin, label14, "label14");
  GLADE_HOOKUP_OBJECT (espacemedecin, label12, "label12");
  GLADE_HOOKUP_OBJECT (espacemedecin, label13, "label13");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry9, "entry9");
  GLADE_HOOKUP_OBJECT (espacemedecin, label18, "label18");
  GLADE_HOOKUP_OBJECT (espacemedecin, label17, "label17");
  GLADE_HOOKUP_OBJECT (espacemedecin, label11, "label11");
  GLADE_HOOKUP_OBJECT (espacemedecin, label6, "label6");
  GLADE_HOOKUP_OBJECT (espacemedecin, button1, "button1");
  GLADE_HOOKUP_OBJECT (espacemedecin, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (espacemedecin, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (espacemedecin, image1, "image1");
  GLADE_HOOKUP_OBJECT (espacemedecin, label19, "label19");
  GLADE_HOOKUP_OBJECT (espacemedecin, label34, "label34");
  GLADE_HOOKUP_OBJECT (espacemedecin, combobox1, "combobox1");
  GLADE_HOOKUP_OBJECT (espacemedecin, label5, "label5");
  GLADE_HOOKUP_OBJECT (espacemedecin, label1, "label1");
  GLADE_HOOKUP_OBJECT (espacemedecin, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (espacemedecin, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (espacemedecin, label20, "label20");
  GLADE_HOOKUP_OBJECT (espacemedecin, calendar1, "calendar1");
  GLADE_HOOKUP_OBJECT (espacemedecin, refresh, "refresh");
  GLADE_HOOKUP_OBJECT (espacemedecin, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (espacemedecin, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (espacemedecin, image3, "image3");
  GLADE_HOOKUP_OBJECT (espacemedecin, label40, "label40");
  GLADE_HOOKUP_OBJECT (espacemedecin, label2, "label2");
  GLADE_HOOKUP_OBJECT (espacemedecin, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry10, "entry10");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry11, "entry11");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry12, "entry12");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry14, "entry14");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry15, "entry15");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry16, "entry16");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry17, "entry17");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry19, "entry19");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry20, "entry20");
  GLADE_HOOKUP_OBJECT (espacemedecin, Modifier, "Modifier");
  GLADE_HOOKUP_OBJECT (espacemedecin, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (espacemedecin, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (espacemedecin, image2, "image2");
  GLADE_HOOKUP_OBJECT (espacemedecin, label32, "label32");
  GLADE_HOOKUP_OBJECT (espacemedecin, label35, "label35");
  GLADE_HOOKUP_OBJECT (espacemedecin, spinbutton4, "spinbutton4");
  GLADE_HOOKUP_OBJECT (espacemedecin, spinbutton5, "spinbutton5");
  GLADE_HOOKUP_OBJECT (espacemedecin, spinbutton6, "spinbutton6");
  GLADE_HOOKUP_OBJECT (espacemedecin, label27, "label27");
  GLADE_HOOKUP_OBJECT (espacemedecin, label26, "label26");
  GLADE_HOOKUP_OBJECT (espacemedecin, label29, "label29");
  GLADE_HOOKUP_OBJECT (espacemedecin, combobox2, "combobox2");
  GLADE_HOOKUP_OBJECT (espacemedecin, label25, "label25");
  GLADE_HOOKUP_OBJECT (espacemedecin, label28, "label28");
  GLADE_HOOKUP_OBJECT (espacemedecin, label24, "label24");
  GLADE_HOOKUP_OBJECT (espacemedecin, label22, "label22");
  GLADE_HOOKUP_OBJECT (espacemedecin, label21, "label21");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry22, "entry22");
  GLADE_HOOKUP_OBJECT (espacemedecin, label39, "label39");
  GLADE_HOOKUP_OBJECT (espacemedecin, label23, "label23");
  GLADE_HOOKUP_OBJECT (espacemedecin, label36, "label36");
  GLADE_HOOKUP_OBJECT (espacemedecin, label37, "label37");
  GLADE_HOOKUP_OBJECT (espacemedecin, label38, "label38");
  GLADE_HOOKUP_OBJECT (espacemedecin, label30, "label30");
  GLADE_HOOKUP_OBJECT (espacemedecin, label31, "label31");
  GLADE_HOOKUP_OBJECT (espacemedecin, label3, "label3");
  GLADE_HOOKUP_OBJECT (espacemedecin, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (espacemedecin, label33, "label33");
  GLADE_HOOKUP_OBJECT (espacemedecin, entry21, "entry21");
  GLADE_HOOKUP_OBJECT (espacemedecin, Supprimer, "Supprimer");
  GLADE_HOOKUP_OBJECT (espacemedecin, label4, "label4");

  gtk_widget_grab_focus (label33);
  gtk_widget_grab_default (label28);
  return espacemedecin;
}

// Code for window_main

#include <gtk-3.0/gtk/gtk.h>
#include "rng.h"

typedef struct {
 /**
  * Contains all radio buttons and the label, but not the 'roll' button
  */
  GtkWidget* w_lbl_display;
  GtkWidget* w_rb_coin;
  GtkWidget* w_rb_3;
  GtkWidget* w_rb_4;
  GtkWidget* w_rb_6;
  GtkWidget* w_rb_8;
  GtkWidget* w_rb_10;
  GtkWidget* w_rb_12;
  GtkWidget* w_rb_20;
} app_widgets;

Rand* rng; // declared as global as it should be valid for the entire program

int main(int argc, char* argv[]) {
  GtkBuilder* builder;
  GtkWidget* window;
  rng = new_rand();
  app_widgets* widgets = g_slice_new(app_widgets);
  gtk_init(&argc, &argv);
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "glade/window_main.glade", NULL);
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
  // get pointers to display label and radio buttons
  widgets->w_lbl_display = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_display"));
  widgets->w_rb_coin = GTK_WIDGET(gtk_builder_get_object(builder, "rb_coin"));
  widgets->w_rb_3 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_3"));
  widgets->w_rb_4 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_4"));
  widgets->w_rb_6 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_6"));
  widgets->w_rb_8 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_8"));
  widgets->w_rb_10 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_10"));
  widgets->w_rb_12 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_12"));
  widgets->w_rb_20 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_20"));
  // connect all the widgets and display window
  gtk_builder_connect_signals(builder, widgets);
  g_object_unref(builder);
  gtk_widget_show(window);
  gtk_main();
  // free memory used by widget struct
  g_slice_free(app_widgets, widgets);
  return 0;
}

void on_window_main_destroy() {
 /**
  * Called when program is closed by user, closes program
  */
  gtk_main_quit();
}

void on_btn_roller_clicked(GtkButton* button, app_widgets* widgets) {
 /**
  * When button is clicked, this function displays the required random number
  * or 'Heads'/'Tails' in the label
  * @param button the button that is clicked
  * @param widgets struct that contains all radio buttons and the label
  */
  int random = 0;
  char button_str[30] = {0};
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_coin))) {
    random = rand_int(rng,0,2);
    switch(random) {
      case 0:
        gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display), "Heads");
        break;
      default:
        gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display), "Tails");
    }
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_3))) {
    random = rand_int(rng,1,4);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_4))) {
    random = rand_int(rng,1,5);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_6))) {
    random = rand_int(rng,1,7);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_8))) {
    random = rand_int(rng,1,9);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_10))) {
    random = rand_int(rng,1,11);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_12))) {
    random = rand_int(rng,1,13);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widgets->w_rb_20))) {
    random = rand_int(rng,1,21);
    sprintf(button_str,"%d",random);
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_display),button_str);
  }
}

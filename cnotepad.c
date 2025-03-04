#include "fileIO\fileIO.h"
#include "libs.h"


GtkWidget *text_view;

void saveText(GtkWidget* button, gpointer user_data){
    GtkTextIter start, end;
    GtkTextBuffer* buffer=gtk_text_view_get_buffer(text_view);
    gchar* text;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text=gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    saveTextInFile(text);
    g_free(text);
}

bool loaded=0;
void loadSave(){
    loaded=1;
    printf("%s", loadTextFromFile("save.txt"));
}
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "C Notepad");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);
    gtk_container_add(GTK_CONTAINER(window), box);
    
    GtkWidget *buttonBox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(box), buttonBox);
    
    GtkWidget *saveButton = gtk_button_new_with_label("Save Text");
    g_signal_connect(saveButton, "clicked", G_CALLBACK(saveText), NULL);
    gtk_box_pack_start(GTK_BOX(buttonBox), saveButton, FALSE, FALSE, 5);

    /*GtkWidget *loadButton = gtk_button_new_with_label("Load Text");
    //g_signal_connect(loadButton, "clicked", G_CALLBACK(reloadSave), NULL);
    gtk_box_pack_start(GTK_BOX(buttonBox), loadButton, FALSE, FALSE, 5);
    */


    text_view = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(box), text_view, TRUE, TRUE, 5);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    //loadSave();
    
    GtkApplication *app = gtk_application_new("com.example.notepad", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

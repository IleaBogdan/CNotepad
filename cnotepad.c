#include <gtk/gtk.h>  // GTK lib

// This function will be called when the GTK application is activated (i.e., when it starts)
static void activate(GtkApplication *app, gpointer user_data) {
    // Create a new window 
    GtkWidget *window = gtk_application_window_new(app);

    // Set the title of the window 
    gtk_window_set_title(GTK_WINDOW(window), "C Notepad");

    // Set the default size of the window (width = 600px, height = 400px)
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    // Set a border inside the window (this will create space between the window edge and its contents)
    // The value of 5 means there will be a 5-pixel space on all sides of the content inside the window
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    // Create a new text view widget (this is where the user can type text)
    GtkWidget *text_view = gtk_text_view_new();

    // Add the text view widget to the window, making it a child of the window
    gtk_container_add(GTK_CONTAINER(window), text_view);

    // Show the window and all its contents (text view will be visible now)
    gtk_widget_show_all(window);
}

// This is the entry point of the program, where everything starts
int main(int argc, char **argv) {
    // Create a new GTK application object
    GtkApplication *app = gtk_application_new("com.example.notepad", G_APPLICATION_FLAGS_NONE);

    // Connect the "activate" signal of the application to the `activate` function defined earlier
    // This ensures that the `activate` function will run when the application starts
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Run the application. This will start the GTK event loop, which handles user input and other events
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    // Release the application object after it's done
    g_object_unref(app);

    // Return the status code (usually 0 for successful execution)
    return status;
}

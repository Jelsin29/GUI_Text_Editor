#include <gtk/gtk.h>
/////Merhaba

static void activate_open_file(GtkApplication* app, gpointer user_data) {
    GtkWidget* dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

        GTK_WINDOW(gtk_application_get_active_window(app)),
        action,
        "_Cancel", GTK_RESPONSE_CANCEL,
        "_Open", GTK_RESPONSE_ACCEPT,
        NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        char* filename;
        GtkFileChooser* chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        // Open the file and display its contents in the text view
        g_print("Open file: %s\n", filename);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

static void activate_save_file(GtkApplication* app, gpointer user_data) {
    GtkWidget* dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Save File",
        GTK_WINDOW(gtk_application_get_active_window(app)),
        action,
        "_Cancel", GTK_RESPONSE_CANCEL,
        "_Save", GTK_RESPONSE_ACCEPT,
        NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        char* filename;
        GtkFileChooser* chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        // Save the contents of the text view to the file
        g_print("Save file: %s\n", filename);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

static void activate_quit(GtkApplication* app, gpointer user_data) {
    g_application_quit(G_APPLICATION(app));
}

static void app_activate(GtkApplication* app, gpointer user_data) {
    GtkWidget* window;
    GtkWidget* vbox, * menubar, * textview;
    GtkWidget* open_menu_item, * save_menu_item, * quit_menu_item;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    menubar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    GtkWidget* file_menu = gtk_menu_new();
    GtkWidget* file_menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file_menu_item);

    open_menu_item = gtk_menu_item_new_with_label("Open");
    g_signal_connect(open_menu_item, "activate", G_CALLBACK(activate_open_file), app);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_menu_item);

    save_menu_item = gtk_menu_item_new_with_label("Save");
    g_signal_connect(save_menu_item, "activate", G_CALLBACK(activate_save_file), app);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_menu_item);

    quit_menu_item = gtk_menu_item_new_with_label("Quit");
    g_signal_connect(quit_menu_item, "activate", G_CALLBACK(activate_quit), app);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_menu_item);

    textview = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(vbox), textview, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
}

int main(int argc, char** argv) {
    GtkApplication* app;
    int status;

    app = gtk_application_new("com.example.text-editor", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

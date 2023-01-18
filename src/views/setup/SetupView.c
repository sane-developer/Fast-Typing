#include "SetupViewWidgets.h"
#include "SetupViewBehavior.h"
#include "../training/TrainingViewBehavior.h"
#include "../../extensions/signals/SignalsDetach.h"

void initialize_setup_ui(GtkBuilder *builder)
{
	SetupMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "setup-window"));

    WordsLengthInput = GTK_ENTRY(gtk_builder_get_object(builder, "words-length"));

    WordsAmountInput = GTK_ENTRY(gtk_builder_get_object(builder, "words-count"));

    MoveToTrainingViewButton = GTK_BUTTON(gtk_builder_get_object(builder, "move-training"));
}

void render_setup_view()
{
    const gchar* path = "/home/krzysztof/Projects/Fast-Typing-Training/src/views/setup/SetupUI.glade";

    GtkBuilder *builder = gtk_builder_new_from_file(path);

    initialize_setup_ui(builder);

    g_signal_connect(MoveToTrainingViewButton, "clicked", G_CALLBACK(move_to_training_view), NULL);

    gtk_builder_connect_signals(builder, NULL); 

    g_object_unref(builder);

	gtk_widget_show_all(SetupMainWindow);

	gtk_main();
}

void dispose_setup_view()
{
    disconnect_parent_signals(SetupMainWindow);

    gtk_widget_destroy(SetupMainWindow);
}

void move_to_training_view()
{
    int wordsLength = atoi(gtk_entry_get_text(WordsLengthInput));

    int wordsAmount = atoi(gtk_entry_get_text(WordsAmountInput));

    dispose_setup_view();

    render_training_view(wordsLength, wordsAmount);
}
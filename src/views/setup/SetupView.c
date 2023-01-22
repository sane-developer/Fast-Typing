#include "SetupView.h"
#include "SetupViewWidgets.h"
#include "SetupViewVariables.h"
#include "SetupViewFunctionality.h"
#include "../training/TrainingView.h"
#include "../../extensions/signals/Detach.h"
#include "../../enumerations/TrainingModes.h"

void initialize_setup_view_widgets(GtkBuilder *builder)
{
	SetupMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "setup-window"));

    AllWordsButton = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "all-words"));

    ShortWordsButton = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "short-words"));

    LongWordsButton = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "long-words"));

    MoveToTrainingViewButton = GTK_BUTTON(gtk_builder_get_object(builder, "move-to-training"));

    g_signal_connect(SetupMainWindow, "realize", G_CALLBACK(create_statistics_file), NULL);

    g_signal_connect(SetupMainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(AllWordsButton, "toggled", G_CALLBACK(on_all_words_toggled), NULL);

    g_signal_connect(ShortWordsButton, "toggled", G_CALLBACK(on_short_words_toggled), NULL);

    g_signal_connect(LongWordsButton, "toggled", G_CALLBACK(on_long_words_toggled), NULL);

    g_signal_connect(MoveToTrainingViewButton, "clicked", G_CALLBACK(switch_context_to_training_view), NULL);
}

void initialize_setup_view_variables()
{
    ChosenTrainingMode = AllWords;

    StatisticsFileName = "statistics.txt";
}

void render_setup_view_ui()
{
    GtkBuilder *builder = gtk_builder_new_from_file("resources/SetupViewUI.glade");

    initialize_setup_view_variables();
    
    initialize_setup_view_widgets(builder);

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

	gtk_widget_show_all(SetupMainWindow);

	gtk_main();
}

void dispose_setup_view_ui()
{
    disconnect_parent_signals(SetupMainWindow);

    gtk_widget_destroy(SetupMainWindow);
}

void switch_context_to_training_view()
{
    dispose_setup_view_ui();

    render_training_view_ui(ChosenTrainingMode);
}

void create_statistics_file()
{
    FILE* statistics_file = fopen(StatisticsFileName, "a");

    fclose(statistics_file);
}

void on_all_words_toggled()
{
    int value = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(AllWordsButton));

    if (value)
    {
        ChosenTrainingMode = AllWords;
    }
}

void on_short_words_toggled()
{
    int value = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ShortWordsButton));

    if (value)
    {
        ChosenTrainingMode = ShortWords;
    }
}

void on_long_words_toggled()
{
    int value = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(LongWordsButton));

    if (value)
    {
        ChosenTrainingMode = LongWords;
    }
}
#include "SummaryViewWidgets.h"
#include "SummaryViewBehavior.h"
#include "../setup/SetupViewBehavior.h"
#include "../../extensions/signals/SignalsDetach.h"

void initialize_summary_ui(GtkBuilder *builder)
{
    SummaryMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "summary-window"));

    CorrectWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "correct-count"));

    IncorrectWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "incorrect-count"));

    TypingAccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy"));

    BestTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "best-time"));

    AverageTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "average-time"));

    WorstTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "worst-time"));

    SetupResetButton = GTK_BUTTON(gtk_builder_get_object(builder, "move-setup"));
}

void render_summary_view(int correctWords, int incorrectWords, float accuracy)
{
    const gchar* path = "/home/krzysztof/Projects/Fast-Typing-Training/src/views/summary/SummaryUI.glade";

    GtkBuilder *builder = gtk_builder_new_from_file(path);

    initialize_summary_ui(builder);

    g_signal_connect(SetupResetButton, "clicked", G_CALLBACK(move_to_setup_view), NULL);

    gtk_builder_connect_signals(builder, NULL); 

    g_object_unref(builder);

	gtk_widget_show_all(SummaryMainWindow);

	gtk_main();
}

void dispose_summary_view()
{
    disconnect_parent_signals(SummaryMainWindow);

    gtk_widget_destroy(SummaryMainWindow);
}

void move_to_setup_view()
{
    dispose_summary_view();
    
    render_setup_view();
}
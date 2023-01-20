#include "SummaryViewWidgets.h"
#include "SummaryViewBehavior.h"
#include "SummaryViewVariables.h"
#include "../setup/SetupViewBehavior.h"
#include "../../extensions/signals/Detach.h"

void initialize_summary_view_widgets(GtkBuilder *builder)
{
    SummaryMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "summary-window"));

    CorrectWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "correct-words-count"));

    IncorrectWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "incorrect-words-count"));

    TypingAccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy"));

    BestWpmLabel = GTK_LABEL(gtk_builder_get_object(builder, "best-wpm"));

    AverageWpmLabel = GTK_LABEL(gtk_builder_get_object(builder, "average-wpm"));

    WorstWpmLabel = GTK_LABEL(gtk_builder_get_object(builder, "worst-wpm"));

    MoveToSetupButton = GTK_BUTTON(gtk_builder_get_object(builder, "move-to-setup"));

    gtk_label_set_text(CorrectWordsCountLabel, g_strdup_printf("%i", CorrectWords));

    gtk_label_set_text(IncorrectWordsCountLabel, g_strdup_printf("%i", IncorrectWords));

    gtk_label_set_text(TypingAccuracyLabel, g_strdup_printf("%.2f%%", Accuracy));

    gtk_label_set_text(BestWpmLabel, g_strdup_printf("%i", GameModeStatistics->best_words_per_minute_score));

    gtk_label_set_text(AverageWpmLabel, g_strdup_printf("%i", GameModeStatistics->average_words_per_minute_score));

    gtk_label_set_text(WorstWpmLabel, g_strdup_printf("%i", GameModeStatistics->worst_words_per_minute_score));

    g_signal_connect(MoveToSetupButton, "clicked", G_CALLBACK(move_to_setup_view), NULL);
}

void initialize_summary_view_variables(const char* mode, int correctWords, int incorrectWords, float accuracy)
{
    ArchiveFileName = "statistics.txt";

    Accuracy = accuracy;

    CorrectWords = correctWords;

    IncorrectWords = incorrectWords;

    WordsPerMinute = correctWords + incorrectWords;

    GameModeStatistics = retrieve_statistics_by_mode(ArchiveFileName, mode);
}

void render_summary_view_ui(const char* mode, int correctWords, int incorrectWords, float accuracy)
{
    GtkBuilder *builder = gtk_builder_new_from_file("summary.glade");

    initialize_summary_view_variables(mode, correctWords, incorrectWords, accuracy);

    initialize_summary_view_widgets(builder);

    g_signal_connect(MoveToSetupButton, "clicked", G_CALLBACK(move_to_setup_view), NULL);

    gtk_builder_connect_signals(builder, NULL); 

    g_object_unref(builder);

	gtk_widget_show_all(SummaryMainWindow);

	gtk_main();
}

void dispose_summary_view_ui()
{
    g_free(GameModeStatistics);

    disconnect_parent_signals(SummaryMainWindow);

    gtk_widget_destroy(SummaryMainWindow);
}

void move_to_setup_view()
{
    archive_statistics(ArchiveFileName, GameModeStatistics->mode, WordsPerMinute);

    dispose_summary_view_ui();
    
    render_setup_view_ui();
}
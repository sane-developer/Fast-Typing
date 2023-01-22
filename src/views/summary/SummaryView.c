#include "SummaryView.h"
#include "SummaryViewWidgets.h"
#include "SummaryViewVariables.h"
#include "SummaryViewFunctionality.h"
#include "../setup/SetupView.h"
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

    g_signal_connect(SummaryMainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(MoveToSetupButton, "clicked", G_CALLBACK(switch_context_to_setup_view), NULL);
}

void initialize_summary_view_variables(enum TrainingModes mode, int correct_words, int incorrect_words, float accuracy)
{
    ArchiveFileName = "statistics.txt";

    Accuracy = accuracy;

    CorrectWords = correct_words;

    IncorrectWords = incorrect_words;

    WordsPerMinute = correct_words + incorrect_words;

    archive_statistics(ArchiveFileName, mode, WordsPerMinute);

    GameModeStatistics = retrieve_statistics_by_mode(ArchiveFileName, mode);

    if (GameModeStatistics->best_words_per_minute_score == 0)
    {
        GameModeStatistics->best_words_per_minute_score = WordsPerMinute;
    }

    if (GameModeStatistics->worst_words_per_minute_score == 0)
    {
        GameModeStatistics->worst_words_per_minute_score = WordsPerMinute;
    }

    if (GameModeStatistics->average_words_per_minute_score == 0)
    {
        GameModeStatistics->average_words_per_minute_score = WordsPerMinute;
    }
}

void render_summary_view_ui(enum TrainingModes mode, int correct_words, int incorrect_words, float accuracy)
{
    GtkBuilder *builder = gtk_builder_new_from_file("resources/SummaryViewUI.glade");

    initialize_summary_view_variables(mode, correct_words, incorrect_words, accuracy);

    initialize_summary_view_widgets(builder);

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

void switch_context_to_setup_view()
{
    dispose_summary_view_ui();
    
    render_setup_view_ui();
}

#include "TrainingView.h"
#include "TrainingViewWidgets.h"
#include "TrainingViewVariables.h"
#include "TrainingViewFunctionality.h"
#include "../summary/SummaryView.h"
#include "../../collections/Words.h"
#include "../../extensions/signals/Detach.h"

void initialize_training_view_variables(enum TrainingModes mode)
{
    struct Words *dictionary = read_words_from_file("resources/Dictionary.txt");

    struct WordRange *range = get_range_from_mode(mode);

    AvailableWords = get_randomized_words(dictionary, range);
    
    CurrentWord = g_strchomp(AvailableWords[0]);

    GameMode = mode;

    g_free(dictionary);

    g_free(range);
}

void initialize_training_view_widgets(GtkBuilder *builder)
{
	TrainingMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "training-window"));

    WordDisplayLabel = GTK_LABEL(gtk_builder_get_object(builder, "word-display"));

    WordInput = GTK_ENTRY(gtk_builder_get_object(builder, "word-text"));

    WrittenWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "written-count"));

    AccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy"));

    RemainingTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "elapsed-time"));

    gtk_label_set_text(WordDisplayLabel, CurrentWord);

    gtk_label_set_text(RemainingTimeLabel, "60 seconds");

    g_signal_connect(TrainingMainWindow, "realize", G_CALLBACK(on_window_realize), NULL);

    g_signal_connect(TrainingMainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(WordInput, "activate", G_CALLBACK(changed_input), NULL);

    g_timeout_add(1000, update_remaining_time, RemainingTimeLabel);
}

void render_training_view_ui(enum TrainingModes mode)
{
    GtkBuilder *builder = gtk_builder_new_from_file("resources/TrainingViewUI.glade");

    initialize_training_view_variables(mode);

    initialize_training_view_widgets(builder);

    gtk_builder_connect_signals(builder, NULL); 

    g_object_unref(builder);

	gtk_widget_show_all(TrainingMainWindow);

	gtk_main();
}

void dispose_training_view_ui()
{
    CorrectWordsCount = 0;

    IncorrectWordsCount = 0;

    dispose_words(AvailableWords, WrittenWordsCount);
    
    WrittenWordsCount = 0;

    disconnect_parent_signals(TrainingMainWindow);

    gtk_widget_destroy(TrainingMainWindow);
}

void on_window_realize() 
{
    RemainingTime = time(NULL) + 60;
}

void changed_input() 
{
    const gchar *text = gtk_entry_get_text(WordInput);

    if (strlen(text) == strlen(CurrentWord))
    {
        WrittenWordsCount++;
        
        if (strcmp(text, CurrentWord) == 0)
        {
            CorrectWordsCount++;
        }
        else
        {
            IncorrectWordsCount++;
        }

        int accuracy = (int)((float)CorrectWordsCount / (float)WrittenWordsCount * 100);

        gtk_label_set_text(AccuracyLabel, g_strdup_printf("%i%%", accuracy));

        gtk_label_set_text(WrittenWordsCountLabel, g_strdup_printf("%i", WrittenWordsCount));

        CurrentWord = g_strchomp(AvailableWords[WrittenWordsCount]);

        gtk_label_set_text(WordDisplayLabel, CurrentWord);

        gtk_entry_set_text(WordInput, "");
    }
}

void switch_context_to_summary_view()
{
    int correct_words = CorrectWordsCount;

    int incorrect_words = IncorrectWordsCount;

    float accuracy = (float)CorrectWordsCount / (float)WrittenWordsCount * 100;

    dispose_training_view_ui();

    render_summary_view_ui(GameMode, correct_words, incorrect_words, accuracy);
}

int update_remaining_time(gpointer label) 
{
    time_t currentTime = time(NULL);

    double remaining_time = difftime(RemainingTime, currentTime);

    if (remaining_time >= 0)
    {
        char* remaining_time_string = g_strdup_printf("%.0f seconds", remaining_time);

        gtk_label_set_text(RemainingTimeLabel, remaining_time_string);

        g_free(remaining_time_string);
    }
    else
    {
        switch_context_to_summary_view();
    }
    
    return 1;
}
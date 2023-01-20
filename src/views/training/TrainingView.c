#include "TrainingViewWidgets.h"
#include "TrainingViewBehavior.h"
#include "TrainingViewVariables.h"
#include "../summary/SummaryViewBehavior.h"
#include "../../extensions/words/Dictionary.h"
#include "../../extensions/signals/Detach.h"

void initialize_training_view_variables(char* length)
{
    struct Dictionary *dictionary = read_words_from_file("words.txt");

    struct WordRange *range = get_range_from_string(length);

    AvailableWords = get_randomized_words(dictionary, range);
    
    g_free(dictionary);

    g_free(range);

    CurrentWord = g_strchomp(AvailableWords[0]);

    StartTime = clock();
}

void initialize_training_view_widgets(GtkBuilder *builder)
{
	TrainingMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "training-window"));

    WordDisplayLabel = GTK_LABEL(gtk_builder_get_object(builder, "word-display"));

    WordInput = GTK_ENTRY(gtk_builder_get_object(builder, "word-text"));

    WrittenWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "written-count"));

    AccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy"));

    ElapsedTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "elapsed-time"));

    gtk_label_set_text(WordDisplayLabel, CurrentWord);
    
    g_signal_connect(WordInput, "activate", G_CALLBACK(changed_input), NULL);
}

void render_training_view_ui(char* wordsLength)
{
    GtkBuilder *builder = gtk_builder_new_from_file("Training.glade");

    initialize_training_view_variables(wordsLength);

    initialize_training_view_widgets(builder);

    gtk_builder_connect_signals(builder, NULL); 

    g_object_unref(builder);

	gtk_widget_show_all(TrainingMainWindow);

	gtk_main();
}

void dispose_training_view_ui()
{
    StartTime = 0;

    CorrectWordsCount = 0;

    IncorrectWordsCount = 0;

    dispose_words(AvailableWords, WrittenWordsCount);
    
    WrittenWordsCount = 0;

    disconnect_parent_signals(TrainingMainWindow);

    gtk_widget_destroy(TrainingMainWindow);
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

    // if (WrittenWordsCount == TotalWordsCount)
    // {
    //     move_to_summary_view();
    // }
}

void move_to_summary_view()
{
    int correctWords = CorrectWordsCount;

    int incorrectWords = IncorrectWordsCount;

    float accuracy = (float)CorrectWordsCount / (float)WrittenWordsCount * 100;

    dispose_training_view_ui();

    render_summary_view_ui(correctWords, incorrectWords, accuracy);
}
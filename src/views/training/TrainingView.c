#include "TrainingViewWidgets.h"
#include "TrainingViewBehavior.h"
#include "TrainingViewVariables.h"
#include "../summary/SummaryViewBehavior.h"
#include "../../extensions/words/Dictionary.h"
#include "../../extensions/signals/Detach.h"

void initialize_training_view_variables(int length, int count)
{
    const char *path = "/home/krzysztof/Projects/Fast-Typing-Training/src/resources/words.txt";

    struct Dictionary *dictionary = read_words_from_file(path);

    const int supportedLength = length > 12 ? 12 : length;

    const int supportedCount = count > 1000 ? 1000 : count;

    AvailableWords = get_random_words(dictionary, supportedCount, supportedLength);
    
    g_free(dictionary);

    CurrentWord = g_strchomp(AvailableWords[0]);

    TotalWordsCount = supportedCount;

    StartTime = clock();
}

void initialize_training_view_widgets(GtkBuilder *builder)
{
	TrainingMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "training-window"));

    WordDisplayLabel = GTK_LABEL(gtk_builder_get_object(builder, "word-display"));

    WordInput = GTK_ENTRY(gtk_builder_get_object(builder, "word-text"));

    WrittenWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "written-count"));

    TotalWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "total-count"));

    AccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy"));

    ElapsedTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "elapsed-time"));

    gtk_label_set_text(WordDisplayLabel, CurrentWord);

    gtk_label_set_text(TotalWordsCountLabel, g_strdup_printf("%i", TotalWordsCount));
    
    g_signal_connect(WordInput, "activate", G_CALLBACK(changed_input), NULL);
}

void render_training_view_ui(int wordsLength, int wordsCount)
{
    const char *path = "Training.glade";

    GtkBuilder *builder = gtk_builder_new_from_file(path);

    initialize_training_view_variables(wordsLength, wordsCount);

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

    WrittenWordsCount = 0;

    dispose_words(AvailableWords, TotalWordsCount);

    disconnect_parent_signals(TrainingMainWindow);

    gtk_widget_destroy(TrainingMainWindow);
}

void changed_input() 
{
    const gchar *text = gtk_entry_get_text(WordInput);

    if (strcmp(text, CurrentWord) == 0)
    {
        WrittenWordsCount++;

        gtk_label_set_text(WrittenWordsCountLabel, g_strdup_printf("%i", WrittenWordsCount));

        if (WrittenWordsCount < TotalWordsCount)
        {
            CurrentWord = g_strchomp(AvailableWords[WrittenWordsCount]);

            gtk_label_set_text(WordDisplayLabel, CurrentWord);

            gtk_entry_set_text(WordInput, "");
        }
    }

    if (WrittenWordsCount == TotalWordsCount)
    {
        move_to_summary_view();
    }
}

void move_to_summary_view()
{
    int correctWords = CorrectWordsCount;

    int incorrectWords = IncorrectWordsCount;

    float accuracy = CorrectWordsCount / TotalWordsCount * 100;

    dispose_training_view_ui();

    render_summary_view_ui(correctWords, incorrectWords, accuracy);
}
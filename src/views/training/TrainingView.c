#include "TrainingViewWidgets.h"
#include "TrainingViewBehavior.h"
#include "TrainingViewProperties.h"
#include "../summary/SummaryViewBehavior.h"
#include "../../extensions/database/Dictionary.h"
#include "../../extensions/signals/SignalsDetach.h"

void initialize_training_ui(GtkBuilder *builder)
{
	TrainingMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "training-window"));

    WordDisplayLabel = GTK_LABEL(gtk_builder_get_object(builder, "word-display"));

    WordInput = GTK_ENTRY(gtk_builder_get_object(builder, "word-text"));

    WrittenWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "written-count"));

    TotalWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "total-count"));

    AccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy"));

    ElapsedTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "elapsed-time"));
}

void initialize_training_ui_properties(int count)
{
    g_signal_connect(WordInput, "changed", G_CALLBACK(on_inserted), NULL);

    gtk_label_set_text(WordDisplayLabel, WordToType);

    gtk_label_set_text(TotalWordsCountLabel, g_strdup_printf("%i", count));
}

void initialize_training_view_variables(int length, int count)
{
    const char *path = "/home/krzysztof/Projects/Fast-Typing-Training/src/database/words.txt";

    struct Dictionary *dictionary = read_words_from_file(path);

    WordsToType = get_random_words(dictionary, count, length);

    free(dictionary);

    WordToType = WordsToType[0];

    TotalWordsCount = count;

    StartTime = clock();
}

void render_training_view(int length, int count)
{
    const gchar *path = "/home/krzysztof/Projects/Fast-Typing-Training/src/views/training/TrainingUI.glade";

    GtkBuilder *builder = gtk_builder_new_from_file(path);

    initialize_training_ui(builder);

    initialize_training_view_variables(length, count);

    initialize_training_ui_properties(count);

    gtk_builder_connect_signals(builder, NULL); 

    g_object_unref(builder);

	gtk_widget_show_all(TrainingMainWindow);

	gtk_main();
}

void dispose_training_view()
{
    free(WordsToType);

    disconnect_parent_signals(TrainingMainWindow);

    gtk_widget_destroy(TrainingMainWindow);
}

void move_to_summary_view()
{
    float accuracy = CorrectWordsCount / TotalWordsCount;

    dispose_training_view();

    render_summary_view(CorrectWordsCount, IncorrectWordsCount, accuracy);
}

static void on_inserted(GtkWidget *widget, gpointer data) 
{
    const gchar *text = gtk_entry_get_text(WordInput);

    if (strcmp(text, WordToType) == 0)
    {
        gtk_entry_set_text(WordInput, "");

        WrittenWordsCount++;

        gtk_label_set_text(WrittenWordsCountLabel, g_strdup_printf("%i", WrittenWordsCount));

        WordToType = WordsToType[WrittenWordsCount];

        gtk_label_set_text(WordDisplayLabel, WordToType);
    }

    if (WrittenWordsCount == TotalWordsCount)
    {
        move_to_summary_view();
    }
}
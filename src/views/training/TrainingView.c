#include "TrainingViewWidgets.h"
#include "TrainingViewBehavior.h"

void renderTrainingView(int wordsLength, int wordsCount)
{
    //  Creates the GTK UI Builder from provided UI configuration
    //
    GtkBuilder *builder = gtk_builder_new_from_file("/home/krzysztof/Projects/Fast-Typing-Training/src/views/training/TrainingUI.glade");

	//  Assigns the main application window widget
    //
	TrainingMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "app-window"));
	
    //  Assigns the word display label widget
    //
    WordDisplayLabel = GTK_LABEL(gtk_builder_get_object(builder, "word-display-label"));

    //  Assigns the word entry widget
    //
    WordInput = GTK_ENTRY(gtk_builder_get_object(builder, "word-text-entry"));

    //  Assigns the written words count label widget
    //
    WrittenWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "written-words-count-label"));

    //  Assigns the total words count label widget
    //
    TotalWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "total-words-count-label"));

    //  Assigns the accuracy label widget
    //
    AccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy-label"));

    //  Assigns the elapsed time label widget
    //
    ElapsedTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "elapsed-time-label"));

	//  Activates the callback system
	//
    gtk_builder_connect_signals(builder, NULL); 
	
    //  Frees the memory
    //
    g_object_unref(builder);
	
    //  Displays the main window
    //
	gtk_widget_show_all(TrainingMainWindow);

    //  Runs the view
    //
	gtk_main();
}


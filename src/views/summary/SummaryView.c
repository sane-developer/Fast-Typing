#include "SummaryViewWidgets.h"
#include "SummaryViewBehavior.h"
#include "../setup/SetupViewBehavior.h"

void renderSummaryView(int correctWords, int incorrectWords, float accuracy)
{
    //  Creates the GTK UI Builder from provided UI configuration
    //
    GtkBuilder *builder = gtk_builder_new_from_file("/home/krzysztof/Projects/Fast-Typing-Training/src/views/summary/SummaryUI.glade");

    //  Assigns the main application window widget
    //
    SummaryMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "app-window"));
    
    //  Assigns the correct words count label widget
    //
    CorrectWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "correct-words-count-label"));
    
    //  Assigns the incorrect words count label widget
    //
    IncorrectWordsCountLabel = GTK_LABEL(gtk_builder_get_object(builder, "incorrect-words-count-label"));
    
    //  Assigns the accuracy label widget
    //
    TypingAccuracyLabel = GTK_LABEL(gtk_builder_get_object(builder, "accuracy-label"));
    
    //  Assigns the best time label widget
    //
    BestTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "best-time-label"));
    
    //  Assigns the average time label widget
    //
    AverageTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "average-time-label"));
    
    //  Assigns the worst time label widget
    //
    WorstTimeLabel = GTK_LABEL(gtk_builder_get_object(builder, "worst-time-label"));
    
    //  Assigns the reset setup button
    //
    SetupResetButton = GTK_BUTTON(gtk_builder_get_object(builder, "reset-setup-button"));

    //  Activates the callback system
	//
    gtk_builder_connect_signals(builder, NULL); 
	
    //  Frees the memory
    //
    g_object_unref(builder);
	
    //  Displays the main window
    //
	gtk_widget_show_all(SummaryMainWindow);

    //  Runs the view
    //
	gtk_main();
}

void reset()
{
    renderSetupView();
}
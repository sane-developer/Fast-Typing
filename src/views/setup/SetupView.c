#include "SetupViewWidgets.h"
#include "SetupViewBehavior.h"
#include "../training/TrainingViewBehavior.h"
#include "../../extensions/signals/SignalsDetach.h"

void renderSetupView()
{
    //  Creates the GTK UI Builder from provided UI configuration
    //
    GtkBuilder *builder = gtk_builder_new_from_file("/home/krzysztof/Projects/Fast-Typing-Training/src/views/setup/SetupUI.glade");

	//  Assigns the main application window widget
    //
	SetupMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "setup-window"));

    //  Assigns the maximum words length input widget
    //
    WordsLengthInput = GTK_ENTRY(gtk_builder_get_object(builder, "words-length"));

    //  Assigns the maximum words count input widget
    //
    WordsAmountInput = GTK_ENTRY(gtk_builder_get_object(builder, "words-count"));

    //  Assigns the start training button widget
    //
    StartTrainingButton = GTK_BUTTON(gtk_builder_get_object(builder, "start-training"));

	//  Activates the callback system
	//
    gtk_builder_connect_signals(builder, NULL); 
	
    //  Frees the memory
    //
    g_object_unref(builder);

    //  Displays the main window
    //
	gtk_widget_show_all(SetupMainWindow);

    //  Runs the view
    //
	gtk_main();
}

void startTraining()
{
    //  Gets the words length from the entry
    //
    int wordsLength = atoi(gtk_entry_get_text(WordsLengthInput));
    
    //  Gets the words amount from the entry
    //
    int wordsAmount = atoi(gtk_entry_get_text(WordsAmountInput));

    //  Disconnects all the signals related to the setup window
    //
    disconnectParentSignals(SetupMainWindow);

    //  Destroys the setup view window
    //
    gtk_widget_destroy(SetupMainWindow);
    
    //  Renders the Training view
    //
    renderTrainingView(wordsLength, wordsAmount);
}
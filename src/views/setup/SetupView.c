#include "SetupViewWidgets.h"
#include "SetupViewBehavior.h"
#include "../training/TrainingViewBehavior.h"

void renderSetupView()
{
    //  Creates the GTK UI Builder
    //
    GtkBuilder *builder = gtk_builder_new();

    //  Updates the builder with the Setup view UI blueprint
    //
    gtk_builder_add_from_file(builder, "SetupView.glade", NULL);

    //  Assigns the main application window widget
    //
    SetupMainWindow = GTK_WIDGET(gtk_builder_get_object(builder, "application"));

    //  Assigns the maximum words length input widget
    //
    WordsLengthInput = GTK_ENTRY(gtk_builder_get_object(builder, "words-length-entry"));

    //  Assigns the maximum words count input widget
    //
    WordsAmountInput = GTK_ENTRY(gtk_builder_get_object(builder, "words-amount-entry"));

    //  Assigns the start training button widget
    //
    StartTrainingButton = GTK_BUTTON(gtk_builder_get_object(builder, "start-training-button"));

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
    
    //  Renders the Training view
    //
    renderTrainingView(wordsLength, wordsAmount);
}
#include <gtk/gtk.h>

/*
 *  Defines the widget which represents the main application window 
 */
GtkWidget* SummaryMainWindow;

/*
 *  Defines the widget which represents the correct words display label 
 */
GtkLabel* CorrectWordsCountLabel;

/*
 *  Defines the widget which represents the incorrect words display label 
 */
GtkLabel* IncorrectWordsCountLabel;

/*
 *  Defines the widget which represents the accuracy label 
 */
GtkLabel* TypingAccuracyLabel;

/*
 *  Defines the widget which represents the best time label 
 */
GtkLabel* BestTimeLabel;

/*
 *  Defines the widget which represents the average time label 
 */
GtkLabel* AverageTimeLabel;

/*
 *  Defines the widget which represents the worst time label 
 */
GtkLabel* WorstTimeLabel;

/*
 *  Defines the widget which represents the settings reset button 
 */
GtkButton* SetupResetButton;
#ifndef SUMMARYVIEWWIDGETS_H
#define SUMMARYVIEWWIDGETS_H

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
GtkLabel* BestWpmLabel;

/*
 *  Defines the widget which represents the average time label 
 */
GtkLabel* AverageWpmLabel;

/*
 *  Defines the widget which represents the worst time label 
 */
GtkLabel* WorstWpmLabel;

/*
 *  Defines the widget which represents the settings reset button 
 */
GtkButton* MoveToSetupButton;

#endif
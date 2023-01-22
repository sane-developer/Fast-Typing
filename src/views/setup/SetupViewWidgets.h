#ifndef SETUPVIEWWIDGETS_H
#define SETUPVIEWWIDGETS_H

#include <gtk/gtk.h>

/*
 *  Defines the widget which represents the main application window
 */
GtkWidget* SetupMainWindow;

/*
 *  Defines the widget which represents the all words radio button
 */
GtkRadioButton* AllWordsButton;

/*
 *  Defines the widget which represents the short words radio button
 */
GtkRadioButton* ShortWordsButton;

/*
 *  Defines the widget which represents the long words radio button
 */
GtkRadioButton* LongWordsButton;

/*
 *  Defines the widget which represents the start training trigger
 */
GtkButton* MoveToTrainingViewButton;

#endif
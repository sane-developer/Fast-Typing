#ifndef TRAININGVIEWFUNCTIONALITY_H
#define TRAININGVIEWFUNCTIONALITY_H

#include <gtk/gtk.h>

/*
 *  Initializes the end time for the stopwatch
 */
extern void on_window_realize();

/*
 *  Handles the actions upon key insertion
 */
extern void changed_input();

/*
 *  Allows to switch context to summary view
 */
extern void switch_context_to_summary_view();

/*
 *  Updates the remaining time each second
 */
extern int update_remaining_time(gpointer);

#endif
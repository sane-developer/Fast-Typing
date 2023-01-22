#ifndef SUMMARYVIEW_H
#define SUMMARYVIEW_H

#include <gtk/gtk.h>
#include "../../enumerations/TrainingModes.h"

/*
 *  Renders the summary view UI components
 */
extern void render_summary_view_ui(enum TrainingModes, int, int, float);

/*
 *  Destroys the summary view UI and set variables
 */
extern void dispose_summary_view_ui();

/*
 *  Initializes every required variable to set up the view widgets
 */
extern void initialize_summary_view_variables(enum TrainingModes, int, int, float);

/*
 *  Initializes every UI component and assigns each component's default state
 */
extern void initialize_summary_view_widgets(GtkBuilder*);

#endif
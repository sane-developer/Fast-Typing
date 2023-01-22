#ifndef TRAININGVIEW_H
#define TRAININGVIEW_H

#include <gtk/gtk.h>
#include "../../enumerations/TrainingModes.h"

/*
 *  Initializes every required variable to set up the view widgets
 */
extern void initialize_training_view_variables(enum TrainingModes);

/*
 *  Initializes every UI component and assigns each component's default state
 */
extern void initialize_training_view_widgets(GtkBuilder*);

/*
 *  Renders the training view UI components
 */
extern void render_training_view_ui(enum TrainingModes);

/*
 *  Destroys the training view UI and frees allocated memory if any
 */
extern void dispose_training_view_ui();

#endif
#ifndef SETUPVIEW_H
#define SETUPVIEW_H

#include <gtk/gtk.h>

/*
 *  Renders the setup view UI components
 */
extern void render_setup_view_ui();

/*
 *  Destroys the setup view UI and set variables
 */
extern void dispose_setup_view_ui();

/*
 *  Initializes every required variable to set up the view widgets
 */
extern void initialize_setup_view_variables();

/*
 *  Initializes every UI component and assigns each component's default state
 */
extern void initialize_setup_view_widgets(GtkBuilder*);

/*
 *  Switches view context to Training view
 */
extern void switch_context_to_training_view();

#endif
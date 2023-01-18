#include <gtk/gtk.h>

/*
 *  Disconnects all of the signals from the parent widget to prevent memory leaks
 */
void disconnect_parent_signals(GtkWidget*);
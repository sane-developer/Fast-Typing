#include <gtk/gtk.h>

//  Disconnects all of the signals from the parent widget to prevent memory leaks
//
void disconnectParentSignals(GtkWidget *parent);
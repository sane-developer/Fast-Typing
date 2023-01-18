#include "Detach.h"

void disconnect_parent_signals(GtkWidget *parent)
{
    //  Gets the parent children
    //
    GList *children = gtk_container_get_children(GTK_CONTAINER(parent));

    //  Loops through the children
    //
    for (GList *iter = children; iter != NULL; iter = iter->next)
    {
        //  Gets the child  
        //
        GtkWidget *child = GTK_WIDGET(iter->data);

        //  Disconnects all the signals
        //
        g_signal_handlers_disconnect_by_data(child, parent);
    }
    
    //  Releases the memory taken by the children list
    //
    g_list_free(children);
}
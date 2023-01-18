#include <gtk/gtk.h>
#include "views/setup/SetupViewBehavior.h"

int main(int argc, char *argv[])
{
	//  Initializes the GTK
	//
	gtk_init(&argc, &argv);

	//  Renders the Setup View
	//
	render_setup_view();

	//  Returns the 0 code
	//
	return 0;
}


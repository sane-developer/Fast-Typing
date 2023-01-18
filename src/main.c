#include <gtk/gtk.h>
#include "views/setup/SetupViewBehavior.h"

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	render_setup_view_ui();
}
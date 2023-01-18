/*
 *  Sets up the required UI elements
 */
void initialize_summary_ui(GtkBuilder*);

/*
 *  Initializes the default states of UI elements
 */
void initialize_summary_ui_properties(int);

/*
 *  Initializes the required variables
 */
void initialize_summary_view_variables(int, int, float);

/*
 *  Renders the summary view
 */
void render_summary_view(int, int, float);

/*
 *  Disposes every element of summary view
 */
void dispose_summary_view();

/*
 *  Handles the page redirection upon clicking
 */
static void on_clicked(GtkWidget*, gpointer);
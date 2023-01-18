/*
 *  Sets up the required UI elements
 */
void initialize_training_ui(GtkBuilder*);

/*
 *  Initializes the default states of UI elements
 */
void initialize_training_ui_properties(int);

/*
 *  Initializes the required variables
 */
void initialize_training_view_variables(int, int);

/*
 *  Renders the training view
 */
void render_training_view(int, int);

/*
 *  Disposes every element of training view
 */
void dispose_training_view();

/*
 *  Allows the application to render next stage of the program
 */
void move_to_summary_view();

/*
 *  Handles new key insertions
 */
static void on_inserted(GtkWidget*, gpointer);
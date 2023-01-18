/*
 *  Initializes the required UI elements
 */
void initialize_setup_ui(GtkBuilder*);

/*
 *  Renders the setup view
 */
void render_setup_view();

/*
 *  Disposes every element of setup view
 */
void dispose_setup_view();

/*
 *  Allows the application to render next stage of the program
 */
void move_to_training_view();
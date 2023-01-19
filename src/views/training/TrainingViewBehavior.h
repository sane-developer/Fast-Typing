/*
 *  Initializes every required variable to set up the view widgets
 */
void initialize_training_view_variables(int, int);

/*
 *  Initializes every UI component and assigns each component's default state
 */
void initialize_training_view_widgets(GtkBuilder*);

/*
 *  Renders the training view UI components
 */
void render_training_view_ui(int, int);

/*
 *  Destroys the training view UI and frees allocated memory if any
 */
void dispose_training_view_ui();

/*
 *  Handles the actions upon key insertion
 */
void changed_input();

/*
 *  Allows to switch context to summary view
 */
void move_to_summary_view();
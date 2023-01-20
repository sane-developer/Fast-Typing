/*
 *  Initializes every required variable to set up the view widgets
 */
void initialize_training_view_variables(int);

/*
 *  Initializes every UI component and assigns each component's default state
 */
void initialize_training_view_widgets(GtkBuilder*);

/*
 *  Renders the training view UI components
 */
void render_training_view_ui(int);

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

/*
 *  Initializes the end time for the stopwatch
 */
void on_window_realize();

/*
 *  Updates the remaining time each second
 */
int update_remaining_time(gpointer);
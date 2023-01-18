/*
 *  Initializes every UI component and assigns each component's default state
 */
void initialize_setup_view_widgets(GtkBuilder*);

/*
 *  Renders the setup view UI components
 */
void render_setup_view_ui();

/*
 *  Destroys the setup view UI and frees allocated memory if any
 */
void dispose_setup_view_ui();

/*
 *  Switches view context to Training view
 */
void move_to_training_view();
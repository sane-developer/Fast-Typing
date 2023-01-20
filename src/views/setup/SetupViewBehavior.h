/*
 *  Renders the setup view UI components
 */
void render_setup_view_ui();

/*
 *  Destroys the setup view UI and frees allocated memory if any
 */
void dispose_setup_view_ui();

/*
 *  Initializes every UI component and assigns each component's default state
 */
void initialize_setup_view_widgets(GtkBuilder*);

/*
 *  Initializes every required variable to set up the view widgets
 */
void initialize_setup_view_variables();

/*
 *  Switches view context to Training view
 */
void move_to_training_view();

/*
 *  Switches chosen word range to all words
 */
void on_all_words_toggled();

/*
 *  Switches chosen word range to short words
 */
void on_short_words_toggled();

/*
 *  Switches chosen word range to long words
 */
void on_long_words_toggled();
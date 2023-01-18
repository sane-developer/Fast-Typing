/*
 *  Initializes every UI component and assigns each component's default state
 */
void initialize_summary_view_widgets(GtkBuilder*, int, int, float);

/*
 *  Renders the summary view UI components
 */
void render_summary_view_ui(int, int, float);

/*
 *  Destroys the summary view UI and frees allocated memory if any
 */
void dispose_summary_view_ui();

/*
 *  Switches view context to Setup view
 */
void move_to_setup_view();
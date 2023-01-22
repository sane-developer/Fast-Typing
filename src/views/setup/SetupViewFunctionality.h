#ifndef SETUPVIEWFUNCTIONALITY_H
#define SETUPVIEWFUNCTIONALITY_H

/*
 *  Creates the statistics file if it does not already exist
 */
extern void create_statistics_file();

/*
 *  Switches chosen word range to all words
 */
extern void on_all_words_toggled();

/*
 *  Switches chosen word range to short words
 */
extern void on_short_words_toggled();

/*
 *  Switches chosen word range to long words
 */
extern void on_long_words_toggled();

#endif
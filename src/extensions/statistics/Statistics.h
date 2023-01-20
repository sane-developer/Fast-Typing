#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  Defines the statistics grouped by type structure
 */
struct TypeStatistics
{
    const char* mode;
    int best_words_per_minute_score;
    int worst_words_per_minute_score;
    int average_words_per_minute_score;
};

/*
 *  Archives the training data into the archive file
 */
void archive_statistics(const char*, const char*, int);

/*
 *  Retrieves the statistics of currently played mode from archive file
 */
struct TypeStatistics* retrieve_statistics_by_mode(const char*, const char*);

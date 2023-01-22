#include "Statistics.h"

void archive_statistics(char* file_name, enum TrainingModes mode, int words_per_minute_score) 
{
    //  Opens file "archive.txt" in "append" mode
    //
    FILE* archive = fopen(file_name, "a"); 
    
    //  Checks if file was opened successfully
    //
    if (archive == NULL) 
    {
        return;
    }

    //  Writes the statistics data in the format "{mode}, {words_per_minute_score}\n" to the file
    //
    fprintf(archive, "%d, %d\n", mode, words_per_minute_score);
    
    //  Closes the file 
    //
    fclose(archive);
}

struct TypeStatistics* retrieve_statistics_by_mode(char* file_name, enum TrainingModes chosen_mode)
{
    //  Initializes the best words per minute score
    //
    int best_words_per_minute_score = 0;

    //  Initializes the worst words per minute score
    //
    int worst_words_per_minute_score = 0;

    //  Initializes the total words per minute score
    //
    int total_words_per_minute_score = 0;

    //  Initializes the total count of mode entries
    //
    int count = 0;

    //  Opens the file for reading
    //
    FILE* statistics_file = fopen(file_name, "r");

    //  Checks if file was opened successfully
    //
    if (statistics_file == NULL) 
    {
        //  Allocates memory for the statistics
        //
        struct TypeStatistics* stats = malloc(sizeof(struct TypeStatistics));
        
        //  Fills the default data
        //
        stats->mode = chosen_mode;
        stats->best_words_per_minute_score = 0;
        stats->worst_words_per_minute_score = 0;
        stats->average_words_per_minute_score = 0;
        
        //  Returns the struct
        //
        return stats;
    }

    //  Reads the file line by line
    //
    char line[256];

    //  Loops through every line of the statistics file
    //
    while (fgets(line, sizeof(line), statistics_file)) 
    {
        //  Splits the line into mode and words_per_minute_score
        //
        enum TrainingModes game_mode;
        
        //  Declares the words per minut score
        //
        int words_per_minute_score;
        
        //  Gets the variables from the line
        //
        sscanf(line, "%d, %d", &game_mode, &words_per_minute_score);

        //  Checks if the mode matches the mode we're looking for
        //
        if (chosen_mode == game_mode)
        {
            //  Update the statistics
            //
            count++;
            
            //  Updates the total words per minute score
            //
            total_words_per_minute_score += words_per_minute_score;
            
            //  Updates the best words per minute score
            //
            if (words_per_minute_score > best_words_per_minute_score) 
            {
                best_words_per_minute_score = words_per_minute_score;
            }
            
            //  Updates the worst words per minute score
            //
            if (words_per_minute_score < worst_words_per_minute_score) 
            {
                worst_words_per_minute_score = words_per_minute_score;
            }
        }
    }

    //  Closes the file
    //
    fclose(statistics_file);

    //  Declares the average words per minute score
    //
    int average_words_per_minute_score = 0;

    //  Computes the average words per minute score
    //
    if (count > 0) 
    {
        average_words_per_minute_score = total_words_per_minute_score / count;
    }

    //  Creates the TypeStatistics struct and return it
    //
    struct TypeStatistics* stats = malloc(sizeof(struct TypeStatistics));
    
    //  Fills the default data
    //
    stats->mode = chosen_mode;
    stats->best_words_per_minute_score = best_words_per_minute_score;
    stats->worst_words_per_minute_score = worst_words_per_minute_score;
    stats->average_words_per_minute_score = average_words_per_minute_score;
    
    //  Returns the struct
    //
    return stats;
}
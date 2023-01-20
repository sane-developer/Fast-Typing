#include "Statistics.h"

void archive_statistics(char* filename, int mode, int words_per_minute_score) 
{
    //  Opens file "archive.txt" in "append" mode
    //
    FILE* archive = fopen(filename, "a"); 
    
    //  Checks if file was opened successfully
    //
    if (archive == NULL) 
    {
        printf("Archive file doesn't exist");
        return;
    }

    //  Writes the statistics data in the format "{mode}, {words_per_minute_score}\n" to the file
    //
    fprintf(archive, "%d, %d\n", mode, words_per_minute_score);
    
    //  Closes the file 
    //
    fclose(archive);
}

struct TypeStatistics* retrieve_statistics_by_mode(char* filename, int mode)
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
    FILE* archive = fopen(filename, "r");

    //  Checks if file was opened successfully
    //
    if (archive == NULL) 
    {
        //  Creates the file of specified name
        //
        FILE* archive = fopen(filename, "a");

        //  Closes the file after creation
        //
        fclose(archive);

        //  Allocates memory for the statistics
        //
        struct TypeStatistics* stats = malloc(sizeof(struct TypeStatistics));
        
        //  Fills the default data
        //
        stats->mode = mode;
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

    //  Loops through every line of the archive file
    //
    while (fgets(line, sizeof(line), archive)) 
    {
        //  Splits the line into mode and words_per_minute_score
        //
        int game_mode;
        
        //  Declares the words per minut score
        //
        int words_per_minute_score;
        
        //  Gets the variables from the line
        //
        sscanf(line, "%d, %d", &game_mode, &words_per_minute_score);

        //  Checks if the mode matches the mode we're looking for
        //
        if (mode == game_mode)
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
    fclose(archive);

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
    stats->mode = mode;
    stats->best_words_per_minute_score = best_words_per_minute_score;
    stats->worst_words_per_minute_score = worst_words_per_minute_score;
    stats->average_words_per_minute_score = average_words_per_minute_score;
    
    //  Returns the struct
    //
    return stats;
}
#include "Words.h"

struct Words* read_words_from_file(const char* file_name) 
{
    //  Allocates memory for the struct Dictionary
    //
    struct Words* words = (struct Words*)malloc(sizeof(struct Words));

    //  Initializes the size to 0
    //
    words->size = 0;

    //  Allocates memory for the first element of the words array
    //
    words->words = (char**) realloc(NULL, sizeof(char*));

    //  Opens the dictionary file in read mode
    //
    FILE* dictionary_file = fopen(file_name, "r");

    //  Declares a buffer to store each word read from the dictionary file
    //
    char word[255];

    //  Reads the file word by word
    //
    while (fscanf(dictionary_file, "%s", word) == 1) 
    {
        //  Increases the size of the words array
        //
        words->size++;

        //  Reallocates memory for the words array to store the new word
        //
        words->words = (char**) realloc(words->words, words->size * sizeof(char*));

        //  Allocates memory for the new word and copies the word to it
        //
        words->words[words->size - 1] = strdup(word);
    }

    //  Closes the file
    //
    fclose(dictionary_file);

    //  Returns the words array
    //
    return words;
}

struct WordRange* get_range_from_mode(enum TrainingModes mode)
{
    struct WordRange* range = (struct WordRange*)malloc(sizeof(struct WordRange));

    if (mode == AllWords)
    {
        range->lowest_length = 1;
        range->highest_length = 12;
    }
    else if (mode == ShortWords)
    {
        range->lowest_length = 1;
        range->highest_length = 6;
    }
    else
    {
        range->lowest_length = 7;
        range->highest_length = 12;
    }

    return range;
}

int get_count_of_words_in_range(struct Words* dictionary, struct WordRange* range)
{
    //  Stores the number of eligible words
    //
    int count = 0;

    //  Iterates through the words array
    //
    for (int i = 0; i < dictionary->size; i++)
    {
        //  Gets the length of the current word
        //
        int length = strlen(dictionary->words[i]);
        
        //  Checks if the length of the word is in the range
        //
        if (length >= range->lowest_length && length <= range->highest_length)
        {
            //  Increments the count of eligible words
            //
            count++;
        }
    }

    //  Returns the count of available words
    //
    return count;
}

char** get_randomized_words(struct Words* words, struct WordRange* range) 
{
    //  Gets the number of words in the specified range
    //
    int count = get_count_of_words_in_range(words, range);

    //  Allocates memory for the randomized words array
    //
    char** randomized_words = (char**) malloc(count * sizeof(char*));

    //  Allocates memory for the used indexes array and set all elements to 0
    //
    int* used_indexes = (int*) calloc(words->size, sizeof(int));

    //  Keeps track of the current index in the randomized words array
    //
    int index = 0;
    
    //  Seeds the random number generator
    //
    srand(time(0));
    
    //  Loops until all of the words have been added to the words array
    //
    while (index < count) 
    {
        //  Generates a random index
        //
        int random_index = rand() % words->size;

        //  Checks if the index has not already been added and the length respects the range criteria
        //
        if (used_indexes[random_index] == 0 && 
            strlen(words->words[random_index]) >= range->lowest_length && 
            strlen(words->words[random_index]) <= range->highest_length) 
        {
            //  Allocates memory for the selected word and copy it to the randomized words array
            //
            randomized_words[index] = strdup(words->words[random_index]);
            
            //  Marks the index as used
            //
            used_indexes[random_index] = 1;
            
            //  Increments the current index
            //
            index++;
        }
    }

    //  Frees the memory used for the used indexes array
    //
    free(used_indexes);
    
    //  Returns the randomized words that match the range criteria
    //
    return randomized_words;
}

void dispose_words(char** words, int count)
{
    for (int i = 0; i < count; i++) 
    {
        free(words[i]);
    }

    free(words);
}
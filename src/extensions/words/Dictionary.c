#include "Dictionary.h"

struct Dictionary* read_words_from_file(const char* file_name) 
{
    //  Allocates memory for the struct Dictionary
    //
    struct Dictionary* words = (struct Dictionary*)malloc(sizeof(struct Dictionary));

    //  Initializes the size to 0
    //
    words->size = 0;

    //  Allocates memory for the first element of the words array
    //
    words->words = (char**) realloc(NULL, sizeof(char*));

    //  Opens the file in read mode
    //
    FILE* file = fopen(file_name, "r");

    //  Declares a buffer to store each word read from the file
    //
    char word[255];

    //  Reads the file word by word
    //
    while (fscanf(file, "%s", word) == 1) 
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
    fclose(file);

    //  Returns the words array
    //
    return words;
}

struct WordRange* get_range_from_string(char* rangeType)
{
    //  Allocates memory for the struct WordRange
    //
    struct WordRange* range = (struct WordRange*)malloc(sizeof(struct WordRange));

    //  Checks if the rangeType string is equal to "all"
    //
    if (strcmp(rangeType, "all") == 0)
    {
        //  Sets the lowest and highest length of the range to 1 and 12 respectively
        //
        range->lowestLength = 1;
        range->highestLength = 12;
    }

    //  Checks if the rangeType string is equal to "short"
    //
    else if (strcmp(rangeType, "short") == 0)
    {
        //  Sets the lowest and highest length of the range to 1 and 6 respectively
        //
        range->lowestLength = 1;
        range->highestLength = 6;
    }
    else
    {
        //  If the rangeType string is not "all" or "short", set the lowest and highest length of the range to 7 and 12 respectively
        //
        range->lowestLength = 7;
        range->highestLength = 12;
    }

    //  Returns the struct WordRange
    //
    return range;
}

int get_count_of_words_in_range(struct Dictionary* dictionary, struct WordRange* range)
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
        if (length >= range->lowestLength && length <= range->highestLength)
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

char** get_randomized_words(struct Dictionary* words, struct WordRange* range) 
{
    //  Gets the number of words in the specified range
    //
    int count = get_count_of_words_in_range(words, range);

    //  Allocates memory for the randomized words array
    //
    char** randomizedWords = (char**) malloc(count * sizeof(char*));

    //  Allocates memory for the used indexes array and set all elements to 0
    //
    int* usedIndexes = (int*) calloc(words->size, sizeof(int));

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
        int randomIndex = rand() % words->size;

        //  Checks if the index has not already been added and the length respects the range criteria
        //
        if (usedIndexes[randomIndex] == 0 && 
            strlen(words->words[randomIndex]) >= range->lowestLength && 
            strlen(words->words[randomIndex]) <= range->highestLength) 
        {
            //  Allocates memory for the selected word and copy it to the randomized words array
            //
            randomizedWords[index] = strdup(words->words[randomIndex]);
            
            //  Marks the index as used
            //
            usedIndexes[randomIndex] = 1;
            
            //  Increments the current index
            //
            index++;
        }
    }

    //  Frees the memory used for the used indexes array
    //
    free(usedIndexes);
    
    //  Returns the randomized words that match the range criteria
    //
    return randomizedWords;
}

void dispose_words(char** words, int count)
{
    //  Loops through the words array
    //
    for (int i = 0; i < count; i++) 
    {
        //  Frees the memory allocated for each word
        //
        free(words[i]);
    }

    //  Frees the memory allocated for the words array
    //
    free(words);
}
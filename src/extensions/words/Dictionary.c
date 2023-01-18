#include "Dictionary.h"

struct Dictionary* read_words_from_file(const char* file_name) 
{
    //  Allocates memory for the struct Dictionary
    //
    struct Dictionary* words = (struct Dictionary*)malloc(sizeof(struct Dictionary));
    
    //  Initializes the size to 0
    //
    words->size = 0;
    
    //  Initializes the words array to NULL
    //
    words->words = NULL;
    
    //  Opens the file in read mode
    //
    FILE* file = fopen(file_name, "r");

    //  Declares a buffer to store each line read from the file
    //
    char line[255];

    //  Reads the file line by line
    //
    while (fgets(line, sizeof(line), file)) 
    {
        //  Gets the length of the line
        //
        int len = strlen(line);

        //  Replaces the newline character with a null terminator
        //
        if (line[len - 1] == '\n') 
        {
            line[len - 1] = '\0';
        }

        //  Increases the size of the words array
        //
        words->size++;
        
        //  Reallocates memory for the words array to store the new word
        //
        words->words = (char**) realloc(words->words, words->size * sizeof(char*));
        
        //  Allocates memory for the new word
        //
        words->words[words->size - 1] = (char*) malloc((len + 1) * sizeof(char));
        
        //  Copies the line to the last element of the words array
        //
        strcpy(words->words[words->size - 1], line);
    }

    //  Closes the file
    //
    fclose(file);

    //  Returns the words array
    //
    return words;
}

char** get_random_words(struct Dictionary* words, int n, int m) 
{
    //  Initializes an array to store the selected words
    //
    char** selected_words = malloc(n * sizeof(char*));

    //  Initializes a variable to store the number of words added to the selected_words array
    //
    int words_added = 0;
    
    //  Seeds the random number generator
    //
    srand(time(NULL));
    
    //  Iterates through the words array
    //
    for (int i = 0; i < words->size; i++) 
    {
        //  Checks if the length of the current word is equal to m
        //
        if (strlen(words->words[i]) == m) 
        {
            //  If it is, checks if the number of words added to the selected_words array is less than n
            //
            if (words_added < n) 
            {
                //  If it is, randomly selects a word from the list of potential words
                //
                int rand_index = rand() % words->size;
                
                //  Checks if the selected word has already been added to the selected_words array
                //
                int duplicate = 0;
                
                for (int j = 0; j < words_added; j++) 
                {
                    if (strcmp(selected_words[j], words->words[rand_index]) == 0) 
                    {
                        duplicate = 1;
                        break;
                    }
                }
                
                //  If the selected word is not a duplicate, adds it to the selected_words array
                //
                if (!duplicate) 
                {
                    selected_words[words_added] = words->words[rand_index];
                    
                    words_added++;
                }
            }
            else 
            {
                break;
            }
        }
    }

    return selected_words;
}
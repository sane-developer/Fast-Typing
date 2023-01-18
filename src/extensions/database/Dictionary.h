#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  Defines the dictionary struct
 */
struct Dictionary 
{
    int size;
    char** words;
};

/*
 *  Gets the words from the file of specified name
 */
struct Dictionary* read_words_from_file(const char*);

/*
 *  Gets {count} random words each of length equal {length} from the dictionary
 */
char** get_random_words(struct Dictionary*, int, int);
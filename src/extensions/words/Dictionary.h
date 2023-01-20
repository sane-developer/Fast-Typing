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
 *  Defines the word length range struct
 */
struct WordRange 
{
    int lowestLength;
    int highestLength;
};

/*
 *  Gets the words from the file of specified name
 */
struct Dictionary* read_words_from_file(const char*);

/*
 *  Gets the word range from the specified string
 */
struct WordRange* get_range_from_string(char*);

/*
 *  Gets the number of words that fall in the specified range
 */
int get_count_of_words_in_range(struct Dictionary*, struct WordRange*);

/*
 *  Gets randomized words of specified range
 */
char** get_randomized_words(struct Dictionary*, struct WordRange*);

/*
 *  Disposes the randomly chosen words
 */
void dispose_words(char**, int);
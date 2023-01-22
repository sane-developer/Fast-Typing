#ifndef WORDS_H
#define WORDS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../enumerations/TrainingModes.h"

/*
 *  Defines the dictionary struct
 */
struct Words 
{
    int size;
    char** words;
};

/*
 *  Defines the word length range struct
 */
struct WordRange 
{
    int lowest_length;
    int highest_length;
};

/*
 *  Gets the words from the file of specified name
 */
struct Words* read_words_from_file(const char*);

/*
 *  Gets the word range from the specified from provided training mode
 */
struct WordRange* get_range_from_mode(enum TrainingModes);

/*
 *  Gets the number of words that fall in the specified range
 */
int get_count_of_words_in_range(struct Words*, struct WordRange*);

/*
 *  Gets randomized words of specified range
 */
char** get_randomized_words(struct Words*, struct WordRange*);

/*
 *  Disposes the randomly chosen words
 */
void dispose_words(char**, int);

#endif
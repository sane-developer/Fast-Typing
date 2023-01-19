#include <time.h>

/*
 *  Defines the time when user gains ability to type words
 */
clock_t StartTime;

/*
 *  Defines the total count of words
 */
int TotalWordsCount;

/*
 *  Defines the written count of words
 */
int WrittenWordsCount;

/*
 *  Defines the count of words that have been correctly typed
 */
int CorrectWordsCount;

/*
 *  Defines the count of words that have been incorrectly typed
 */
int IncorrectWordsCount;

/*
 *  Defines the next word to type
 */
char *CurrentWord;

/*
 *  Defines the words to type
 */
char **AvailableWords;
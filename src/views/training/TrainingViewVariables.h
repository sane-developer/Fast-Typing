#include <time.h>

/*
 *  Defines the time when user gains ability to type words
 */
time_t RemainingTime;

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
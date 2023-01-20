#include <time.h>

/*
 *  Defines the time when user gains ability to type words
 */
clock_t StartTime;

/*
 *  Defines the total time for the training (60s)
 */
clock_t RemainingTime = 60000;

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
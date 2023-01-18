#include <time.h>

/*
 *  Defines the time when user gains ability to type words
 */
clock_t StartTime;

/*
 *  Defines the time when all of the requested words have been typed
 */
clock_t FinishTime;

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
gchar *WordToType;

/*
 *  Defines the words to type dictionary
 */
gchar **WordsToType;
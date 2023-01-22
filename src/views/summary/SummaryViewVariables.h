#ifndef SUMMARYVIEWVARIABLES_H
#define SUMMARYVIEWVARIABLES_H

#include "../../extensions/data/Statistics.h"

/*
 *  Defines the file name of the archive 
 */
char* ArchiveFileName;

/*
 *  Defines the input accuracy
 */
float Accuracy;

/*
 *  Defines the words per minute ratio
 */
int WordsPerMinute;

/*
 *  Defines the correct words
 */
int CorrectWords;

/*
 *  Defines the incorrect words
 */
int IncorrectWords;


/*
 *  Defines the type statistics for chosen mode by player
 */
struct TypeStatistics* GameModeStatistics;

#endif
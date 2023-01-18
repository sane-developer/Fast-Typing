#include "Compare.h"

int compare_strings(const char *source, const char *target)
{
    int i;

    for (i = 0; source[i] != '\0' && target[i] != '\0'; i++) 
    {
        if (source[i] != target[i]) 
        {
            return -1;
        }
    }

    if (source[i] != '\0' || target[i] != '\0') 
    {
        return 1;
    }

    return 0;
}
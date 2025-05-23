#include "../include/input.h"

int read(char *string, int length)
{
    char *startingPos = NULL;

    if (fgets(string, length, stdin) != NULL)
    {
        startingPos = strchr(string, '\n');
        if (startingPos != NULL)
        {
            *startingPos = '\0';
        }
        else
        {
            emptyBuffer();
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

void emptyBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void strlwr(char *s)
{
    while (*s)
    {
        *s = tolower(*s);
        s++;
    }
}
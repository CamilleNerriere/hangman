#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./include/game.h"
#include "./include/input.h"


void initializePlayerGuessTries(char *playerGuessTries, int wordLength);


int main(int argc, const char *argv[])
{
    int remainingTries = 10;
    int hasWon = 0;
    int nbOfTries = 0;

    char guessWord[50];

    printf("Joueur 1 : choisissez un mot : ");
    read(guessWord, 50);
    strlwr(guessWord);

    int wordLength = strlen(guessWord);

    char *playerGuessTries = malloc(sizeof(char) * wordLength);

    if (!playerGuessTries)
    {
        fprintf(stderr, "Malloc Error.\n");
        return 1;
    }

    char askedLetters[50] = {0};
    char lastLetterAsked = 0;

    initializePlayerGuessTries(playerGuessTries, wordLength);

    playHangman(playerGuessTries, &hasWon, &remainingTries, guessWord, askedLetters, &lastLetterAsked, wordLength, &nbOfTries);

    free(playerGuessTries);
    return 0;
}


void initializePlayerGuessTries(char *playerGuessTries, int wordLength)
{
    for (size_t i = 0; i < wordLength; i++)
    {
        playerGuessTries[i] = '*';
    }
}





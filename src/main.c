#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int read(char *string, int length);
void emptyBuffer();
void initializePlayerGuessTries(char *playerGuessTries, int wordLength);
void strlwr(char *s);
void addTryToAskedLetter(char *askedLetters, char *lastLetterAsked);
void checkIfGoodTry(char lastLetterAsked, char *playerGuessTries, char *guessWord, int *remainingTries, int wordLenght);
void checkIfHasWon(char *playerGuessTries, int *hasWon, int wordLenght);
void printHangman();

int main(int argc, const char *argv[])
{
    int remainingTries = 10;
    int hasWon = 0;
    int nbOfTries = 0;

    char guessWord[50];

    printf("Joueur 1 : choisissez un mot : ");
    read(guessWord, 50);
    strlwr(guessWord);

    int wordLenght = strlen(guessWord);

    char *playerGuessTries = malloc(sizeof(char) * wordLenght);

    char askedLetters[50] = {0};
    char lastLetterAsked = 0;

    initializePlayerGuessTries(playerGuessTries, wordLenght);

    while (hasWon != 1 && remainingTries > 0)
    {
        printf("Joueur 2 - Mot à deviner : %s \n\n", playerGuessTries);
        printf("Nombre de tentatives restantes : %d \n\n", remainingTries);
        printf("Devinez une lettre : ");
        addTryToAskedLetter(askedLetters, &lastLetterAsked);
        printf("Lettres déja demandées : ");
        for (size_t i = 0; i < 50 && askedLetters[i] != '0'; i++)
        {
            printf("%c ", askedLetters[i]);
        }
        printf("\n\n");

        checkIfGoodTry(lastLetterAsked, playerGuessTries, guessWord, &remainingTries, wordLenght);
        checkIfHasWon(playerGuessTries, &hasWon, wordLenght);
        nbOfTries++;
    }

    if (hasWon == 1)
    {
        printf("Bravo, vous avez gagné en %d coups \n", nbOfTries);
    }
    else
    {
        printHangman();
    }

    free(playerGuessTries);
    return 0;
}

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

void initializePlayerGuessTries(char *playerGuessTries, int wordLength)
{
    for (size_t i = 0; i < wordLength; i++)
    {
        playerGuessTries[i] = '*';
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

void addTryToAskedLetter(char *askedLetters, char *lastLetterAsked)
{
    *lastLetterAsked = getchar();
    emptyBuffer();

    for (size_t i = 0; i < 50; i++)
    {
        if (askedLetters[i] == '\0')
        {
            askedLetters[i] = *lastLetterAsked;
            break;
        }
    }
}

void checkIfGoodTry(char lastLetterAsked, char *playerGuessTries, char *guessWord, int *remainingTries, int wordLenght)
{
    int guessRight = 0;

    for (size_t i = 0; i <= wordLenght; i++)
    {
        if (guessWord[i] == lastLetterAsked)
        {
            playerGuessTries[i] = lastLetterAsked;
            guessRight = 1;
        }
    }

    if (guessRight == 1)
    {
        printf("Bien joué, le mot contient bien la lettre %c \n", lastLetterAsked);
    }
    else
    {
        (*remainingTries)--;
        printf("Bien tenté, mais le mot ne contient pas la lettre %c \n", lastLetterAsked);
    }
}

void checkIfHasWon(char *playerGuessTries, int *hasWon, int wordLenght)
{
    int remainLetterToGuess = 0;
    for (size_t i = 0; i <= wordLenght; i++)
    {
        if (playerGuessTries[i] == '*')
        {
            remainLetterToGuess = 1;
        }
    }

    if (remainLetterToGuess == 0)
    {
        *hasWon = 1;
    }
}

void printHangman()
{
    printf("\n");
    printf("  _______\n");
    printf(" |/      |\n");
    printf(" |      (_)\n");
    printf(" |      \\|/\n");
    printf(" |       |\n");
    printf(" |      / \\\n");
    printf(" |\n");
    printf("_|___\n");
    printf("\n Perdu ! \n");
}
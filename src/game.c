#include "../include/game.h"
#include "../include/input.h"

void addTryToAskedLetter(char *askedLetters, char *lastLetterAsked)
{
    *lastLetterAsked = getchar();
    emptyBuffer();

    for (int i = 0; i < 50; i++)
    {
        if (askedLetters[i] == '\0')
        {
            askedLetters[i] = *lastLetterAsked;
            break;
        }
    }
}

void checkIfGoodTry(char lastLetterAsked, char *playerGuessTries, char *guessWord, int *remainingTries, int wordLength)
{
    int guessRight = 0;

    for (int i = 0; i < wordLength; i++)
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

void checkIfHasWon(char *playerGuessTries, int *hasWon, int wordLength)
{
    int remainLetterToGuess = 0;
    for (size_t i = 0; i < wordLength; i++)
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

void playHangman(char *playerGuessTries, int *hasWon, int *remainingTries, char *guessWord, char *askedLetters, char *lastLetterAsked, int wordLength, int *nbOfTries)
{
    while (*hasWon != 1 && *remainingTries > 0)
    {
        printf("Joueur 2 - Mot à deviner : %s \n\n", playerGuessTries);
        printf("Nombre de tentatives restantes : %d \n\n", *remainingTries);
        printf("Devinez une lettre : ");
        addTryToAskedLetter(askedLetters, lastLetterAsked);
        printf("Lettres déja demandées : ");
        for (int i = 0; i < 50 && askedLetters[i] != '0'; i++)
        {
            printf("%c ", askedLetters[i]);
        }
        printf("\n\n");

        checkIfGoodTry(*lastLetterAsked, playerGuessTries, guessWord, remainingTries, wordLength);
        checkIfHasWon(playerGuessTries, hasWon, wordLength);
        (*nbOfTries)++;
    }

    if (*hasWon == 1)
    {
        printf("Bravo, vous avez gagné en %d coups \n", *nbOfTries);
        printf("Le mot à deviner était : %s \n", guessWord);
    }
    else
    {
        printHangman();
        printf("Le mot à deviner était : %s \n", guessWord);
    }
}

#ifndef game_h 
#define game_h

#include <stdio.h>

void addTryToAskedLetter(char *askedLetters, char *lastLetterAsked);
void checkIfGoodTry(char lastLetterAsked, char *playerGuessTries, char *guessWord, int *remainingTries, int wordLength);
void checkIfHasWon(char *playerGuessTries, int *hasWon, int wordLength);
void printHangman();
void playHangman(char *playerGuessTries, int *hasWon, int *remainingTries, char *guessWord, char *askedLetters, char *lastLetterAsked, int wordLength, int *nbOfTries);

#endif
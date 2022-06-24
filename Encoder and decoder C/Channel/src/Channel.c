#include <Channel.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int GetRandomNumber() {
    return rand() % 8;
}

char RandomizeChar(char inputCharacter, int bitNumber) {
    return inputCharacter ^ (1 << bitNumber);
}
#include <stdio.h>
#include <stdint.h>

char EncodeNibble(char);
void GenerateParityBits(char, char, char, char, char*, char*, char*);
char ExtractLowNibble(char);
char ExtractHighNibble(char);
char ConstructByte(char, char, char, char, char, char, char);
#include <stdio.h>
#include <stdint.h>

char DecodeNibble(char);
void ExtractBits(char, uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*);
uint8_t VerifyParityBits(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t*, uint8_t*, uint8_t*);
void PrintByte(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
void ConstructNibble(char, char, char, char, char*);
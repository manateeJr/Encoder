#include <Encode.h>

// The expected input here is a high or low nibble in the format 0000 b3 b2 b1 b0
char EncodeNibble(char inputNibble) {
    char d0 = inputNibble & 1;
    char d1 = (inputNibble & (1 << 1)) >> 1;
    char d2 = (inputNibble & (1 << 2)) >> 2;
    char d3 = (inputNibble & (1 << 3)) >> 3;

    // char d1 = (inputNibble >> 1) & 1;

    char p0, p1, p2;
    GenerateParityBits(d0, d1, d2, d3, &p0, &p1, &p2);
    
    inputNibble = ConstructByte(p0, p1, p2, d0, d1, d2, d3);
    return inputNibble;
}

// Returns parity bits on the appropriate positions
void GenerateParityBits(char d0, char d1, char d2, char d3, char* p0, char* p1, char* p2) {
    *p0 = (d0 + d1 + d2) % 2;
    *p2 = (d1 + d2 + d3) % 2;
    *p1 = (d0 + d1 + d3) % 2;
}

char ExtractLowNibble(char inputByte) {
    return inputByte & 0b1111;
}
char ExtractHighNibble(char inputByte){
    return inputByte >> 4;   
}

char ConstructByte(char p0, char p1, char p2, char d0, char d1, char d2, char d3) {
    char inputNibble;

    inputNibble &= 0;
    inputNibble |= p0;
    inputNibble |= p1 << 1;
    inputNibble |= p2 << 2;
    inputNibble |= d0 << 3;
    inputNibble |= d1 << 4;
    inputNibble |= d2 << 5;
    inputNibble |= d3 << 6;

    return inputNibble;
}
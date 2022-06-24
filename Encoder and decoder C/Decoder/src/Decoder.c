/

#include "Decoder.h"

char DecodeNibble(char inputNibble) { 
    // Extract bits
    uint8_t p0, p1, p2, d0, d1, d2, d3, MSB;
    ExtractBits(inputNibble, &p0, &p1, &p2, &d0, &d1, &d2, &d3, &MSB);

    // Check is MSB is corrupt
    if (MSB == 1) {
        ConstructNibble(d0, d1, d2, d3, &inputNibble);
        return inputNibble;
    }

    // Check which parity bits are corrupt
    uint8_t p0Corrupt, p1Corrupt, p2Corrupt;
    uint8_t corruptParityBits = VerifyParityBits(p0, p1, p2, d0, d1, d2, d3, &p0Corrupt, &p1Corrupt, &p2Corrupt);

    // Locate corrupt data bits
    if (corruptParityBits == 1) {
        ConstructNibble(d0, d1, d2, d3, &inputNibble);
        return inputNibble;
    }
    else if (corruptParityBits == 2) {
        if (p0Corrupt & p1Corrupt) {
            d0 ^= 1;
        }
        else if (p0Corrupt & p2Corrupt) {
            d2 ^= 1;
        }
        else if (p1Corrupt & p2Corrupt) {
            d3 ^= 1;
        }
    }
    else if (corruptParityBits == 3) {
        d1 ^= 1; // d1 = d1 ^ 1;
    }
    
    ConstructNibble(d0, d1, d2, d3, &inputNibble);
    return inputNibble;
}

// Extracts parity and data bits
void ExtractBits(char inputCharacter, uint8_t* p0, uint8_t* p1, uint8_t* p2, uint8_t* d0, uint8_t* d1, uint8_t* d2, uint8_t* d3, uint8_t* MSB) {
    *p0 = inputCharacter & 1;
    *p1 = (inputCharacter >> 1) & 1;
    *p2 = (inputCharacter >> 2) & 1;

    *d0 = (inputCharacter >> 3) & 1;
    *d1 = (inputCharacter >> 4) & 1;
    *d2 = (inputCharacter >> 5) & 1;
    *d3 = (inputCharacter >> 6) & 1;

    *MSB = (inputCharacter >> 7) & 1;
}

// Function for debugging/testing
void PrintByte(uint8_t p0, uint8_t p1, uint8_t p2, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t MSB) {
     printf("\n\nByte: %d%d%d%d%d%d%d%d", MSB, d3, d2, d1, d0, p2, p1, p0);
}

// Function that counts corrupt parity bits in a byte
uint8_t VerifyParityBits(uint8_t p0, uint8_t p1, uint8_t p2, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t* p0Corrupt,  uint8_t* p1Corrupt,  uint8_t* p2Corrupt) {
    uint8_t corruptParityBitsCount = 0;
    
    if (((p0 + d0 + d1 + d2) % 2) != 0) {
        *p0Corrupt = 1;
        corruptParityBitsCount++;
    }
    else {
        *p0Corrupt = 0;
    } 
    
    if (((p1 + d0 + d1 + d3) % 2) != 0) {
        *p1Corrupt = 1;
        corruptParityBitsCount++;
    }
    else {
        *p1Corrupt = 0;
    } 

    if (((p2 + d1 + d2 + d3) % 2) != 0) {
        *p2Corrupt = 1;
        corruptParityBitsCount++;
    }
    else {
        *p2Corrupt = 0;
    }
    
    return corruptParityBitsCount;
}

void ConstructNibble (char d0, char d1, char d2, char d3, char* nibble) {
        *nibble &= 0;
        *nibble |= d0;
        *nibble |= d1 << 1;
        *nibble |= d2 << 2;
        *nibble |= d3 << 3;
}
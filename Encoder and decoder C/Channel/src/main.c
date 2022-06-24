// The channel simulates a transmission channel and corrupts each byte by flipping a bit. The channel reads data from the 'encodedData'
// file and writes the corrupted data to 'transmittedData'. We achieve that by using the command line. The first arguement is the 
// input and the second arguement is the output.

#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <Channel.h>

int main(int argc, char* argv[])
{
	FILE* inputFile = NULL;
	FILE* outputFile = NULL;
	
	inputFile = fopen(argv[1], "rb");
	outputFile = fopen(argv[2], "wb");
	
	if (inputFile == NULL) {
		printf("Failed to open input file.");
		return 0;
	}

	if (outputFile == NULL) {
		printf("Failed to open output file.");
		return 0;
	}

	char inputCharacter, randomizedChar;
	srand(time(NULL));
	
	while ((inputCharacter = fgetc(inputFile)) != EOF) {		
		randomizedChar = RandomizeChar(inputCharacter, GetRandomNumber());
		fputc(randomizedChar, outputFile);
	}

	fclose(inputFile);
	fclose(outputFile);

	return (0);
}
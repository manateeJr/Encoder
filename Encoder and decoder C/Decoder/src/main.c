// The decoder reads and decodes data from the channel and writes it onto the decodedData output text file.


#include <Decoder.h>

int main(int argc, char* argv[])
{
	FILE* inputFile = NULL;
	FILE* outputFile = NULL;

	inputFile = fopen(argv[1], "rb");
	outputFile = fopen(argv[2], "w");

	if (inputFile == NULL) {
		printf("Failed to open input file.");
		return 0;
	}

	if (outputFile == NULL) {
		printf("Failed to open output file.");
		return 0;
	}

	char inputCharacter, lowNibble, highNibble;
	
	while ((inputCharacter = fgetc(inputFile)) != EOF) {
		lowNibble = DecodeNibble(inputCharacter);
		
		inputCharacter = fgetc(inputFile);
		highNibble = DecodeNibble(inputCharacter);

		inputCharacter = lowNibble | (highNibble << 4);
		
		fputc(inputCharacter, outputFile);
	}

	fclose(inputFile);
	fclose(outputFile);
	return (0);
}
// The encoder encrypts data from the inputData.txt file using the command line when executing. The first arguement is the input file 
// and the second file is the output file (encodedData)
#include <Encode.h>

int main(int argc, char* argv[])
{

	FILE* inputFile = NULL;
	FILE* outputFile = NULL;

	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "wb");

	if (inputFile == NULL) {
		printf("Failed to open input file.");
		return 0;
	}

	if (outputFile == NULL) {
		printf("Failed to open output file.");
		return 0;
	}
	char lowNibble, inputCharacter, highNibble;
	
	while ((inputCharacter = fgetc(inputFile)) != EOF) {
		// if (inputCharacter == EOF) break;

		lowNibble = ExtractLowNibble(inputCharacter);
		fputc(EncodeNibble(lowNibble), outputFile);

		highNibble = ExtractHighNibble(inputCharacter);
		fputc(EncodeNibble(highNibble), outputFile);
	}

	fclose(inputFile);
	fclose(outputFile);
	return (0);
}
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *input, *output;
	int count = 0;
	
	if (argv[1] == NULL || argv[2] == NULL) {
		printf("Incorrect number of arguments!\n");
	return 0;
	}

	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");

	if (input == NULL || output == NULL) {
		printf("Something broke.\n");
		fclose(input);
		fclose(output);
		return 0;
	}

	do{
		char c = fgetc(input);
		if (feof(input)) break;
		fputc(c, output);
		count ++;
		} while(1);
		
	printf("File copied!\nTotal characters: %i\n", count);
	fclose(input);
	fclose(output);
	return 0;
}
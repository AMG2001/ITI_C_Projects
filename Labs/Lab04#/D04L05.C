#include <stdio.h>
#include <stdlib.h>

void readStrings(char** strings, int numStrings, int stringSize) {
    int i;
    for (i = 0; i < numStrings; i++) {
        printf("Enter string %d: ", i + 1);
        scanf(" %[^\n]", strings[i]);

        // Add terminator character if the input string exceeds the specified size
        if (strlen(strings[i]) > stringSize) {
            strings[i][stringSize] = '\0';
        }
    }
}

void printStrings(char** strings, int numStrings) {
    int i;
    for (i = 0; i < numStrings; i++) {
        printf("String %d: %s\n", i + 1, strings[i]);
    }
}

void main(void) {
	int numStrings, stringSize;
	int i;
	char** strings;

	clrscr();
	printf("Enter the number of strings: ");
	scanf("%d", &numStrings);

	printf("Enter the size of each string: ");
	scanf("%d", &stringSize);

	// Allocate memory for the array of strings
	strings = (char**)malloc(numStrings * sizeof(char*));
	for (i = 0; i < numStrings; i++) {
		strings[i] = (char*)malloc((stringSize + 1) * sizeof(char));
	}

	readStrings(strings, numStrings, stringSize);
	printStrings(strings, numStrings);

	// Free memory for the array of strings
	for (i = 0; i < numStrings; i++) {
		free(strings[i]);
	}
	free(strings);

    getch();
}

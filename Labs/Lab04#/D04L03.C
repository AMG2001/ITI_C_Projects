#include <stdio.h>

void stringCopy(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main(void) {
    char source[] = "Hello in AMG World";
    char destination[20];

    clrscr();
	stringCopy(destination, source);

	printf("\n\nSource string : %s \n\n", source);
	printf("Destination string: %s", destination);

	getch();
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	unsigned int number = 5;

	char *str = (char *) malloc(sizeof(char) * 2);

        sprintf(str, "%d", number);

	printf("number converted to string %s\n", str);

	return 0;
}


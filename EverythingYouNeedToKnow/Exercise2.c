#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer;
	size_t len = 32;
	size_t string;

	buffer = malloc(len * sizeof(char));
	if (buffer == NULL)
		return -1;

	write(STDOUT_FILENO, "$ ", 2);
	string = getline(&buffer, &len, stdin);
	printf("You typed:%s \n", buffer);

	return 0;
}

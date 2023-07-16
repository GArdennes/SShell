#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char string[] = "I wish I knew it all";
	char *characters;

	characters = strtok(string, " ");
	if (characters == NULL)
		return 0;

	while (characters != NULL)
	{
		printf("Words: %s \n", characters);
		characters = strtok(NULL, " ");
	}

	return 0;
}

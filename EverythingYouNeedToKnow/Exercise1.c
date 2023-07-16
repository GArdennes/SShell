#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0;
	int counter;

	while(argv[i] != NULL)
	{
		i++;
	}

	for (counter = 0; counter < i; counter++)
	{
		printf("%s \n", argv[counter]);
	}

	return 0;
}

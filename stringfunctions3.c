#include "shell.h"

/*
 *_puts - prints string
 *@str: characters to check
 *Return: On success the string
 
void _puts(char *str)
{
int count = 0;

if(str == NULL)
return;

while(str[count] != '\0')
{
_putchar(str[count]);
count++;
}
}
*/

/**
*_putchar - prints single character
*@ch: character to check
*Return: On success the character

char _putchar(char ch)
{
return (write(1,&ch,1));
}
*/

/**
 *_memset - fill a block of memory with value
 *@s: character to check
 *@b: character to check
 *@n: number to check
 *Return: On success memory allocation
 */
/*
char *_memset(char *s, char b, unsigned int n)
{

char *buffer to create space
find the length of the string 
allocate memory with malloc
create a loop to fill string with character
for the number of integer value times
return string

char *string = s;

while (n > 0)
{
	*s = b;
	s++;
	n--;
}

return (string);
}
*/

/**
 * _eatoi - function to convert exit code to integer
 * @s: the string to check
 * Return: On success integer value
 */
int _eatoi(char *s)
{
int i, j, n, x;

i = n = 0;
x = 1;
while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
{
if (s[i] == '-')
x *= -1;
i++;
}
j = i;
while ((s[j] >= '0') && (s[j] <= '9'))
{
n = (n * 10) + x * ((s[j]) - '0');
j++;
}
return (n);
}

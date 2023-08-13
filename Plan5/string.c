#include "sshell.h"

/**
 * _strdup - strdup function
 * @str: string to strdup
 * Return: On success char*
 */
char *_strdup(char *str)
{
size_t length, index;
char *ret;

if (str == NULL)
return (NULL);

length = _strlen(str);
ret = malloc(length + 1);

if (ret == NULL)
return (NULL);

for (index = 0; index < length; index++)
ret[index] = str[index];

ret[length] = '\0';
return (ret);
}

/**
 * count_words - count words in a string
 * @str: the string to count
 * @d: the string to check
 * Return: On success int
 */
int count_words(char *str, char *d)
{
int numwords = 0;
int i;

if (str == NULL || str[0] == '\0')
return (0);

if (d == NULL)
d = " ";

for (i = 0; str[i] != '\0'; i++)
{
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || str[i + 1] == '\0'))
numwords++;
}
return (numwords);
}

/**
 * allocate_string_array - allocate a string array
 * @size: size of the array
 * Return: On success char**
 */
char **allocate_string_array(int size)
{
char **s = malloc((size + 1) * sizeof(char *));

if (s == NULL)
return (NULL);

return (s);
}

/**
 * split_string - split a string into tokens
 * @str: the string to split
 * @d: the delimiter
 * @result: the result
 */
void split_string(char *str, char *d, char **result)
{
int i, j, k, m;
int numwords = count_words(str, d);

for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], d) && str[i + k] != '\0')
k++;

result[j] = malloc((k + 1) * sizeof(char));
if (result[j] == NULL)
{
for (k = 0; k < j; k++)
free(result[k]);
free(result);
return;
}

for (m = 0; m < k; m++)
result[j][m] = str[i++];
result[j][m] = '\0';
}
result[j] = NULL;
}

/**
 * _strtow - strtok function
 * @str: the string to check
 * @d: the delimiter
 * Return: On success char**
 */
char **_strtok(char *str, char *d)
{
char **result;
int numwords;

numwords = count_words(str, d);

if (numwords == 0)
return (NULL);

result = allocate_string_array(numwords);

if (result == NULL)
return (NULL);

split_string(str, d, result);

return (result);
}

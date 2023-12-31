#include "shell.h"

/**
 * check_interactive - Verifies whether the shell is in interactive mode
 * @inf: Pointer to struct address
 * Return: returns 1 if in the interactive mode, returns 0 if not
 */
int check_interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd < 3);
}

/**
 * checkis_delim - Determines whether a character is a delimiter
 * @a: The character to test 
 * @del: The delimiter string
 * Return: 1 if true and 0 if false
 */
int checkis_delim(char a, char *del)
{
	if (!del)
		return (0);

	while (*del)
	{
		if (*del == a)
			return (1);
		del++;
	}
	return (0);
}

/**
 * is_alphabetic - Determines whether a char is an alphabet
 * @c: The char to confirm
 * Return: returns 1 if c is an alphabet if not returns 0
 */
int is_alphabetic(int i)
{
	return ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'));
}

/**
 * custom_atoi - converts a string to integer
 * @s: The string to be changed
 * Return: if our string contains no numbers return 0,
 *	else, the converted numb
 */
int custom_atoi(char *r)
{
	int i;
	int sign = 1, f = 0, out;
	unsigned int res = 0;

	for (i = 0; r[i] != '\0' && f != 2; i++)
	{
		if (r[i] == '-')
			sign *= -1;

		if (r[i] >= '0' && r[i] <= '9')
		{
			f = 1;
			res *= 10;
			res += (r[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		out = -res;
	else
		out = res;

	return (out);
}

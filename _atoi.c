#include "shell.h"

/**
 * interactive - verifies whether shell is in interactive mode
 * @info: Points to structure's address
 *
 * Return: returs 1 if interactive mode, returns 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - verifies whether a character is a delimiter
 * @c: The char to verify
 * @delim: Reps delimiter to string
 * Return: returns 1 if true, wil return 0 if false
 */
int is_delim(char c, char *delim)
{
	if (!delim)
		return (0);

	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * is_alphabetic - Verifies if a char is an alphabet
 * @c: The char to verify
 * Return: returns 1 if c is an alphabet, else return 0
 */
int is_alphabetic(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * custom_atoi - Changes a string to an integer
 * @s: The string to be changed
 * Return: if no numbs in our string retnurn 0,
 *	else, the converted numb
 */
int custom_atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

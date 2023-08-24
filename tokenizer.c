#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *string, char *dee)
{
	char **r;
	int i, j, k, m;
	int nwords = 0;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!dee)
		dee = " ";
	for (i = 0; string[i] != '\0'; i++)
		if (!checkis_delim(string[i], dee) && (checkis_delim(string[i + 1], dee) || !string[i + 1]))
			nwords++;

	if (nwords == 0)
		return (NULL);
	r = malloc((1 + nwords) * sizeof(char *));
	if (!r)
		return (NULL);
	for (i = 0, j = 0; j < nwords; j++)
	{
		while (checkis_delim(string[i], dee))
			i++;
		k = 0;
		while (!checkis_delim(string[i + k], dee) && string[i + k])
			k++;
		r[j] = malloc((k + 1) * sizeof(char));
		if (!r[j])
		{
			for (k = 0; k < j; k++)
				free(r[k]);
			free(r);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			r[j][m] = string[i++];
		r[j][m] = 0;
	}
	r[j] = NULL;
	return (r);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *string, char dee)
{
	int m, i, k, j, nwords = 0;
	char **r;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (i = 0; string[i] != '\0'; i++)
		if ((string[i] != dee && string[i + 1] == dee) ||
		    (string[i] != dee && !string[i + 1]) || string[i + 1] == dee)
			nwords++;
	if (nwords == 0)
		return (NULL);
	r = malloc((1 + nwords) * sizeof(char *));
	if (!r)
		return (NULL);
	for (i = 0, j = 0; j < nwords; j++)
	{
		while (string[i] == dee && string[i] != dee)
			i++;
		k = 0;
		while (string[i + k] != dee && string[i + k] && string[i + k] != dee)
			k++;
		r[j] = malloc((k + 1) * sizeof(char));
		if (!r[j])
		{
			for (k = 0; k < j; k++)
				free(r[k]);
			free(r);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			r[j][m] = string[i++];
		r[j][m] = 0;
	}
	r[j] = NULL;
	return (r);
}

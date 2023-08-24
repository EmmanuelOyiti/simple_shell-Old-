#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *in, char *b, size_t *point)
{
	size_t i = *point;

	if (b[i] == '|' && b[i + 1] == '|')
	{
		b[i] = 0;
		i++;
		in->cmd_buf_type = CMD_OR;
	}
	else if (b[i] == '&' && b[i + 1] == '&')
	{
		b[i] = 0;
		i++;
		in->cmd_buf_type = CMD_AND;
	}
	else if (b[i] == ';') /* found end of this command */
	{
		b[i] = 0; /* replace semicolon with null */
		in->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*point = i;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *in, char *buff, size_t *point, size_t i, size_t length)
{
	size_t k = *point;

	if (in->cmd_buf_type == CMD_AND)
	{
		if (in->status)
		{
			buff[i] = 0;
			k = length;
		}
	}
	if (in->cmd_buf_type == CMD_OR)
	{
		if (!in->status)
		{
			buff[i] = 0;
			k = length;
		}
	}

	*point = k;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *in)
{
	int j;
	list_t *node;
	char *point;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(in->alias, in->argv[0], '=');
		if (!node)
			return (0);
		free(in->argv[0]);
		point = _strchr(node->str, '=');
		if (!point)
			return (0);
		point = _strdup(point + 1);
		if (!point)
			return (0);
		in->argv[0] = point;
	}
	return (1);
}

/**
 * replace_var - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_var(info_t *in)
{
	int j = 0;
	list_t *n;

	for (j = 0; in->argv[j]; j++)
	{
		if (in->argv[j][0] != '$' || !in->argv[j][1])
			continue;

		if (!_strcmp(in->argv[j], "$?"))
		{
			replace_string(&(in->argv[j]),
				_strdup(convert_number(in->status, 10, 0)));
			continue;
		}
		if (!_strcmp(in->argv[j], "$$"))
		{
			replace_string(&(in->argv[j]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		n = node_starts_with(in->env, &in->argv[j][1], '=');
		if (n)
		{
			replace_string(&(in->argv[j]),
				_strdup(_strchr(n->str, '=') + 1));
			continue;
		}
		replace_string(&in->argv[j], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **ol, char *n)
{
	free(*ol);
	*ol = n;
	return (1);
}


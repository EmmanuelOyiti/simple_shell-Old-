#include "shell.h"

/**
 * show_environment - displays the environment running
 * @info: Struct containing probable arguments. 
 *	Maintains constant funct prototype.
 * Return: Always returns 0
 */
int show_environment(info_t *info)
{
	print_str_elements(info->env);
	return (0);
}

/**
 * get_var_value - retrieves value of an environ variable
 * @info: Struct containing probable arguments. 
 *	Maintains @name: env var name
 *
 * Return: returns the value
 */
char *get_var_value(info_t *info, const char *name)
{
	list_element *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_my_variable - Commences a new environment variable,
 *             or changes an existing one
 * @info: Struct having probable arguments. 
 *	Maintains constant function prototype.
 *  Return: Always returns 0
 */
int set_my_variable(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_my_variable - clear an environ variable
 * @info: Struct containing probable arguments. 
 *	Used to maintain constant function prototype.
 *  Return: Always returns 0.
 */
int unset_my_variable(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * create_my_variable_ls - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int create_my_variable_ls(info_t *info)
{
	list_element *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		insert_at_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

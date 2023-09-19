#include "shell.h"

/**
 * exit_command - this exits the shell we in
 * @info: The structure containing potential arguments. Used to maintain
 *       out constant function prototype.
 * Return:  returns exits with our given exit status
 * reuturns (0) if info.argv[0] != "exit"
 */
int exit_command(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* Maybe if there is an exit argument */
	{
		exitcheck = convert_to_int(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			show_error_ms(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = convert_to_int(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * change_directory_command -here we  change the current directory of the process
 * @info: The structure containing potential arguments. Used to maintain
 *        our constant function prototype.
 * Return: Always return 0
 */
int change_directory_command(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = get_var_value(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should be here? */
				chdir((dir = get_var_value(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_var_value(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(get_var_value(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should be here? */
			chdir((dir = get_var_value(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		show_error_ms(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", get_var_value(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * show_help - will displays help information in our proj
 * @info: The structure containing potential arguments. Used to maintain
 *         our constant function prototype.
 * Return: Always return 0
 */
int show_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused, workaround */
	return (0);
}

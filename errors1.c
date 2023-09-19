#include "shell.h"

/**
 * convert_to_int - changes a string to an integer
 * @s: our string to be changed
 * Return: 0 if no nums in our string, converted numr otherwise
 *       -1 on error
 */
int convert_to_int(char *text)
{
	int i = 0;
	unsigned long int result = 0;

	if (*text == '+')
		text++;
	for (i = 0; text[i] != '\0'; i++)
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			result *= 10;
			result += (text[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * show_error_ms - generates an error response
 * @info: parameter's value and return information struct
 * @estr: reps the requested error type
 * Return: 0 if no nums in string, converted number if not
 *        -1 on error
 */
void show_error_ms(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	shows_int(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * shows_int - prints a decimal (integer) number in the 10th base
 * @input: input parameter
 * @fd: is the filedescriptor which to write to
 *
 * Return: number of characters printed
 */
int shows_int(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - A copy of itoa's converter function
 * @num: numb
 * @base: the base
 * @flags: are the argument flags
 * Return: returns a string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - changes the first occurrence of
 * "#" with "0" in the function
 * @buf: address of the modified string
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

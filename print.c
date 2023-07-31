#include "main.h"

/**
 * _printf - Function that produces output according to a format
 * @format: initial string with all identifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count, ch;
	char *str;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				{
					ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				}
				case 's':
				{
					*str = va_arg(args, char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				default:
					putchar('%'); /* Print the '%' character if not followed by a known specifier */
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * main - sample program
 * Return: 0 on success
 */

int main(void)
{
	int num;
	char ch;
	char str[];

	num = 10;
	ch = 'A';
	str[] = "Hello, World!";

	int count = _printf("Number: %d\nCharacter: %c\nString: %s\n%%\n", num, ch, str);
	printf("Number of characters printed: %d\n", count);

	return (0);
}

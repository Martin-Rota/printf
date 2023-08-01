#include "main.h"

/**
 * _printf - Function that produces output according to a format
 * @format: initial string with all identifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count, ch;
	char *str;
	va_list args;
	va_start(args, format);

	count = 0;

	if (format == NULL)
		return (-1);

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
					str = va_arg(args, char *);
					if (str == NULL)
					{
						fputs("(null)", stdout);
						count += 6;
					}
					else
					{
						while (*str != '\0')
						{
							putchar(*str);
							str++;
							count++;
						}
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				case 'd':
				case 'i':
				{
					int num, num_copy, digits, i;

					num = va_arg(args, int);
					num_copy = num;
					digits = 0;

					if (num == 0)
						digits = 1;
					else
					{
						while (num_copy != 0)
						{
							num_copy /= 10;
							digits++;
						}
					}

					if (num < 0)
					{
						putchar('-');
						count++;
						digits--;
						num = -num;
					}

					for (i = 0; i < digits; i++)
					{
						int digit = num / pow(10, digits - i - 1);
						num %= (int)pow(10, digits - i - 1);
						putchar('0' + digit);
						count++;
					}
					break;
				}
				default:
				{
					putchar('%');
					putchar(*format);
					count += 2;
					break;
				}
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

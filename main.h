#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * Custom power function
 * @base: base value
 * @exponent: exponent value (non-negative)
 *
 * Return: Result of base raised to the exponent power
 */
int custom_pow(int base, int exponent)
{
	int result = 1;
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

int _printf(const char *format, ...);

#endif

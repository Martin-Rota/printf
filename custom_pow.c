#include "main.h"

/**
 * custom_pow - Custom power function
 * @base: base value
 * @exponent: exponent value (non-negative)
 *
 * Return: Result of base raised to the exponent power
 */

int custom_pow(int base, int exponent)
{
	int result;

	result = 1;
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

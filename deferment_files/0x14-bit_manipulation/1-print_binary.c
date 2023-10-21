#include "main.h"
/**
 * print_binary - Converts a number to binary.
 * @n: the number to covert
 */
void print_binary(unsigned long int n)
{
	int bit_position, bit_set;
	unsigned long int mask;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	bit_position = sizeof(n) * 8 - 1;
	bit_set = 0;

	while (bit_position >= 0)
	{
		mask = 1UL << bit_position;
		if (n & mask)
		{
			_putchar('1');
			bit_set = 1;
		}
		else if (bit_set)
		{
			_putchar('0');
		}
		bit_position--;
	}
}

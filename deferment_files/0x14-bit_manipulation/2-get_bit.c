#include "main.h"
/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The unsigned long integer containing the bit.
 * @index: The index of the bit to retrieve (starting from 0).
 *
 * Return: The value of the bit at the specified index (0 or 1) or -1..
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = 1UL << index;
	if (n & mask)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

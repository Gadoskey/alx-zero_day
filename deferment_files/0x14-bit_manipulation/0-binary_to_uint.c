#include "main.h"
/**
 * binary_to_uint - Converts a binary number as string to an unsigned int.
 * @b: A pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if invalid characters or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int result = 0;

	if (b == NULL)
	{
		return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
		{
			result = result << 1;
		}
		else if (b[i] == '1')
		{
			result = result << 1;
			result = result | 1;
		}
		else
		{
			return (0);
		}
	}
	return (result);
}

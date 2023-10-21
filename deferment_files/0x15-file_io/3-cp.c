#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define BUFSIZE 1024
void print_error(int err, char *file);
/**
 * print_error - exit program
 * @err: The error code
 * @file: The message
 */
void print_error(int err, char *file)
{
	switch (err)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", file);
			break;
		default:
			break;
	}
}
/**
 * my_cp- copy contents from one file to another
 * @file_from: the file from
 * @file_to: the file to
 * Return: 0
 */
int my_cp(char *file_from, char *file_to)
{
	char buffer[BUFSIZE];
	int fd_from, fd_to, bytes_read, bytes_written;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		print_error(98, file_from);
		return (98);
	}
	fd_to = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_to == -1)
	{
		print_error(99, file_to);
		return (99);
	}
	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written < 0)
		{
			print_error(99, file_to);
			return (99);
		}
	}
	if (bytes_read < 0)
	{
		print_error(98, file_from);
		return (98);
	}
	if (close(fd_from) == -1)
	{
		print_error(100, file_from);
		return (100);
	}
	if (close(fd_to) == -1)
	{
		print_error(100, file_to);
		return (100);
	}
	return (0);
}
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or exit with an error code.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error(97, NULL);
		return (97);
	}
	return (my_cp(argv[1], argv[2]));
}

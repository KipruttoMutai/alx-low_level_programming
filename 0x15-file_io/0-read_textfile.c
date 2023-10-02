#include "main.h"
#include <stdlib.h>
/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return:  i - actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t file_descriptor;
	ssize_t i;
	ssize_t j;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	j = read(file_descriptor, buff, letters);
	i = write(STDOUT_FILENO, buff, j);

	free(buff);
	close(file_descriptor);
	return (i);
}

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * checkElfHeader - Checks if a file is an ELF file.
 * @headerData: A pointer to an array containing the ELF magic numbers.
 */
void checkElfHeader(unsigned char *headerData)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (headerData[index] != 127 &&
				headerData[index] != 'E' &&
				headerData[index] != 'L' &&
				headerData[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagicNumbers - Prints the magic numbers of an ELF header.
 * @headerData: A pointer to an array containing the ELF magic numbers.
 */
void printMagicNumbers(unsigned char *headerData)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", headerData[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printHeaderClass - Prints the class of an ELF header.
 * @headerData: A pointer to an array containing the ELF class.
 */
void printHeaderClass(unsigned char *headerData)
{
	printf(" Class: ");

	switch (headerData[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", headerData[EI_CLASS]);
	}
}

/**
 * printHeaderData - Prints the data of an ELF header.
 * @headerData: A pointer to an array containing the ELF class.
 */
void printHeaderData(unsigned char *headerData)
{
	printf(" Data: ");

	switch (headerData[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", headerData[EI_CLASS]);
	}
}

/**
 * printHeaderVersion - Prints the version of an ELF header.
 * @headerData: A pointer to an array containing the ELF version.
 */
void printHeaderVersion(unsigned char *headerData)
{
	printf(" Version: %d",
			headerData[EI_VERSION]);

	switch (headerData[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * printHeaderOSABI - Prints the OS/ABI of an ELF header.
 * @headerData: A pointer to an array containing the ELF version.
 */
void printHeaderOSABI(unsigned char *headerData)
{
	printf(" OS/ABI: ");

	switch (headerData[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", headerData[EI_OSABI]);
	}
}

/**
 * printHeaderABI - Prints the ABI version of an ELF header.
 * @headerData: A pointer to an array containing the ELF ABI version.
 */
void printHeaderABI(unsigned char *headerData)
{
	printf(" ABI Version: %d\n",
			headerData[EI_ABIVERSION]);
}

/**
 * printHeaderType - Prints the type of an ELF header.
 * @headerType: The ELF type.
 * @headerData: A pointer to an array containing the ELF class.
 */
void printHeaderType(unsigned int headerType, unsigned char *headerData)
{
	if (headerData[EI_DATA] == ELFDATA2MSB)
		headerType >>= 8;

	printf(" Type: ");

	switch (headerType)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", headerType);
	}
}

/**
 * printEntryPoint - Prints the entry point of an ELF header.
 * @entryPoint: The address of the ELF entry point.
 * @headerData: A pointer to an array containing the ELF class.
 */
void printEntryPoint(unsigned long int entryPoint, unsigned char *headerData)
{
	printf(" Entry point address: ");

	if (headerData[EI_DATA] == ELFDATA2MSB)
	{
		entryPoint = ((entryPoint << 8) & 0xFF00FF00) |
			((entryPoint >> 8) & 0xFF00FF);
		entryPoint = (entryPoint << 16) | (entryPoint >> 16);
	}

	if (headerData[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entryPoint);
	else
		printf("%#lx\n", entryPoint);
}

/**
 * closeFile - Closes an ELF file.
 * @fileDescriptor: The file descriptor of the ELF file.
 */
void closeFile(int fileDescriptor)
{
	if (close(fileDescriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fileDescriptor);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on successs
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, readResult;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	readResult = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (readResult == -1)
	{
		free(header);
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkElfHeader(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printHeaderClass(header->e_ident);
	printHeaderData(header->e_ident);
	printHeaderVersion(header->e_ident);
	printHeaderOSABI(header->e_ident);
	printHeaderABI(header->e_ident);
	printHeaderType(header->e_type, header->e_ident);
	printEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeFile(fileDescriptor);
	return (0);
}

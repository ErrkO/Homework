#include <unistd.h>
#include <fcntl.h>

// Eric Oliver
// CSCI 4100
// Assignemnt 4

/* This program opens a file and then copies it to a new file*/

int main(int argc, char *argv[])
{

	int file = -1, filecp = -1;

	if (argc != 3)
	{

		printf( "Usage: %s filename copyfilename\n", argv[0] );

	}

	else
	{

		char buffer[4096];

		file = open(argv[1], 0644);

		filecp = creat(argv[2], 0644);

		if (file == -1)
		{

			printf("Could not open the file\n");

		}

		else if (filecp == -1)
		{

			printf("Could not create the cp file\n");

		}

		else
		{

			int cread = read(file,buffer,4095);

			int cwrite = write(filecp,buffer,4095);

			int result = close(file);

			int result2 = close(filecp);

		}

	}

}
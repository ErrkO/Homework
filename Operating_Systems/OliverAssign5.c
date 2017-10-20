#include <stdlib.h>
#include <stdio.h>

// Eric Oliver
// CSCI 4100
// Assignment 5

// This program is a basic shell that executes linux commands

#define MAX_LINE = 100;
#define MAX_ARGS = 2;

int main( int argc, char *argv[])
{

	int xtf = 0;

	char prompt[] = "";
	char xt[] = "exit";
	char space[] = " ";

	char cmdln[] = "";

	while (xtf == 0)
	{

		printf("> ");

		scanf("%s",prompt);

		if (strcmp(prompt,xt) == 0)
		{

			printf("[exiting turtle shell]");

			xtf = 1;

		}

		else
		{

			printf("%s",prompt);

			printf("\n");

		}

	}

}

void Read_Line(char line[])
{

	char temp[];

	for (int i = 0; i < MAX_LINE; i++)
	{

		if (strcmp(line,space) == 0)
		{

			

		}

	}

}

int Is_Blank(char line[])
{

	if (strcmp(line,"") == 0 || strcmp(line," ") == 0)
	{

		return 1;

	}

	return 0;

}

void Parse_Args(char command, char argv)
{



}
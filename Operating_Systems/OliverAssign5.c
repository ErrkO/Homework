#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Eric Oliver
// CSCI 4100
// Assignment 5

// This program is a basic shell that executes linux commands

#define MAX_LINE = 256;
#define MAX_ARGS = 64;

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

void Read_Line(char *line)
{

	char c;

  	int chars_read = 0;

  	while((c = getchar()) != '\n' && chars_read < MAX_LINE)
  	{

    	line[chars_read++] = c;

    }

  	line[chars_read] = '\0';

}

int Is_Blank(const char *line)
{

	int i = 0;

  	while(line[i] != '\0') 
  	{

    	if(!isspace(line[i++]))
    	{

      		return 0;

      	}

  	}
  return 1;

}

void Parse_Args(char *command, char *argv[])
{

	int argc = 0;

  	while(*command != '\0' && argc < MAX_ARGS) 
  	{

    	int i = 0;

    	while(!isspace(command[i]) && command[i] != '\0') i++;

    	argv[argc] = (char *) malloc(i + 1);

    	strncpy(argv[argc], command, i);

    	while(isspace(command[i])) i++;

    	command += i;

    	argc++;

  	}

  	if(argc < MAX_ARGS)
  	{

    	argv[argc] = NULL;

    }

  	else
  	{

    	argv[MAX_ARGS - 1] = NULL;

    }

}
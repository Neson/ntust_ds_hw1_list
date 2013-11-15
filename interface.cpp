/** @file interface.cpp
  * @brief functions for command line interface
  *
  * Use GNU ReadLine to create a user-friendly command line interface.
  *
  * @author PokaiChang
  * @date 2013-11-15
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "interface.h"


char *rl_gets(const char* text)
{
	char *line_read = (char *)NULL;

	if (line_read) {
		free (line_read);
		line_read = (char *)NULL;
	}

	char* prompt;
	if (text) {
		prompt = (char *)malloc(strlen(text) + sizeof(" > "));
		strcpy(prompt, text);
		strcat(prompt, " > ");
	}
	else {
		prompt = (char *)malloc(sizeof(" > "));
		strcpy(prompt, " > ");
	}

	line_read = readline(prompt);

	free(prompt);

	if (line_read && *line_read)
		add_history(line_read);

	return (line_read);
}


static char* command_generator(const char *text, int state)
{
	char *name;
	int list_index, len;
	if (!state) {
		list_index = 0;
		len = strlen(text);
	}
	while ((name = commands[list_index])) {
		list_index++;
		if (strncmp(name, text, len) == 0)
			return strdup(name);
	}

	return ((char *)NULL);
}


static char* argument_generator(const char *text, int state)
{
	return ((char *)NULL);
}


char** list_completion(char *text, int start, int end)
{
	char **matches = NULL;

	if (start == 0)
		matches = rl_completion_matches(text, command_generator);
	else
		matches = rl_completion_matches(text, argument_generator);

	return (matches);
}


void initialize_readline()
{
	rl_readline_name = (char *)"list";
	rl_attempted_completion_function = (CPPFunction *)list_completion;
	return ;
}

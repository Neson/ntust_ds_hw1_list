/** @file main.cpp
  * @brief main function of list program
  *
  * @author PokaiChang
  * @date 2013-11-15
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "data_structure.h"

char *commands[] = {  // Commands for completion
	(char *)"help",
	(char *)"quit",
	(char *)"exit",
	(char *)"create",
	(char *)"list",
	(char *)"destroy",
	(char *)"select",
	(char *)"use",
	(char *)"add",
	(char *)"insert",
	(char *)"delete",
	(char *)"clear",
	(char *)"get",
	(char *)"find",
	(char *)"print",
};


int main ()
{
	LinkedList lists;  // make a list of lists
	LinkedList *current_list=NULL;
	char *read_command=(char *)NULL, *current_list_name=(char *)NULL;
	int done=0, n, i, t;
	bool success;

	LinkedList *tmp_llp;
	LinkedListNode *tmp_llnp;
	LinkedListData tmp_lld;

	initialize_readline();


	while (!done) {  // loop until the user exits

		/* READ COMMAND */

		read_command = rl_gets(current_list_name);

		if (!strcmp(read_command, ""))
			continue;

		char *token;
		token = strtok(read_command, " ");

		/* EXECUTE COMMAND */

		if (!strcmp(token, "exit") || !strcmp(token, "quit")) {
			printf("bye!\n");
			break;
		}

		else if (!strcmp(token, "help")) {
			printf("commands: \n\tcreate\t create a new list \n\tlist\t print out all lists \n\tdestroy\t delete a list \n\tselect\t select a list to use \n\t \t the selected list will be shown in the prompt \n\tuse\t same as 'select' \n\tadd\t add an node/nodes at the end of the selected list \n\tinsert\t insert an node to the nth position of the selected list \n\tdelete\t delete the nth node of the selected list \n\tclear\t delete all nodes from the selected list \n\tget\t get the nth node from the selected list \n\tfind\t find an node with its data from the selected list \n\tprint\t print out the selected list \n\tquit\t quit this application \n\thelp\t show this message \n");
		}

		else if (!strcmp(token, "create")) {
			token = strtok(NULL, " ");  // next token (list name)
			if (!token || !strcmp(token, "")) {
				printf("usage: create <new_list_name>\n");
				continue;
			}
			tmp_llnp = lists.head();
			while (tmp_llnp) {
				if (!strcmp(token, tmp_llnp->data.list.name)) {
					printf("List '%s' already exists!\n", token);
					break;
				}
				tmp_llnp = tmp_llnp->next;
			}
			if (tmp_llnp && !strcmp(token, tmp_llnp->data.list.name))
				continue;
			tmp_lld.list.name = (char *)malloc(sizeof(token));
			strcpy(tmp_lld.list.name, token);
			tmp_lld.list.pointer = (LinkedList *)new LinkedList;
			lists.insertNode(tmp_lld);
		}

		else if (!strcmp(token, "list") || !strcmp(token, "ls")) {
			tmp_llnp = lists.head();
			i = 0;
			while (tmp_llnp) {
				printf("%s\n", tmp_llnp->data.list.name);
				tmp_llnp = tmp_llnp->next;
				i++;
			}
			if (i)
				printf("%d list(s) in total.\n", i);
			else
				printf("No existing list.\n");
		}

		else if (!strcmp(token, "destroy")) {
			token = strtok(NULL, " ");  // next token (list name)
			if (!token || !strcmp(token, "")) {
				printf("usage: destroy <list_to_destory>\n");
				continue;
			}

			success = false;
			tmp_llnp = lists.head();
			i = 0;
			while (tmp_llnp) {
				i++;
				if (!strcmp(token, tmp_llnp->data.list.name)) {
					tmp_llp = (LinkedList *)tmp_llnp->data.list.pointer;
					tmp_llp->clear();  // clear the selected list

					if (current_list_name && !strcmp(current_list_name, tmp_llnp->data.list.name)) {
						current_list_name = NULL;
						current_list = NULL;
					}

					delete tmp_llp;
					lists.deleteNode(i);

					success = true;
					break;
				}
				tmp_llnp = tmp_llnp->next;
			}
			if (!success)
				printf("List '%s' does not exists!\n", token);
		}

		else if (!strcmp(token, "select") || !strcmp(token, "use")) {
			token = strtok(NULL, " ");  // next token (list name)
			if (!token || !strcmp(token, "")) {
				printf("usage: select <list_name>\n");
				continue;
			}
			success = false;
			tmp_llnp = lists.head();
			while (tmp_llnp) {
				if (!strcmp(token, tmp_llnp->data.list.name)) {
					current_list = (LinkedList *)tmp_llnp->data.list.pointer;
					current_list_name = tmp_llnp->data.list.name;
					success = true;
					break;
				}
				tmp_llnp = tmp_llnp->next;
			}
			if (success)
				printf("Using list '%s'.\n", current_list_name);
			else
				printf("List '%s' does not exists! Enter 'create %s' if you want to create it.\n", token, token);
		}

		else if (!strcmp(token, "add")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}
			token = strtok(NULL, " ");  // next token (data to add)
			if (!token || !strcmp(token, "")) {
				printf("usage: add <data> [data2] [data3] [...]\n");
				continue;
			}
			while (token) {
				tmp_lld.number = atoi(token);
				current_list->insertNode(tmp_lld);
				token = strtok(NULL, " ");  // next token (data to add)
			}
		}

		else if (!strcmp(token, "insert")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}

			token = strtok(NULL, " ");  // next token (where to insert)
			if (!token || !strcmp(token, "")) {
				printf("usage: insert <n> <data>\n");
				continue;
			}
			n = atoi(token);

			token = strtok(NULL, " ");  // next token (data to insert)
			if (!token || !strcmp(token, "")) {
				printf("Please provide the data to be inserted.\n");
				continue;
			}
			while (token) {
				tmp_lld.number = atoi(token);
				current_list->insertNode(n, tmp_lld);
				token = strtok(NULL, " ");  // next token (data to insert)
				n++;
			}
		}

		else if (!strcmp(token, "delete")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}

			token = strtok(NULL, " ");  // next token (which to delete)
			if (!token || !strcmp(token, "")) {
				printf("usage: delete <n>\n");
				continue;
			}

			while (token) {
				n = atoi(token);
				current_list->deleteNode(n);
				token = strtok(NULL, " ");  // next token (data to insert)
			}
		}

		else if (!strcmp(token, "clear")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}

			current_list->clear();
		}

		else if (!strcmp(token, "get")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}

			token = strtok(NULL, " ");  // next token (which to get)
			if (!token || !strcmp(token, "")) {
				printf("usage: get <n>\n");
				continue;
			}
			n = atoi(token);
			if ((tmp_llnp = (LinkedListNode *)current_list->getNode(n)))
				printf("%d: %d\n", n, tmp_llnp->data.number);
		}

		else if (!strcmp(token, "find")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}

			token = strtok(NULL, " ");  // next token (what to find)
			if (!token || !strcmp(token, "")) {
				printf("usage: find <data>\n");
				continue;
			}
			n = atoi(token);
			if (current_list->length() == 0) {
				printf("This is an empty list.\n");
			}
			else {
				tmp_llnp = current_list->head();
				i = 1;
				t = 0;
				printf("Found '%d' at ", n);
				while (tmp_llnp) {
					if (tmp_llnp->data.number == n) {
						printf("[%d], ", i);
						t++;
					}
					tmp_llnp = tmp_llnp->next;
					i++;
				}
				if (t)
					printf("%d match(s).\n", t);
				else
					printf("nowhere.\n");
			}
		}

		else if (!strcmp(token, "print")) {
			if (!current_list) {
				printf("Please select a list to use!\n");
				continue;
			}
			if (current_list->length() == 0) {
				printf("This is an empty list.\n");
			}
			else {
				tmp_llnp = current_list->head();
				i = 1;
				while (tmp_llnp) {
					printf("%d: %d\n", i, tmp_llnp->data.number);
					tmp_llnp = tmp_llnp->next;
					i++;
				}
				printf("Total of %d node(s).\n", current_list->length());
			}
		}

		else {
			printf("Unrecognized command: '%s'. Enter 'help' for introductions.\n", token);
		}

		token = strtok(NULL, " ");  // next token

		/* RESET */

		free(read_command);
	}

	return 0;
}

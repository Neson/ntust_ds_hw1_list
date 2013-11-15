/** @file interface.h
  * @brief functions for command line interface
  *
  * @author PokaiChang
  * @date 2013-11-15
  */
void initialize_readline();  // Function to initialize GNU Readline

char *rl_gets(const char *text);  // Get command from terminal

char** list_completion(char*, int, int);  // Do completion

extern char *commands[];  // Commands

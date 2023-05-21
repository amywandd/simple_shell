#include "main.h"
/**
 * exit_sh - exits the shell
 * @buffer : is char type
 * return : nothing
 */
void exit_sh(char *buffer)
{
if (_strcmp(buffer, "exit\n") == 0)
{
free(buffer);
exit(1);
}
}

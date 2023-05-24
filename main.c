#include "main.h"
#define  BUFSIZE_sh 32
#define STR_PROMPT "#cisfun$"
/**
 * main - Entry point
 * Return: return(0)
 */
int main(void)
{
char *buffer;
size_t bufsize;
int buf;
char *st;
char **arrp;
signal(SIGINT, sigintHandler);
while (1)
{
st = STR_PROMPT;
print_sh(st);
buffer = NULL;
bufsize = BUFSIZE_sh;
buffer = (char *)malloc(bufsize *sizeof(char));
if (buffer == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}
buf = getline(&buffer, &bufsize, stdin);
if (buf == EOF)
{
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
exit_sh(buffer);
arrp = divide_buffer(buffer);
exe(arrp);
if (arrp && arrp[0])
env_sh(arrp);
}
return (0);
}

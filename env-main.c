#include <stdio.h>

/**
 * print_env - prints the environment var
 *
 * Return: Always 0.
 */
int print_env(char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** main file
*/

#include "mysh.h"

char **find_arg(char *command, minish *mysh)
{
    char **arg;
    char *str;

    if (*command == '\0' || command == NULL)
        return (NULL);
    mysh->nb = 0;
    str = cleaned_str(command);
    mysh->nb = nb_words(str);
    arg = word_array(str, mysh->nb);
    return (arg);
}

void free_param(minish *mysh)
{
    while (*mysh->arg != NULL) {
        free(*mysh->arg);
        mysh->arg++;
    }
}

/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** env manager
*/

#include "mysh.h"

char *find_name(char *line)
{
    char *name;
    int i;

    if (line == NULL)
        return (NULL);
    name = malloc(sizeof(char) * (256));
    for (i = 0; line[i] != 61; i++)
        name[i] = line[i];
    name[i] = '\0';
    if (name[0] == '\0')
        return (NULL);
    return (name);
}

char *find_value(char *line)
{
    char *value;
    int i;
    int j;

    if (line == NULL)
        return (NULL);
    value = malloc(sizeof(*value) * my_strlen(line));
    for (i = 0; line[i] != 61; i++);
    j = 0;
    while (line[++i] != '\0') {
        value[j] = line[i];
        j++;
    } value[j] = '\0';
    return (value);
}

char *search_env(mysh_t *exe, char *to_find)
{
    int i;
    char *NOM;

    if (to_find == NULL || exe->envp == NULL)
        return (NULL);
    for (i = 0; exe->envp[i] != NULL; i++) {
        NOM = find_name(exe->envp[i]);
        if (NOM != NULL && my_strcmp(to_find, NOM) == 0) {
            free(NOM);
            return (exe->envp[i]);
        } else
            free(NOM);
    } return (NULL);
}

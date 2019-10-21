/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** create my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strdup(char const *src)
{
    char *new;
    char *cpy;

    cpy = malloc(sizeof(char) * (my_strlen(src) + 1));
    new = cpy;
    while (*src) {
        *cpy = *src;
        cpy++;
        src++;
    } *cpy = '\0';
    return (new);
}

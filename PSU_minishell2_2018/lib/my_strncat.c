/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** create my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    char *cpy;

    i = 0;
    cpy = dest;
    while (*dest)
        dest++;
    while (i != nb) {
        *dest = *src;
        src++;
        dest++;
        i++;
    } *dest = '\0';
    return (cpy);
}

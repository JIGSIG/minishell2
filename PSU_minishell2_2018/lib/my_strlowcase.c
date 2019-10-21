/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** create my_strlowcase
*/

char *my_strlowcase(char *str)
{
    char *cpy;

    cpy = str;
    while (*str) {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
        str++;
    } return (cpy);
}

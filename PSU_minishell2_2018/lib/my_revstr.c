/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** create my_revstr
*/

char *my_revstr(char *str)
{
    int i;
    int j;
    char tmp;

    i = 0;
    j = 0;
    while (str[i] != '\0') {
        for (j = i; str[j] != '\0'; j++) {
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
        i++;
    }
    return (str);
}

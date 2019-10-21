/*
** EPITECH PROJECT, 2019
** sort words
** File description:
** main file
*/

#include "my.h"

char **word_array(char *str, int nb_of_words)
{
    int i;
    int j;
    int k;
    int len;
    char **array;

    if (str == NULL || *str == '\0')
        return (NULL);
    len = my_strlen(str);
    array = malloc(sizeof(char *) * (nb_of_words + 1));
    for (i = 0; i < (nb_of_words + 1); i++)
        array[i] = malloc(sizeof(char) * (len + 1));
    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    for (j = 0; j < nb_of_words && str[i] != '\0'; j++) {
        k = 0;
        while ((str[i] != ' ' && str[i] != '\t') && k <= len)
            array[j][k++] = str[i++];
        while (str[++i] == ' ' || str[i] == '\t');
    } array[j] = NULL;
    return (array);
}

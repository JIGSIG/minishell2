/*
** EPITECH PROJECT, 2019
** sort words
** File description:
** main file
*/

#include "my.h"

void fill_str(char *output, char *str, int *i, int *j)
{
    if (str[*i] != ' ' && str[*i] != '\t') {
        if (str[*i - 1] == ' ' || str[*i - 1] == '\t') {
            output[*j] = ' ';
            (*j)++;
        } output[*j] = str[*i];
        (*j)++;
    }
}

char *cleaned_str(char *str)
{
    int i;
    int j;
    char *output;

    i = -1;
    j = 0;
    if (str == NULL || *str == '\0')
        return (NULL);
    output = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[++i] == ' ' || str[i] == '\t');
    output[j++] = str[i++];
    while (str[i] != '\0') {
        fill_str(output, str, &i, &j);
        i++;
    } output[j] = '\0';
    return (output);
}

int nb_words(char *str)
{
    int nb_of_words;

    if (str == NULL || *str == '\0')
        return (0);
    nb_of_words = 0;
    while (*str) {
        if (*str == ' ')
            nb_of_words++;
        str++;
    } nb_of_words++;
    return (nb_of_words);
}

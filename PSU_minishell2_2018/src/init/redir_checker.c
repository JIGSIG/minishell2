/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main file
*/

#include "mysh.h"

int count_redir(char *all_command)
{
    int count;
    int i;

    i = -1;
    count = 0;
    while (all_command[++i]) {
        if (is_redir(all_command[i]) == true) {
            while (all_command[i + 1] != '\0'
            && is_redir(all_command[++i]) == true);
            count++;
        }
    } return (count);
}

char **mem_alloc_redir(int rows, char *all_command)
{
    int i;
    int length;
    char **new;

    length = my_strlen(all_command);
    new = malloc(sizeof(char *) * rows);
    for (i = 0; i < rows; i++) {
        new[i] = malloc(sizeof(char) * (length + 1));
        new[i][0] = '\0';
    } new[rows] = NULL;
    return (new);
}

char *remove_begin_end_redir(char *s)
{
    int i;
    int j;
    int k;
    int n;
    char *new;

    if (s == NULL || *s == 0)
        return (NULL);
    for (i = -1, j = my_strlen(s); i < -1; i++);
    while (s[++i] && is_redir(s[i]) == true);
    while (j > 0 && is_redir(s[--j]) == true);
    new = malloc(sizeof(char) * (j - i + 1));
    for (k = 0, n = i; n <= j; n++)
        new[k++] = s[n];
    return (new);
}

char **make_the_arr(char *s)
{
    int i;
    int j;
    int k;
    char **new;
    int rows;


    if (s == NULL || *s == 0)
        return (NULL);
    s = remove_begin_end_redir(s);
    rows = 2 * count_redir(s) + 1;
    new = malloc(sizeof(char *) * (rows + 1));
    for (i = 0; i < rows; i++)
        new[i] = malloc(sizeof(char) * (my_strlen(s) + 1));
    for (i = 0, j = 0; i < rows && s[j] != 0; i++) {
        for (k = 0; s[j] && is_redir(s[j]) == false; j++)
            new[i][k++] = s[j];
        for ( i = i + 1, k = 0; s[j] && is_redir(s[j]) == true; j++)
            new[i][k++] = s[j];
    } new[i] = NULL;
    return (new);
}

char **cleaned_arr(char *s)
{
    char **arr;
    char **new;
    int len;
    int i;

    arr = make_the_arr(s);
    len = -1;
    while (arr[++len]);
    i = -1;
    new = malloc(sizeof(char *) * (len + 1));
    while (arr[++i]) {
        if (i % 2 != 0)
            new[i] = arr[i];
        else
            new[i] = cleaned_str(arr[i]);
    } new[i] = NULL;
    return (new);
}

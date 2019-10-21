/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main file
*/

#include "mysh.h"

void init_prompt(mysh_t *exe, prompt_t *prompt)
{
    int i;
    int len1;
    int len2;

    if ((prompt->path = find_path(exe)) != NULL) {
        len1 = my_strlen(prompt->path) + 1;
        for (i = len1 - 1; prompt->path[i] != '/'; i--);
        prompt->dir = fill_dir(prompt->path, len1, i);
        len2 = 20 + my_strlen(prompt->dir);
        prompt->prmt = fill_prompt(prompt->dir, len2);
    }
}

void display_prompt(mysh_t *exe)
{
    prompt_t prompt;

    init_prompt(exe, &prompt);
    if (prompt.path == NULL || prompt.dir == NULL)
        return;
    my_printf("\033[01m\033[32m%s\033[00m", prompt.prmt);
    free(prompt.prmt);
    free(prompt.path);
    free(prompt.dir);
}

void minishell(mysh_t *exe)
{
    char *all_command;
    int size;

    for (size = 0, signal(SIGINT, SIG_IGN); size < 0; size++);
    display_prompt(exe);
    while ((all_command = get_next_line(0)) != NULL) {
        if ((size = my_strlen(all_command)) > 0) {
            execution_of_shell(exe, all_command);
        } else
            display_prompt(exe);
    } my_putchar('\n');
}

/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** execute
*/

#include "mysh.h"

char **mem_alloc(int nb, int size)
{
    char **new;
    int i;

    new = malloc(sizeof(char *) * (nb + 1));
    for (i = 0; i < nb; i++) {
        new[i] = malloc(sizeof(char) * (size + 1));
        new[i][0] = '\0';
    } new[i] = NULL;
    return (new);
}

char **find_path2(mysh_t *exe)
{
    char **path;
    char *PATH;
    int nb;
    int i;
    int j;
    int k;

    PATH = search_env(exe, "PATH");
    for (i = 0, nb = 0; PATH[i] != '\0'; i++)
        if (PATH[i] == ':')
            nb++;
    path = mem_alloc(nb += 2, my_strlen(PATH));
    for (i = 0, j = 0, k = 0; PATH[i] != '\0'; i++) {
        if (PATH[i] == ':') {
            j++;
            k = 0;
            i++;
        } path[j][k++] = PATH[i];
    } path[nb] = NULL;
    return (path);
}

int check_access(mysh_t *exe)
{
    int i;
    char **path;

    if (exe->mysh->arg == NULL)
        return (84);
    i = 0;
    path = find_path2(exe);
    if (access(*exe->mysh->arg, X_OK) == 0) {
        signal(SIGSEGV, SIG_IGN);
        signal(SIGFPE, SIG_IGN);
                return (0);
    } while (path[i++] != NULL) {
        if (path[i] == NULL)
            break;
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], *exe->mysh->arg);
        if (access(path[i], X_OK) == 0)
            return (1);
    } return (84);
}

int do_exec(mysh_t *exe)
{
    int i;
    char **path;

    if (exe->mysh->arg == NULL)
        return (84);
    i = -1;
    path = find_path2(exe);
    while (path[++i] != NULL) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], *exe->mysh->arg);
        if (execve(path[i], exe->mysh->arg, exe->envp) != -1) {
            putstr_fd(1, exe->mysh->arg[0]);
            putstr_fd(1, ": Exec format error. Wrong Architecture.\n");
        }
    } return (0);
}

void execute(mysh_t *exe)
{
    pid_t childID;

    exe->mysh->builtin = false;
    check_exit(exe);
    check_cd(exe);
    check_setenv(exe);
    check_unsetenv(exe);
    childID = give_birth();
    child_process(childID, exe);
    if (childID != -1 && childID != 0)
        parent_process(childID, exe);
    return;
}

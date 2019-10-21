/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** header
*/

#ifndef MYSH_H
#define MYSH_H
#define _POSIX_SOURCE
#define _GNU_SOURCE
#define _POSIX_C_SOURCE
#define _XOPEN_SOURCE
#define CREATE_FILE (O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP)

#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>
#include "my.h"

typedef struct minish minish;
struct minish
{
    char *prg;
    char **arg;
    size_t nb;

    char *command;

    char *redir;
    bool bad_redir;
    bool no_redir;

    bool builtin;
    bool seg;
    minish *next;
};

typedef struct mysh_t mysh_t;
struct mysh_t
{
    minish *mysh;
    char **envp;
    int len;
    int fd;
    bool sigsegv;
    bool sigfpe;
};

typedef struct prompt_t prompt_t;
struct prompt_t
{
    char *path;
    char *dir;
    char *prmt;
};


int check_arg(int ac, char **av);
char **my_env(char *envp[]);
char **find_path2(mysh_t *exe);

int count_slash(char *line);
char *fill_dir(char *path, int len, int i);
char *fill_prompt(char *dir, int len2);
void display_prompt(mysh_t *exe);
void lauch_execution(mysh_t *exe);
void free_list(minish *mysh);
void execution_of_shell(mysh_t *exe, char *all_command);
void minishell(mysh_t *exe);

char *cleaned_str(char *str);
int nb_words(char *str);
char **word_array(char *str, int nb_of_words);

char **find_arg(char *command, minish *mysh);
void find_param(char *command, minish *mysh);
void free_param(minish *mysh);

pid_t give_birth(void);
void do_it(int can_i, mysh_t *exe);
void end_status(mysh_t *exe, int status);
void child_process(pid_t childID, mysh_t *exe);
void parent_process(pid_t childID, mysh_t *exe);

int check_access(mysh_t *exe);
int do_exec(mysh_t *exe);
void execute(mysh_t *exe);

void check_exit(mysh_t *exe);
void check_cd(mysh_t *exe);
void check_setenv(mysh_t *exe);
void check_unsetenv(mysh_t *exe);
void check_semicolon(mysh_t *exe, char *redir);
void check_write_in_file(mysh_t *exe, char *redir);
void check_write_at_end_of_file(mysh_t *exe, char *redir);
void check_read_from_file(mysh_t *exe, char *redir);
void check_read_here_document(mysh_t *exe, char *redir);
void check_pipe(mysh_t *exe, char *redir);

char *find_path(mysh_t *exe);
void builtin_cd(mysh_t *exe);

char *find_name(char *line);
char *find_value(char *line);
char *search_env(mysh_t *exe, char *to_find);
int builtin_setenv(mysh_t *exe);
int builtin_unsetenv(mysh_t *exe);

void builtin_semicolon(mysh_t *exe);
void builtin_write_in_file(mysh_t *exe);
void builtin_write_at_end_of_file(mysh_t *exe);
void builtin_read_from_file(mysh_t *exe);
void builtin_read_here_document(mysh_t *exe);
void builtin_pipe(mysh_t *exe);

char *remove_begin_end_redir(char *s);
bool is_redir(char c);
int count_redir(char *all_command);
char **mem_alloc_redir(int rows, char *all_command);
char **make_the_arr(char *all_command);
char **cleaned_arr(char *all_command);

int redir_syntax(char *command);
minish *create_list(char *command, char *redir);
minish *add_to_list(minish *list, char *command, char *redir);
minish *delete_node(minish *link);
minish *init_list_of_command(mysh_t *exe, char *all_command);
char *to_redir(char *redir);

void stdout_to_write(char *fichier, int flags);
void read_to_stdin(char *fichier, int flags);
char *putstr_fd(int fd, char *str);

#endif

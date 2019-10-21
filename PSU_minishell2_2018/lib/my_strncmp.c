/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** create my_strncmp
*/

int my_strncmp(char const *S_one, char const *S_two, int n)
{
    int i = 1;

    while (*S_one && *S_two && *S_one == *S_two && i != n) {
        i++;
        S_one++;
        S_two++;
    } return (*S_one - *S_two);
}

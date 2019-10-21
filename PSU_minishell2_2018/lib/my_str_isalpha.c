/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** create my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    int len;
    int check;

    len = 0;
    check = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || *str == 0)
            check++;
        else if ((*str >= 'A' && *str <= 'Z') || *str == 0)
            check++;
        else if ((*str >= '0' && *str <= '9') || *str == 0)
            check++;
        len++;
        str++;
    } return (len - check);
}

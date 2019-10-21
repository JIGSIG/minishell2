/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_putstr with additionnal octal base
*/

#include "my.h"

void my_put(char c)
{
    if (c < 8)
        my_putstr("00");
    if (c < 64 && c >= 8)
        my_putchar('0');
}

void my_format(char *str)
{
    while (*str) {
        if (*str < 32 || *str >= 127) {
            my_putstr("\\");
            my_put(*str);
            dectooct(*str);
        } else
            my_putchar(*str);
        str++;
    }
}

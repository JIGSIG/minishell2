/*
** EPITECH PROJECT, 2019
** filesize
** File description:
** return the number of bytes of a file from the filepath
*/

#include "my.h"

int from_fp(char *fp)
{
    struct stat statbuff;

    if (stat(fp, &statbuff) == -1) {
        return (-1);
    } return (statbuff.st_size);
}

int from_fd(int fd)
{
    struct stat statbuff;

    if (fstat(fd, &statbuff) == -1) {
        return (-1);
    } return (statbuff.st_size);
}

int form_file(const char *format, va_list ap)
{
    int size;
    int fd;
    char *fp;

    size = -1;
    switch (*format) {
    case 'd':
        fd = va_arg(ap, int);
        if ((size = from_fd(fd)) == -1)
            return (-1);
        break;
    case 's':
        fp = va_arg(ap, char *);
        if ((size = from_fp(fp)) == -1)
            return (-1);
        break;
    } return (size);
}

int my_filesize(const char *format, ...)
{
    va_list ap;
    int size;

    size = 0;
    if (my_strlen(format) != 2)
        return (-1);
    va_start(ap, format);
    while (*format) {
        if (*format != '%') {
            format++;
        } if (*format == '%') {
            format++;
            size = form_file(format, ap);
            format++;
        }
    } va_end(ap);
    return (size);
}

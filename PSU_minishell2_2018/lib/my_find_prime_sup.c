/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** create my_find_prime_sup
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    int i;

    i = nb;
    while (my_is_prime(i) != 1)
        i++;
    return (i);
}

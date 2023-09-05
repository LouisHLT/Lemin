/*
** EPITECH PROJECT, 2022
** my_atoi.c
** File description:
** my atoi fx
*/

#include <stdio.h>
#include <limits.h>

static int my_atoicond(int sign)
{
    if (sign == 1)
        return INT_MAX;
    else
        return INT_MIN;
}

int my_atoi(char *str)
{
    int sign = 1, base = 0, i = 0;

    while (str[i] == ' ') {
    i++;
    }
    if (str[i] == '-' || str[i] == '+') {
    sign = 1 - 2 * (str[i++] == '-');
    }
    while (str[i] >= '0' && str[i] <= '9') {
    if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
        my_atoicond(sign);
    }
    base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

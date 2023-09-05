/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** mini version on printf
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int mod = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        mod = (nb % 10);
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(48 + mod);
    } else {
        mod = nb;
        my_putchar(48 + mod);
    }
}

int switch_check(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case 'd':
    case 'i': my_put_nbr(va_arg(list, int)); i++; break;
    case 'c': my_putchar(va_arg(list, int)); i++; break;
    case 's': my_putstr(va_arg(list, char *)); i++; break;
    case '%': my_putchar('%'); i++; break;
    }
    return i;
}

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i = switch_check(format, i, list);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return 0;
}

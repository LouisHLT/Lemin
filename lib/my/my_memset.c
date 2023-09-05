/*
** EPITECH PROJECT, 2023
** my_memset.c
** File description:
** memset
*/

#include <unistd.h>
#include "my.h"

void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;
    for (size_t i = 0; i < num; i++) {
        *p++ = (unsigned char)value;
    }
    return ptr;
}

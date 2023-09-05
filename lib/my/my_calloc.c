/*
** EPITECH PROJECT, 2023
** my_calloc.c
** File description:
** calloc
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void *my_calloc(size_t count, size_t size)
{
    size_t total_size = count * size;
    void *ptr = malloc(total_size);
    if (ptr == NULL) {
        return NULL;
    }
    my_memset(ptr, 0, total_size);
    return ptr;
}

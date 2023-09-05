/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** my_array_len.c
*/

#include "my.h"

int my_array_len(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}

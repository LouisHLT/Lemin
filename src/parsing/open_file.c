/*
** EPITECH PROJECT, 2023
** read_anthill.c
** File description:
** read file
*/

#include "my.h"

int check_empty_file(int empty_file, ssize_t bytes_read, char *buffer)
{
    if (empty_file){
        return 84;
    }
    if (bytes_read == -1) {
        if (buffer != NULL)
            free(buffer);
        return 1;
    }
}

int open_file(char **av, anth_t *anth)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read; char ch;
    int empty_file = 1;
    while ((bytes_read = read(STDIN_FILENO, &ch, 1)) > 0) {
        empty_file = 0;
        buffer_size++;
        buffer = my_realloc(buffer, buffer_size + 1);
        buffer[buffer_size - 1] = ch;
    }
    if (check_empty_file(empty_file, bytes_read, buffer) == 84){
        return 84;
    }
    buffer = my_realloc(buffer, buffer_size + 1);
    if (buffer == NULL)
        return 1;
    buffer[buffer_size] = '\0';
    anth->info = my_str_to_word_array(buffer, '\n');
    free(buffer);
    return 0;
}

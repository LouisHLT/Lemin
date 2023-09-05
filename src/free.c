/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** free.c
*/

#include "my.h"

void free_var(anth_t *anth)
{
    for (int i = 0; anth->info[i]; i++)
        free(anth->info[i]);
    free(anth->info);
    free(anth);

}

void free_linked_list(list_t *head)
{
    list_t *current = head;
    list_t *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

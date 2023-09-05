/*
** EPITECH PROJECT, 2023
** linked_lists_utils.c
** File description:
** utils
*/

#include "my.h"

void add_node(list_t **head, char *data)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void fill_linked_list(anth_t *anth, list_t **head)
{
    for (int i = 0; anth->info[i] != NULL; i++) {
        add_node(head, anth->info[i]);
    }
    list_t *current = *head;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}

int nb_count(int nb, char *str, char *name)
{
    if (my_strcmp(str, name) == 0)
        nb++;
    return nb;
}

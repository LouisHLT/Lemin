/*
** EPITECH PROJECT, 2023
** display_anthill.c
** File description:
** display hill
*/

#include "my.h"

void display_info(int ants_number, room_t *rooms,
                int room_count, list_t *head)
{
    my_printf("#number_of_ants\n");
    my_printf("%d\n", ants_number);
    my_printf("#rooms\n");
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].is_start)
            my_printf("##start\n");
        if (rooms[i].is_end)
            my_printf("##end\n");
        my_printf("%s %d %d\n", rooms[i].name, rooms[i].x, rooms[i].y);
    }
    my_printf("#tunnels\n");
    list_t *current = head;
    while (current != NULL) {
        char *line = current->data;
        if (my_strchr(line, '-'))
            my_printf("%s\n", line);
        current = current->next;
    }
}

void display_parsed_info(int ants_number, room_t *rooms,
                        int room_count, list_t *head)
{
    display_info(ants_number, rooms, room_count, head);
    for (int i = 0; i < room_count; i++) {
        free(rooms[i].name);
    }
    free(rooms);
}

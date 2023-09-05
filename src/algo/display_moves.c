/*
** EPITECH PROJECT, 2023
** display_moves.c
** File description:
** display moves
*/

#include "my.h"

void reconstruct_path(int *parents, anth_t *anth, int **path, int *path_length)
{
    *path_length = 0;
    int current_room = anth->end_room;
    while (current_room != anth->start_room) {
        (*path_length)++;
        *path = (int *)my_realloc(*path, *path_length * sizeof(int));
        (*path)[*path_length - 1] = current_room;
        current_room = parents[current_room];
    }
    (*path_length)++;
    *path = (int *)my_realloc(*path, *path_length * sizeof(int));
    (*path)[*path_length - 1] = anth->start_room;
    for (int i = 0; i < *path_length / 2; i++) {
        int temp = (*path)[i];
        (*path)[i] = (*path)[*path_length - 1 - i];
        (*path)[*path_length - 1 - i] = temp;
    }
}

void update_ant_positions(int ant, print_moves_t *data)
{
    if (data->ants_positions[ant] < data->path_length - 1) {
        int next_room = data->path[data->ants_positions[ant] + 1];
        if (data->occupied_rooms[next_room]) {
            return;
        }
        data->ants_positions[ant]++;
        data->occupied_rooms[next_room] = 1;
        my_printf("P%d-%d ", ant + 1, next_room);
        if (next_room == data->path[data->path_length - 1]) {
            (*data->ants_finished)++;
        }
    }
}

void print_ant_movements(int number_of_ants, int *path, int path_length)
{
    int *ants_positions = (int *)my_calloc(number_of_ants, sizeof(int));
    int ants_finished = 0;
    int max_room_id = find_max_room_id(path, path_length);

    print_moves_t data = {
        number_of_ants, ants_positions, NULL, path,
        path_length, &ants_finished
    };

    while (ants_finished < number_of_ants) {
        int *occupied_rooms = (int *)my_calloc(max_room_id + 1, sizeof(int));
        data.occupied_rooms = occupied_rooms;
        for (int ant = 0; ant < number_of_ants; ant++) {
            update_ant_positions(ant, &data);
        }
        my_printf("\n");
        free(occupied_rooms);
    }
    free(ants_positions);
}

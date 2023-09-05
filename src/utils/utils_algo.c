/*
** EPITECH PROJECT, 2023
** utils_algo.c
** File description:
** utils aglo
*/

#include "limits.h"
#include"my.h"

int *init_ant_pos(int number_of_ants, int start_room)
{
    int *ants_positions = (int *)malloc(number_of_ants * sizeof(int));
    for (int i = 0; i < number_of_ants; i++) {
        ants_positions[i] = start_room;
    }
    return ants_positions;
}

int *initialize_distances(int number_of_vertices, int start_room)
{
    int *distances = (int *)malloc(number_of_vertices * sizeof(int));
    for (int i = 0; i < number_of_vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[start_room] = 0;
    return distances;
}

int find_max_room_id(int *path, int path_length)
{
    int max_room_id = -1;
    for (int i = 0; i < path_length; i++) {
        if (path[i] > max_room_id) {
            max_room_id = path[i];
        }
    }
    return max_room_id;
}

int graph_has_edge(graph_t *graph, int v1, int v2)
{
    node_t *current_node = graph->adj_lists[v1];
    while (current_node != NULL) {
        if (current_node->vertex == v2) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

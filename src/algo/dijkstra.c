/*
** EPITECH PROJECT, 2023
** dijkstra.c
** File description:
** algo
*/

#include "limits.h"
#include "my.h"

void update_current_room(graph_t *graph, dijkstra_data_t *data,
                        int *current_room, int *min_distance)
{
    *current_room = -1;
    *min_distance = INT_MAX;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (!graph->visited[i] && data->distances[i] < *min_distance) {
            *min_distance = data->distances[i];
            *current_room = i;
        }
    }
}

void update_distance(int new_distance, dijkstra_data_t *data,
                    int i, int current_room)
{
    if (new_distance < data->distances[i]) {
        data->distances[i] = new_distance;
        data->parents[i] = current_room;
    }
}

void update_distances_and_parents(graph_t *graph,
                    dijkstra_data_t *data, int current_room)
{
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph_has_edge(graph, current_room, i)) {
            int new_distance = data->distances[current_room] + 1;
            update_distance(new_distance, data, i, current_room);
        }
    }
}

void dijkstra(graph_t *graph, int start_room,
                int end_room, dijkstra_data_t *data)
{
    graph->visited = (int *)my_calloc(graph->num_vertices, sizeof(int));
    int current_room;
    int min_distance;

    while (1) {
        update_current_room(graph, data, &current_room, &min_distance);
        if (current_room == -1) {
            break;
        }
        graph->visited[current_room] = 1;
        update_distances_and_parents(graph, data, current_room);
    }
}

/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** engine.c
*/

#include "my.h"
#include "graph.h"
#include "limits.h"

int process_algo_lem(int num_edges, int num_vertices, anth_t *anth)
{
    graph_t *graph = create_graph(num_vertices);
    process_edges(anth, graph);
    int *ants_positions = init_ant_pos(anth->num_ants, anth->start_room);
    dijkstra_data_t data;
    data.distances = initialize_distances(num_vertices, anth->start_room);
    data.parents = (int *)malloc(num_vertices * sizeof(int));
    dijkstra(graph, anth->start_room, anth->end_room, &data);
    if (data.distances[anth->end_room] == INT_MAX) {
        my_printf("There is no valid path between the start and end rooms.\n");
        free_graph(graph);
        return 84;
    }
    int *path = NULL;
    int path_length = 0;
    reconstruct_path(data.parents, anth, &path, &path_length);
    print_ant_movements(anth->num_ants, path, path_length);
    free_graph(graph);
    return 0;
}

int engine_lemin(int ret_value, anth_t *anth)
{
    if (ret_value == 0) {
        ret_value = parsing(anth);
        if (ret_value == 0) {
            my_printf("#moves\n");
            store_room(anth);
            int num_vertices = count_vertices(anth->info);
            int num_edges = count_edges(anth->info);
            ret_value = process_algo_lem(num_edges, num_vertices, anth);
        }
    }
    return ret_value;
}

int engine(int argc, char **argv)
{
    if (argc != 1) {
        my_printf("Check usage\n");
        return 84;
    }
    anth_t *anth = malloc(sizeof(anth_t));
    int ret_value = open_file(argv, anth);
    if (ret_value == 84) {
        my_printf("File is empty\n");
        return 84;
    }
    ret_value = engine_lemin(ret_value, anth);
    for (int i = 0; anth->info[i] != NULL; i++) {
        free(anth->info[i]);
    }
    free(anth->info);
    return ret_value;
}

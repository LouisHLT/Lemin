/*
** EPITECH PROJECT, 2023
** process_graph.c
** File description:
** process_graph
*/

#include "my.h"
#include "graph.h"

void parse_edge_info(char *str, int *src, int *dest)
{
    *src = my_atoi(str);
    while (*str != '-' && *str != '\0') {
        str++;
    }
    if (*str == '-') {
        str++;
    }
    *dest = my_atoi(str);
}

void process_edges(anth_t *anth, graph_t *graph)
{
    for (int i = 0; anth->info[i] != NULL; i++) {
        if (anth->info[i][0] >= '0' && anth->info[i][0] <= '9'
            && my_strchr(anth->info[i], '-') != NULL) {
            int src;
            int dest;
            parse_edge_info(anth->info[i], &src, &dest);
            add_edge(graph, src, dest);
            add_edge(graph, dest, src);
        }
    }
}

int count_vertices(char **info)
{
    int count = 0;
    for (int i = 0; info[i] != NULL; i++) {
        if (info[i][0] != '#' && my_strchr(info[i], '-') == NULL) {
            count++;
        }
    }
    return count;
}

int count_edges(char **info)
{
    int count = 0;
    for (int i = 0; info[i] != NULL; i++) {
        if (info[i][0] != '#' && my_strchr(info[i], '-') != NULL) {
            count++;
        }
    }
    return count;
}

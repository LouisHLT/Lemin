/*
** EPITECH PROJECT, 2023
** create_graph.c
** File description:
** create graph
*/

#include "my.h"
#include "graph.h"

node_t *create_node(int v)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

graph_t *create_graph(int num_vertices)
{
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->adj_lists = malloc(num_vertices * sizeof(node_t*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

void free_graph(graph_t *graph)
{
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *curr = graph->adj_lists[i];
        while (curr != NULL) {
            node_t *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->adj_lists);
    free(graph);
}

void add_edge(graph_t *graph, int src, int dest)
{
    node_t *new_node = create_node(dest);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
}

void print_graph(graph_t *graph)
{
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *curr = graph->adj_lists[i];
        if (curr == NULL) continue;
        my_printf("adjacency list of vertex %d: ", i);
        while (curr != NULL){
            my_printf("(%d) -> ", curr->vertex);
            curr = curr->next;
        }
        my_printf("NULL\n");
    }
}

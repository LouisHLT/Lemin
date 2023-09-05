/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** my.h
*/

#ifndef _MY_H_
    #define _MY_H_

    #include "graph.h"
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <dirent.h>
    #include <string.h>
    #include <errno.h>
    #include <stdbool.h>
    #include <stdint.h>

    #define NORMAL_ROOM 0
    #define START_ROOM 1
    #define END_ROOM 2
    #define TRUE 0
    #define FALSE 1
    #define ERROR 84
    #define SUCCESS 0

typedef struct list {
    char *data;
    struct list *next;
} list_t;

typedef struct anth {
    int num_ants;
    int start_room;
    int end_room;
    char **info;
} anth_t;

typedef struct room {
    char *name;
    int x;
    int y;
    int is_start;
    int is_end;
} room_t;

typedef struct node_t {
    int vertex;
    struct node_t *next;
} node_t;

typedef struct graph_t {
    int num_vertices;
    node_t **adj_lists;
    int *distance;
    int *visited;
    int *parents;
    int *path;
    int path_length;
} graph_t;

typedef struct dikstra_data{
    int *distances;
    int *parents;
} dijkstra_data_t;

typedef struct print_moves {
    int number_of_ants;
    int *ants_positions;
    int *occupied_rooms;
    int *path;
    int path_length;
    int *ants_finished;
} print_moves_t;

/* main.c */

/* free.c */
void free_var(anth_t *anth);
void free_linked_list(list_t *head);

/* open_file.c */
int open_file(char **av, anth_t *anth);
int check_empty_file(int empty_file, ssize_t bytes_read, char *buffer);

/* parsing.c */
int parsing(anth_t *anth);
int check_tunnels(anth_t *anth, int i);

/* linked_lists_utils.c */
void add_node(list_t **head, char *data);
void fill_linked_list(anth_t *anth, list_t **head);
void free_tab(char **tab);
int nb_count(int nb, char *str, char *name);

/*algo_utils.c*/
int *init_ant_pos(int number_of_ants, int start_room);
int find_max_room_id(int *path, int path_length);
int *initialize_distances(int number_of_vertices, int start_room);
int graph_has_edge(graph_t *graph, int v1, int v2);

/*dijkstra.c*/
void dijkstra(graph_t *graph, int start_room,
            int end_room, dijkstra_data_t *data);
void reconstruct_path(int *parents, anth_t *anth,
            int **path, int *path_length);
void print_ant_movements(int number_of_ants, int *path, int path_length);

/*display_moves.c*/
void reconstruct_path(int *parents, anth_t *anth,
            int **path, int *path_length);
void print_ant_movements(int number_of_ants, int *path, int path_length);


/*check_rooms.c*/
int check_rooms(anth_t *anth, int i);
int info_tunnel(char *str);
int nb_count(int nb, char *str, char *name);
void store_room(anth_t *anth);
char *rm_comment(char *str);

/* display_anthill.c */
void display_info(int ants_number, room_t *rooms,
                int room_count, list_t *head);
void display_parsed_info(int ants_number, room_t *rooms,
                        int room_count, list_t *head);

/* create_graph.c*/
node_t *create_node(int v);
graph_t *create_graph(int num_vertices);
void free_graph(graph_t *graph);
void add_edge(graph_t *graph, int src, int dest);
void print_graph(graph_t *graph);

/*process_graph.c*/
void parse_edge_info(char *str, int *src, int *dest);
void process_edges(anth_t *anth, graph_t *graph);
int count_vertices(char **info);
int count_edges(char **info);

/* engine.c */
int engine(int argc, char **argv);

/* LIB */
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int rows_string(char *str);
char **malloc_array(char *str);
int switch_check(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *str, char separator);
int my_atoi(char *str);
int my_str_isalpha(char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strdup(char *str);
char *my_strstr(const char *haystack, const char *needle);
void *my_realloc(void *ptr, size_t size);
void *my_memcpy(void *dest, void *src, size_t n);
char *my_strchr(const char *s, int c);
int my_array_len(char **array);
int my_is_digit(char *str);
void *my_calloc(size_t count, size_t size);
void *my_memset(void *ptr, int value, size_t num);

#endif

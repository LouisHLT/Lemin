/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** parsisng.c
*/

#include "graph.h"
#include "my.h"

int check_tunnels(anth_t *anth, int i)
{
    int a = i;
    for (i; anth->info[i] != NULL; i++) {
        if (anth->info[i][0] == '#' && anth->info[i][1] != '#')
            continue;
        if (anth->info[i][0] == '#' && anth->info[i][1] == '#')
            return FALSE;
        if (info_tunnel(anth->info[i]) == FALSE)
            return FALSE;
        if (i == a)
        my_printf("#tunnels\n");
        my_printf("%s\n", anth->info[i]);
    }
    if (i == a)
        return FALSE;
    return TRUE;
}

static int check_anth_number(anth_t *anth, int i)
{
    anth->info[i] = rm_comment(anth->info[i]);
    char *num = anth->info[i];
    if (num[0] == '\0') {
        return FALSE;
    }
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] >= '0' && num[i] <= '9') {
            continue;
        } else {
        my_printf("#number_of_ants\n");
            return FALSE;
        }
    }
    if (my_strcmp(num, "0") == 0) {
        my_printf("#number_of_ants\n0\n#rooms\n");
        return FALSE;
    }
    my_printf("#number_of_ants\n%s\n", anth->info[i]);
    anth->num_ants = my_atoi(num);
    return TRUE;
}

static int parse_rooms(anth_t *anth)
{
    int i = 0;
    for (i; anth->info[i][0] == '#' && anth->info[i][1] != '#'; i++);
    if (check_anth_number(anth, i) == FALSE)
        return FALSE;
    i++;
    i = check_rooms(anth, i);
    if (i == FALSE)
        return FALSE;
    if (check_tunnels(anth, i) == FALSE)
        return FALSE;
    return TRUE;
}

static int parse_anthill(anth_t *anth, list_t **head, room_t **rooms)
{
    int ants_number = 0;
    int room_count = 0;
    int ret_value = parse_rooms(anth);
    fill_linked_list(anth, head);
    for (int i = 0; i < room_count; i++) {
        free((*rooms)[i].name);
    }
    free(*rooms);
    return ret_value;
}

int parsing(anth_t *anth)
{
    list_t *head = NULL;
    room_t *rooms = NULL;
    int ret_value = parse_anthill(anth, &head, &rooms);
    if (ret_value != 0)
        return 1;
    else
        return 0;
}

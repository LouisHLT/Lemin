/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** check_rooms.c
*/

#include "my.h"

char *rm_comment(char *str)
{
    int i = 2;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == '#') {
            str[i] = '\0';
            break;
        }
    }
    if (str[i - 1] == ' ')
        str[i - 1] = '\0';
    return str;
}

int info_room(char *str)
{
    if (str[0] == '#')
        return TRUE;
    str = rm_comment(str);
    char **tab = my_str_to_word_array(str, ' ');
    if (my_array_len(tab) != 3) {
        free_tab(tab);
        return FALSE;
    }
    for (int i = 1; tab[i] != NULL; i++) {
        if (my_is_digit(tab[i]) == TRUE) {
            free_tab(tab);
            return FALSE;
        }
    }
    free_tab(tab);
    return TRUE;
}

int info_tunnel(char *str)
{
    str = rm_comment(str);
    char **tab = my_str_to_word_array(str, '-');
    if (my_array_len(tab) != 2) {
        free_tab(tab);
        return FALSE;
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_is_digit(tab[i]) == TRUE) {
            free_tab(tab);
            return FALSE;
        }
    }
    free_tab(tab);
    return TRUE;
}

void store_room(anth_t *anth)
{
    int start_room_found = 0;
    int end_room_found = 0;
    for (int i = 1; anth->info[i] != NULL; i++) {
        if (my_strcmp(anth->info[i], "##start") == 0) {
            start_room_found = 1;
            anth->start_room = my_atoi(anth->info[i + 1]);
        }
        if (my_strcmp(anth->info[i], "##end") == 0) {
            end_room_found = 1;
            anth->end_room = my_atoi(anth->info[i + 1]);
        }
    }
}

int check_rooms(anth_t *anth, int i)
{
    int start = 0; int end = 0;
    int false_room = 0; int ret = 0; my_printf("#rooms\n");
    for (i; anth->info[i] != NULL; i++) {
        if (anth->info[i][0] == '#' && anth->info[i][1] != '#') continue;
        if (anth->info[i][0] == '#' && anth->info[i][1] == '#'
                && (my_strcmp(anth->info[i], "##start") != 0
                && my_strcmp(anth->info[i], "##end") != 0))
                    return FALSE;
        start = nb_count(start, anth->info[i], "##start");
        if (start > 1)
            return FALSE;
        end = nb_count(end, anth->info[i], "##end");
        if (end > 1)
            return FALSE;
        if (info_tunnel(anth->info[i]) == TRUE) break;
        if (info_room(anth->info[i]) == FALSE) return FALSE;
    my_printf("%s\n", anth->info[i]);
    }
    if (start == 0 || end == 0) return FALSE;
    return i;
}

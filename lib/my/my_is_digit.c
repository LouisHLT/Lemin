/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** my_is_digit.c
*/

int my_is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

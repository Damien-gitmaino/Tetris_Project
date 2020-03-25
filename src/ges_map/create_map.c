/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_map.c
*/

#include "tetris.h"

char **fill_map(char **map, int line, int colum)
{
    for (int i = 0; i < line + 2; i++)
        for (int o = 0; o < colum + 2; o++)
            map[i][o] = ' ';
    map[0][0] = '+';
    map[(line + 2) - 1][0] = '+';
    map[0][(colum + 2) - 1] = '+';
    map[(line + 2) - 1][(colum + 2) - 1] = '+';
    for (int i = 1; i < (colum + 2) - 1; i++)
        map[0][i] = '-';
    for (int i = 1; i < (colum + 2) - 1; i++)
        map[(line + 2) - 1][i] = '-';
    for (int i = 1; i < (line + 2) - 1; i++)
        map[i][0] = '|';
    for (int i = 1; i < (line + 2) - 1; i++)
        map[i][(colum + 2) - 1] = '|';
    return (map);
}

void init_map(info_g *info, int line, int colum)
{
    info->map = malloc(sizeof(char *) * (line + 2) + 1);

    if (info->map == NULL)
        exit (84);
    info->map[line + 2] = NULL;
    for (int i = 0; i < line + 2; i++) {
        info->map[i] = malloc(sizeof(char) * (colum + 2) + 1);
        if (info->map[i] == NULL)
            exit (84);
        info->map[i][colum + 2] = '\0';
    }
    info->map = fill_map(info->map, line, colum);
}
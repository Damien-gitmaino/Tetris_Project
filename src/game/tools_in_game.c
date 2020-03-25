/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tools_in_game.c
*/

#include "tetris.h"

int check_line_full(char **map)
{
    int count = 0;

    for (int i = 1; map[i] != NULL; i++)  {
        for (int o = 0; map[i][o] != '\0'; o++)
            if (map[i][o] == '*')
                count += 1;
        if (count == my_strlen(map[i]) - 2)
            return (i);
        else
            count = 0;
    }
    return (-1);
}

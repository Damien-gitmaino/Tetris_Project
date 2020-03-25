/*
** EPITECH PROJECT, 2019
** Tetris_Project
** File description:
** game_loop.c
*/

#include "tetris.h"

void print_map(char **map)
{
    int row = 0;
    int col = 0;
    int number_n = 0;

    for (; map[number_n] != NULL; number_n++);
    getmaxyx(stdscr, row, col);
    row = (row - (number_n / 2) * 2) / 2;
    for (int i = 0; i < number_n; i++, row++)
        mvprintw(row, (col - my_strlen(map[i])) / 2, "%s\n", map[i]);
}

void game_loop(key_p *key, trimino_d *mino)
{
    char **map = init_map(key->line, key->colum);

    initscr();
    noecho();
    print_map(map);
    refresh();
    getch();
    endwin();
}
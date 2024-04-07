/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** functions for sokoban
*/

#include "struct.h"

static void is_player(game_t *all, int i, int j)
{
    if (all->tab[i][j] == 'P') {
        all->py = i;
        all->px = j;
    }
}

void get_pos(game_t *all)
{
    for (int i = 0; all->tab[i] != NULL; i++) {
        for (int j = 0; all->tab[i][j] != '\0'; j++) {
            is_player(all, i , j);
        }
    }
}

static int move_up(game_t *all)
{
    if (all->py == 0 || all->tab[all->py - 1][all->px] == '#') {
        return (0);
    }
    if (all->tab[all->py - 1][all->px] == ' ' ||
    all->tab[all->py - 1][all->px] == 'O') {
        all->tab[all->py - 1][all->px] = 'P';
        all->tab[all->py][all->px] = ' ';
    }
    if (all->tab[all->py - 1][all->px] == 'X') {
        if (all->py - 1 == 0 || all->tab[all->py - 2][all->px] == '#' ||
        all->tab[all->py - 2][all->px] == 'X')
            return (0);
        all->tab[all->py - 1][all->px] = 'P';
        all->tab[all->py - 2][all->px] = 'X';
        all->tab[all->py][all->px] = ' ';
    }
    return (0);
}

static int move_down(game_t *all)
{
    if (all->tab[all->py + 1] == NULL ||
    all->tab[all->py + 1][all->px] == '#') {
        return (0);
    }
    if (all->tab[all->py + 1][all->px] == ' ' ||
    all->tab[all->py + 1][all->px] == 'O') {
        all->tab[all->py + 1][all->px] = 'P';
        all->tab[all->py][all->px] = ' ';
    }
    if (all->tab[all->py + 1][all->px] == 'X') {
        if (all->tab[all->py + 2] == NULL ||
        all->tab[all->py + 2][all->px] == '#' ||
        all->tab[all->py + 2][all->px] == 'X')
            return (0);
        all->tab[all->py + 1][all->px] = 'P';
        all->tab[all->py + 2][all->px] = 'X';
        all->tab[all->py][all->px] = ' ';
    }
    return (0);
}

static int move_left(game_t *all)
{
    if (all->px == 0 || all->tab[all->py][all->px - 1] == '#') {
        return (0);
    }
    if (all->tab[all->py][all->px - 1] == ' ' ||
    all->tab[all->py][all->px - 1] == 'O') {
        all->tab[all->py][all->px - 1] = 'P';
        all->tab[all->py][all->px] = ' ';
    }
    if (all->tab[all->py][all->px - 1] == 'X') {
        if (all->px - 1 == 0 || all->tab[all->py][all->px - 2] == '#' ||
        all->tab[all->py][all->px -2] == 'X')
            return (0);
        all->tab[all->py][all->px - 1] = 'P';
        all->tab[all->py][all->px - 2] = 'X';
        all->tab[all->py][all->px] = ' ';
    }
    return (0);
}

static int move_right(game_t *all)
{
    if (all->tab[all->py][all->px + 1] == '\0' ||
    all->tab[all->py][all->px + 1] == '#') {
        return (0);
    }
    if (all->tab[all->py][all->px + 1] == ' ' ||
    all->tab[all->py][all->px + 1] == 'O') {
        all->tab[all->py][all->px + 1] = 'P';
        all->tab[all->py][all->px] = ' ';
    }
    if (all->tab[all->py][all->px + 1] == 'X') {
        if (all->tab[all->py][all->px + 2] == '\0' ||
        all->tab[all->py][all->px + 2] == '#' ||
        all->tab[all->py][all->px + 2] == 'X')
            return (0);
        all->tab[all->py][all->px + 1] = 'P';
        all->tab[all->py][all->px + 2] = 'X';
        all->tab[all->py][all->px] = ' ';
    }
    return (0);
}

void display(game_t *all, int i)
{
    for (int j = 0; all->calk[i][j] != '\0'; j++) {
        mvprintw(i, j, "%c", all->calk[i][j]);
        if (all->tab[i][j] == 'P' || all->tab[i][j] == 'X')
            mvprintw(i, j, "%c", all->tab[i][j]);
    }
}

void load(game_t *all)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    for (int i = 0; all->calk[i] != NULL; i++)
        display(all, i);
}

void reset(int argc, char **argv, game_t *all)
{
    all->restart = 1;
    setup(argc, argv, all);
}

int move_player(game_t *all, int argc, char **argv)
{
    switch (all->entry) {
        case ' ':
            reset(argc, argv, all);
            return (0);
        case 'q':
            return (-1);
        case KEY_UP:
            move_up(all);
            return (0);
        case KEY_DOWN:
            move_down(all);
            return (0);
        case KEY_LEFT:
            move_left(all);
            return (0);
        case KEY_RIGHT:
            move_right(all);
            return (0);
    }
    return (0);
}

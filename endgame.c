/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** win and loose for my_sokoban
*/

#include "struct.h"

int help(int argc, char **argv, game_t *all)
{
    all->restart = 0;
    if (argc != 2)
        return (0);
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        my_putstr("USAGE\n");
        my_putstr("\t./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tmap file representing the warehouse map,");
        my_putstr(" containing '#' for walls,\n\t\t'P' for the player,");
        my_putstr(" 'X' for boxes and 'O' for storage locations.\n");
        return (1);
    }
    return (0);
}

int termsize(game_t *all)
{
    int rows = 0;
    int cols = 0;

    getmaxyx(stdscr, rows, cols);
    if (rows < all->lines || cols < all->cols) {
        clear();
        mvprintw(rows / 2, cols / 2 - 15, "Please enlarge terminal size");
        refresh();
        return (1);
    }
    return (0);
}

static int boxstuck(game_t *all, int i, int j)
{
    if (all->tab[i][j] == 'X') {
        if (((all->tab[i - 1][j] == '#' || all->tab[i - 1][j] == 'X') &&
        (all->tab[i][j - 1] == '#' || all->tab[i][j - 1] == 'X')) ||
        ((all->tab[i][j - 1] == '#' || all->tab[i][j - 1] == 'X') &&
        (all->tab[i + 1][j] == '#' || all->tab[i + 1][j] == 'X')) ||
        ((all->tab[i + 1][j] == '#' || all->tab[i + 1][j] == 'X') &&
        (all->tab[i][j + 1] == '#' || all->tab[i][j + 1] == 'X')) ||
        ((all->tab[i][j + 1] == '#' || all->tab[i][j + 1] == 'X') &&
        (all->tab[i - 1][j] == '#' || all->tab[i - 1][j] == 'X'))) {
            return (1);
        }
    }
    return (0);
}

int loose(game_t *all)
{
    int nbrstuck = 0;

    for (int i = 0; all->tab[i] != NULL; i++) {
        for (int j = 0; all->tab[i][j] != '\0'; j++) {
            nbrstuck += boxstuck(all, i, j);
        }
    }
    if (nbrstuck == all->box) {
        endwin();
        return (1);
    }
    return (0);
}

static int boxonplace(game_t *all, int i, int j)
{
    if (all->tab[i][j] == 'X' && all->calk[i][j] == 'O')
        return (1);
    return (0);
}

int win(game_t *all)
{
    int nbrfill = 0;

    for (int i = 0; all->tab[i] != NULL; i++) {
        for (int j = 0; all->tab[i][j] != '\0'; j++) {
            nbrfill += boxonplace(all, i, j);
        }
    }
    if (nbrfill == all->box) {
        usleep(1000000);
        endwin();
        return (1);
    }
    return (0);
}

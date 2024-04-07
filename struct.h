/*
** EPITECH PROJECT, 2023
** struct_h
** File description:
** struct my sokoban
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include "my.h"
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <stdlib.h>

typedef struct game_s {
    int py;
    int px;
    int entry;
    char *str;
    char **tab;
    char **calk;
    int lines;
    int cols;
    int box;
    int restart;
} game_t;

void get_pos(game_t *all);
int move_player(game_t *all, int argc, char **argv);
void load(game_t *all);
void display(game_t *all, int i);
int win(game_t *all);
int loose(game_t *all);
int help(int argc, char **argv, game_t *all);
int setup(int argc, char **argv, game_t *all);
int errorcase(int argc, char **argv, game_t *all);
int termsize(game_t *all);

#endif

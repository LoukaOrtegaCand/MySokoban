/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** setting_up.c
*/

#include "struct.h"

static void recup(game_t *all, char **argv)
{
    struct stat info;
    char *file = argv[1];
    int fd = open(file, O_RDONLY);
    int offset = 0;
    int len;
    int size = 0;

    stat(file, &info);
    size = info.st_size;
    if (all->restart == 0)
        all->str = malloc(sizeof(char) * (size + 1));
    len = read(fd, all->str + offset, size - offset);
    while (len > 0) {
        offset += len;
        len = read(fd, all->str + offset, size - offset);
    }
    all->str[offset] = '\0';
}

static void dimension(game_t *all)
{
    int n = 0;

    all->lines = 0;
    all->cols = 0;
    for (int i = 0; all->str[i] != '\0'; i++) {
        if (all->cols < n)
            all->cols = n;
        if (all->str[i] == '\n') {
            all->lines += 1;
            n = 0;
        } else
            n += 1;
    }
}

static void copytab(game_t *all)
{
    int k = 0;
    int l = 0;

    for (int i = 0; all->str[i] != '\0'; i++) {
        if (all->str[i] == '\n') {
            all->tab[k][l] = '\0';
            i += 1;
            k += 1;
            l = 0;
        }
        if (all->str[i] != '\0') {
            all->tab[k][l] = all->str[i];
            l += 1;
        }
    }
    all->tab[k + 1] = NULL;
}

static void tab_to_tabstar(game_t *all)
{
    if (all->restart == 0) {
        all->tab = malloc(sizeof(char *) * (all->lines + 1));
        for (int i = 0; i < all->lines; i++)
            all->tab[i] = malloc(sizeof(char) * (all->cols + 1));
    }
    copytab(all);
    if (all->restart == 0) {
        all->calk = malloc(sizeof(char *) * (all->lines + 1));
        for (int i = 0; i < all->lines; i++)
            all->calk[i] = malloc(sizeof(char) * (all->cols + 1));
    }
}

static void element(game_t *all, int i, int j)
{
    if (all->tab[i][j] == '#' || all->tab[i][j] == 'O')
        all->calk[i][j] = all->tab[i][j];
    else
        all->calk[i][j] = ' ';
}

static void calk_map(game_t *all)
{
    int i = 0;
    int j = 0;

    for (; all->tab[i] != NULL; i++) {
        for (; all->tab[i][j] != '\0'; j++) {
            element(all, i, j);
        }
        all->calk[i][j] = '\0';
        j = 0;
    }
    all->calk[i] = NULL;
}

int errorcase(int argc, char **argv, game_t *all)
{
    int storage = 0;

    all->box = 0;
    if (argc != 2)
        return (84);
    if (open(argv[1], O_RDONLY) == -1)
        return (84);
    for (int i = 0; all->str[i] != '\0'; i++) {
        if (all->str[i] != 'O' && all->str[i] != ' ' && all->str[i] != '#' &&
        all->str[i] != 'X' && all->str[i] != 'P' && all->str[i] != '\n')
            return (84);
        if (all->str[i] == 'O')
            storage += 1;
        if (all->str[i] == 'X')
            all->box += 1;
        mvprintw(100, 0, "%i", all->box);
    }
    if (all->box != storage || all->box == 0)
        return (84);
    return (0);
}

int setup(int argc, char **argv, game_t *all)
{
    recup(all, argv);
    dimension(all);
    tab_to_tabstar(all);
    calk_map(all);
    return (errorcase(argc, argv, all));
}

int play(game_t *all, int argc, char **argv)
{
    while (1) {
        if (win(all) == 1)
            return (0);
        if (loose(all) == 1)
            return (1);
        get_pos(all);
        if (termsize(all) == 1)
            continue;
        all->entry = getch();
        if (move_player(all, argc, argv) == -1) {
            endwin();
            return (0);
        }
        clear();
        for (int i = 0; all->calk[i] != NULL; i++)
            display(all, i);
        refresh();
    }
}

int main(int argc, char **argv)
{
    game_t *all = malloc(sizeof(game_t));

    if (help(argc, argv, all) == 1)
        return (0);
    if (setup(argc, argv, all) == 84)
        return (84);
    load(all);
    return (play(all, argc, argv));
}

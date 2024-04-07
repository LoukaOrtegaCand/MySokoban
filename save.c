static void display(game_t *all, int i)
{
    for (int j = 0; all->calk[i][j] != '\0'; j++) {
        mvprintw(LINES / 2 - (all->lines / 2) + i, COLS / 2 - (all->cols / 2) + j, "%c", all->calk[i][j]);
        if (all->tab[i][j] == 'P' || all->tab[i][j] == 'X')
            mvprintw(LINES / 2 - (all->lines / 2) + i, COLS / 2 - (all->cols / 2) + j, "%c", all->tab[i][j]);
    }
}

/*
** EPITECH PROJECT, 2019
** main solver
** File description:
** martinage eleonore
*/

#include "solver.h"

int main(int ac, char **av)
{
    data_t *maze_sol;
    char **maze = get_maze(av[1]);

    if (ac != 2)
        return (84);
    else if (open(av[1], O_RDONLY) == -1)
        return (84);
    maze_sol = solve(maze, 0, 0);
    if (!maze_sol || maze_sol)
        return (84);
    while (maze_sol->next->next) {
        maze[maze_sol->y][maze_sol->x] = 'o';
        maze_sol = maze_sol->prev;
    }
    for (int i = 0; maze[i]; i++) {
        my_putstr(maze[i]);
        write(1, "\n", 1);
    }
    return (0);
}

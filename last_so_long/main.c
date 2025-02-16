/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +:+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:36:33 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/16 17:58:33 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Number of arguments not correct");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("ERROR opening file");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    char **map = NULL;
    int rows = 0;
    int cols = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        rows++;
        if (cols == 0)
        {
            cols = strlen(line) - 1;
        }
        free(line);
    }

    close(fd);
    fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("ERROR reopening file");
        return EXIT_FAILURE;
    }

    map = (char **)malloc(sizeof(char *) * rows);
    if (!map)
    {
        perror("Error allocating memory for map");
        close(fd);
        return EXIT_FAILURE;
    }

    int r = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[r] = (char *)malloc(sizeof(char) * (cols + 1));
        if (!map[r])
        {
            perror("Error allocating memory for map row");
            close(fd);
            free_map(map, r);
            return EXIT_FAILURE;
        }
        strncpy(map[r], line, cols);
        map[r][cols] = '\0';
        free(line);
        r++;
    }

    close(fd);

    map_check_wall(map, rows, cols);
    map_check_player(map, rows, cols);
    map_check_collectables(map, rows, cols);
    ghayermarghoub_fiha(map, rows, cols);
    printf("Map checked and it is success!\n");

    find_player_position_co(map, rows, cols);


    int game_status = 0;
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, cols * 64, rows * 64, "so_long");

    draw_map(mlx, mlx_win, map, rows, cols);

    void *params[8];
    params[0] = map;
    params[1] = (void *)(size_t)rows;
    params[2] = (void *)(size_t)cols;
    params[3] = &game_status;
    params[4] = mlx;
    params[5] = mlx_win;
   
    mlx_key_hook(mlx_win, key_hook);
    // key_hook(keycode, *params);

    mlx_loop(mlx);

    free_map(map, rows);

    return EXIT_SUCCESS;
}


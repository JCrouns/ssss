/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:18:21 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/16 20:24:03 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_map(void *mlx, void *mlx_win, char **tab, int rows, int cols)
{
    int width = 64;
    int height = 64;
    void *img;

    int y = 0;
    while (y < rows)
    {
        int x = 0;
        while (x < cols)
        {
            if (tab[y][x] == WALL)
                img = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
            else if (tab[y][x] == SPACE)
                img = mlx_xpm_file_to_image(mlx, "empty.xpm", &width, &height);
            else if (tab[y][x] == PLAYER)
                img = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height);
            else if (tab[y][x] == COLLECTABLE)
                img = mlx_xpm_file_to_image(mlx, "fruite.xpm", &width, &height);
            else if (tab[y][x] == EXIT)
                img = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height);
            else
                img = NULL;

            if (img)
            {
                mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
                mlx_destroy_image(mlx, img);
            }
            else
                fprintf(stderr, "Error: Could not load image for tile %c\n", tab[y][x]);

            x++;
        }
        y++;
    }
}


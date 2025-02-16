/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:50:31 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/16 18:05:16 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "./get_next_line.h"
#include </usr/include/minilibx-linux/mlx.h>
#include <stdlib.h>

#define PLAYER 'P'
#define COLLECTABLE 'C'
#define WALL '1'
#define SPACE '0'
#define EXIT 'E'

void map_check_wall(char **tab, int rows, int cols);
void map_check_player(char **tab, int rows, int cols);
void map_check_collectables(char **tab, int rows, int cols);
void ghayermarghoub_fiha(char **tab, int rows, int cols);
void print_map(char **tab, int rows, int cols);
void draw_map(void *mlx, void *mlx_win, char **tab, int rows, int cols);
int key_hook(int keycode, void *param);
void free_map(char **map, int rows);
int find_player_position_co(char **tab, int rows, int cols);
int find_player_position_ro(char **tab, int rows, int cols);
int move_player(char **tab, int rows, int cols, char direction , void **param);



#endif

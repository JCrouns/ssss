/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:18:02 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/16 18:18:03 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int move_player(char **tab, int rows, int cols, char direction) {
    int collected_items = 0;
    int total_collectables = 0;

    // Retrieve row and column from param
   
    int row = (int)(size_t)param[6];
    int col = (int)(size_t)param[7];

    // Validate tab pointer
    if (tab == NULL) {
        printf("Error: tab is NULL.\n");
        return -1;
    }

    // Validate row and column indices
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        printf("Error: Invalid row or column index.\n");
        return -1;
    }

    // Update new_row and new_col based on direction
    if (direction == 'W') {
        printf("move w\n");
        new_row--;
    } else if (direction == 'S') {
        printf("move s\n");
        new_row++;
    } else if (direction == 'A') {
        printf("move a\n");
        new_col--;
    } else if (direction == 'D') {
        printf("move d\n");
        new_col++;
    }

    // Validate new_row and new_col
    if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || tab[new_row][new_col] == WALL) {
        printf("Invalid move: Out of bounds or hitting a wall.\n");
        return 0;
    }

    // Update the player's position
    tab[row][col] = '0'; // Clear the current position

    if (tab[new_row][new_col] == 'C') {
        collected_items++;
    }

    tab[new_row][new_col] = 'P'; // Move the player to the new position
    return 2;
}
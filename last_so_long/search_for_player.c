/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:17:51 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/16 18:17:52 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_row = -1;
int player_col  = -1;
int collected_items =  0;
int total_collectables = 0;


int find_player_position_co(char **tab, int rows, int cols)
{
    int r = 0;
    int c = 0;
    int co;
    while (r < rows)
    {
        while (c < cols)
        {
            if (tab[r][c] == PLAYER)
            {
                player_row = r;
                player_col = c;
            }
            c++;
        }
        r++;
    }
    co = c;
    return (co);
}
int find_player_position_ro(char **tab, int rows, int cols)
{
    int r = 0;
    int c = 0;
    int ro;
    while (r < rows)
    {
        while (c < cols)
        {
            if (tab[r][c] == PLAYER)
            {
                player_row = r;
                player_col = c;
            }
            c++;
        }
        r++;
    }
    ro = r;
    return (ro);
}


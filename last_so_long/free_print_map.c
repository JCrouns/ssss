/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_print_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:18:10 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/16 18:18:11 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void free_map(char **map, int rows)
{
    int r = 0;
    while (r < rows)
    {
        free(map[r]);
        r++;
    }
    free(map);
}

void print_map(char **tab, int rows, int cols)
{
int collected_items =  0;
int total_collectables = 0;

    int r = 0;
    while (r < rows)
    {
        printf("%s\n", tab[r]);
        r++;
    }
    printf("Collected Items: %d/%d\n", collected_items, total_collectables);
}


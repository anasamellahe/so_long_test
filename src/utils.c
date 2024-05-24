/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:31:11 by anamella          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:58 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_size(t_vars *var)
{
	int	x;
	int	y;

	mlx_get_screen_size(var->mlx, &x, &y);
	if (var->win_x > x || var->win_y > y)
		return (1);
	return (0);
}

int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

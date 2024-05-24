/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:31:45 by anamella          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:31 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_free(map[i]);
		i++;
	}
	ft_free(map);
	return (1);
}

void	invalid_free(char *error, char **map, t_vars *var, t_img *img)
{
	if (img->bg)
		mlx_destroy_image(var->mlx, img->bg);
	if (img->col)
		mlx_destroy_image(var->mlx, img->col);
	if (img->exit)
		mlx_destroy_image(var->mlx, img->exit);
	if (img->player)
		mlx_destroy_image(var->mlx, img->player);
	if (img->wall)
		mlx_destroy_image(var->mlx, img->wall);
	free_map(map);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	write(2, error, ft_strlen(error));
	exit(1);
}

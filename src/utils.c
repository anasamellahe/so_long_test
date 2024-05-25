/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:31:11 by anamella          #+#    #+#             */
/*   Updated: 2024/05/25 16:24:03 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	check_file(char	*file)
{
	char	*tmp;

	tmp = ft_strnstr(file, ".ber", ft_strlen(file));
	while (ft_strlen(tmp) > ft_strlen(".ber"))
		tmp = ft_strnstr(tmp + 1, ".ber", ft_strlen(file));
	if (tmp == NULL)
		return (1);
	if (ft_strncmp(tmp, ".ber", ft_strlen(tmp)) == 0)
		return (0);
	return (1);
}

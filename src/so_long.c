/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:31:22 by anamella          #+#    #+#             */
/*   Updated: 2024/05/25 15:21:04 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_window_size(t_vars *var, int size, char **map)
{
	var->win_x = ft_strlen(map[0]) * size;
	var->win_y = 0;
	while (map[var->win_y])
		var->win_y++;
	var->win_y *= size;
}

int	set_img(t_vars *var, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(var->mlx, "textures/wall/wall.xpm",
			&img->wall_x, &img->wall_y);
	img->bg = mlx_xpm_file_to_image(var->mlx, "textures/bg/bg.xpm", &img->bg_x,
			&img->bg_y);
	img->player = mlx_xpm_file_to_image(var->mlx, "textures/player/player.xpm",
			&img->player_x, &img->player_y);
	img->col = mlx_xpm_file_to_image(var->mlx, "textures/apple/apple.xpm",
			&img->col_x, &img->col_y);
	img->exit = mlx_xpm_file_to_image(var->mlx, "textures/exit/exit.xpm",
			&img->exit_x, &img->exit_y);
	if (!img->wall || !img->bg || !img->player || !img->col || !img->exit)
		return (1);
	return (0);
}

void	set_posistion(t_position **pos, int size, t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				ft_lstadd_back_pos(pos, ft_new_pos(j * size, i * size, 1));
			if (map[i][j] == 'C')
				ft_lstadd_back_pos(pos, ft_new_pos(j * size, i * size, 2));
			if (map[i][j] == 'E')
				ft_lstadd_back_pos(pos, ft_new_pos(j * size, i * size, 3));
			if (map[i][j] == 'P')
			{
				player->x = j * size;
				player->y = i * size;
			}
			j++;
		}
		i++;
	}
}

int	map_generator(int fd)
{
	char	*line;
	char	*str;
	char	**map;

	line = get_next_line(fd);
	str = NULL;
	while (line)
	{
		str = ft_strjoin(str, line);
		ft_free(line);
		line = get_next_line(fd);
	}
	if (check_map_line(str) != -1)
	{
		map = ft_split(str, '\n');
		ft_free(str);
		if (check_map(map) == 1)
			return (free_map(map), 1);
		print_map(map);
	}
	else
		return (ft_free(str), 1);
	return (0);
}

int	main(int ac, char *av[])
{
	int	fd;

	if (ac == 2)
	{
		if (check_file(av[1]))
			return (write(2, "Error: invalid .ber file\n", 25), 1);
		fd = open(av[1], O_RDWR);
		if (fd == -1)
			return (write(2, "Error: No such file or directory\n", 33), 1);
		if (map_generator(fd))
			return (write(2, "Error:map invalid\n", 19), 1);
	}
	else
		return (write(2, "Error: invalid number of args\n", 30), 1);
	return (0);
}

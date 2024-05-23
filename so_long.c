#include "so_long.h"

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
	img->wall = mlx_xpm_file_to_image(var->mlx, "img/wall/wall32.xpm",
			&img->wall_x, &img->wall_y);
	img->bg = mlx_xpm_file_to_image(var->mlx, "img/bg/bg32.xpm",
			&img->bg_x, &img->bg_y);
	img->player = mlx_xpm_file_to_image(var->mlx, "img/player/player.xpm",
			&img->player_x, &img->player_y);
	img->col = mlx_xpm_file_to_image(var->mlx, "img/apple/apple1.xpm",
			&img->col_x, &img->col_y);
	img->exit = mlx_xpm_file_to_image(var->mlx, "img/exit/exit.xpm",
			&img->exit_x, &img->exit_y);
	if (!img->wall || !img->bg || !img->player || !img->col
		|| !img->exit)
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
		fd = open(av[1], O_RDWR);
		if (fd == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (map_generator(fd))
		{
			write(2, "Error:map invalid\n", 19);
			return (1);
		}
	}
	else
		return (1);
	return (0);
}

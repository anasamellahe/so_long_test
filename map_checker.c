#include "so_long.h"

int	check_if_map_closed(char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map && map[i][j])
		{
			if (map[0][j] != '1')
				return (1);
			if (map[i + 1] == NULL && map[i][j] != '1')
				return (1);
			j++;
		}
		if (map[i][j - 1] != '1' || map[i][0] != '1' || j < len || j > len)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_line(char *str)
{
	int	collectible;
	int	player;
	int	exit;
	int	i;

	collectible = 0;
	player = 0;
	exit = 0;
	i = 0;
	while (str[i])
	{
		exit += (str[i] == 'E');
		player += (str[i] == 'P');
		collectible += (str[i] == 'C');
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (-1);
		if ((str[i] != 'C' && str[i] != 'P' && str[i] != 'E' && str[i] != '0'
				&& str[i] != '1' && str[i] != '\n') || str[0] == '\n')
			return (-1);
		i++;
	}
	if (exit != 1 || player != 1 || collectible == 0)
		return (-1);
	return (0);
}

int	check_map(char **map)
{
	char	**tmp_map;
	int		i;
	int		j;

	if (check_if_map_closed(map))
		return (1);
	tmp_map = malloc(sizeof(char *) * (map_len(map) + 1));
	i = 0;
	while (map[i])
	{
		tmp_map[i] = ft_strdup(map[i]);
		i++;
	}
	tmp_map[i] = NULL;
	i = 0;
	j = 0;
	while (tmp_map[i] && tmp_map[i][j] != 'P')
	{
		j = 0;
		while (tmp_map[i][j] && tmp_map[i][j] != 'P')
			j++;
		i += (tmp_map[i][j] != 'P');
	}
	flood_fill(tmp_map, j, i, map_len(tmp_map));
	return (check_validation(tmp_map));
}

void	flood_fill(char **map, int x, int y, int h)
{
	if (map[y][x] != '0' && map[y][x] != 'C'
		&& map[y][x] != 'E' && map[y][x] != 'P')
		return ;
	map[y][x] = ('-' * (map[y][x] != 'E')) + ('2' * (map[y][x] == 'E'));
	if (y > 0)
		flood_fill(map, x, y - 1, h);
	if (y < h)
		flood_fill(map, x, y + 1, h);
	if (x > 0)
		flood_fill(map, x - 1, y, h);
	if (x < (int)ft_strlen(map[0]) && map[y][x + 1] != '\0')
		flood_fill(map, x + 1, y, h);
}

int	check_validation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
			{
				free_map(map);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_map(map);
	return (0);
}

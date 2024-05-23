#include "so_long.h"

void	print_collectible(t_vars *var, t_img *img, t_position *pos)
{
	while (pos)
	{
		if (pos->col_x != -1 && pos->col_y != -1)
			mlx_put_image_to_window(var->mlx, var->win, img->col, pos->col_x,
				pos->col_y);
		pos = pos->next;
	}
}

void	print_wall(t_vars *var, t_position *pos, t_img *img)
{
	while (pos)
	{
		if (pos->wall_x != -1 && pos->wall_y != -1)
			mlx_put_image_to_window(var->mlx, var->win, img->wall, pos->wall_x,
				pos->wall_y);
		pos = pos->next;
	}
}

void	print_bg(t_vars *var, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->win_x)
	{
		j = 0;
		while (j < var->win_y)
		{
			mlx_put_image_to_window(var->mlx, var->win, img->bg, i, j);
			j += img->bg_y;
		}
		i += img->bg_x;
	}
}

void	print_player(t_param *param, int x, int y)
{
	int			old_x;
	int			old_y;
	int			size;
	t_position	*pos;

	pos = param->pos;
	size = param->img->player_x;
	old_x = param->player->x + ((x * size) * -1);
	old_y = param->player->y + ((y * size) * -1);
	while (pos)
	{
		if (pos->exit_x == old_x && pos->exit_y == old_y)
		{
			mlx_put_image_to_window(param->var->mlx, param->var->win,
				param->img->exit, old_x, old_y);
			old_x = -1;
			break ;
		}
		pos = pos->next;
	}
	if (old_x != -1)
		mlx_put_image_to_window(param->var->mlx, param->var->win,
			param->img->bg, old_x, old_y);
	mlx_put_image_to_window(param->var->mlx, param->var->win,
		param->img->player, param->player->x, param->player->y);
}

void	print_map(char **map)
{
	t_position	*pos;
	t_player	player;
	t_vars		var;
	t_img		img;

	pos = NULL;
	var.mlx = mlx_init();
	if (set_img(&var, &img))
		invalid_free("Error : invalid xpm file\n", map, &var, &img);
	get_window_size(&var, img.wall_x, map);
	if (check_map_size(&var))
		invalid_free("Error : invalid map size\n", map, &var, &img);
	var.win = mlx_new_window(var.mlx, var.win_x, var.win_y, "so_long");
	print_bg(&var, &img);
	set_posistion(&pos, img.wall_x, &player, map);
	free_map(map);
	print_wall(&var, pos, &img);
	print_collectible(&var, &img, pos);
	print_exit(&var, &img, pos);
	move_play(&var, &img, pos, &player);
	mlx_loop(var.mlx);
}

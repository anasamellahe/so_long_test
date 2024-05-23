#include "so_long.h"

int	check_exit(t_param *param)
{
	t_position	*tmp_pos;

	tmp_pos = param->pos;
	while (tmp_pos)
	{
		if (tmp_pos->col_x != -1 && tmp_pos->col_y != -1)
			return (0);
		tmp_pos = tmp_pos->next;
	}
	return (1);
}

int	check_move(t_param *param, int x, int y)
{
	int			size;
	t_position	*tmp_pos;

	tmp_pos = param->pos;
	size = param->img->player_x;
	while (tmp_pos)
	{
		if (tmp_pos->wall_x == (param->player->x + (x * size))
			&& tmp_pos->wall_y == (param->player->y + (y * size)))
			return (0);
		if ((param->player->x + (x * size)) == tmp_pos->col_x
			&& (param->player->y + (y * size)) == tmp_pos->col_y)
		{
			tmp_pos->col_x = -1;
			tmp_pos->col_y = -1;
			return (1);
		}
		if (param->player->x + (x * size) == tmp_pos->exit_x && param->player->y
			+ (y * size) == tmp_pos->exit_y)
			return (-1);
		tmp_pos = tmp_pos->next;
	}
	return (1);
}

int	check_position(t_param *param, int x, int y, int *moves)
{
	char	*smoves;

	if (check_move(param, x, y) == 1)
	{
		param->player->x += x * param->img->player_x;
		param->player->y += y * param->img->player_x;
		print_player(param, x, y);
		return (1);
	}
	if (check_move(param, x, y) == -1 && check_exit(param))
	{
		smoves = ft_itoa(*moves);
		mlx_string_put(param->var->mlx, param->var->win, 10, 10, 0, smoves);
		ft_free(smoves);
		destroy(param);
	}
	else if (check_move(param, x, y) == -1)
	{
		param->player->x += x * param->img->player_x;
		param->player->y += y * param->img->player_x;
		print_player(param, x, y);
		return (1);
	}
	return (0);
}

int	check_key(int key, t_param *p)
{
	static int	moves;
	int			i;
	char		*smoves;

	if (key == ESC)
		i = (i * 0) + destroy(p);
	if (key == UP_W || key == UP)
		i = (i * 0) + check_position(p, 0, -1, &moves);
	if (key == DOWN_S || key == DOWN)
		i = (i * 0) + check_position(p, 0, 1, &moves);
	if (key == LEFT_A || key == LEFT)
		i = (i * 0) + check_position(p, -1, 0, &moves);
	if (key == RIGHT_D || key == RIGHT)
		i = (i * 0) + check_position(p, 1, 0, &moves);
	moves += i;
	if (i != 0)
	{
		mlx_put_image_to_window(p->var->mlx, p->var->win, p->img->wall, 0, 0);
		mlx_put_image_to_window(p->var->mlx, p->var->win, p->img->wall, 32, 0);
		mlx_put_image_to_window(p->var->mlx, p->var->win, p->img->wall, 64, 0);
		smoves = ft_itoa(moves);
		mlx_string_put(p->var->mlx, p->var->win, 10, 10, 0, smoves);
		ft_free(smoves);
	}
	return (0);
}

void	move_play(t_vars *var, t_img *img, t_position *pos, t_player *player)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	param->img = img;
	param->player = player;
	param->pos = pos;
	param->var = var;
	print_player(param, 0, 0);
	mlx_hook(var->win, 2, 1L >> 0, check_key, param);
	mlx_hook(var->win, 17, 0, destroy, param);
}

#include "so_long.h"

void	print_exit(t_vars *var, t_img *img, t_position *pos)
{
	while (pos)
	{
		if (pos->exit_x != -1 && pos->exit_y != -1)
		{
			mlx_put_image_to_window(var->mlx, var->win, img->exit,
				pos->exit_x, pos->exit_y);
			break ;
		}
		pos = pos->next;
	}
}

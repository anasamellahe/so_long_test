#include "so_long.h"

void	ft_lstadd_back_pos(t_position **lst, t_position *new)
{
	t_position	*head;

	if (!*lst)
		*lst = new;
	else
	{
		head = *lst;
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = head;
	}
}

t_position	*ft_new_pos(int x, int y, int flag)
{
	t_position	*new;

	new = malloc(sizeof(t_position));
	if (!new)
		return (NULL);
	new->wall_x = (flag == 1) * x + (flag != 1) * -1;
	new->wall_y = (flag == 1) * y + (flag != 1) * -1;
	new->col_x = (flag == 2) * x + (flag != 2) * -1;
	new->col_y = (flag == 2) * y + (flag != 2) * -1;
	new->exit_x = (flag == 3) * x + (flag != 3) * -1;
	new->exit_y = (flag == 3) * y + (flag != 3) * -1;
	new->next = NULL;
	return (new);
}
void free_list(t_position *list)
{
	t_position *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	
}

int	destroy(t_param *param)
{

	mlx_destroy_image(param->var->mlx,param->img->bg_image);
	mlx_destroy_image(param->var->mlx,param->img->col_img);
	mlx_destroy_image(param->var->mlx,param->img->exit_img);
	mlx_destroy_image(param->var->mlx,param->img->player_image);
	mlx_destroy_image(param->var->mlx,param->img->wall_img);
	mlx_destroy_display(param->var->mlx);
	mlx_destroy_window(param->var->mlx, param->var->win);
	free(param->var->mlx);
	free_list(param->pos);
	free(param);
	exit(0);
}

void	ft_free(void *var)
{
	if (var)
		free(var);
	var = NULL;
}

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
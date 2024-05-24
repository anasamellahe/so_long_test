/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:31:30 by anamella          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:47 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_exit(t_vars *var, t_img *img, t_position *pos)
{
	while (pos)
	{
		if (pos->exit_x != -1 && pos->exit_y != -1)
		{
			mlx_put_image_to_window(var->mlx, var->win, img->exit, pos->exit_x,
				pos->exit_y);
			break ;
		}
		pos = pos->next;
	}
}

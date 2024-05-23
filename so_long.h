#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
#include <string.h>

# define RIGHT	65363
# define DOWN	65364
# define LEFT	65361
# define UP		65362
# define RIGHT_D	100
# define DOWN_S 	115
# define LEFT_A 	97
# define UP_W	119
# define ESC		65307

// # define RIGHT	124
// # define DOWN	125
// # define LEFT	123
// # define UP		126
// # define RIGHT_D	2
// # define DOWN_S 	1
// # define LEFT_A 	0
// # define UP_W	13
// # define ESC		53



typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
}	t_vars;

typedef struct s_img
{
	void	*player_image;
	void	*exit_img;
	void	*bg_image;
	void	*wall_img;
	void	*col_img;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		bg_x;
	int		bg_y;
	int		wall_x;
	int		wall_y;
	int		col_x;
	int		col_y;
}	t_img;

typedef struct s_position
{
	int					wall_x;
	int					wall_y;
	int					col_x;
	int					col_y;
	int					exit_x;
	int					exit_y;
	struct s_position	*next;
}	t_position;

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_param
{
	t_vars		*var;
	t_img		*img;
	t_position	*pos;
	t_player	*player;
}	t_param;

void		set_posistion(t_position **pos, int size,
				t_player *player, char **map);
void		get_window_size(t_vars *var, int size, char **map);
int			set_img(t_vars *var, t_img *img);
int			map_generator(int fd);
int			free_map(char **map);
int			map_len(char **map);

void		print_collectible(t_vars *var, t_img *img, t_position *pos);
void		print_wall(t_vars *var, t_position *pos, t_img *img);
void		print_exit(t_vars *var, t_img *img, t_position *pos);
void		print_player(t_param *param, int x, int y);
void		print_bg(t_vars *var, t_img *img);
void		print_map(char **map);
int			destroy(t_param *param);

void		move_play(t_vars *var, t_img *img, t_position *pos,
				t_player *player);
int			check_position(t_param *param, int x, int y, int *moves);
int			check_move(t_param *param, int x, int y);
int			check_key(int key, t_param *param);
int			check_exit(t_param *param);

void		flood_fill(char **map, int x, int y, int h);
int			check_if_map_closed(char **map);
int			check_validation(char **map);
int			check_map_line(char *str);
int			check_map(char **map);

void		ft_lstadd_back_pos(t_position **lst, t_position *new);
void		ft_free(void *var);
t_position	*ft_new_pos(int x, int y, int flag);

#endif
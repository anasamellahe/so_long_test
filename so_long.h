#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RIGHT 65363
# define DOWN 65364
# define LEFT 65361
# define UP 65362
# define RIGHT_D 100
# define DOWN_S 115
# define LEFT_A 97
# define UP_W 119
# define ESC 65307

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
	void				*mlx;
	void				*win;
	int					win_x;
	int					win_y;
}						t_vars;

typedef struct s_img
{
	void				*player;
	void				*exit;
	void				*bg;
	void				*wall;
	void				*col;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
	int					bg_x;
	int					bg_y;
	int					wall_x;
	int					wall_y;
	int					col_x;
	int					col_y;
}						t_img;

typedef struct s_position
{
	int					wall_x;
	int					wall_y;
	int					col_x;
	int					col_y;
	int					exit_x;
	int					exit_y;
	struct s_position	*next;
}						t_position;

typedef struct s_player
{
	int					x;
	int					y;
}						t_player;

typedef struct s_param
{
	t_vars				*var;
	t_img				*img;
	t_position			*pos;
	t_player			*player;
}						t_param;

void					move_play(t_vars *var, t_img *img, t_position *pos,
							t_player *player);
void					invalid_free(char *error, char **map, t_vars *var,
							t_img *img);
void					print_collectible(t_vars *var, t_img *img,
							t_position *pos);
void					set_posistion(t_position **pos, int size,
							t_player *player, char **map);

void					ft_lstadd_back_pos(t_position **lst, t_position *new);
void					print_wall(t_vars *var, t_position *pos, t_img *img);
void					print_exit(t_vars *var, t_img *img, t_position *pos);
void					get_window_size(t_vars *var, int size, char **map);
void					flood_fill(char **map, int x, int y, int h);
void					print_player(t_param *param, int x, int y);
void					print_bg(t_vars *var, t_img *img);
void					free_list(t_position *list);
void					print_map(char **map);
void					ft_free(void *var);

int						check_position(t_param *param, int x, int y,
							int *moves);
int						check_move(t_param *param, int x, int y);
int						check_key(int key, t_param *param);
int						set_img(t_vars *var, t_img *img);
int						set_img(t_vars *var, t_img *img);
int						check_if_map_closed(char **map);
int						check_validation(char **map);
int						check_map_size(t_vars *var);
int						check_exit(t_param *param);
int						check_map_line(char *str);
int						destroy(t_param *param);
int						map_generator(int fd);
int						map_generator(int fd);
int						check_map(char **map);
int						free_map(char **map);
int						free_map(char **map);
int						map_len(char **map);
int						map_len(char **map);

t_position				*ft_new_pos(int x, int y, int flag);

#endif
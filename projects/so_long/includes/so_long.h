/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:19:13 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/21 00:08:43 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

//Enumeration (enum) - user defined data type in C. It is mainly used to assign
//names to integral constants.
enum {
	X_CLOSE = 17,
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
};

typedef struct s_image_assets
{
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		img_width;
	int		img_height;
}t_images;

typedef struct s_coordinates_position
{
	int		row;
	int		col;
}t_coordinates;

typedef struct s_file_read
{
	char	*line;
	int		fd;
}t_file_read;

typedef struct s_data
{
	int		rows;
	int		columns;
	char	**map;
	int		fd;
	int		i;
}t_data;

typedef struct s_mlx_build {
	int				height;
	int				width;
	int				row;
	int				col;
	void			*mlx;
	void			*window;
	char			**map;
	t_images		images;
	t_coordinates	coordinates;
}t_mlx_build;

void		draw_map(t_mlx_build *mlx_b, int row, int col, char new_coordinate);
void		set_coordinates(t_mlx_build *mlx_b, int *row, int *col);
void		draw_map_with_movecount(t_mlx_build *mlx_b);
void		window_dimensions(t_mlx_build *mlx_b);
void		game_over(t_mlx_build *mlx_b);

int			ft_count_positions(int n);
void		ft_add_to_list(char *lst_chars, unsigned int number, int count);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
void		redraw_on_start(t_mlx_build *mlx_b, char type);

void		free_map(char **map);
void		ft_putstr_fd(char *s, int fd);;
char		*ft_strrchr(const char *s, int c);
void		number_of_columns_rows(int *rows, int *columns, char *map_path);
char		**string_to_matrix(char *map_path);

int			check_input(int argc, char *argv[], t_mlx_build *mlx_b);
int			file_exists(char *map_path);
int			is_ber_file(char *map);
int			map_is_rectangular(t_mlx_build *mlx_b);

int			keyboard_iput(int keycode, t_mlx_build *mlx_b);
int			destroy_session(t_mlx_build *mlx_b);
int			x_close(void);
t_coordinates	player_position(t_mlx_build mlx_b);

void		draw_map_logic(t_mlx_build *mlx_b);
t_images	get_images(t_mlx_build *mlx_b);
char		*map_is_not_valid2(t_mlx_build *mlx_b);

char		*map_is_not_valid(t_mlx_build *mlx_b, char *map_path);
int			has_item(char **map, char c);
int			only_one_player(char **map);
int			only_allowed_chars(char **map);
int			has_valid_borders(char **map, char *map_path);

#endif
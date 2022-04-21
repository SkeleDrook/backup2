/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:17:42 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/20 20:32:09 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_mlx_build *mlx_b, int row, int col, char new_coordinate)
{
	static char	last_coordinate;
	int			was_exit;

	if (last_coordinate == 'E')
		was_exit = 1;
	set_coordinates(mlx_b, &row, &col);
	new_coordinate = mlx_b->map[row][col];
	if (new_coordinate == '1')
		return ;
	if (!has_item(mlx_b->map, 'C') && new_coordinate == 'E')
	{
		mlx_b->map[row][col] = 'P';
		game_over(mlx_b);
		return ;
	}
	last_coordinate = mlx_b->map[row][col];
	mlx_b->map[row][col] = 'P';
	if (was_exit == 1)
		mlx_b->map[mlx_b->coordinates.row][mlx_b->coordinates.col] = 'E';
	else
	{
		mlx_b->map[mlx_b->coordinates.row][mlx_b->coordinates.col] = '0';
		was_exit = 0;
	}
	draw_map_with_movecount(mlx_b);
}

void	set_coordinates(t_mlx_build *mlx_b, int *row, int *col)
{
	mlx_b->coordinates = player_position(*mlx_b);
	*row += mlx_b->coordinates.row;
	*col += mlx_b->coordinates.col;
}

void	draw_map_with_movecount(t_mlx_build *mlx_b)
{
	static int	moves = 0;

	moves++;
	draw_map_logic(mlx_b);
	mlx_string_put(mlx_b->mlx, mlx_b->window, 20, 20,
		0x44FF0022, ft_itoa(moves));
}

void	window_dimensions(t_mlx_build *mlx_b)
{
	mlx_b->height *= mlx_b->images.img_height;
	mlx_b->width *= mlx_b->images.img_width;
	mlx_b->window = mlx_new_window(mlx_b->mlx, mlx_b->width,
			mlx_b->height, "Realm of the Mad God");
}

void	game_over(t_mlx_build *mlx_b)
{	
	mlx_b->map[mlx_b->coordinates.row][mlx_b->coordinates.col] = '0';
	draw_map_logic(mlx_b);
	mlx_string_put(mlx_b->mlx, mlx_b->window, 20, 20, 0x44FF0022, "Game over");
	mlx_string_put(mlx_b->mlx, mlx_b->window, 20, 40,
		0x44FF0022, "Press any key to exit");
	mlx_key_hook(mlx_b->window, destroy_session, mlx_b);
}

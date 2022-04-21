/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:48:39 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/19 19:01:27 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	keyboard_iput(int keycode, t_mlx_build *mlx_b)
{
	if (keycode == ESC)
		destroy_session(mlx_b);
	else if (keycode == W || keycode == UP)
		draw_map(mlx_b, -1, 0, 'x');
	else if (keycode == A || keycode == LEFT)
		draw_map(mlx_b, 0, -1, 'x');
	else if (keycode == S || keycode == DOWN)
		draw_map(mlx_b, 1, 0, 'x');
	else if (keycode == D || keycode == RIGHT)
		draw_map(mlx_b, 0, 1, 'x');
	return (0);
}

int	destroy_session(t_mlx_build *mlx_b)
{
	mlx_destroy_window(mlx_b->mlx, mlx_b->window);
	free_map(mlx_b->map);
	exit(EXIT_SUCCESS);
}

int	x_close(void)
{
	exit(EXIT_SUCCESS);
}

t_coordinates	player_position(t_mlx_build mlx_b)
{
	t_coordinates	p_pos;

	p_pos.row = 0;
	while (mlx_b.map[p_pos.row])
	{
		p_pos.col = 0;
		while (mlx_b.map[p_pos.row][p_pos.col])
		{
			if (mlx_b.map[p_pos.row][p_pos.col] == 'P')
				return (p_pos);
			p_pos.col++;
		}
		p_pos.row++;
	}
	return (p_pos);
}

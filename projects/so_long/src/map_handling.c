/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:34:36 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/21 00:09:58 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	draw_map_logic(t_mlx_build *mlx_b)
{
	void	*img;	

	mlx_b->row = 0;
	while (mlx_b->map[mlx_b->row])
	{
		mlx_b->col = 0;
		while (mlx_b->map[mlx_b->row][mlx_b->col])
		{
			if (mlx_b->map[mlx_b->row][mlx_b->col] == '0')
				img = mlx_b->images.floor;
			else if (mlx_b->map[mlx_b->row][mlx_b->col] == '1')
				img = mlx_b->images.wall;
			else if (mlx_b->map[mlx_b->row][mlx_b->col] == 'C')
				img = mlx_b->images.collectible;
			else if (mlx_b->map[mlx_b->row][mlx_b->col] == 'E')
				img = mlx_b->images.exit;
			else if (mlx_b->map[mlx_b->row][mlx_b->col] == 'P')
				img = mlx_b->images.player;
			mlx_put_image_to_window(mlx_b->mlx, mlx_b->window, img,
				mlx_b->images.img_width * mlx_b->col,
				mlx_b->images.img_height * mlx_b->row);
			mlx_b->col++;
		}
		mlx_b->row++;
	}
}

t_images	get_images(t_mlx_build *mlx_b)
{
	t_images	images;

	images.floor = mlx_xpm_file_to_image(mlx_b->mlx,
			"/Users/ohulik/projects/projects/so_long/images/floor.xpm",
			&images.img_width, &images.img_height);
	images.wall = mlx_xpm_file_to_image(mlx_b->mlx,
			"/Users/ohulik/projects/projects/so_long/images/wall.xpm",
			&images.img_width, &images.img_height);
	images.collectible = mlx_xpm_file_to_image(mlx_b->mlx,
			"/Users/ohulik/projects/projects/so_long/images/collectible.xpm",
			&images.img_width, &images.img_height);
	images.exit = mlx_xpm_file_to_image(mlx_b->mlx,
			"/Users/ohulik/projects/projects/so_long/images/exit.xpm",
			&images.img_width, &images.img_height);
	images.player = mlx_xpm_file_to_image(mlx_b->mlx,
			"/Users/ohulik/projects/projects/so_long/images/player.xpm",
			&images.img_width, &images.img_height);
	return (images);
}

char	*map_is_not_valid2(t_mlx_build *mlx_b)
{
	if (has_item(mlx_b->map, 'C'))
	{
		return ("Error\nThere are no collectibles on the map.\n");
		free_map(mlx_b->map);
	}
	if (has_item(mlx_b->map, 'E'))
	{
		return ("Error\nThere is no exit on the map.\n");
		free_map(mlx_b->map);
	}
	if (only_one_player(mlx_b->map))
	{
		return ("Error\nThere is more or less than 1 player on the map.\n");
		free_map(mlx_b->map);
	}
	return (0);
}

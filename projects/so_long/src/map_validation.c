/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:50:33 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/21 01:02:23 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*map_is_not_valid(t_mlx_build *mlx_b, char *map_path)
{
	if (!map_is_rectangular(mlx_b))
	{
		return ("Error\nMap is not rectangular.\n");
		free_map(mlx_b->map);
	}
	if (!only_allowed_chars(mlx_b->map))
	{
		return ("Error\nThe map contains forbidden characters.\n");
		free_map(mlx_b->map);
	}
	if (has_valid_borders(mlx_b->map, map_path))
	{
		return ("Error\nThe map is not enclosed by borders.\n");
		free_map(mlx_b->map);
	}
	map_is_not_valid2(mlx_b);
	return (0);
}

int	has_item(char **map, char c)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == c)
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int	only_one_player(char **map)
{
	int		row;
	int		col;
	int		player_amount;

	player_amount = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				player_amount++;
				if (player_amount > 1)
					return (0);
			}
			col++;
		}
		row++;
	}
	if (player_amount == 1)
		return (1);
	return (0);
}

int	only_allowed_chars(char **map)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!ft_strchr("10EPC", map[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	has_valid_borders(char **map, char *map_path)
{
	int	i;
	int	j;
	int	row;
	int	col;

	number_of_columns_rows(&row, &col, map_path);
	row--;
	col--;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && (i == 0 || i == row || j == 0 || j == col))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
	
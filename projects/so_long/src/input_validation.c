/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:25:08 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/21 00:11:52 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_input(int argc, char *argv[], t_mlx_build *mlx_b)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong ammount of arguments.\n", 1);
		ft_putstr_fd("Program requires 2 arguments: ", 1);
		ft_putstr_fd("./so_long and file_name.ber \n", 1);
		return (0);
	}
	if (!file_exists(argv[1]))
	{
		ft_putstr_fd("Error\nThe file does not exist.\n", 1);
		return (0);
	}
	if (is_ber_file(argv[1]) != 1)
	{	
		ft_putstr_fd("Error\nThe programme only accepts .ber files.\n", 1);
		return (0);
	}
	if (map_is_not_valid(mlx_b, argv[1]) != 0)
	{
		ft_putstr_fd(map_is_not_valid(mlx_b, argv[1]), 1);
		return (0);
	}
	return (1);
}

int	file_exists(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	return (1);
}

int	is_ber_file(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 5 || map[len - 1] != 'r' || map[len - 2] != 'e' \
	|| map[len - 3] != 'b' || map[len - 4] != '.')
		return (0);
	return (1);
}

int	map_is_rectangular(t_mlx_build *mlx_b)
{
	size_t	i;
	size_t	size;
	size_t	boop;

	i = 0;
	size = 0;
	boop = 0;
	while (mlx_b->map[i + 1])
	{
		boop = ft_strlen(mlx_b->map[i]);
		if (size != ft_strlen(mlx_b->map[i++]))
			return (0);
	}
	if (size == i)
		return (0);
	return (1);
}

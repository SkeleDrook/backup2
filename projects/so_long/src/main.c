/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:30:33 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/21 00:56:20 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char *argv[])
{
	t_mlx_build	mlx_b;

	if (check_input(argc, argv, &mlx_b) == 0)
		return (1);
	mlx_b.mlx = mlx_init();
	number_of_columns_rows(&(mlx_b.height), &(mlx_b.width), argv[1]);
	mlx_b.images = get_images(&mlx_b);
	window_dimensions(&mlx_b);
	mlx_b.map = string_to_matrix(argv[1]);
	draw_map_logic(&mlx_b);
	mlx_key_hook(mlx_b.window, keyboard_iput, &mlx_b);
	mlx_hook(mlx_b.window, X_CLOSE, 0, x_close, 0);
	mlx_loop(mlx_b.mlx);
	return (0);
}

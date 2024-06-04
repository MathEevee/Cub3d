/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:20:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:37:56 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx.h"

t_mlx	wmlx_init(void)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, WIN_N);
	mlx.img.img = mlx_new_image(mlx.ptr, WIN_X, WIN_Y);
	mlx.img.addr = mlx_get_data_addr(
			mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	return (mlx);
}

int	wmlx_destroy(t_joe_mama *var)
{
	wmlx_free_exit(var, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	wmlx_free_exit(t_joe_mama *var, int code)
{
	mlx_destroy_image(var->mlx.ptr, var->mlx.img.img);
	mlx_destroy_window(var->mlx.ptr, var->mlx.win);
	mlx_destroy_display(var->mlx.ptr);
	free(var->mlx.ptr);
	exit(code);
}

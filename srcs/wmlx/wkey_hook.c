/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkey_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:35:16 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "cub3d.h"
#include "mlx.h"

void	wkey_init_hook(t_joe_mama *var)
{
	mlx_hook(var->mlx.win, 17, 1L << 17, wmlx_destroy, var);
	mlx_key_hook(var->mlx.win, wkey_hook, var);
	mlx_loop_hook(var->mlx.ptr, wmlx_loop, var);
}

int	wmlx_loop(t_joe_mama *var)
{
	wmlx_update_win(var->mlx);
	return (0);
}

int	wkey_hook(int keycode, t_joe_mama *var)
{
	t_coord	b;
	t_coord	e;

	b.x = 100;
	b.y = 100;
	e.x = 300;
	e.y = 300;
	wmlx_put_rect(&var->mlx.img, b, e, 0x00ffffff);
	if (keycode == 65307)
		wmlx_free_exit(var, EXIT_SUCCESS);
	return (0);
}

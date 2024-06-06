/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkey_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/05 16:20:36 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "cub3d.h"
#include "mlx.h"

void	wkey_init_hook(t_joe_mama *var)
{
	mlx_hook(var->mlx.win, 17, 1L << 17, wmlx_destroy, var);
	mlx_hook(var->mlx.win, 2, 1L << 0, wkey_hook, var);
	mlx_loop_hook(var->mlx.ptr, wmlx_loop, var);
}

int	wkey_hook(int keycode, t_joe_mama *var)
{
	if (keycode == 65307)
		wmlx_free_exit(var, EXIT_SUCCESS);
	else if (keycode < 1000)
		display_map(&var->mlx.i_win, var->info);
	else
		wati_fprintf(2, "key: %i\n", keycode);
	return (0);
}

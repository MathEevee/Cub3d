/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkey_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 13:13:20 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx.h"

void	wkey_init_hook(t_joe_mama *var)
{
	mlx_hook(var->mlx.win, 17, 1L << 17, wmlx_destroy, var);
	mlx_key_hook(var->mlx.win, wkey_hook, var);
}

int	wkey_hook(int keycode, t_joe_mama *var)
{
	if (keycode == 65307)
		wmlx_free_exit(var, EXIT_SUCCESS);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:38:51 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "cub3d.h"
#include "mlx.h"

t_info	init_info(void)
{
	
}

int	main(void)
{
	t_joe_mama	var;

	var.mlx = wmlx_init();
	wkey_init_hook(&var);
	mlx_loop(var.mlx.ptr);
	return (0);
}

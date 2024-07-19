/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:39:20 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/19 10:10:49 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmlx_loop_draw(t_joe_mama *var)
{
	wmlx_clear_img(var->mlx.pimg.win);
	wmlx_clear_img(var->mlx.pimg.map);
	display(var->mlx.pimg, var->info);
}

void	wmlx_update_win(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.win.img, 0, 0);
}

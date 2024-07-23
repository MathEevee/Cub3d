/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:34 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 15:20:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_wptr ptr, t_info *info)
{
	if (info->img_no.img)
		mlx_destroy_image(ptr, info->img_no.img);
	if (info->img_so.img)
		mlx_destroy_image(ptr, info->img_so.img);
	if (info->img_we.img)
		mlx_destroy_image(ptr, info->img_we.img);
	if (info->img_ea.img)
		mlx_destroy_image(ptr, info->img_ea.img);
}

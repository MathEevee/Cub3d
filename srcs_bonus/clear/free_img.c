/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:34 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/22 11:39:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs_bonus/cub3d.h"

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

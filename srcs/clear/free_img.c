/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:34 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/08 13:53:07 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_wptr ptr, t_info *info)
{
	mlx_destroy_image(ptr, info->img_no.img);
	mlx_destroy_image(ptr, info->img_so.img);
	mlx_destroy_image(ptr, info->img_we.img);
	mlx_destroy_image(ptr, info->img_ea.img);
}

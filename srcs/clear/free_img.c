/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:34 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/05 17:37:09 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_img(t_fimg *img)
{
	if (img != NULL)
	{
		if (img->img != NULL)
			// mlx_destroy_image(img); // todo get mlx
		free(img);
	}
}

void	free_mlx(t_info *info)
{
	free_img(&info->img_no);
	free_img(&info->img_so);
	free_img(&info->img_we);
	free_img(&info->img_ea);
}

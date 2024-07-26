/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 15:43:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmlx_clear_img(t_data *data)
{
	wati_bzero(data->addr, data->max.y * data->line_length + data->max.x
		* (data->bits_per_pixel / 8));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:24:06 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/26 10:49:15 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_var(t_joe_mama *var)
{
	free_mlx(var->mlx.ptr, &var->info);
	wmlx_destroy(var->mlx);
	wati_free_tab(var->info.map.map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:11 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/19 11:35:47 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

void	begin_cub3d(int fd, t_joe_mama *var)
{
	char		**file;

	init_info(&var->info);
	file = format_fd_no_nl(fd);
	if (file == NULL)
	{
		free_var(var);
		wati_fprintf(2, "This file is empty\nError\n");
		return ;
	}
	if (set_info(file, var) == -1)
	{
		free_var(var);
		wati_free_tab(file);
		return ;
	}
	wati_free_tab(file);
	if (map_checker(&var->info) == true)
	{
		wkey_init_hook(var);
		mlx_loop(var->mlx.ptr);
	}
	free_var(var);
}

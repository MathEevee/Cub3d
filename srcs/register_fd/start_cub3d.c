/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:11 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/08 15:26:08 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	begin_cub3d(int fd)
{
	char		**file;
	t_joe_mama	var;

	init_info(&var.info);
	var.mlx = wmlx_init();
	file = format_fd_no_nl(fd);
	if (file == NULL)
	{
		wati_fprintf(2, "This file is empty\nError\n");
		return ();
	}
	if (set_info(file, &var) == -1)
	{
		//addfree
		return ();
	}
	wati_free_tab(file);
	if (map_checker(&var.info) == true)
	{
		wati_printf("good\n");
		// start_game();
	}
	// freeall dans tous les cas
}

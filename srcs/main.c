/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:28:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/08 16:57:36 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "cub3d.h"
#include "mlx.h"

int	check_ac(int ac)
{
	if (ac != 2)
	{
		if (ac < 2)
			wati_fprintf(2, "Too few argument\n");
		else
			wati_fprintf(2, "Too many arguments\n");
		return (-1);
	}
	return (0);
}

int	check_fd(char *str)
{
	int	len;
	int	fd;

	len = wati_strlen(str) - 4;
	if (wati_strncmp(str + len, ".cub", 4) != 0)
	{
		wati_fprintf(2, "Wrong format\n");
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		wati_fprintf(2, "Don't have permission or this file does not exist\n");
	return (fd);
}

int	main(int argc, char **argv)
{
	t_joe_mama	var;
	t_fd		fd;

	if (check_ac(argc) == -1)
		return (0);
	fd = check_fd(argv[1]);
	if (fd <= 2)
		return (1);
	joe_mama_init(&var);
	begin_cub3d(fd);
	if (!var.info.map)
	{
		wmlx_destroy(var.mlx);
		return (1);
	}
	var.mlx = wmlx_init();
	wmlx_loop_draw(&var);
	wmlx_update_win(var.mlx);
	wkey_init_hook(&var);
	mlx_loop(var.mlx.ptr);
	wmlx_destroy(var.mlx);
	wati_free_tab(var.info.map);
	return (0);
}

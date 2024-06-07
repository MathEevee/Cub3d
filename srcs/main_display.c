/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/07 14:54:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "cub3d.h"
#include "mlx.h"

t_info	test_info(char *name)
{
	t_info	info;
	t_fd	file;

	file = open(name, O_RDONLY);
	if (file > 2)
		info.map = get_file(file);
	else
		info.map = NULL;
	close(file);
	info.base.angle = 0;
	info.base.pos.x = 2;
	info.base.pos.y = 2;
	info.color_c = 0x00c0c0ff;
	info.color_f = 0x006060ff;
	return (info);
}

int	main(int argc, char **argv)
{
	t_joe_mama	var;

	if (argc > 1)
		var.info = test_info(argv[1]);
	else
		var.info = test_info("test.cub");
	if (!var.info.map)
		return (1);
	joe_mama_init(&var);
	var.mlx = wmlx_init();
	wmlx_loop_draw(&var);
	wmlx_update_win(var.mlx);
	wkey_init_hook(&var);
	mlx_loop(var.mlx.ptr);
	wmlx_destroy(var.mlx);
	wati_free_tab(var.info.map);
	return (0);
}

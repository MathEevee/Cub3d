/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 16:55:46 by bedarenn         ###   ########.fr       */
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
	info.base.pos.x = 2 * IMG_SIZE;
	info.base.pos.y = 2 * IMG_SIZE;
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
	var.mlx = wmlx_init();
	wkey_init_hook(&var);
	mlx_loop(var.mlx.ptr);
	return (0);
}

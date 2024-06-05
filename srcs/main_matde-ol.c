/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_matde-ol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:28:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/05 17:26:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include <fcntl.h>

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

int	main(int ac, char **av)
{
	t_fd	fd;

	fd = 0;
	if (check_ac(ac) == -1)
		return (0);
	fd = check_fd(av[1]);
	if (fd > 0)
		begin_cub3d(fd);
	return (0);
	// t_info	info;
	// (void) ac;
	// init_info(&info);
	// wati_printf("%d\n", check_path(av[1], &info));
	// wati_printf("%u\n", info.color_c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_matde-ol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:28:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:19:28 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_info	info;
	(void) ac;
	init_info(&info);
	wati_printf("%d\n", check_path(av[1], &info));
	wati_printf("%u\n", info.color_c);
}

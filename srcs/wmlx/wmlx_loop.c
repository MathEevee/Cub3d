/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/05 16:11:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_ltime	diff_timeval(t_tv t1, t_tv t2)
{
	t_ltime	t;

	t = (t1.tv_sec - t2.tv_sec) * S_US + (t1.tv_usec - t2.tv_usec);
	return (t);
}

bool	fps_manager(int fps)
{
	static t_tv	last;
	t_tv		actu;

	gettimeofday(&actu, NULL);
	if (diff_timeval(actu, last) < S_US / fps)
		return (false);
	return (true);
}

int	wmlx_loop(t_joe_mama *var)
{
	if (fps_manager(FPS))
		wmlx_update_win(var->mlx);
	return (0);
}

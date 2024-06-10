/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/10 14:49:25 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "cub3d.h"

void	move_toward(t_player *player, float mv, char **map)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = player->pos.x + (mv * cos(player->angle));
	tmp_y = player->pos.y + (mv * sin(player->angle));
	if (map[(int)player->pos.y][(int)tmp_x] != '1')
		player->pos.x = tmp_x;
	if (map[(int)tmp_y][(int)player->pos.x] != '1')
		player->pos.y = tmp_y;
}

bool	wmlx_key_update(t_joe_mama *var)
{
	static t_tv	last;
	t_tv		actu;
	t_ltime		diff;
	float		mv;
	double		rotate;

	gettimeofday(&actu, NULL);
	diff = diff_timeval(actu, last);
	if (diff < FMS)
		return (false);
	last = actu;
	mv = MV_SPEED / FPS * (diff / FMS);
	rotate = (FOV_INCR * (PI / 180.0)) / FPS * (diff / FMS);
	if (var->press.key_a)
		var->info.base.angle -= rotate;
	if (var->press.key_d)
		var->info.base.angle += rotate;
	if (var->press.key_w)
		move_toward(&var->info.base, -mv, var->info.map);
	if (var->press.key_s)
		move_toward(&var->info.base, mv, var->info.map);
	return (true);
}

int	wmlx_loop(t_joe_mama *var)
{
	if (wmlx_key_update(var))
	{
		wmlx_loop_draw(var);
		wmlx_update_win(var->mlx);
	}
	return (0);
}

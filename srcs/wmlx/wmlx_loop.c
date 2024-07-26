/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 11:22:54 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	move_toward(t_player *player, t_float mv)
{
	player->pos.x += (mv * cosf(player->angle));
	player->pos.y += (mv * sinf(player->angle));
}

static void	move_side(t_player *player, t_float mv)
{
	player->pos.x += (mv * cosf(player->angle + M_PI_2));
	player->pos.y += (mv * sinf(player->angle + M_PI_2));
}

static t_ltime	wmlx_fps_manager(void)
{
	static t_tv	last;
	t_tv		actu;
	t_ltime		diff;

	gettimeofday(&actu, NULL);
	diff = diff_timeval(actu, last);
	if (diff < FMS)
		return (0);
	last = actu;
	return (diff);
}

static bool	wmlx_key_update(t_joe_mama *var)
{
	t_ltime		diff;
	t_float		mv;
	t_angle		rotate;

	diff = wmlx_fps_manager();
	if (!diff)
		return (true);
	mv = (MV_SPEED / FPS) * (diff / FMS);
	rotate = (FOV_INCR * (M_PI / 180.0)) / FPS * (diff / FMS);
	if (var->press.key_left)
		var->info.base.angle -= rotate;
	if (var->press.key_right)
		var->info.base.angle += rotate;
	if (var->press.key_w)
		move_toward(&var->info.base, -mv);
	if (var->press.key_s)
		move_toward(&var->info.base, mv);
	if (var->press.key_d)
		move_side(&var->info.base, -mv);
	if (var->press.key_a)
		move_side(&var->info.base, mv);
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

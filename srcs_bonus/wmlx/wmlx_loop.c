/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/23 15:20:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	move_toward(t_player *player, t_float mv, char **map)
{
	t_coord_f	tmp;

	tmp.x = player->pos.x + (mv * cosf(player->angle));
	tmp.y = player->pos.y + (mv * sinf(player->angle));
	if (map[(int)player->pos.y][(int)tmp.x] != '1')
		player->pos.x = tmp.x;
	else
	{
		if (tmp.x > player->pos.x)
			player->pos.x = (int)player->pos.x + (1 - HIT_BOX);
		else if (tmp.x < player->pos.x)
			player->pos.x = (int)player->pos.x + HIT_BOX;
	}
	if (map[(int)tmp.y][(int)player->pos.x] != '1')
		player->pos.y = tmp.y;
	else
	{
		if (tmp.y > player->pos.y)
			player->pos.y = (int)player->pos.y + (1 - HIT_BOX);
		else if (tmp.y < player->pos.y)
			player->pos.y = (int)player->pos.y + HIT_BOX;
	}
}

static void	move_side(t_player *player, t_float mv, char **map)
{
	t_coord_f	tmp;

	tmp.x = player->pos.x + (mv * cosf(player->angle + M_PI_2));
	tmp.y = player->pos.y + (mv * sinf(player->angle + M_PI_2));
	if (map[(int)player->pos.y][(int)tmp.x] != '1')
		player->pos.x = tmp.x;
	else
	{
		if (tmp.x > player->pos.x)
			player->pos.x = (int)player->pos.x + (1 - HIT_BOX);
		else if (tmp.x < player->pos.x)
			player->pos.x = (int)player->pos.x + HIT_BOX;
	}
	if (map[(int)tmp.y][(int)player->pos.x] != '1')
		player->pos.y = tmp.y;
	else
	{
		if (tmp.y > player->pos.y)
			player->pos.y = (int)player->pos.y + (1 - HIT_BOX);
		else if (tmp.y < player->pos.y)
			player->pos.y = (int)player->pos.y + HIT_BOX;
	}
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
		move_toward(&var->info.base, -mv, var->info.map);
	if (var->press.key_s)
		move_toward(&var->info.base, mv, var->info.map);
	if (var->press.key_d)
		move_side(&var->info.base, -mv, var->info.map);
	if (var->press.key_a)
		move_side(&var->info.base, mv, var->info.map);
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

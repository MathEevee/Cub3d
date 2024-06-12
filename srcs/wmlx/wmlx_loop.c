/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/12 15:33:06 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "cub3d.h"

#define TMP 0.9

char	get_place(char **tab, float x, float y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (tab[coord.y][coord.x]);
}

void	move_toward(t_player *player, float mv, char **map)
{
	float	tmp_x;
	float	tmp_y;
	int		tmp;

	tmp_x = player->pos.x + (mv * cos(player->angle));
	tmp_y = player->pos.y + (mv * sin(player->angle));
	if (get_place(map, tmp_x, player->pos.y) != '1')
		player->pos.x = tmp_x;
	else
	{
		tmp = tmp_x;
		printf("x: %i %f\n", tmp, tmp_x);
	}
	if (get_place(map, player->pos.x, tmp_y) != '1')
		player->pos.y = tmp_y;
	else
	{
		tmp = tmp_y;
		printf("x: %i %f\n", tmp, tmp_y);
	}
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

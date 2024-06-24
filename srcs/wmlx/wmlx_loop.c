/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/24 12:04:00 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

#define TMP 0.9

char	get_place(char **tab, t_float x, t_float y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (tab[coord.y][coord.x]);
}

void	move_toward(t_player *player, t_float mv, char **map)
{
	t_coord_f	tmp;

	tmp_x = player->pos.x + (mv * cos(player->angle));
	tmp_y = player->pos.y + (mv * sin(player->angle));
	// printf("player->pos.x = %f | player->pos.y = %f \n", player->pos.x, player->pos.y);
	// printf("tmp.x = %f | tmp.y = %f\n", tmp_x, tmp_y);
	if (get_place(map, tmp_x, player->pos.y) != '1')
		player->pos.x = tmp_x;
	// else if (get_place(map, tmp_x + 1, player->pos.y) == '1')
		// player->pos.x += (tmp_x - player->pos.x + ((mv * cos(player->angle))));
	if (get_place(map, player->pos.x, tmp_y) != '1')
		player->pos.y = tmp_y;
	// else if (get_place(map, tmp_x, player->pos.y + 1) == '1')
		// player->pos.y += (tmp_y - player->pos.y + ((mv * sin(player->angle))));
}

bool	wmlx_key_update(t_joe_mama *var)
{
	static t_tv	last;
	t_tv		actu;
	t_ltime		diff;
	t_float		mv;
	t_angle		rotate;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:26:53 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/06 10:24:50 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ltime	diff_timeval(t_tv t1, t_tv t2)
{
	t_ltime	t;

	t = (t1.tv_sec - t2.tv_sec) * S_US + (t1.tv_usec - t2.tv_usec);
	return (t);
}

bool	fps_manager(int fps)
{
	static t_tv	last;
	t_tv		actu;
	t_ltime		diff;

	gettimeofday(&actu, NULL);
	diff = diff_timeval(actu, last);
	if (diff < S_US / fps)
		return (false);
	last = actu;
	return (true);
}

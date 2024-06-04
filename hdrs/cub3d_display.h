/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:22:17 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DISPLAY_H
# define CUB3D_DISPLAY_H

# include "w_struct.h"

t_mlx	wmlx_init(void);

void	wkey_init_hook(t_joe_mama *var);
int		wkey_hook(int keycode, t_joe_mama *yo_mama);

void	wmlx_update_win(t_mlx mlx);
void	wmlx_put_pixel(t_data *data, t_coord coord, int color);
void	wmlx_put_rect(t_data *data, t_coord begin, t_coord end, int color);

int		wmlx_loop(t_joe_mama *var);

int		wmlx_destroy(t_joe_mama *var);
void	wmlx_free_exit(t_joe_mama *var, int code);

#endif // CUB3D_DISPLAY_H

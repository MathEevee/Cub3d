/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/05 16:17:43 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DISPLAY_H
# define CUB3D_DISPLAY_H

# include "w_struct.h"

t_coord	set_coord(int x, int y);

t_mlx	wmlx_init(void);

void	wkey_init_hook(t_joe_mama *var);
t_data	wmlx_init_img(t_wptr ptr, int x, int y);
int		wkey_hook(int keycode, t_joe_mama *yo_mama);
int		wmlx_destroy(t_joe_mama *var);
void	wmlx_free_exit(t_joe_mama *var, int code);

void	wmlx_update_win(t_mlx mlx);
void	wmlx_put_pixel(t_data *data, t_coord coord, t_color color);
void	wmlx_put_rect(t_data *data, t_coord begin, t_coord end, t_color color);
void	wmlx_put_square(t_data *data, t_coord coord, int size, t_color color);

void	display_map(t_data *data, t_info info);

bool	fps_manager(int fps);
int		wmlx_loop(t_joe_mama *var);

#endif // CUB3D_DISPLAY_H

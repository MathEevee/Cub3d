/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/08 14:42:39 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DISPLAY_H
# define CUB3D_DISPLAY_H

# include "w_struct.h"

t_coord		set_coord(int x, int y);

t_mlx		wmlx_init(void);
void		wmlx_destroy(t_mlx mlx);

void		joe_mama_init(t_joe_mama *var);
t_key_press	key_press_init(void);
t_data		wmlx_init_img(t_wptr ptr, int x, int y);

void		wkey_init_hook(t_joe_mama *var);
int			wkey_hook_press(int keycode, t_joe_mama *yo_mama);
int			wkey_hook_release(int keycode, t_joe_mama *var);

void		wmlx_put_pixel(t_data *data, t_coord coord, t_color color);
void		wmlx_put_rect(t_data *data, t_coord begin, t_coord end,
				t_color color);
void		wmlx_put_rect(t_data *data, t_coord begin, t_coord end,
				t_color color);
void		wmlx_put_square(t_data *data, t_coord coord, int size,
				t_color color);
void		wmlx_clear_img(t_data *data);

void		ray_casting(t_data *data, t_coord player, t_info info);

void		wmlx_loop_draw(t_joe_mama *var);
void		wmlx_update_win(t_mlx mlx);

void		display_map(t_data *data, t_coord coord, t_info info);
void		display_minimap(t_data *data, t_info info);

t_ltime		diff_timeval(t_tv t1, t_tv t2);
bool		fps_manager(int fps);

bool		wmlx_key_update(t_joe_mama *var);
int			wmlx_loop(t_joe_mama *var);

#endif // CUB3D_DISPLAY_H

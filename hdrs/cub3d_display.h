/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:04 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/16 10:52:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DISPLAY_H
# define CUB3D_DISPLAY_H

# include "w_struct.h"

t_coord		set_coord(int x, int y);
t_coord_f	set_coord_f(t_float x, t_float y);
t_coord		cast_to_coord(t_coord_f pos);
t_coord_f	cast_to_coord_f(t_coord pos);
t_coord_f	sum_coord_f(t_coord_f a, t_coord_f b);

t_mlx		wmlx_init(void);
void		wmlx_destroy(t_mlx mlx);

void		joe_mama_init(t_joe_mama *var);
void		change_mode(t_pdata *data);

t_key_press	key_press_init(void);
t_data		wmlx_init_img(t_wptr ptr, int x, int y);

void		wkey_init_hook(t_joe_mama *var);
int			wkey_hook_press(int keycode, t_joe_mama *yo_mama);
int			wkey_hook_release(int keycode, t_joe_mama *var);

void		wmlx_put_pixel(t_data *data, t_coord coord, t_color color);
t_color		wmlx_get_pixel(t_data *data, t_coord coord);
void		wmlx_put_rect(t_data *data, t_coord begin, t_coord end,
				t_color color);
void		wmlx_put_square(t_data *data, t_coord coord, int size,
				t_color color);
void		wmlx_put_line(t_data *data, t_coord start, t_coord end,
				t_color color);
void		wmlx_clear_img(t_data *data);

void		ray_casting(t_pdata pdata, t_info info, t_coord map);

t_ray		ray_loop(t_ray_cast x, t_ray_cast y, char **map);

t_ray_cast	ray_init_x(t_coord_f coord, t_trigo trig);
t_ray_cast	ray_init_y(t_coord_f coord, t_trigo trig);
void		ray_incr(t_ray_cast *ray, t_ray_cast *x, t_ray_cast *y);
t_float		toprev_int(t_float nb);
t_float		tonext_int(t_float nb);

void		ray_print(t_data *data, t_info info, t_ray ray, t_float wall);

void		wmlx_loop_draw(t_joe_mama *var);
void		wmlx_update_win(t_mlx mlx);

void		display(t_pdata pdata, t_info info);
void		display_minimap(t_data *data, t_coord pos_map, t_info info);
t_coord		get_pixel_minimap(t_coord pos_map, t_coord_f coord);

t_ltime		diff_timeval(t_tv t1, t_tv t2);
bool		fps_manager(int fps);

int			wmlx_loop(t_joe_mama *var);

bool		check_map(t_coord hit, char **map);
bool		check_map_convert(t_coord_f hit, char **map);

#endif // CUB3D_DISPLAY_H

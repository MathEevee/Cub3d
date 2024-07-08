/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct_display.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:26:05 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/06 19:55:30 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_DISPLAY_H
# define W_STRUCT_DISPLAY_H

# include "w_const.h"
# include "w_struct.h"
# include "w_typedef.h"

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_coord_f
{
	t_float	x;
	t_float	y;
}			t_coord_f;

typedef struct s_range
{
	int	min;
	int	max;
}			t_range;

typedef struct s_ray
{
	t_coord_f	pos;
	t_coord		hit;
	t_float		len;
	t_coord_f	v;
	t_coord_f	i;
	t_float		i_len;
	char		dir;
}			t_ray;

typedef struct s_trigo
{
	t_angle	cos;
	t_angle	sin;
}			t_trigo;

typedef struct s_cst
{
	t_float	a;
	t_float	o;
	t_float	h;
}			t_cst;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	max;
}			t_data;

typedef struct s_key_press
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
}			t_key_press;

typedef struct s_wdata
{
	t_data	win;
	t_data	map;
}			t_wdata;

typedef struct s_pdata
{
	t_data	*win;
	t_data	*map;
}			t_pdata;

typedef struct s_mlx
{
	t_wptr	ptr;
	t_wwin	win;
	t_wdata	img;
	t_pdata	pimg;
}			t_mlx;

typedef struct s_coord_part
{
	t_coord	min;
	t_coord	max;
}			t_coord_part;

typedef struct s_tab_str_incr
{
	char	**strs;
	char	*str;
}			t_tab_str_incr;

#endif // W_STRUCT_DISPLAY_H

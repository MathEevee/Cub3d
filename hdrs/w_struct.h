/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:24:01 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 11:39:46 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_H
# define W_STRUCT_H

# include "w_struct_display.h"

typedef struct s_map
{
	t_coord	size;
	char	**map;
}			t_map;

typedef struct s_player
{
	t_coord_f	pos;
	t_angle		angle;
}				t_player;

typedef struct s_info
{
	t_map		map;
	t_player	base;
	t_data		img_no;
	t_data		img_so;
	t_data		img_we;
	t_data		img_ea;
	t_color		color_f;
	t_color		color_c;
}				t_info;

typedef struct s_joe_mama
{
	t_mlx		mlx;
	t_info		info;
	t_key_press	press;
}				t_joe_mama;

#endif // W_STRUCT_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:24:01 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/06 10:42:51 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_H
# define W_STRUCT_H

# include "w_struct_parsing.h"
# include "w_struct_display.h"


typedef struct s_player
{
	t_coord_f	pos;
	double	angle;
}	t_player;

typedef struct s_fimg
{
	void	*img;
	t_coord	coord;
}	t_fimg;

typedef struct s_info
{
	char		**map;
	t_player	base;
	t_fimg		img_no;
	t_fimg		img_so;
	t_fimg		img_we;
	t_fimg		img_ea;
	t_color		color_f;
	t_color		color_c;
}	t_info;

typedef struct s_joe_mama
{
	t_mlx	mlx;
	t_info	info;
}	t_joe_mama;

#endif // W_STRUCT_H

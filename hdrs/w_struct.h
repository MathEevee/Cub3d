/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:24:01 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/03 14:59:50 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_H
# define W_STRUCT_H

# include "w_struct_parsing.h"
# include "w_struct_display.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_player
{
	t_coord	pos;
	double	angle;
}	t_player;

typedef struct s_info
{
	char		**map;
	t_player	base;
	t_wimg		img_no;
	t_wimg		img_so;
	t_wimg		img_we;
	t_wimg		img_ea;
	t_color		color_f;
	t_color		color_c;
}	t_info;

#endif // W_STRUCT_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct_display.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:26:05 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 12:11:21 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_DISPLAY_H
# define W_STRUCT_DISPLAY_H

# include "w_typedef.h"
# include "w_const.h"

typedef struct s_mlx
{
	t_wptr	ptr;
	t_wwin	win;
}	t_mlx;

#endif // W_STRUCT_DISPLAY_H

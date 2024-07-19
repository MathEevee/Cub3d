/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_const.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:25:29 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/16 12:29:55 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_CONST_H
# define W_CONST_H

# ifndef FOV
#  define FOV 90
# endif

# define FOV_INCR 180

# define WIN_N "Cub3D"

# define WIN_X 1080
# define WIN_Y 720

# define MAP_X 150
# define MAP_Y 150

# define SQRT_SIZE 10
# define MAP_MARGE 10
# define PLAYER_SIZE 3

# define IMG_SIZE 1500

# define FPS 60.0
# define S_US 1000000.0
# define FMS 16666.67 // FPS / S_US
# define MV_SPEED 8.0 // 8.0 / FPS

# define HIT_BOX 0.01

typedef enum s_key
{
	KEY_ESC = 65307,
	KEY_TAB = 65289,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
}	t_key;

#endif // W_CONST_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_const.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:25:29 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/10 09:43:15 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_CONST_H
# define W_CONST_H

# ifndef FOV
#  define FOV 80
# endif

# define FOV_INCR 180

# define PI 3.14159265358979323846

# define WIN_N "Cub3D"

# define WIN_X 640
# define WIN_Y 480

# define MAP_X 150
# define MAP_Y 150

# define SQRT_SIZE 50
# define MAP_MARGE 10
# define PLAYER_SIZE 10

# define IMG_SIZE 1500

# define FPS 60.0
# define S_US 1000000.0
# define FMS 16666.67 // FPS / S_US

# define MV_SPEED 4.0

typedef enum s_key
{
	KEY_ESC = 65307,
	KEY_TAB = 65289,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
}	t_key;

typedef enum s_mode
{
	MODE_MAIN = 1,
	MODE_MINIMAP = 2
}	t_mode;

#endif // W_CONST_H
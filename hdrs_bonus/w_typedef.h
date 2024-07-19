/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_typedef.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:27:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/16 10:45:00 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_TYPEDEF_H
# define W_TYPEDEF_H

# include <sys/time.h>
# include <stdint.h>

typedef int				t_fd;
typedef __uint32_t		t_color;
typedef __int64_t		t_color_def;

typedef void *			t_wptr;
typedef void *			t_wwin;
typedef void *			t_wimg;

typedef long int		t_ltime;
typedef struct timeval	t_tv;

typedef float			t_float;
typedef float			t_angle;

#endif // W_TYPEDEF_H

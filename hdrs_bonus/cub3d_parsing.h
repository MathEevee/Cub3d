/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:21:50 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/19 11:41:40 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include <stdbool.h>
# include "mlx.h"
# include "w_const.h"
# include "w_struct.h"

bool	check_path(char *line, t_joe_mama *info);

void	init_player(t_info *info, int x, int y, t_angle radiant);
void	init_info(t_info *info);

void	begin_cub3d(int fd, t_joe_mama *var);

char	**format_fd_no_nl(int fd);

bool	map_checker(t_info *info);

bool	map_close(char **map);

int		set_info(char **file, t_joe_mama *var);

char	**copy_tab(char **tab);

bool	color_check(char *str);

int		check_img(t_joe_mama *var);

void	free_mlx(t_wptr ptr, t_info *info);

void	free_var(t_joe_mama *var);

#endif // CUB3D_PARSING_H

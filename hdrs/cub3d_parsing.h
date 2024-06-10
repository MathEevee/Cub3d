/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:21:50 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/10 13:03:32 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include <stdbool.h>
# include "mlx.h"
# include "w_const.h"
# include "w_struct.h"

bool	check_path(char *line, t_joe_mama *info);
void	init_player(t_info *info, int x, int y, long double radiant);
t_fimg	create_wimg(void);
void	init_info(t_info *info);
void	init_wimg(t_info *info);
void	begin_cub3d(int fd, t_joe_mama *var);
char	**format_fd_no_nl(int fd);
bool	map_checker(t_info *info);
bool	map_close(char **map);
int		map_register(char **file, int i, t_joe_mama *var);
int		set_info(char **file, t_joe_mama *var);
char	**copy_tab(char **tab);
// void	free_mlx(t_joe_mama *info);

#endif // CUB3D_PARSING_H

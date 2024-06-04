/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_register.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:27:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/04 17:12:20 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static bool	init_path(t_fimg *img, t_info *map, char *line)
{
	if (map->img_no.img == NULL && wati_strncmp(line, "NO", 2) == 0)
		map->img_no = *img;
	else if (map->img_so.img == NULL && wati_strncmp(line, "SO", 2) == 0)
		map->img_so = *img;
	else if (map->img_we.img == NULL && wati_strncmp(line, "WE", 2) == 0)
		map->img_we = *img;
	else if (map->img_ea.img == NULL && wati_strncmp(line, "EA", 2) == 0)
		map->img_ea = *img;
	else
		return (false);
	return (true);
}

static bool	register_path(char *line, t_info *map)
{
	int	i;
	void	*mlx;
	t_fimg	img;

	i = 2;
	if (wati_isspace(line[i]) == 0)
		return (false);
	while (wati_isspace(line[i]) != 0)
		i++;
	img = create_wimg();
	mlx = mlx_init();
	if (mlx == NULL)
		return (false);
	img.img = mlx_xpm_file_to_image(mlx, line + i, &img.coord.x, &img.coord.y);
	if (img.img == NULL)
	{
		free(mlx);
		return(false);
	}
	if (init_path(&img, map, line) == true)
		return (true);
	return (false);
}

bool	convert_color(char *line, t_color_def *color)
{
	int	i;
	int	vir;

	i = 0;
	*color = 0;
	vir = 0;
	wati_printf("test1 |%c| %d |%s|\n", line[i], i, line +i);
	while (wati_isspace(line[i]) != 0)
		i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		while (wati_isspace(line[i]) != 0)
			i++;
		*color *= 256;
		printf("test in while 1 : %lx\n", *(color));
		*color += wati_atoi(line + i);
		wati_printf("atoi solo : %d\n", wati_atoi(line + i));
		printf("test in while 2 : %lx\n", *(color));
		printf("test in while %s\n", line+i);
		vir++;
		if (wati_strchr(line + i, ',') != 0)
			i = wati_strlen((wati_strchr(line + i, ','))) + (*line + i);
		else
			break;
	}
	printf("test %lx\n", *(color));
	if (*color < 0)
		return (false);
	return (true);
} // reparer l'addition pour l'hexa

static bool	register_color(char *line, t_info *map)
{
	int			i;
	t_color_def	tmp;

	i = 1;
	tmp = 0;
	if (wati_isspace(line[i]) == 0)
		return (false);
	while (wati_isspace(line[i]) != 0)
		i++;
	if (convert_color(line + i, &tmp) == false)
		return (false);
	if (line[0] == 'C')
		map->color_c = tmp;
	else if (line[0] == 'F')
		map->color_f = tmp;
	return (true);
}

bool	check_path(char *line, t_info *map)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (false);
	while (wati_isspace(line[i]) != 0)
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (false);
	if (wati_strncmp(line + i, "NO", 2) == 0 || wati_strncmp(line + i, "SO", 2) == 0
			|| wati_strncmp(line + i, "WE", 2) == 0
			|| wati_strncmp(line + i, "EA", 2) == 0)
	{
		if (register_path(line + i, map) == true)
			return (true);
	}
	else if (wati_strncmp(line + i, "C", 1) == 0
			|| (wati_strncmp(line + i, "F", 1) == 0))
	{
		if (register_color(line + i, map) == true)
			return (true);
	}
	return (false);
}

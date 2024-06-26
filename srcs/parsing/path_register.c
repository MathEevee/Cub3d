/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_register.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:27:10 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/26 09:27:12 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_path(t_fimg *img, t_joe_mama *var, char *line)
{
	int	i;

	i = 0;
	while (wati_isspace(line[i]) != 0)
		i++;
	if (var->info.img_no.img == NULL && wati_strncmp(line + i, "NO", 2) == 0)
		var->info.img_no = *img;
	else if (var->info.img_so.img == NULL
		&& wati_strncmp(line + i, "SO", 2) == 0)
		var->info.img_so = *img;
	else if (var->info.img_we.img == NULL
		&& wati_strncmp(line + i, "WE", 2) == 0)
		var->info.img_we = *img;
	else if (var->info.img_ea.img == NULL
		&& wati_strncmp(line + i, "EA", 2) == 0)
		var->info.img_ea = *img;
	else
	{
		wati_fprintf(2, "Argument : ");
		write(2, &line, 2);
		wati_fprintf(2, "\nError\n");
		return (false);
	}
	return (true);
}

static bool	register_path(char *line, t_joe_mama *var)
{
	int		i;
	t_fimg	img;

	i = 2;
	if (wati_isspace(line[i]) == 0)
		return (false);
	while (wati_isspace(line[i]) != 0)
		i++;
	img = create_wimg();
	img.img = mlx_xpm_file_to_image(var->mlx.ptr, line + i, \
		&img.coord.x, &img.coord.y);
	if (img.img == NULL)
		return (false);
	if (init_path(&img, var, line) == true)
		return (true);
	return (false);
}

bool	convert_color(char *line, t_color_def *color)
{
	int	i;

	i = 0;
	while (wati_isspace(line[i]) != 0)
		i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		while (wati_isspace(line[i]) != 0)
			i++;
		*color = *color * 256 + wati_atoi(line + i);
		while (line[i] != ',')
		{
			if (line[i] == '\0')
				break ;
			i++;
		}
		if (line[i] == ',')
			i++;
	}
	if (*color <= 0 || color_check(line) == false)
		return (false);
	return (true);
}

static bool	register_color(char *line, t_joe_mama *var)
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
		var->info.color_c = tmp;
	else if (line[0] == 'F')
		var->info.color_f = tmp;
	return (true);
}

bool	check_path(char *line, t_joe_mama *var)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (false);
	while (wati_isspace(line[i]) != 0)
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (false);
	if (wati_strncmp(line + i, "NO", 2) == 0
		|| wati_strncmp(line + i, "SO", 2) == 0
		|| wati_strncmp(line + i, "WE", 2) == 0
		|| wati_strncmp(line + i, "EA", 2) == 0)
	{
		if (register_path(line + i, var) == true)
			return (true);
	}
	else if (wati_strncmp(line + i, "C", 1) == 0
		|| (wati_strncmp(line + i, "F", 1) == 0))
	{
		if (register_color(line + i, var) == true)
			return (true);
	}
	return (false);
}

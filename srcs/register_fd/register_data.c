/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:16:58 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/05 17:28:08 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_size(int i, char **file)
{
	int	len;
	int	idx;

	len = 0;
	while (file[i] != NULL)
	{
		idx = 0;
		while (file[i][idx] != '\0')
			idx++;
		if (len < idx)
			len = idx;
		i++;
	}
	return (len);
}

static void	map_copy(int i, int j, t_info *info, char **file)
{
	int	len;
	int	map_j;
	int	map_i;

	len = map_size(i, file);
	map_j = 0;
	info->map = malloc(sizeof(char *) * (j + 1));
	while (file[i] != NULL)
	{
		info->map[map_j] = malloc(sizeof(char) * (len + 1));
		wati_strlcpy(info->map[map_j], file[i], wati_strlen(file[i]) + 1);
		map_i = wati_strlen(file[i]);
		while (map_i < len)
		{
			info->map[map_j][map_i] = ' ';
			map_i++;
		}
		info->map[map_j][map_i] = '\0';
		map_j++;
		i++;
	}
	info->map[map_j] = NULL;
}

static int	map_register(char **file, int i, t_info *info)
{
	int	j;

	j = 0;
	if (file[i] == NULL)
		return (-1);
	while (file[i][0] == '\n')
		i++;
	while (file[i + j] != NULL)
		j++;
	map_copy(i, j, info, file);
	return (0);
}

static int	loop_file(int *i, char **file, int count, t_info *info)
{
	while (file[*i] != NULL)
	{
		if (file[*i][0] == '\0')
			(*i)++;
		else
		{
			if (check_path(file[*i], info) == true)
				count++;
			else
				break;
			(*i)++;
		}
	}
	return (count);
}

static int	set_info(char **file, t_info *info)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = loop_file(&i, file, count, info);
	if (count != 6)
	{
		wati_fprintf(2, "Wrong path or color\nError\n");
		return (-1);
	}
	if (map_register(file, i, info) == -1)
		return (-1);
	return (0);
}

void	begin_cub3d(int fd)
{
	char	**file;
	t_info	info;

	init_info(&info);
	file = format_fd_no_nl(fd);
	if (file == NULL)
	{
		wati_fprintf(2, "This file is empty\nError\n");
		return;
	}
	if (set_info(file, &info) == -1)
	{
		free_mlx(&info);
		wati_free_tab(file);
		return ;
	}
	wati_free_tab(file);

	// int	j;
	// j=0;
	// while (info.map[j])
	// {
	// 	wati_printf("%s\n", info.map[j]);
	// 	j++;
	// }
}

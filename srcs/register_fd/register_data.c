/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:16:58 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/26 11:45:54 by matde-ol         ###   ########.fr       */
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

static void	map_copy(int i, int j, t_joe_mama *var, char **file)
{
	int	len;
	int	map_j;
	int	map_i;

	len = map_size(i, file);
	map_j = 0;
	var->info.map.map = malloc(sizeof(char *) * (j + 1));
	while (file[i] != NULL)
	{
		var->info.map.map[map_j] = malloc(sizeof(char) * (len + 1));
		wati_strlcpy(var->info.map.map[map_j], file[i], \
			wati_strlen(file[i]) + 1);
		map_i = wati_strlen(file[i]);
		while (map_i < len)
		{
			var->info.map.map[map_j][map_i] = ' ';
			map_i++;
		}
		var->info.map.map[map_j][map_i] = '\0';
		map_j++;
		i++;
	}
	var->info.map.map[map_j] = NULL;
}

static int	loop_file(int *i, char **file, int count, t_joe_mama *var)
{
	while (file[*i] != NULL)
	{
		if (file[*i][0] == '\0')
			(*i)++;
		else
		{
			if (check_path(file[*i], var) == true)
				count++;
			else
				break ;
			(*i)++;
		}
	}
	return (count);
}

static int	map_register(char **file, int i, t_joe_mama *var)
{
	int	j;

	j = 0;
	if (file[i] == NULL)
	{
		wati_fprintf(2, "Map doesn't exist\nError\n");
		return (-1);
	}
	while (file[i][0] == '\n')
		i++;
	while (file[i + j] != NULL)
		j++;
	if (j > 1000 || map_size(i, file) > 1000)
	{
		wati_fprintf(2, "Map too big\nError\n");
		wati_free_tab(file);
		return (-1);
	}
	map_copy(i, j, var, file);
	return (0);
}

int	set_info(char **file, t_joe_mama *var)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = loop_file(&i, file, count, var);
	if (count != 6)
	{
		wati_fprintf(2, "Wrong path or color\nError\n");
		return (-1);
	}
	if (check_img(var) == -1)
	{
		wati_fprintf(2, "Wrong size for image\nError\n");
		return (-1);
	}
	if (map_register(file, i, var) == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:34:22 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/07 16:07:41 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	printf_tab(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		printf("%s\n", map[y]);
		y++;
	}
}

char	**copy_tab(char **tab)
{
	char	**cpy_tab;
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	cpy_tab = malloc(sizeof(char *) * (i + 1));
	if (cpy_tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		cpy_tab[i] = wati_strdup(tab[i]);
		if (cpy_tab[i] == NULL)
		{
			wati_free_tab(&cpy_tab);
			return (NULL);
		}
		i++;
	}
	return (cpy_tab);
}

bool	check_pos(char **map, int *x, int *y, int status)
{
	int	x_bis;
	int	y_bis;

	x_bis = 0;
	y_bis = 0;
	while (map[*y] != NULL)
	{
		(*x) = 0;
		while (map[*y][*x] != '\0')
		{
			if (status == 1 && (map[*y][*x] == '0' || wati_isalpha(map[*y][*x]) != 0))
				return (true);
			(*x)++;
		}
		(*y)++;
	}
	if (status == 2)
	{
		check_pos(map, &x_bis, &y_bis, 2);
		return (true);
	}
	else if (status == 1)
		return (true);
	return (false);
}

int	span_check(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_pos(map, &x, &y, 1);
	while (map[y][x] != '\0')
	{
		if (map[y][x] == '0' && (x == 0 || y == 0))
			return (false);
		if (map[y][x] == '0' && (map[y][x + 1] == '\0' || map[y][x + 1] == ' '))
		{
			return (false);
		}
		else if (map[y][x] == '0' && (map[y + 1][x] == ' '))
		{
			return (false);
		}
			printf("|%c|\n", map[y][x]);
		if (map[y][x] == '0' || wati_isalpha(map[y][x]) != 0)
			map[y][x] = '1';
		x++;
	}
	if (map[y] == NULL || map[y][x] == '\0')
		return (true);
	return (false);
}

bool	map_span_fill(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (span_check(map) == true)
	{
		if (check_pos(map, &x ,&y ,2) == true)
			return (true);
		return(map_span_fill(map));
	}
	return (false);
}

bool	map_close(char **map)
{
	char	**cpy_map;

	cpy_map = copy_tab(map);
	if (cpy_map == NULL)
	{
		wati_fprintf(2, "Malloc failed\nError\n");
		return (false);
	}
	if (map_span_fill(cpy_map) == false)
	{
		// wati_free_tab(cpy_map);
		wati_fprintf(2, "Map is not close\nError\n");
		return (false);
	}
	// wati_free_tab(cpy_map);
	return (true);
}

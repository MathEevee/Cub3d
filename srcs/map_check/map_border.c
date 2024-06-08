/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:34:22 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/08 14:20:30 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	printf_tab(char **map)
{
	while (*map != NULL)
	{
		wati_printf("%s\n", *map);
		map++;
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
	cpy_tab[i] = NULL;
	return (cpy_tab);
}

void	check_pos(char **map, int *x, int *y)
{
	while (map[*y] != NULL)
	{
		*x = 0;
		while (map[*y][*x] != '\0')
		{
			if (wati_isalpha(map[*y][*x]) != 0 || map[*y][*x] == '0')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

bool	span_check_conditions(char **map, int x, int y)
{
	if (map[y][x] == ' ' || map[y][x + 1] == '\0')
		return (false);
	if (map[y][x] == '0' && (x == 0 || y == 0))
		return (false);
	if (map[y + 1] == NULL)
		return (false);
	if (((map[y + 1] != NULL) && (map[y + 1][x] == ' ')) || map[y - 1][x] != '1')
		return (false);
	return (true);
}

bool	span_check(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_pos(map, &x, &y);
	if (map[y] == NULL)
		return (false);
	while (map[y][x] != '\0')
	{
		if (map[y][x] == '1')
			return (true);
		if (span_check_conditions(map, x, y) == false)
			return (false);
		if (map[y][x] == '0' || wati_isalpha(map[y][x]) != 0)
			map[y][x] = '1';
		x++;
	}
	if (map[y + 1] == NULL)
		return (false);
	return (true);
}

bool	map_span_fill(char **map)
{
	int	x;
	int	y;
	int	x_bis;
	int	y_bis;

	x = 0;
	y = 0;
	if (span_check(map) == true && map[y] != NULL)
	{
		x_bis = 0;
		y_bis = 0;
		printf_tab(map);
		check_pos(map, &x_bis, &y_bis);
		wati_printf("test : |%s|\n", map[y_bis]);
		if (map[y_bis] == NULL)
			return (true);
		return(map_span_fill(map));
	}
	return (false);
}

bool	map_close(char **map)
{
	char	**cpy_map;

	cpy_map = copy_tab(map);
	printf_tab(cpy_map);
	printf("%s\n", cpy_map[0]);
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

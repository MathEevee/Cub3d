/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:34:22 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/06 14:32:09 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

//bas, gauche, haut, droite

bool	map_flood_fill(char **map)
{
	
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
	if (map_flood_fill(cpy_map) == false)
	{
		wati_free_tab(cpy_map);
		wati_fprintf(2, "Map is not close\nError\n");
		return (false);
	}
	wati_free_tab(cpy_map);
	return (true);
}

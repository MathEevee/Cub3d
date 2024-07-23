/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:29:53 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 15:20:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwati.h"
#include "cub3d.h"

bool	color_check(char *str)
{
	int	i;
	int	count;
	int	nbr;

	i = 0;
	count = 0;
	while (wati_isspace(str[i]) != 0)
		i++;
	while (str[i] != '\0')
	{
		nbr = 0;
		while (wati_isdigit(str[i + nbr]) != 0)
			nbr++;
		if (!(str[i] != '\0') && (nbr > 3 || str[i + nbr] != ','
				|| wati_isspace(str[i]) != 0))
			return (false);
		i += nbr;
		if (str[i] == ',')
			count++;
		i++;
	}
	if (nbr > 3 || count != 2)
		return (false);
	return (true);
}

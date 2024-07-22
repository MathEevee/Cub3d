/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:05:36 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/22 11:39:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs_bonus/cub3d.h"
#include "libwati.h"

static int	count_tab(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

static char	*copy_any_nl(char *old)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (wati_strlen(old) + 1));
	if (new == NULL)
		return (NULL);
	while (old[i] != '\0')
	{
		new[i] = old[i];
		if (old[i] == '\n')
			new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**format_fd_no_nl(int fd)
{
	char	**old_fd;
	char	**new_fd;
	int		j;

	j = 0;
	old_fd = get_file(fd);
	if (old_fd == NULL)
		return (NULL);
	new_fd = malloc(sizeof(char *) * (count_tab(old_fd) + 1));
	if (new_fd == NULL)
		return (NULL);
	while (old_fd[j] != NULL)
	{
		new_fd[j] = copy_any_nl(old_fd[j]);
		if (new_fd[j] == NULL)
		{
			wati_free_tab(old_fd);
			wati_free_tab(new_fd);
			return (NULL);
		}
		j++;
	}
	new_fd[j] = NULL;
	wati_free_tab(old_fd);
	return (new_fd);
}

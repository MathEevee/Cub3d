/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:54:18 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:53:06 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwati.h"
#include <stdlib.h>

static t_cbuf	**get_static(void)
{
	static t_cbuf	*b = NULL;

	return (&b);
}

t_cbuf	*get_buffer(int fd)
{
	t_cbuf	**s;

	s = get_static();
	if (!*s)
	{
		*s = new_buffer(fd);
		if (!s)
			return (NULL);
	}
	if ((*s)->fd == fd)
		return (*s);
	while ((*s)->next && (*s)->next->fd != fd)
		*s = (*s)->next;
	if (!(*s)->next)
	{
		(*s)->next = new_buffer(fd);
		if (!(*s)->next)
			return (NULL);
	}
	return ((*s)->next);
}

void	delete_buffer(int fd)
{
	t_cbuf	**s;
	t_cbuf	*b;

	s = get_static();
	if (!*s)
		return ;
	if ((*s)->fd == fd)
	{
		b = *s;
		*s = (*s)->next;
		free(b->buffer);
		free(b);
		return ;
	}
	while ((*s)->next && (*s)->next->fd != fd)
		*s = (*s)->next;
	if (!(*s)->next)
		return ;
	b = (*s)->next;
	(*s)->next = b->next;
	free(b->buffer);
	free(b);
}

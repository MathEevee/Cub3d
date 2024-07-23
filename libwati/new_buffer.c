/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:31:55 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:53:10 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwati.h"
#include <stdlib.h>

t_cbuf	*new_buffer(int fd)
{
	t_cbuf	*buffer;

	buffer = malloc(sizeof(t_cbuf));
	if (!buffer)
		return (NULL);
	buffer->buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer->buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer->fd = fd;
	buffer->r = BUFFER_SIZE;
	buffer->cursor = BUFFER_SIZE;
	buffer->next = NULL;
	return (buffer);
}

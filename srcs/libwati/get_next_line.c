/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:54:49 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:53:31 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwati.h"
#include <stddef.h>

char	*get_next_line(int fd)
{
	t_cbuf	*b;
	char	*str;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	b = get_buffer(fd);
	if (!b)
		return (NULL);
	str = read_file(b);
	if (b->r < BUFFER_SIZE && b->cursor >= b->r)
		delete_buffer(fd);
	return (str);
}

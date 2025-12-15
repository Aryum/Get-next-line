/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:55:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/16 08:32:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		readbytes;
	char		*ret;

	ret = malloc(1); 
	if (fd < 0 || BUFFER_SIZE < 1 || ret == NULL)
		return (h_updateret(&ret, NULL));
	ret[0] = '\0';
	readbytes = 0;
	if (!h_appendbuffer(&ret, buffer))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		buffer[readbytes] = '\0';
		while (readbytes > 0)
		{
			if (h_appendbuffer(&ret, buffer) || readbytes < BUFFER_SIZE)
				break ;
			readbytes = read(fd, buffer, BUFFER_SIZE);
			buffer[readbytes] = '\0';
		}
	}
	if (ret == NULL || ret[0] == '\0' || readbytes < 0)
		return (h_resetbuffer(buffer, 1), h_updateret(&ret, NULL));
	else
		return (h_resetbuffer(buffer, 0), ret);
}

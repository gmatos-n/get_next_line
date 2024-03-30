/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmatos-n <gmatos-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:49:48 by gmatos-n          #+#    #+#             */
/*   Updated: 2024/03/29 22:58:24 by gmatos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = nl_strjoin(line, buffer[fd]);
		if (nl_strlen(buffer[fd]) == 0)
			return (line);
		if (find_and_clean(buffer[fd]) == 1)
			break ;
		if (read(fd, buffer[fd], BUFFER_SIZE) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

/* #include <fcntl.h>

int main()
{
	int	fd;
	char	*line;

	fd = open("teste1.txt", O_RDONLY);
	line = get_next_line(0);
	while (line)
	{
		printf("Line: %s", line);
		line = get_next_line(0);
	}
	close(fd);
	return (0);
} */

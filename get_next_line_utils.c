/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmatos-n <gmatos-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:49:45 by gmatos-n          #+#    #+#             */
/*   Updated: 2024/03/29 22:53:43 by gmatos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	nl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	find_and_clean(char *buffer)
{
	int	i;
	int	j;
	int	nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			nl = 1;
		buffer[i] = '\0';
		i++;
	}
	return (nl);
}

char	*nl_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(nl_strlen(line) + nl_strlen(buffer) + 1);
	if (!str)
		return (NULL);
	while (line && line[j])
		str[i++] = line[j++];
	j = 0;
	while (buffer && buffer[j])
	{
		str[i] = buffer[j++];
		if (str[i++] == '\n')
			break ;
	}
	str[i] = '\0';
	free (line);
	return (str);
}

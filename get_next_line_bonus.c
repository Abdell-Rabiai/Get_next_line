/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:24:56 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/12 10:58:19 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_there_newline(char *str, int *newline)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			*newline = i;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*read_the_rest(char *saved_string, int newline_index)
{
	char	*str;
	int		i;
	int		j;

	if (!saved_string)
		return (NULL);
	if (saved_string[newline_index] == '\0')
	{
		free(saved_string);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char)
			* (ft_strlen(saved_string) - newline_index));
	if (!str)
		return (NULL);
	j = newline_index + 1;
	i = 0;
	while (saved_string[j] != '\0')
		str[i++] = saved_string[j++];
	str[i] = '\0';
	free(saved_string);
	return (str);
}

char	*read_file(int fd, char *saved_string)
{
	char	*buffer;
	int		nbytes;
	int		newline_index;

	newline_index = 0;
	nbytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!is_there_newline(saved_string, &newline_index) && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			free(saved_string);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		saved_string = ft_strjoin(saved_string, buffer);
	}
	return (free(buffer), saved_string);
}

char	*get_next_line(int fd)
{
	static char	*saved_string[1024];
	char		*line;
	int			newline_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved_string[fd])
	{
		saved_string[fd] = (char *)malloc(sizeof(char));
		saved_string[fd][0] = '\0';
	}
	saved_string[fd] = read_file(fd, saved_string[fd]);
	if (!saved_string[fd])
		return (NULL);
	if (is_there_newline(saved_string[fd], &newline_index))
	{
		line = ft_substr(saved_string[fd], 0, newline_index + 1);
		saved_string[fd] = read_the_rest(saved_string[fd], newline_index);
	}
	else
	{
		line = ft_substr(saved_string[fd], 0, ft_strlen(saved_string[fd]) + 1);
		saved_string[fd] = read_the_rest(saved_string[fd],
				ft_strlen(saved_string[fd]));
	}
	return (line);
}

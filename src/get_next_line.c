/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:11:30 by anamella          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:14 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*read_file(char *s, int fd)
{
	int		byte;
	char	*buffer;

	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	byte = 1;
	while (!ft_strchr(s, '\n') && byte)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			if (s)
				free(s);
			return (0);
		}
		buffer[byte] = 0;
		s = ft_strjoin(s, buffer);
	}
	if (buffer)
		free(buffer);
	return (s);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	tmp = malloc(i + 1 + (s[i] == '\n'));
	if (!tmp)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		tmp[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*ft_new_str(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	while (s[i] && s[i] != '\n')
		i++;
	tmp = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!tmp)
		return (0);
	i += (s[i] == '\n');
	j = 0;
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = 0;
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (s)
		{
			free(s);
			s = 0;
		}
		return (0);
	}
	s = read_file(s, fd);
	if (!s)
		return (0);
	line = ft_get_line(s);
	s = ft_new_str(s);
	if (s && !s[0])
	{
		free(s);
		s = NULL;
	}
	return (line);
}

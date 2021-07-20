/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:12:12 by kchaniot          #+#    #+#             */
/*   Updated: 2021/07/16 19:12:13 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

static char	*set_stuff(char *line, char *box)
{
	char	*ptr;
	int		len;
	char	*tmp;

	len = 0;
	tmp = ft_buffjoin(line, box);
	free(line);
	line = tmp;
	ptr = ft_strchr(box, '\n');
	while (ptr[len])
		len++;
	box = ft_memmove(box, ++ptr, len);
	ft_bzero(box + len, 1);
	return (line);
}

static char	*freedom(char *line, char *box)
{
	char	*tmp;

	tmp = ft_buffjoin(line, box);
	free(line);
	line = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes;
	static char	box[BUFFER_SIZE + 1];
	char		*line;

	line = (char *)ft_calloc(1, sizeof(*line));
	while (!(ft_strchr(box, '\n')))
	{
		if (box[0])
			line = freedom(line, box);
		bytes = read(fd, box, BUFFER_SIZE);
		box[bytes] = '\0';
		if (bytes <= 0 && !(*line))
		{
			free(line);
			return (NULL);
		}
		if (bytes < BUFFER_SIZE && !ft_strchr(box, '\n'))
		{
			line = freedom(line, box);
			ft_bzero(box, 1);
			return (line);
		}
	}
	line = set_stuff(line, box);
	return (line);
}

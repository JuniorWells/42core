/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:12:12 by kchaniot          #+#    #+#             */
/*   Updated: 2021/11/03 10:50:11 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static int	check_bytes(int bytes, char *line)
{
	int	flag;

	flag = 0;
	if (bytes <= 0 && !(*line))
	{
		free(line);
		flag = 1;
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	int			bytes;
	static char	box[FD_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(*line));
	while (!(ft_strchr(box[fd], '\n')))
	{
		if (*box[fd])
			line = freedom(line, box[fd]);
		bytes = read(fd, box[fd], BUFFER_SIZE);
		if (check_bytes(bytes, line))
			return (NULL);
		box[fd][bytes] = '\0';
		if (bytes < BUFFER_SIZE && !ft_strchr(box[fd], '\n'))
		{
			line = freedom(line, box[fd]);
			ft_bzero(box[fd], 1);
			return (line);
		}
	}
	line = set_stuff(line, box[fd]);
	return (line);
}

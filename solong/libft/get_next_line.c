/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:12:12 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/12 12:45:29 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_n(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

static char	*ft_buffjoin(char *s1, char *s2)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen_n(s1) + ft_strlen_n(s2) + 1;
	ret = (char *)ft_calloc(len, sizeof(char));
	if (!ret)
		return (NULL);
	while (*s1)
		ret[i++] = *(char *)s1++;
	while (*s2 && (*s2 != '\n'))
		ret[i++] = *(char *)s2++;
	if (*s2 == '\n')
		ret[i] = *(char *)s2;
	return (ret);
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
	ft_memmove(box, ++ptr, len);
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
		if (*box)
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

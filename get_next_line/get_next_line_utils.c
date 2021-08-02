/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:40:58 by kchaniot          #+#    #+#             */
/*   Updated: 2021/07/16 19:11:44 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = 0;
}

void	*ft_calloc(size_t n_elem, size_t size)
{
	void	*ptr;

	ptr = malloc(n_elem * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n_elem * size);
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

char	*ft_buffjoin(char *s1, char *s2)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)calloc(len, sizeof(char));
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ret;

	if (!src && !dest)
		return (0);
	ret = dest;
	if (src < dest)
	{
		src += n;
		dest += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}
	else
		while (n--)
			*(char *)dest++ = *(char *)src++;
	return (ret);
}

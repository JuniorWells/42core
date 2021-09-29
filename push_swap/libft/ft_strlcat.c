/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:21:12 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/04 11:02:32 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Note, however, that if strlcat() traverses size characters without finding a 
** NUL, the length of the string is considered to be size and the destination 
** string will not be NUL-terminated (since there was no space for the NUL).
** This keeps strlcat() from running off the end of a string. In practice this 
** should not happen (as it means that either size is incorrect or that dst is 
** not a proper ''C'' string). The check exists to prevent potential security
** problems in incorrect code.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
	{
		i++;
		dst++;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src++)
		i++;
	return (i);
}

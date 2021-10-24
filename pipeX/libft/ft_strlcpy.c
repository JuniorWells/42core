/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:18:00 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/04 14:23:48 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcpy() function copies up to size - 1 characters from the 
** NUL-terminated ** string src to dst, NUL-terminating the result. 
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	if (!src && !dest)
		return (0);
	i = 0;
	while (src[i] && i + 1 < destsize)
	{
		dest[i] = src[i];
		i++;
	}
	if (destsize != '\0')
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}

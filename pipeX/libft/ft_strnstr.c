/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:37:21 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/09 10:45:28 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	len_need;

	if (!*needle)
		return ((char *)haystack);
	len_need = ft_strlen(needle);
	if (!ft_strlen(haystack) || len < len_need)
		return (0);
	len -= --len_need;
	while (len-- && *haystack)
	{
		a = (char *)haystack;
		b = (char *)needle;
		while (*b && *a == *b)
		{
			++a;
			++b;
		}
		if (*b == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:46:47 by kchaniot          #+#    #+#             */
/*   Updated: 2021/05/25 12:54:02 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;
	size_t	len;

	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_isset(set, *start))
		start++;
	while (start < end && ft_isset(set, *(end - 1)))
		end--;
	len = end - start + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, start, len);
	return (ret);
}

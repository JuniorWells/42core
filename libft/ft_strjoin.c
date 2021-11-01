/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:06:42 by kchaniot          #+#    #+#             */
/*   Updated: 2021/11/01 18:47:13 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	while (*s1)
		ret[i++] = *(char *)s1++;
	while (*s2)
		ret[i++] = *(char *)s2++;
	ret[i] = '\0';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:47:35 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/09 10:47:36 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	count;
	char			*ret;

	count = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s[count])
	{
		ret[count] = f(count, s[count]);
		count++;
	}
	ret[count] = 0;
	return (ret);
}

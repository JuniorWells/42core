/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:02:03 by kchaniot          #+#    #+#             */
/*   Updated: 2021/05/18 15:50:53 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	while (1)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		if (*s == 0)
			break ;
		++s;
	}
	return (ret);
}

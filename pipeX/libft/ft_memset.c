/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:25:37 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/03 18:38:37 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The C library function void *memset(void *str, int c, size_t n) copies the 
** character c (an unsigned char) to the first n characters of the string 
** pointed to, by the argument str.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	void	*str;

	str = s;
	while (n--)
	{
		*(char *)s++ = (unsigned char)c;
	}
	return (str);
}

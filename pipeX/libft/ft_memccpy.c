/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:13:36 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/03 18:20:04 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies no more than n bytes from memory area src to 
** memory area dest, stopping when the character c is 
** found.
*/
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(char *)dest++ = *(char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
			return (dest);
	}
	return (0);
}

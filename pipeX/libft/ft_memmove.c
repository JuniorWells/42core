/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:26:35 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/03 18:36:20 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove() function copies n bytes from memory area src to
** memory area dest.  The memory areas may overlap: copying takes
** place as though the bytes in src are first copied into a
** temporary array that does not overlap src or dest, and the bytes
** are then copied from the temporary array to dest.
*/
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

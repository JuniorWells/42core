/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:54:57 by kchaniot          #+#    #+#             */
/*   Updated: 2021/05/27 12:27:39 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	void	*ptr;

	ptr = malloc(n_elem * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n_elem * size);
	return (ptr);
}

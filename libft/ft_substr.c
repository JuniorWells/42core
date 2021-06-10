/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:47:53 by kchaniot          #+#    #+#             */
/*   Updated: 2021/06/09 10:48:56 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	ret = (char *)malloc((++len) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len);
	return (ret);
}

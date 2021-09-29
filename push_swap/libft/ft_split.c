/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:49:00 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/29 15:13:32 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free(char **str, int len)
{
	int	j;

	j = 0;
	while (j < len && str[j])
		free(str[j++]);
	free(str);
	return (0);
}

static	char	*ft_malloc_str(size_t len)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	return (ret);
}

static size_t	get_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*temp;
	size_t	i;
	size_t	temp_len;

	ret = (char **)malloc(sizeof(char *) * get_words(s, c) + 1);
	if (!ret)
		ft_free(ret, get_words(s, c) + 1);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			temp = (char *)s;
			while (*s && *s != c)
				s++;
			temp_len = s - temp + 1;
			ret[i] = ft_malloc_str(temp_len);
			ft_strlcpy(ret[i++], temp, temp_len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}

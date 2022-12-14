/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:18:11 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/19 21:51:50 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!src && !dest)
		return (NULL);
	if (dest < src)
	{
		if (src == ((void *)0) && dest == ((void *)0))
			return (dest);
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)malloc(len1 + len2 + 1);
	if (!s3)
		return (NULL);
	ft_memmove(s3, s1, len1);
	i = 0;
	while (i < len2)
	{
		s3[len1 + i] = s2[i];
		i++;
	}
	s3[len1 + i] = '\0';
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	while ((i - start) < len && i < ft_strlen(s))
		i++;
	subs = (char *)malloc(sizeof(char) * ((i - start) + 1));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

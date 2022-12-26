/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/26 23:39:05 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;
	int			r;
	size_t		i;

	r = -1;
	i = -1;
	buf = malloc(BUFFER_SIZE + 1);
	while (r != 0)
	{
		while (stash[++i])
		{
			if (stash[i] == '\n')
			{
				line = ft_substr(stash, 0, i);
				free(stash);
				stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
				if (!line || !stash)
					return (NULL);
			}
		}
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1 || fd < 0)
			return (NULL);
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
	}
	// printf("\n");
	// while (get_next_line(0))
	// 	printf("%s\n", get_next_line(0));
}

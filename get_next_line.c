/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/01/08 15:56:41 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char *) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
		line[i] = stash[i];
	line[++i] = '\0';
	stash = ft_substr(stash, i, ft_strlen(stash) - i);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;
	int			r;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = read(fd, buf, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	else if (r != 0)
	{
		stash = ft_strjoin(stash, buf);
		get_next_line(fd);
	}
	line = ft_get_line(stash);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("fd = %d/n", fd);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	while (line)
// 		printf("%s\n", line);
// 	// printf("\n");
// 	// while (get_next_line(0))
// 	// 	printf("%s\n", get_next_line(0));
// 	return (0);
// }

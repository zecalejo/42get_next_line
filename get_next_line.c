/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/01/18 18:07:45 by jnuncio-         ###   ########.fr       */
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
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = -1;
	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		ft_memset(buf, 0, ft_strlen(buf));
		return (NULL);
	}
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buf);
		if (ft_clnbuf(buf))
			break ;
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %d/n", fd);
	line = get_next_line(fd);
	printf("%s\n", line);
	while (line)
		printf("%s\n", line);
	// printf("\n");
	// while (get_next_line(0))
	// 	printf("%s\n", get_next_line(0));
	return (0);
}

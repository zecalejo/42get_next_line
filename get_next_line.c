/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/15 00:28:53 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff [BUFFER_SIZE];
	int			i;
	int			r;

	i = -1;
	while (1)
	{
		r = read(fd, &buff[++i], BUFFER_SIZE);
		if (r == -1 || fd < 0)
			return (NULL);
		if (buff[i] == '\n' || r == 0)
		{
			buff[i] = '\0';
			break ;
		}
		
	}
	printf("%s\n", buff);
	return (buff);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
}

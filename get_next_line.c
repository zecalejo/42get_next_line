/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/13 00:58:12 by jnuncio-         ###   ########.fr       */
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
		r = read(fd, &buff[++i], 1);
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			break ;
		}
		if (r == -1)
		{
			buff[i - 1] = '\0';
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
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}

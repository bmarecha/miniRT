/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:51:20 by bmarecha          #+#    #+#             */
/*   Updated: 2019/12/16 15:22:14 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	is_end_of_file(char **memfd, int gnl_value)
{
	if (!gnl_value)
	{
		free(*memfd);
		*memfd = 0;
	}
}

int		get_next_line(int fd, char **line)
{
	static char		*memory[126];
	char			*temp;
	int				res;
	int				readv;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 ||
			(!(memory[fd]) && ((!(memory[fd] = malloc(1)))
			|| (*memory[fd] = 0))) ||
			!(temp = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strrchr(memory[fd], '\n')
		&& (readv = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[readv] = '\0';
		memory[fd] = ft_stradd(memory[fd], temp);
	}
	free(temp);
	res = ft_strrchr(memory[fd], '\n');
	*line = ft_cpyto(memory[fd], '\n');
	memory[fd] = ft_resetto(memory[fd], '\n');
	if (readv == -1)
		return (-1);
	is_end_of_file(&memory[fd], res);
	return (res);
}

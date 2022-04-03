/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/02/27 19:02:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

char	*get_next_line(int fd)
{
	t_save			*save;
	static t_save	list[255];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = &list[fd];
	save->fd = fd;
	save->line = 0;
	if (*save->all_data == 0)
	{
		if ((read(fd, save->all_data, BUFFER_SIZE)) <= 0)
			return (0);
	}
	ft_read_and_save(save);
	if (!save->line)
	{
		free(save->line);
		return (0);
	}
	return (save->line);
}

size_t	ft_get_line(char *all_data)
{
	size_t	i;

	i = 0;
	while (all_data[i] && all_data[i] != '\n')
		i++;
	if (all_data[i] == '\n')
		i++;
	return (i);
}

int	ft_save(char *line, char *all_data)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (line[i] != '\0')
		i++;
	while (all_data[c])
	{
		line[i + c] = all_data[c];
		if (all_data[c] == '\n')
			return (c + 1);
		c++;
	}
	return (-1);
}

void	ft_read_and_save(t_save *save)
{
	size_t	size;
	char	*buff;
	int		read_bytes;

	read_bytes = save->read_bytes;
	size = ft_get_line(&save->all_data[read_bytes]);
	if (save->line)
		size += ft_get_line(save->line);
	buff = (char *) calloc(size + 1, sizeof(char));
	if (save->line)
	{
		ft_save(buff, save->line);
		free(save->line);
	}
	read_bytes = ft_save(buff, &save->all_data[read_bytes]);
	save->line = buff;
	if (read_bytes == -1)
	{
		bzero(save->all_data, BUFFER_SIZE);
		save->read_bytes = 0;
		if ((read(save->fd, save->all_data, BUFFER_SIZE)) > 0)
			ft_read_and_save(save);
	}
	else
		save->read_bytes = read_bytes + read_bytes;
}

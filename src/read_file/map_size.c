/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:47:29 by lenamelard        #+#    #+#             */
/*   Updated: 2022/05/26 15:41:50 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_error(int fd)
{
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_wordcount(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 1)
		{
			count++;
			while (line[i] != '\n' && line[i] != ' ')
				i++;
		}
		i++;
	}
	return (count);
}

int	ft_get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = 0;
	fd = open(file, O_RDONLY);
	ft_error(fd);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	ft_get_width(char *file)
{
	char	*line;
	int		fd;
	int		width;

	fd = 0;
	fd = open(file, O_RDONLY);
	ft_error(fd);
	line = get_next_line(fd);
	width = ft_wordcount(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width);
}

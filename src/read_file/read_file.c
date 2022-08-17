/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:57:14 by lenamelard        #+#    #+#             */
/*   Updated: 2022/05/26 15:22:32 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	**ft_free_all(int **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

int	*ft_fill_line(int *data, char *line, int width)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split_fdf(line, ' ', width);
	while (str[i] && str[i][0] != '\n')
	{
		data[i] = ft_atoi_fdf(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (data);
}

int	**ft_read_map(char *file, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = 0;
	data->tab = malloc(sizeof(int *) * data->height);
	if (!(data->tab))
		return (0);
	fd = open(file, O_RDONLY);
	while (i < data->height)
	{
		data->tab[i] = malloc(sizeof(int) * data->width);
		if (!(data->tab[i]))
			return (ft_free_all(data->tab, i));
		line = get_next_line(fd);
		data->tab[i] = ft_fill_line(data->tab[i], line, data->width);
		free(line);
		i++;
	}
	close(fd);
	return (data->tab);
}

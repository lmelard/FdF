/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:18:40 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/24 13:21:53 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_point	ft_init_point(int x, int y, t_data *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = data->tab[y][x];
	if (point.z == 0)
		point.color = COLOR_LOW;
	else
		point.color = COLOR_HIGH;
	return (point);
}

void	ft_draw_map(t_data *data, t_img *img)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = -1;
	while (++ y < data->height)
	{
		x = -1;
		while (++ x < data->width)
		{
			if (x < data->width - 1)
			{
				p1 = ft_init_point(x, y, data);
				p2 = ft_init_point(x + 1, y, data);
				ft_draw_line(ft_project(&p1, data), ft_project(&p2, data), img);
			}
			if (y < data->height - 1)
			{
				p1 = ft_init_point(x, y, data);
				p2 = ft_init_point(x, y + 1, data);
				ft_draw_line(ft_project(&p1, data), ft_project(&p2, data), img);
			}
		}
	}
}

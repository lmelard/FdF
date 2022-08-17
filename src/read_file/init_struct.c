/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:25:30 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/25 17:49:10 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	ft_new_width(t_data *data)
{
	int		dx;
	t_point	p1;
	t_point	p2;

	p1 = ft_init_point(0, data->height - 1, data);
	p1.y *= data->zoom;
	p1.x *= data->zoom;
	p2 = ft_init_point(data->width - 1, 0, data);
	p2.y *= data->zoom;
	p2.x *= data->zoom;
	ft_isometric(&p1);
	ft_isometric(&p2);
	dx = ft_abs(p2.x - p1.x);
	return (dx);
}

static int	ft_new_x1(t_data *data)
{
	t_point	p1;

	p1 = ft_init_point(0, data->height - 1, data);
	p1.x *= data->zoom;
	p1.y *= data->zoom;
	ft_isometric(&p1);
	return (p1.x);
}

static int	ft_new_height(t_data *data)
{
	int		dy;
	t_point	p1;
	t_point	p2;

	p1 = ft_init_point(0, 0, data);
	p1.y *= data->zoom;
	p1.x *= data->zoom;
	p2 = ft_init_point(data->width - 1, data->height - 1, data);
	p2.y *= data->zoom;
	p2.x *= data->zoom;
	ft_isometric(&p1);
	ft_isometric(&p2);
	dy = ft_abs(p2.y - p1.y);
	return (dy);
}

static int	ft_new_y1(t_data *data)
{
	t_point	p1;

	p1 = ft_init_point(0, 0, data);
	p1.y = p1.y * data->zoom;
	p1.x = p1.y * data->zoom;
	ft_isometric(&p1);
	return (p1.y);
}

void	ft_init_struct(t_data *data, char *file)
{
	data->height = ft_get_height(file);
	data->width = ft_get_width(file);
	data->altitude = 1.5;
	if (data->height > 400)
	{
		data->zoom = 1.6;
		data->altitude = 1;
	}
	else
		data->zoom = ft_min(WIN_WIDTH / data->width / 2,
				WIN_HEIGHT / data->height / 2);
	data->tab = ft_read_map(file, data);
	data->newx = ((WIN_WIDTH - ft_new_width(data)) / 2) - ft_new_x1(data);
	data->newy = ((WIN_HEIGHT - ft_new_height(data)) / 2) - ft_new_y1(data);
}
